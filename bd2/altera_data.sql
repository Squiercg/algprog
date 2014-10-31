Use Empresa;
DELIMITER $$
CREATE PROCEDURE altera_data (in cpf_in int, in nova_data date)
BEGIN  
	if (cpf_in is null) then
		select ("CPF Nulo") as Erro;
	else
		update Funcionario
        set Datanasc = nova_data
        where Cpf = cpf_in;
	end if;
END
$$
DELIMITER ;