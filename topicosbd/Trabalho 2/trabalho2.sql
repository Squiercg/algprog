/*

ssh 201319030386@10.87.0.219 
mkdir   ponto_extra2_201319030386

createdb -T template0 -E UTF-8 db_trabalho2_201319030386 -U 201319030386 -W

psql -d db_trabalho2_201319030386 -U 201319030386 -W

*/


/* O TRABALHO PRECISA CONTER PELO MENOS 15 TABELAS */
create table campeonato(
	nomecampeonato varchar(68) not null, 
	codcampeonato serial primary key, 
	ano integer not null
);

create table time( 
	nomecompletotime varchar(256) not null, 
	nomecurtotime varchar(68) not null,
	cidade varchar(68) not null,
	codtime serial primary key,
	nomeestadio varchar(256) not null
);

create table confederacao( 
	confederacaoid serial primary key,
 	nome varchar(256) not null,
	sede varchar(68) not null,
	estado varchar(2) not null,
	codtime integer,
	foreign key(codtime) references time(codtime) on delete restrict on update cascade
);

create table tecnico(
	codtecnico serial primary key, 
	nome varchar(68) not null,
	ultimo_nome varchar(68) not null,
	ano_nascimento int not null

);

create table contrato_tecnico_time(
	numero_contrato integer primary key,
	data_fim timestamp,
	data_inicio timestamp not null,
	codtime integer,
	foreign key(codtime) references time(codtime) on delete restrict on update cascade
);


create table torcida_organizada(
	torcidaid integer primary key,
	nome_torcida varchar(68) not null,
	codtime integer,
	foreign key(codtime) references time(codtime) on delete restrict on update cascade
);

create table empresario(
	empresarioid serial primary key,
	primeiro_nome varchar(256) not null,
	ultimo_nome varchar(256) not null,
	registro_empresario varchar(256) not null
); 


create table jogador( 
	codjogador serial primary key,
	nomecompletojogador varchar(256) not null,
	nomecurtojogador varchar(68) not null,
	posicao varchar(68) not null,
	numerocamisa integer not null,
	titular boolean not null default false,
	empresarioid integer,
	codtime integer,
	foreign key(codtime) references time(codtime) on delete restrict on update cascade,
	foreign key(empresarioid) references empresario(empresarioid) on delete restrict on update cascade
);

create table fa_clube(
	fa_clubeid integer primary key,
	nome_fa_clube varchar(68) not null,
	codjogador integer,
	foreign key(codjogador) references jogador(codjogador) on delete restrict on update cascade
);

create table arbrito(
	arbritoid serial primary key,
	primeiro_nome varchar(256) not null,
	ultimo_nome varchar(256) not null,
	registro_arbritro varchar(256) not null
);

create table jogo( 
	codjogo serial primary key,
	codtimecasa integer references time(codtime) on delete restrict on update cascade, 
	codtimevisitante integer references time(codtime) on delete restrict on update cascade,
	golstimecasa integer not null default 0,
	golstimevisitante integer not null default 0,
	arb1 integer not null,
	arb2 integer not null,
	arb3 integer not null,
	arb4 integer not null, 
	codcampeonato integer references campeonato(codcampeonato) on delete restrict on update cascade,
	foreign key(arb1) references arbrito(arbritoid) on delete restrict on update cascade,
	foreign key(arb2) references arbrito(arbritoid) on delete restrict on update cascade,
	foreign key(arb3) references arbrito(arbritoid) on delete restrict on update cascade,
	foreign key(arb4) references arbrito(arbritoid) on delete restrict on update cascade
);

create table gols(
	codgol serial primary key,
	codjogador integer,
	codjogo integer,
	codcampeonato integer,
	foreign key(codjogador) references jogador(codjogador) on delete restrict on update cascade,
	foreign key(codjogo) references jogo(codjogo) on delete restrict on update cascade,
	foreign key(codcampeonato) references campeonato(codcampeonato) on delete restrict on update cascade
);

create table jogo_tem_torcida_organizada(
	codjogo integer,
	torcidaid integer,
	primary key(codjogo,torcidaid),
	foreign key(codjogo) references jogo(codjogo) on delete restrict on update cascade,
	foreign key(torcidaid) references torcida_organizada(torcidaid) on delete restrict on update cascade
);

create table timecampeonato(
	codtime integer not null,
	codcampeonato integer not null,
	primary key(codtime, codcampeonato),
	foreign key(codtime) references time(codtime) on delete restrict on update cascade,
	foreign key(codcampeonato) references campeonato(codcampeonato) on delete restrict on update cascade
);

/*O BANCO DE DADOS PRECISA CONTER PELO MENOS 2 TRIGGERS*/

create function time_fechado() 
returns trigger as $$
declare
    contador integer := 0;
begin 
	SELECT count(*) INTO contador
  	FROM jogador
  	WHERE titular = true;
    if contador > 11 then
	 RAISE EXCEPTION 'time está completo';
    end if;
end; $$ language plpgsql;

CREATE TRIGGER time_completo BEFORE INSERT OR UPDATE ON jogador
    FOR EACH ROW EXECUTE PROCEDURE time_fechado();

/*O BANCO DE DADOS PRECISA ESTAR ALIMENTADO COM DADOS, DE TAL FORMA QUE, CONTENHA PELO MENOS 2 CAMPEONATOS ATIVOS CADASTRADOS, COM PELO MENOS 10 TIMES E 30 JOGOS CADASTRADOS PARA CADA CAMPEONATO.*/

/*O BANCO DE DADOS PRECISA CONTER A FUNÇÃO QUE EXIBE A CLASSIFICAÇÃO DO CAMPEONATO*/

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


/*O BANCO DE DADOS PRECISA CONTER A FUNÇÃO QUE EXIBE A LISTA DE ARTILHEIROS DO CAMPEONATO*/

CREATE FUNCTION artilheiro(campeonato_id bigint) RETURNS TABLE(ranque bigint, jogador text, gols bigint)
AS $$


select nomecompletojogador, (select count(g.*)
				from gols g, jogador j, campeonato c
				where c.codcampeonato = 1 and g.codjogador= j.codjogador) as gols
from jogador
order by gols

$$ LANGUAGE SQL;






