/*
pg_dump -Fp -O db_provaPratica_201319030386 -U 201319030386 -W > ~/prova/questao2.sql
*/

insert into Pessoa(cpf,rg,nome,formacaomusical,endereco,localnasc,datanasc) values('000000000','00000000','Augusto Ribas','Nenhuma','Campo Grande','1981-05-26 15:36:38');
insert into Pessoa(cpf,rg,nome,formacaomusical,endereco,localnasc,datanasc) values('000000001','00000001','Doglas Sorgatto','Bacharel em Musica','Campo Grande','1980-05-26 15:36:38');

insert into Autor(formacaopoetica,cpf) values('Nenhuma','000000000');
insert into Autor(formacaopoetica,cpf) values('Nenhuma','000000001');

insert into Cantor(grupo,estilo,empresario,valorcache,cpf) values('Capiband','Punk','Bruno Nazário',800.00,'000000000');
insert into Cantor(grupo,estilo,empresario,valorcache,cpf) values('Farock','Rock','Bruno Nazário',800.00,'000000001');
