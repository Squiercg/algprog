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
	nomeestadio varchar(256) not null,
	nometecnico varchar(256) not null
);

create table jogador(
	codjogador serial primary key,
	nomecompletojogador varchar(256) not null,
	nomecurtojogador varchar(68) not null,
	posicao varchar(68) not null,
	numerocamisa integer not null,
	codtime integer references time(codtime) on delete restrict on update cascade
);

create table jogo(
codjogo serial primary key,
codtimecasa integer references time(codtime) on delete restrict on update cascade,
codtimevisitante integer references time(codtime) on delete restrict on update cascade,
golstimecasa integer not null default 0,
golstimevisitante integer not null default 0,
arb1 varchar(256) not null,
arb2 varchar(256) not null,
arb3 varchar(256) not null,
arb4 varchar(256) not null,
codcampeonato integer references campeonato(codcampeonato) on delete restrict on update cascade
);

create table timecampeonato(
codtime integer not null,
codcampeonato integer not null,
primary key(codtime,codcampeonato),
foreign key(codtime) references time(codtime) on delete restrict on update cascade,
foreign key(codcampeonato) references campeonato(codcampeonato) on delete restrict on update cascade
);