CREATE FUNCTION "atualizaMesa"() RETURNS trigger
    LANGUAGE plpgsql
    AS $$
DECLARE
BEGIN

	UPDATE restaurante.mesa
    SET disponibilidade='0'
    WHERE id IN
    (
    	SELECT mesa_id
        FROM restaurante.mesa_has_atendimento
        WHERE atendimento_idatendimento = NEW.atendimento_idatendimento

    );

RETURN NEW;

END;

$$;



CREATE TRIGGER "criaAtendimentoAtualizaMesa"
    AFTER INSERT OR UPDATE ON mesa_has_atendimento
    FOR EACH ROW
    EXECUTE PROCEDURE "atualizaMesa"();

