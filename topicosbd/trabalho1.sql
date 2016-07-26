/*
Tópicos de Banco de dados (Professor: Hercules da Costa Sandim)
Aluno: Augusto Cesar de Aquino Ribas

T1 = Trabalho 1 (entregar a implementação da FUNCTION que exibe a classificação do campeonato de futebol)

*criando banco para o trabalho
createdb -T template0 -E UTF-8 campeonatot1_db_201319030386 -U 201319030386 -W

*Depois foram usados os arquivos
SQL LDD Campeonato Futebol Arquivo
SQL Povoamento

*acessando o banco
psql -d campeonatot1_db_201319030386 -U 201319030386 -W
*/



/*
Essa função tem um parametro, o id(um inteiro) do campeonato que se deseja a classificação final.
*/

CREATE FUNCTION classifica_campeonato(campeonato_id bigint) RETURNS TABLE(ranque bigint, nomecurtotime text, numero_pontos bigint, numero_jogos bigint, numero_vitorias bigint, numero_empates bigint, numero_derrotas bigint, gols_pro bigint, gols_contra bigint, saldo_gols bigint)
AS $$

select rank() over( order by numero_pontos desc, numero_vitorias desc, saldo_gols desc, gols_pro desc), * from
(SELECT 
	
	t.nomecurtotime,
		(
		(
			SELECT 3*COUNT(*)
			FROM jogo j1
			WHERE j1.codtimecasa=t.codtime and j1.golstimecasa>j1.golstimevisitante		
		)+
		(
			SELECT 3*COUNT(*)
			FROM jogo j2
			WHERE j2.codtimevisitante=t.codtime and j2.golstimevisitante>j2.golstimecasa
		)+
		(
			SELECT COUNT(*)
			FROM jogo j3
			WHERE (j3.codtimevisitante=t.codtime or j3.codtimecasa=t.codtime)  and golstimevisitante=golstimecasa		
		)
		) as numero_pontos		, 
		(
		(
			SELECT COUNT(*)
			FROM jogo j4
			WHERE j4.codtimecasa=t.codtime
		)+
		(
			SELECT COUNT(*)
			FROM jogo j5
			WHERE j5.codtimevisitante=t.codtime
		)
		) as numero_jogos   ,
		
		(
		(
			SELECT COUNT(*)
			FROM jogo j6
			WHERE j6.codtimecasa=t.codtime and j6.golstimecasa>j6.golstimevisitante		
		)+
		(
			SELECT COUNT(*)
			FROM jogo j7
			WHERE j7.codtimevisitante=t.codtime and j7.golstimevisitante>j7.golstimecasa
		)
		) as numero_vitorias	,
		
		(
			SELECT COUNT(*)
			FROM jogo j8
			WHERE (j8.codtimevisitante=t.codtime or j8.codtimecasa=t.codtime)  and golstimevisitante=golstimecasa		
		) as numero_empates ,
		
		(
		(
			SELECT COUNT(*)
			FROM jogo j9
			WHERE j9.codtimecasa=t.codtime and j9.golstimecasa < j9.golstimevisitante		
		)+
		(
			SELECT COUNT(*)
			FROM jogo j10
			WHERE j10.codtimevisitante=t.codtime and j10.golstimevisitante < j10.golstimecasa
		)
		) as numero_derrotas	,		
		(
		(
			SELECT SUM(j11.golstimecasa)
			FROM jogo j11
			WHERE j11.codtimecasa=t.codtime
		)+
		(
			SELECT  SUM(j12.golstimevisitante)
			FROM jogo j12
			WHERE j12.codtimevisitante=t.codtime
		)
		) as gols_pro	,		
		(
		(
			SELECT SUM(j13.golstimevisitante)
			FROM jogo j13
			WHERE j13.codtimecasa=t.codtime
		)+
		(
			SELECT  SUM(j14.golstimecasa)
			FROM jogo j14
			WHERE j14.codtimevisitante=t.codtime
		)
		) as gols_contra,
		(
		(
			SELECT SUM(j15.golstimecasa - j15.golstimevisitante)
			FROM jogo j15
			WHERE j15.codtimecasa=t.codtime
		)+
		(
			SELECT  SUM(j16.golstimevisitante - j16.golstimecasa )
			FROM jogo j16
			WHERE j16.codtimevisitante=t.codtime
		)
		) as saldo_gols		
		
FROM timecampeonato tc JOIN time t on tc.codtime=t.codtime
WHERE codcampeonato = $1
ORDER BY numero_pontos desc, numero_vitorias desc, saldo_gols desc, gols_pro desc) as classificacao

$$ LANGUAGE SQL;

/*
Exemplo de uso:
select * from classifica_campeonato(1);

Saída:
 ranque | nomecurtotime | numero_pontos | numero_jogos | numero_vitorias | numero_empates | numero_derrotas | gols_pro | gols_contra | saldo_gols 
--------+---------------+---------------+--------------+-----------------+----------------+-----------------+----------+-------------+------------
      1 | Palmeiras     |            14 |            6 |               4 |              2 |               0 |       14 |           8 |          6
      2 | Sao Paulo     |             9 |            6 |               2 |              3 |               1 |        8 |           7 |          1
      3 | Corinthians   |             6 |            6 |               1 |              3 |               2 |        9 |          13 |         -4
      4 | Santos        |             3 |            6 |               1 |              0 |               5 |       10 |          13 |         -3
(4 rows)
*/

