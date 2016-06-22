/*
*Augusto Cesar de Aquino Ribas
*Tópicos de Banco de dados - Hercules Sandim
*
*Comandos Usados:
*
*Criando o banco no terminal (usando o ssh)
*createdb -T template0 -E UTF-8 db_futebol_201319030386 -U 201319030386 -W
*
*/

/*Cria a tabela jogador*/

create table jogador(
jogadorId integer not null primary key,
nomeCompleto varchar(100) not null,
nomeCurto varchar(50) not null,
posicao varchar(50) not null,
camisa integer not null,
codTime integer not null
);

/*Cria a tabela time, e depois altera a tabela jogador para ter chave extrangeira dessa tabela*/
create table time(
codTime integer not null primary key,
nomeCompleto varchar(100) not null,
nomeCurto varchar(50) not null,
estadio varchar(50) not null,
tecnico varchar(50) not null,
cidade varchar(50) not null,
estado varchar(50) not null
);

ALTER TABLE jogador ADD CONSTRAINT codTime FOREIGN KEY (codTime) REFERENCES time (codTime) on delete cascade;

/*Cria tabela campeonato*/
create table campeonato(
codcampeonato integer not null primary key,
nome varchar(50) not null,
ano timestamp not null
);

/*Cria tabela jogo, depois adiciona as chaves extrangeiras*/
create table jogo(
jogoId integer not null primary key,
a1 varchar(100) not null,
a2 varchar(100) not null,
a3 varchar(100) not null,
a4 varchar(100) not null,
codCampeonato integer not null,
codTimeCasa integer not null,
golsTimeCasa integer not null default 0,
codTimeVisitante integer not null,
golsTimeVisitante integer not null default 0
);

ALTER TABLE jogo ADD CONSTRAINT codCampeonato FOREIGN KEY (codCampeonato) REFERENCES campeonato (codCampeonato) on delete cascade;
ALTER TABLE jogo ADD CONSTRAINT codTimeCasa FOREIGN KEY (codTimeCasa) REFERENCES time (codTime) on delete cascade;
ALTER TABLE jogo ADD CONSTRAINT codTimeVisitante FOREIGN KEY (codTimeVisitante) REFERENCES time (codTime) on delete cascade;

/*Cria tabela de relação n para n campeonatotime*/
CREATE TABLE campeonatotime (
codCampeonato int REFERENCES campeonato (codCampeonato) ON DELETE CASCADE,
codTime int REFERENCES time (codTime) ON UPDATE CASCADE
);


