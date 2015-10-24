USE Universidade;
DELIMITER $$
CREATE PROCEDURE consulta_disciplina (in codigo_in varchar(10), in nome_in varchar(30))
BEGIN
	if(codigo_in is null) then
		if(nome_in is null) then
			select ("É necessário o nome ou codigo da disciplina!") as Erro;
		else
			select *
            from Disciplinas 
            where nome LIKE nome_in;
		end if;
	else
		select *
        from Disciplinas 
        where codigo = codigo_in;
	end if;
END
$$
DELIMITER ;