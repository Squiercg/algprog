SET search_path = restaurante, pg_catalog;
drop function "atualizaMesa"()  cascade;

insert into funcionario(cpf,nome,funcao,salario,sexo) values('00000000001','Augusto Ribas','garcom',880.00,'M');
insert into funcionario(cpf,nome,funcao,salario,sexo) values('00000000002','Bruno Nazario','garcom',880.00,'M');
insert into mesa(id,disponibilidade,capacidade) values(1,BIT'0',8);
insert into mesa(id,disponibilidade,capacidade) values(2,BIT'0',6);
insert into atendimento(datahora,funcionario_cpf) values('2016-07-05 12:00:00','00000000001');
insert into atendimento(datahora,funcionario_cpf) values('2016-07-05 12:00:00','00000000002');

insert into mesa_has_atendimento(mesa_id,atendimento_idatendimento) values (1,1);
insert into mesa_has_atendimento(mesa_id,atendimento_idatendimento) values (2,2);


insert into fabricante(nome,nacionalidade) values ('FEMSA','BRA');

insert into TipoBebida(nome) values('Refrigerante');

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