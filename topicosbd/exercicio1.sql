/*Acessando o servidor */
ssh 201319030386@10.87.0.219

/*Criando banco de dados*/
createdb -T template0 -E UTF-8 db_201319030386 -U 201319030386 -W

/*Entrando no banco */
psql -d db_201319030386 -U 201319030386 -W

/*Criando tabela */
create table aluno(
id_aluno integer not null primary key,
nome_aluno varchar(40) not null default 'NP',
sexo_aluno char(1) not null check (sexo_aluno in ('M','F')),
dt_nasc timestamp,
dt_alter_tab timestamp not null default now(),
observacoes varchar(250)
);

/* 
NOTICE:  CREATE TABLE / PRIMARY KEY will create implicit index "aluno_pkey" for table "aluno"
CREATE TABLE   
*/

/*Inserindo dados na tabela aluno*/
insert into aluno (id_aluno, sexo_aluno) values ('1','X');
insert into aluno (id_aluno, sexo_aluno) values ('1','M');
insert into aluno (id_aluno, sexo_aluno) values ('1','F');

/* 
ERROR:  new row for relation "aluno" violates check constraint "aluno_sexo_aluno_check" 

INSERT 0 1 

ERROR:  duplicate key value violates unique constraint "aluno_pkey"                                                    
DETAIL:  Key (id_aluno)=(1) already exists.
*/

/*Alterando tabela aluno */
--alter table aluno drop column cod_sit_aluno;
alter table aluno add column cod_sit_aluno integer not null;
alter table aluno add column cod_sit_aluno integer;
alter table aluno add column id_curso integer;
alter table aluno alter column id_curso set not null;

update aluno set id_curso=0 where id_aluno=1;
update aluno set cod_sit_aluno=0 where id_aluno=1;

alter table aluno alter column cod_sit_aluno set not null;
alter table aluno alter column id_curso set not null;

/*
ERROR:  column "cod_sit_aluno" contains null values
ALTER TABLE 
ALTER TABLE
ERROR:  column "id_curso" contains null values
*/


/* Tabela situacao */
create table situacao(
cod_sit_aluno integer not null primary key,
desc_sit_aluno varchar(30),
dt_alteracao timestamp default now()
);
/*
NOTICE:  CREATE TABLE / PRIMARY KEY will create implicit index "situacao_pkey" for table "situacao"
CREATE TABLE
*/



/*Criar tabela curso*/

create table curso(
  id_curso integer not null primary key,
  nome_curso varchar(40) not null,
  dt_implantacao timestamp not null,
  dt_alteracao timestamp not null default now()
);

/*NOTICE:  CREATE TABLE / PRIMARY KEY will create implicit index "curso_pkey" for table "curso"
CREATE TABLE
*/

/*Alterar tabela aluno para setar chave estrangeira*/

alter table aluno add foreign key(id_curso) references curso(id_curso);
delete from aluno;
insert into aluno (id_aluno,sexo_aluno,id_curso,cod_sit_aluno) values (1,'M',1,1);
insert into curso (id_curso,nome_curso,dt_implantacao) values (1,'analise sistemas',now());
insert into situacao (cod_sit_aluno) values (1);

alter table aluno add foreign key(id_curso) references curso(id_curso) on delete restrict on update cascade;
alter table aluno add foreign key(cod_sit_aluno) references situacao(cod_sit_aluno) on delete restrict on update cascade;

/* 
ERROR:  insert or update on table "aluno" violates foreign key constraint "aluno_id_curso_fkey"
DETAIL:  Key (id_curso)=(0) is not present in table "curso".
DELETE 1

*/

/* */

/* */

/* */

/* */

/* */

/* */

/* */

/* */