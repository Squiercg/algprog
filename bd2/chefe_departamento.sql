Use Empresa;
DELIMITER $$
CREATE PROCEDURE chefe_departamento (in codigo_in int, in nome_in varchar(20))
BEGIN
	declare chefe_cpf int;
    
	if(codigo_in is null) then
		if(nome_in is null) then
			select("Nulo!") as Erro;
		else
			set chefe_cpf = (select Cpfgerente from Departamento where Dnome like nome_in);
            select Pnome, Unome, Cpf from Funcionario where Cpf = chefe_cpf;
		end if;
	else
		set chefe_cpf = (select Cpfgerente from departamento where Dnumero = codigo_in);
		select Pnome, Unome, Cpf from Funcionario where Cpf = chefe_cpf;
	end if;
END
$$
DELIMITER ;
