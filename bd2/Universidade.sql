CREATE SCHEMA Universidade;
USE Universidade;

CREATE TABLE Professores
(
	matricula SMALLINT,
	nome VARCHAR(100) not null,
	CPF VARCHAR(11) not null UNIQUE,
	sexo ENUM('M', 'F') not null,
	data_nascimento DATE not null,
	titulacao ENUM ('graduado', 'especialista', 'mestre', 'doutor'),
	categoria ENUM('auxiliar', 'assistente', 'adjunto', 'titular'),
	nro_Turmas SMALLINT DEFAULT 1,
	primary key (matricula)
) ENGINE = INNODB;

INSERT INTO Professores VALUES
	(1, 'Maria', '12345678912', 'F', '1971-05-09', 'doutor', 'assistente', 1), 
	(2, 'João', '12345678911', 'M', '1977-06-18', 'mestre', 'assistente', 1);

CREATE TABLE Cursos
(
	codigo SMALLINT,
	nome VARCHAR(30) not null UNIQUE,
	duracao ENUM ('4', '5', '6', '7', '8', '9', '10', '11', '12') not null,
	coordenador SMALLINT not null DEFAULT 1,
	primary key (codigo),
	foreign key (coordenador) REFERENCES Professores (matricula)
)ENGINE=INNODB;


INSERT INTO Cursos VALUES 
	(1, 'CCO', '4', 1), 
	(2, 'SIN', '6', 2), 
	(3, 'VET', '8', 1),
	(4, 'MAT', '10', 1);
	
CREATE TABLE Disciplinas
(
	codigo VARCHAR(10),
	nome VARCHAR(30) not null UNIQUE,
	creditos ENUM('2','3','4','5','6','7','8'),
	PRIMARY KEY (codigo)
)ENGINE=INNODB;

INSERT INTO Disciplinas VALUES 
	('CCO013', 'Fundamentos de Programacao', 6),
	('CCT620', 'Banco de Dados II', 4),
	('SIT420', 'Laboratório de Banco de Dados', 3),
	('CSP410', 'Computador e Sociedade', 3);

CREATE TABLE Turmas
(
	disciplina VARCHAR(10),
	codigo VARCHAR(10),
	vagas SMALLINT,
	professor SMALLINT,
	PRIMARY KEY (disciplina, codigo),
	FOREIGN KEY (disciplina) REFERENCES Disciplinas(codigo) ON DELETE CASCADE ON UPDATE CASCADE,
	FOREIGN KEY (professor) REFERENCES Professores (matricula) ON UPDATE CASCADE
)ENGINE=INNODB;

INSERT INTO Turmas VALUES ('CCT620', 'CCO_2007_1', 25, 02), ('SIT420', 'SIT_207_1', 20, 01);

INSERT INTO Turmas VALUES ('CSP410', 'CCO_2008_1', 25, 02);

CREATE TABLE Curriculos
(
	curso SMALLINT,
	disciplina VARCHAR(10),
	fase ENUM ('1','2','3','4','5','6','7','8','9','10','11','12'),
	PRIMARY KEY (curso, disciplina),
	FOREIGN KEY (curso) REFERENCES Cursos(codigo) ON DELETE CASCADE ON UPDATE CASCADE,
	FOREIGN KEY (disciplina) REFERENCES Disciplinas(codigo) ON DELETE CASCADE ON UPDATE CASCADE
)ENGINE=INNODB;

INSERT INTO Curriculos VALUES ('1', 'SIT420', 5);
