
/*funcionario(*idfuncionario,nome)*/
create table funcionario(
	idfuncionario serial primary key,
	nome varchar(200) not null
);


/*cliente(*idcliente,nome,endereco)*/
create table cliente(
	idcliente serial primary key,
	nome varchar(200) not null,
	endereco varchar(200) not null
);

/*cardapio(*idcardapio,nome,preco)*/
create table cardapio(
	idcardapio serial primary key,
	nome varchar(200) not null,
	preco numeric not null
);

/*estoque(*idestoque,nome,disponivel)*/
create table estoque(
	idestoque serial primary key,
	nome varchar(200) not null,
	disponivel int not null
);

/*conta(*idconta,entrada,saida,mesa,*idfuncionario,*idcliente)*/
create table conta(
	idconta serial primary key,
	entrada timestamp not null,
	saida timestamp,
	mesa int not null,
	idfuncionario integer references funcionario(idfuncionario) on delete restrict on update cascade,
	idcliente integer references cliente(idcliente) on delete restrict on update cascade
);


/*telefone(*idtelefone,numero,*idcliente)*/
create table telefone(
	numero varchar(11) not null,
	idcliente integer references cliente(idcliente) on delete restrict on update cascade,
	primary key(numero,idcliente)
);

/*conta_consumiu_cardapio(*idconta,*idcardapio,quantidade)*/
create table conta_consumiu_cardapio(
	idconta integer not null,
	idcardapio integer not null,
	quantidade integer not null default 1,
	primary key(idconta,idcardapio),
	foreign key(idconta) references conta(idconta) on delete restrict on update cascade,
	foreign key(idcardapio) references cardapio(idcardapio) on delete restrict on update cascade
);

/*cardapio_utiliza_estoque(*id_cardapio,*idestoque,quantidade)*/
create table cardapio_utiliza_estoque(
	idcardapio integer not null,
	idestoque integer not null,
	quantidade integer not null default 1,
	primary key(idcardapio,idestoque),	
	foreign key(idcardapio) references cardapio(idcardapio) on delete restrict on update cascade,
	foreign key(idestoque) references estoque(idestoque) on delete restrict on update cascade
);






