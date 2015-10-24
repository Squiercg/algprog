CREATE SCHEMA Empresa;
USE Empresa;


CREATE TABLE Funcionario 
(
 Pnome VARCHAR(20), 
 Minicial CHAR,
 
 Unome VARCHAR(20), 
 Cpf INT, 
 Datanasc DATE, 
 Endereco VARCHAR(50), 
 Sexo CHAR, 
 Salario NUMERIC, 
 Cpfsuper INT,
                          
 Dnr INT,

 PRIMARY KEY(Cpf),
 FOREIGN KEY(Cpfsuper) REFERENCES Funcionario (Cpf));



CREATE TABLE Departamento 
(
 Dnumero INT, 
 Dnome VARCHAR(20), 
 Cpfgerente INT,

 Datainigerente DATE,
 PRIMARY KEY(Dnumero),
 FOREIGN KEY(Cpfgerente) REFERENCES Funcionario (Cpf));



CREATE TABLE Projeto 
(
 Projnumero INT, 
 Projnome VARCHAR(20), 
 Projlocal VARCHAR(20),
 Dnum INT,
 PRIMARY KEY(Projnumero),
 FOREIGN KEY(Dnum) REFERENCES Departamento (Dnumero));



CREATE TABLE Dependente 
(
 Fcpf INT, 
 Nomedepend VARCHAR(20), 
 Sexo CHAR, 
 Datanasc DATE,

 Parentesco VARCHAR(20),
 PRIMARY KEY(Fcpf, Nomedepend),
 FOREIGN KEY(Fcpf) REFERENCES Funcionario (Cpf));



CREATE TABLE Local_Depto 
( 
 Dnumero INT, 
 Dlocal VARCHAR(20),

 PRIMARY KEY(Dnumero, Dlocal),

 FOREIGN KEY(Dnumero) REFERENCES Departamento (Dnumero));



CREATE TABLE Trabalha_Em 
(
 Fcpf INT, 
 Pnr INT, 
 Horas NUMERIC,

 PRIMARY KEY(Fcpf, Pnr),

 FOREIGN KEY(Fcpf) REFERENCES Funcionario (Cpf),

 FOREIGN KEY(Pnr) REFERENCES Projeto (Projnumero));

ALTER TABLE Funcionario ADD CONSTRAINT FOREIGN KEY(Dnr) REFERENCES Departamento (Dnumero);

