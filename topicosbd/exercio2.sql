select * from information_schema.table_constraints;
select * from information_schema.key_column_usage;

/*
1 - Monte a consulta SQL ao catálogo do PostgreSQL, capaz de retornar as seguintes informações:
*/

/*a) retornar as chaves primárias de todas as tabelas do banco de dados*/

select A.table_name as tabela, B.column_name as "chave primaria" 
from information_schema.table_constraints A,
     information_schema.key_column_usage B
where A.constraint_type='PRIMARY KEY' and A.constraint_name=B.constraint_name;
/*Saida:
  tabela  | chave primaria 
----------+----------------
 aluno    | id_aluno
 curso    | id_curso
 situacao | cod_sit_aluno
(3 rows)
*/

/*b) retornar as chaves estrangeiras de uma determinada tabela do banco de dados*/

select A.table_name as tabela, B.column_name as "chave estrangeira" 
from information_schema.table_constraints A,
     information_schema.key_column_usage B
where A.constraint_type='FOREIGN KEY' and A.constraint_name=B.constraint_name and A.table_name='aluno';
/*Saida
 tabela | chave estrangeira 
--------+-------------------
 aluno  | id_curso
 aluno  | cod_sit_aluno
(2 rows)
*/

/*c) retornar o tamanho de um banco de dados, em bytes*/
SELECT pg_database_size('db_201319030386');


/*Podemos usar a função pg_size_pretty para transformar essa saida em kbytes, mas não foi o caso aqui
pg_database_size 
------------------
          6169400
(1 row)
*/

/*d) retornar o tamanho de uma tabela, em bytes*/

SELECT pg_table_size('aluno');

/*
 pg_table_size 
---------------
          8192
(1 row)
*/

/*e) retornar, para  cada atributo de uma determinada tabela: nome do atributo, tipo do atributo, nulabilidade (not null ou não) e valor default (se houver)*/

select column_name, data_type, is_nullable, column_default
from information_schema.columns
where table_name='aluno';

/*
  column_name  |          data_type          | is_nullable |     column_default      
---------------+-----------------------------+-------------+-------------------------
 cod_sit_aluno | integer                     | NO          | 
 id_curso      | integer                     | NO          | 
 observacoes   | character varying           | YES         | 
 dt_alter_tab  | timestamp without time zone | NO          | now()
 dt_nasc       | timestamp without time zone | YES         | 
 sexo_aluno    | character                   | NO          | 
 nome_aluno    | character varying           | NO          | 'NP'::character varying
 id_aluno      | integer                     | NO          | 
(8 rows)
*/
