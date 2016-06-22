/*
Exercicio 4
Augusto Cesar de Aquino Ribas
Tópicos de banco de dados

Aqui estão as alterações no banco e povoamento simples (não adicionei o nome dos jogadores).
No fim está a consulta do exercicio.
*/


/*Adicionando dois campos de pontuação necessarios*/
alter table jogo add column pontosTimeCasa integer not null;
alter table jogo add column pontosTimeVisitante integer not null;

/*Criando uma sequencia, e usando ela para chave do campeonato*/
create sequence seq_campeonato;
alter table campeonato alter codcampeonato set default nextval('seq_campeonato');
create sequence seq_jogador;
alter table jogador alter jogadorid set default nextval('seq_jogador');
create sequence seq_time;
alter table time alter codTime set default nextval('seq_time');
create sequence seq_jogo;
alter table jogo alter jogoid set default nextval('seq_jogo');

/*Adicionar dados*/
insert into campeonato (ano,nome) values('2016-06-01','Disputa Facom');

insert into time(estado,cidade,tecnico,estadio,nomecurto,nomecompleto) values('MS','Campo Grande','Augusto','Morenão','Abio','Atlética Biologia');
insert into time(estado,cidade,tecnico,estadio,nomecurto,nomecompleto) values('MS','Campo Grande','Bruno','Capirão','ACapy','Atlética Capivara');
insert into time(estado,cidade,tecnico,estadio,nomecurto,nomecompleto) values('MS','Campo Grande','Doglas','Filosofão','Afio','Atlética Filosofia');

insert into campeonatotime values(1,1);
insert into campeonatotime values(1,2);
insert into campeonatotime values(1,3);

insert into jogo (pontostimevisitante,pontostimecasa,golstimevisitante,golstimecasa,codtimevisitante,codtimecasa,codcampeonato,a4,a3,a2,a1)
values(0,3,2,6,1,2,1,'Ze','Tião','João','Hercules');
insert into jogo (pontostimevisitante,pontostimecasa,golstimevisitante,golstimecasa,codtimevisitante,codtimecasa,codcampeonato,a4,a3,a2,a1)
values(3,0,5,1,1,3,1,'Ze','Tião','João','Hercules');
insert into jogo (pontostimevisitante,pontostimecasa,golstimevisitante,golstimecasa,codtimevisitante,codtimecasa,codcampeonato,a4,a3,a2,a1)
values(3,0,2,1,2,3,1,'Ze','Tião','João','Hercules');
insert into jogo (pontostimevisitante,pontostimecasa,golstimevisitante,golstimecasa,codtimevisitante,codtimecasa,codcampeonato,a4,a3,a2,a1)
values(1,1,1,1,2,1,1,'Ze','Tião','João','Hercules');
insert into jogo (pontostimevisitante,pontostimecasa,golstimevisitante,golstimecasa,codtimevisitante,codtimecasa,codcampeonato,a4,a3,a2,a1)
values(0,3,0,1,3,1,1,'Ze','Tião','João','Hercules');
insert into jogo (pontostimevisitante,pontostimecasa,golstimevisitante,golstimecasa,codtimevisitante,codtimecasa,codcampeonato,a4,a3,a2,a1)
values(0,3,0,2,3,2,1,'Ze','Tião','João','Hercules');
insert into jogo (pontostimevisitante,pontostimecasa,golstimevisitante,golstimecasa,codtimevisitante,codtimecasa,codcampeonato,a4,a3,a2,a1)
values(3,0,7,1,1,2,1,'Ze','Tião','João','Hercules');
insert into jogo (pontostimevisitante,pontostimecasa,golstimevisitante,golstimecasa,codtimevisitante,codtimecasa,codcampeonato,a4,a3,a2,a1)
values(0,3,0,1,3,2,1,'Ze','Tião','João','Hercules');
insert into jogo (pontostimevisitante,pontostimecasa,golstimevisitante,golstimecasa,codtimevisitante,codtimecasa,codcampeonato,a4,a3,a2,a1)
values(0,3,0,1,2,1,1,'Ze','Tião','João','Hercules');

/*Consulta sql*/
select 
	row_number() over (order by pontos desc, vitorias desc, saldo_gols desc, gols_pro desc) as classificacao, 
	*
from (
	select 	
		nomecompleto ,
		(
			select
				sum(pontostimecasa)
			from jogo
			where codTime=codTimeCasa
		) + (
			select	
				sum(pontostimeVisitante)
			from jogo
			where codTime=codTimeVisitante
		) as pontos ,


		(
			select
				count(jogoID)
			from jogo
			where codTime=codTimeCasa
		) + (
			select	
				count(jogoID)
			from jogo
			where codTime=codTimeVisitante
		) as jogos ,

		(
			select
				count(jogoID)
			from jogo
			where codTime=codTimeCasa and pontostimecasa=3
		) + (
			select	
				count(jogoID)
			from jogo
			where codTime=codTimeVisitante and pontostimeVisitante=3
		) as vitorias , 

		(
			select
				count(jogoID)
			from jogo
			where codTime=codTimeCasa and pontostimecasa=1
		) + (
			select	
				count(jogoID)
			from jogo
			where codTime=codTimeVisitante and pontostimeVisitante=1
		) as empates , 

		(
			select
				count(jogoID)
			from jogo
			where codTime=codTimeCasa and pontostimecasa=0
		) + (
			select	
				count(jogoID)
			from jogo
			where codTime=codTimeVisitante and pontostimeVisitante=0
		) as derrotas , 

		(
			select
				sum(golstimecasa)
			from jogo
			where codTime=codTimeCasa
		) + (
			select	
				sum(golstimeVisitante)
			from jogo
			where codTime=codTimeVisitante
		) as gols_pro , 

		(
			select
				sum(golstimeVisitante)
			from jogo
			where codTime=codTimeCasa
		) + (
			select	
				sum(golstimecasa)
			from jogo
			where codTime=codTimeVisitante
		) as gols_contra , 


		(
			select
				sum(golstimecasa-golstimeVisitante)
			from jogo
			where codTime=codTimeCasa
		) + (
			select	
				sum(golstimeVisitante-golstimecasa)
			from jogo
			where codTime=codTimeVisitante
		) as saldo_gols

	from time
) as geral
order by classificacao;

/*
Saida:
 classificacao |    nomecompleto    | pontos | jogos | vitorias | empates | derrotas | gols_pro | gols_contra | saldo_gols 
---------------+--------------------+--------+-------+----------+---------+----------+----------+-------------+------------
             1 | Atlética Biologia  |     13 |     6 |        4 |       1 |        1 |       17 |           9 |          8
             2 | Atlética Capivara  |     13 |     7 |        4 |       1 |        2 |       13 |          12 |          1
             3 | Atlética Filosofia |      0 |     5 |        0 |       0 |        5 |        2 |          11 |         -9
(3 rows)
*/




