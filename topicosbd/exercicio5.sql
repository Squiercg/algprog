/*
*********************************** 
*Augusto Cesar de Aquino Ribas    *
*Análise de Sistemas              *
*Tópicos de banco de dados        *
*Professor: Hercolis Sandim       *
***********************************
*/

/*No ssh:
** Acessando o servidor 
ssh 201319030386@10.87.0.219

**Caso o banco ja exista
dropdb  restaurante_db_201319030386 -U 201319030386 -W

** Criando banco de dados
createdb -T template0 -E UTF-8 restaurante_db_201319030386 -U 201319030386 -W

** Entrando no banco 
psql -d restaurante_db_201319030386 -U 201319030386 -W
*/


/*Na interface psql*/

CREATE SCHEMA bebida;
CREATE SCHEMA comida;

/*Tabela Funcionario*/
create table Funcionario(
cpf varchar(11) not null primary key,
nome varchar(128) not null,
funcao varchar(64) not null,
salario double precision not null
);

/*Tabela Mesa*/
create table Mesa(
idMesa serial not null primary key,
disponibilidade boolean not null,
capacidade integer not null
);

/*Tabela Atendimento*/
create table Atendimento(
idAtendimento serial not null primary key,
data timestamp not null,
cpf varchar(11) references Funcionario(cpf) on delete restrict on update cascade
);

/*Tabela Mesa_Realizado_Atendimento*/
create table Mesa_Realizado_Atendimento(
idMesa integer not null,
idAtendimento integer not null,
primary key(idMesa,idAtendimento),
foreign key(idMesa) references Mesa(idMesa) on delete restrict on update cascade,
foreign key(idAtendimento) references Atendimento(idAtendimento) on delete restrict on update cascade
);

/**********************************
*Bebida
***********************************/

/*Tabela Fabricante*/
create table bebida.Fabricante(
idFabricante serial not null primary key,
nome varchar(128) not null,
nacionalidade varchar(3) not null
);

/*Tabela TipoBebida*/
create table bebida.TipoBebida(
idTipoBebida serial not null primary key,
nome varchar(128) not null
);

/*Bebida*/
create table bebida.Bebida(
idBebida serial not null primary key,
nome varchar(64) not null,
preco_venda double precision not null CHECK (preco_venda >= 0),
idTipoBebida integer not null,
idFabricante integer not null,
foreign key(idTipoBebida) references bebida.TipoBebida(idTipoBebida) on delete restrict on update cascade,
foreign key(idFabricante) references bebida.Fabricante(idFabricante) on delete restrict on update cascade
);

/*AtendimentoServeBebida*/
create table bebida.AtendimentoServeBebida(
idBebida serial not null,
idAtendimento integer not null,
preco_pago double precision not null CHECK (preco_pago >= 0),
primary key(idBebida,idAtendimento),
foreign key(idBebida) references bebida.Bebida(idBebida) on delete restrict on update cascade,
foreign key(idAtendimento) references Atendimento(idAtendimento) on delete restrict on update cascade
);

/**********************************
*Comida
***********************************/

/*Tabela Item*/
create table comida.Item(
idItem serial not null primary key,
nome varchar(128) not null
);

/*Tabela TipoPrato*/
create table comida.TipoPrato(
idTipoPrato serial not null primary key,
nome varchar(128) not null
);

/*Tabela Prato*/
create table comida.Prato(
idPrato serial not null primary key,
nome varchar(128) not null,
preco_venda double precision not null CHECK (preco_venda >= 0),
idTipoPrato integer not null,
foreign key(idTipoPrato) references comida.TipoPrato(idTipoPrato) on delete restrict on update cascade
);

/*Tabela PratoPossuiItem*/
create table comida.PratoPossuiItem(
idPrato integer not null,
idItem integer not null,
primary key(idPrato,idItem),
foreign key(idPrato) references comida.Prato(idPrato) on delete restrict on update cascade,
foreign key(idItem) references comida.Item(idItem) on delete restrict on update cascade
);

/*AtendimentoServePrato*/
create table comida.AtendimentoServePrato(
idPrato integer not null,
idAtendimento integer not null,
preco_pago double precision not null CHECK (preco_pago >= 0),
primary key(idPrato,idAtendimento),
foreign key(idPrato) references comida.Prato(idPrato) on delete restrict on update cascade,
foreign key(idAtendimento) references Atendimento(idAtendimento) on delete restrict on update cascade
);

/*Funcao e trigger para avaliar o salario condiz com um salario minimo*/
CREATE FUNCTION salario_minimo() RETURNS trigger AS $salario_minimo$
    BEGIN
        --Checa se o funcionario recebe salario minimo
        IF NEW.salario < 880.00 THEN
            RAISE EXCEPTION '% Nao pode receber menos de um salario minimo';
        END IF;

        RETURN NEW;

    END;
$salario_minimo$ LANGUAGE plpgsql;

CREATE TRIGGER salario_minimo BEFORE INSERT OR UPDATE ON Funcionario
    FOR EACH ROW EXECUTE PROCEDURE salario_minimo();


/*Povoamento*/
insert into Funcionario(cpf,nome,funcao,salario) values('00000000001','Augusto Ribas','garcom',880.00);
insert into Funcionario(cpf,nome,funcao,salario) values('00000000002','Bruno Nazario','garcom',880.00);
insert into Mesa(disponibilidade,capacidade) values('true',8);
insert into Mesa(disponibilidade,capacidade) values('true',6);
insert into Atendimento(data,cpf) values('2016-07-05 12:00:00','00000000001');
insert into Atendimento(data,cpf) values('2016-07-05 12:00:00','00000000002');
insert into Mesa_Realizado_Atendimento(idMesa,idAtendimento) values (1,1);
insert into Mesa_Realizado_Atendimento(idMesa,idAtendimento) values (2,2);
insert into bebida.Fabricante(nome,nacionalidade) values ('FEMSA','BRA');
insert into bebida.TipoBebida(nome) values('Refrigerante');
insert into bebida.Bebida(nome,preco_venda,idTipoBebida,idFabricante) values ('Coca Cola',3.50,1,1);
insert into bebida.AtendimentoServeBebida(idBebida,idAtendimento,preco_pago) values (1,1,7);
insert into bebida.AtendimentoServeBebida(idBebida,idAtendimento,preco_pago) values (1,2,3.50);
insert into comida.Item(nome) values('hamburguer');
insert into comida.Item(nome) values('pao');
insert into comida.TipoPrato(nome) values ('sanduiche');
insert into comida.Prato(nome,preco_venda,idTipoPrato) values('Hamburguer Simples',10.00,1);
insert into comida.PratoPossuiItem(idPrato,idItem) values(1,1);
insert into comida.PratoPossuiItem(idPrato,idItem) values(1,2);
insert into comida.AtendimentoServePrato(idPrato,idAtendimento,preco_pago) values (1,1,12);
insert into comida.AtendimentoServePrato(idPrato,idAtendimento,preco_pago) values (1,2,12);

/*Checa se a Trigger existe
select tgname
from pg_trigger
where not tgisinternal
and tgrelid = 'Funcionario'::regclass;

*Seu codigo
select tgname, proname, prosrc 
from pg_trigger t
join pg_proc p on p.oid = tgfoid
where not tgisinternal
and tgrelid = 'Funcionario'::regclass;
*/


/*PG DUMP
pg_dump --inserts -Fp restaurante_db_201319030386 -U 201319030386 -W > pg_dump_restaurante_db_201319030386.sql
*/









