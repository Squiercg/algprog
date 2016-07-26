CREATE FUNCTION functionSalary(mes integer, anos integer) RETURNS TABLE(f1 text, f2 double precision)
AS $$

select F.nome , 
/*Salario base*/
F.salario + 
/*Gorgetas das bebidas*/
(
	select sum(preco_pago) * 0.05 
	from atendimento_has_bebida 
	where atendimento_idatendimento=(
		select idatendimento 
		from atendimento 
		where funcionario_cpf=F.cpf and date_part('month',datahora)=$1 and date_part('year',datahora)=$2)
) +
/*Gorgetas das comidas*/
(
	select sum(preco_pago) * 0.05 
	from prato_has_atendimento 
	where atendimento_idatendimento=(
		select idatendimento 
		from atendimento 
		where funcionario_cpf=F.cpf and date_part('month',datahora)=$1 and date_part('year',datahora)=$2)
) as salario_total
from funcionario F
$$ LANGUAGE SQL;
