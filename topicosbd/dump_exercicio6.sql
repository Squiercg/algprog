--
-- PostgreSQL database dump
--

SET statement_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SET check_function_bodies = false;
SET client_min_messages = warning;

--
-- Name: restaurante; Type: SCHEMA; Schema: -; Owner: 201319030386
--

CREATE SCHEMA restaurante;


ALTER SCHEMA restaurante OWNER TO "201319030386";

--
-- Name: plpgsql; Type: EXTENSION; Schema: -; Owner: 
--

CREATE EXTENSION IF NOT EXISTS plpgsql WITH SCHEMA pg_catalog;


--
-- Name: EXTENSION plpgsql; Type: COMMENT; Schema: -; Owner: 
--

COMMENT ON EXTENSION plpgsql IS 'PL/pgSQL procedural language';


SET search_path = restaurante, pg_catalog;

--
-- Name: sexo; Type: DOMAIN; Schema: restaurante; Owner: 201319030386
--

CREATE DOMAIN sexo AS character(1) NOT NULL
	CONSTRAINT sexo_chk CHECK ((VALUE = ANY (ARRAY['M'::bpchar, 'F'::bpchar])));


ALTER DOMAIN restaurante.sexo OWNER TO "201319030386";

--
-- Name: atualizaMesa(); Type: FUNCTION; Schema: restaurante; Owner: 201319030386
--

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


ALTER FUNCTION restaurante."atualizaMesa"() OWNER TO "201319030386";

--
-- Name: functionsalary(integer, integer); Type: FUNCTION; Schema: restaurante; Owner: 201319030386
--

CREATE FUNCTION functionsalary(mes integer, anos integer) RETURNS TABLE(f1 text, f2 double precision)
    LANGUAGE sql
    AS $_$

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
$_$;


ALTER FUNCTION restaurante.functionsalary(mes integer, anos integer) OWNER TO "201319030386";

SET default_tablespace = '';

SET default_with_oids = false;

--
-- Name: atendimento; Type: TABLE; Schema: restaurante; Owner: 201319030386; Tablespace: 
--

CREATE TABLE atendimento (
    idatendimento integer NOT NULL,
    funcionario_cpf character varying(11) NOT NULL,
    datahora timestamp without time zone DEFAULT now() NOT NULL
);


ALTER TABLE restaurante.atendimento OWNER TO "201319030386";

--
-- Name: atendimento_has_bebida; Type: TABLE; Schema: restaurante; Owner: 201319030386; Tablespace: 
--

CREATE TABLE atendimento_has_bebida (
    atendimento_idatendimento integer NOT NULL,
    bebida_idbebida integer NOT NULL,
    preco_pago double precision NOT NULL
);


ALTER TABLE restaurante.atendimento_has_bebida OWNER TO "201319030386";

--
-- Name: atendimento_idatendimento_seq; Type: SEQUENCE; Schema: restaurante; Owner: 201319030386
--

CREATE SEQUENCE atendimento_idatendimento_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE restaurante.atendimento_idatendimento_seq OWNER TO "201319030386";

--
-- Name: atendimento_idatendimento_seq; Type: SEQUENCE OWNED BY; Schema: restaurante; Owner: 201319030386
--

ALTER SEQUENCE atendimento_idatendimento_seq OWNED BY atendimento.idatendimento;


--
-- Name: bebida; Type: TABLE; Schema: restaurante; Owner: 201319030386; Tablespace: 
--

CREATE TABLE bebida (
    idbebida integer NOT NULL,
    tipobebida_idtipobebida integer NOT NULL,
    fabricante_idfabricante integer,
    nome character varying(64) NOT NULL,
    preco_venda double precision NOT NULL
);


ALTER TABLE restaurante.bebida OWNER TO "201319030386";

--
-- Name: bebida_idbebida_seq; Type: SEQUENCE; Schema: restaurante; Owner: 201319030386
--

CREATE SEQUENCE bebida_idbebida_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE restaurante.bebida_idbebida_seq OWNER TO "201319030386";

--
-- Name: bebida_idbebida_seq; Type: SEQUENCE OWNED BY; Schema: restaurante; Owner: 201319030386
--

ALTER SEQUENCE bebida_idbebida_seq OWNED BY bebida.idbebida;


--
-- Name: fabricante; Type: TABLE; Schema: restaurante; Owner: 201319030386; Tablespace: 
--

CREATE TABLE fabricante (
    idfabricante integer NOT NULL,
    nome character varying(128) NOT NULL,
    nacionalidade character(3) NOT NULL
);


ALTER TABLE restaurante.fabricante OWNER TO "201319030386";

--
-- Name: fabricante_idfabricante_seq; Type: SEQUENCE; Schema: restaurante; Owner: 201319030386
--

CREATE SEQUENCE fabricante_idfabricante_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE restaurante.fabricante_idfabricante_seq OWNER TO "201319030386";

--
-- Name: fabricante_idfabricante_seq; Type: SEQUENCE OWNED BY; Schema: restaurante; Owner: 201319030386
--

ALTER SEQUENCE fabricante_idfabricante_seq OWNED BY fabricante.idfabricante;


--
-- Name: funcionario; Type: TABLE; Schema: restaurante; Owner: 201319030386; Tablespace: 
--

CREATE TABLE funcionario (
    cpf character varying(11) NOT NULL,
    nome character varying(128) NOT NULL,
    funcao character varying(64) NOT NULL,
    salario double precision NOT NULL,
    sexo sexo NOT NULL
);


ALTER TABLE restaurante.funcionario OWNER TO "201319030386";

--
-- Name: item; Type: TABLE; Schema: restaurante; Owner: 201319030386; Tablespace: 
--

CREATE TABLE item (
    iditem integer NOT NULL,
    nome character varying(128) NOT NULL
);


ALTER TABLE restaurante.item OWNER TO "201319030386";

--
-- Name: item_iditem_seq; Type: SEQUENCE; Schema: restaurante; Owner: 201319030386
--

CREATE SEQUENCE item_iditem_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE restaurante.item_iditem_seq OWNER TO "201319030386";

--
-- Name: item_iditem_seq; Type: SEQUENCE OWNED BY; Schema: restaurante; Owner: 201319030386
--

ALTER SEQUENCE item_iditem_seq OWNED BY item.iditem;


--
-- Name: mesa; Type: TABLE; Schema: restaurante; Owner: 201319030386; Tablespace: 
--

CREATE TABLE mesa (
    id integer NOT NULL,
    disponibilidade bit(1) NOT NULL,
    capacidade integer NOT NULL
);


ALTER TABLE restaurante.mesa OWNER TO "201319030386";

--
-- Name: mesa_has_atendimento; Type: TABLE; Schema: restaurante; Owner: 201319030386; Tablespace: 
--

CREATE TABLE mesa_has_atendimento (
    mesa_id integer NOT NULL,
    atendimento_idatendimento integer NOT NULL
);


ALTER TABLE restaurante.mesa_has_atendimento OWNER TO "201319030386";

--
-- Name: prato; Type: TABLE; Schema: restaurante; Owner: 201319030386; Tablespace: 
--

CREATE TABLE prato (
    idprato integer NOT NULL,
    tipoprato_idtipoprato integer NOT NULL,
    nome character varying(128) NOT NULL,
    preco_venda double precision NOT NULL
);


ALTER TABLE restaurante.prato OWNER TO "201319030386";

--
-- Name: prato_has_atendimento; Type: TABLE; Schema: restaurante; Owner: 201319030386; Tablespace: 
--

CREATE TABLE prato_has_atendimento (
    prato_idprato integer NOT NULL,
    atendimento_idatendimento integer NOT NULL,
    preco_pago double precision NOT NULL
);


ALTER TABLE restaurante.prato_has_atendimento OWNER TO "201319030386";

--
-- Name: prato_has_item; Type: TABLE; Schema: restaurante; Owner: 201319030386; Tablespace: 
--

CREATE TABLE prato_has_item (
    prato_idprato integer NOT NULL,
    item_iditem integer NOT NULL
);


ALTER TABLE restaurante.prato_has_item OWNER TO "201319030386";

--
-- Name: prato_idprato_seq; Type: SEQUENCE; Schema: restaurante; Owner: 201319030386
--

CREATE SEQUENCE prato_idprato_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE restaurante.prato_idprato_seq OWNER TO "201319030386";

--
-- Name: prato_idprato_seq; Type: SEQUENCE OWNED BY; Schema: restaurante; Owner: 201319030386
--

ALTER SEQUENCE prato_idprato_seq OWNED BY prato.idprato;


--
-- Name: tipobebida; Type: TABLE; Schema: restaurante; Owner: 201319030386; Tablespace: 
--

CREATE TABLE tipobebida (
    idtipobebida integer NOT NULL,
    nome character varying(128) NOT NULL
);


ALTER TABLE restaurante.tipobebida OWNER TO "201319030386";

--
-- Name: tipobebida_idtipobebida_seq; Type: SEQUENCE; Schema: restaurante; Owner: 201319030386
--

CREATE SEQUENCE tipobebida_idtipobebida_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE restaurante.tipobebida_idtipobebida_seq OWNER TO "201319030386";

--
-- Name: tipobebida_idtipobebida_seq; Type: SEQUENCE OWNED BY; Schema: restaurante; Owner: 201319030386
--

ALTER SEQUENCE tipobebida_idtipobebida_seq OWNED BY tipobebida.idtipobebida;


--
-- Name: tipoprato; Type: TABLE; Schema: restaurante; Owner: 201319030386; Tablespace: 
--

CREATE TABLE tipoprato (
    idtipoprato integer NOT NULL,
    nome character varying(128) NOT NULL
);


ALTER TABLE restaurante.tipoprato OWNER TO "201319030386";

--
-- Name: tipoprato_idtipoprato_seq; Type: SEQUENCE; Schema: restaurante; Owner: 201319030386
--

CREATE SEQUENCE tipoprato_idtipoprato_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE restaurante.tipoprato_idtipoprato_seq OWNER TO "201319030386";

--
-- Name: tipoprato_idtipoprato_seq; Type: SEQUENCE OWNED BY; Schema: restaurante; Owner: 201319030386
--

ALTER SEQUENCE tipoprato_idtipoprato_seq OWNED BY tipoprato.idtipoprato;


--
-- Name: idatendimento; Type: DEFAULT; Schema: restaurante; Owner: 201319030386
--

ALTER TABLE ONLY atendimento ALTER COLUMN idatendimento SET DEFAULT nextval('atendimento_idatendimento_seq'::regclass);


--
-- Name: idbebida; Type: DEFAULT; Schema: restaurante; Owner: 201319030386
--

ALTER TABLE ONLY bebida ALTER COLUMN idbebida SET DEFAULT nextval('bebida_idbebida_seq'::regclass);


--
-- Name: idfabricante; Type: DEFAULT; Schema: restaurante; Owner: 201319030386
--

ALTER TABLE ONLY fabricante ALTER COLUMN idfabricante SET DEFAULT nextval('fabricante_idfabricante_seq'::regclass);


--
-- Name: iditem; Type: DEFAULT; Schema: restaurante; Owner: 201319030386
--

ALTER TABLE ONLY item ALTER COLUMN iditem SET DEFAULT nextval('item_iditem_seq'::regclass);


--
-- Name: idprato; Type: DEFAULT; Schema: restaurante; Owner: 201319030386
--

ALTER TABLE ONLY prato ALTER COLUMN idprato SET DEFAULT nextval('prato_idprato_seq'::regclass);


--
-- Name: idtipobebida; Type: DEFAULT; Schema: restaurante; Owner: 201319030386
--

ALTER TABLE ONLY tipobebida ALTER COLUMN idtipobebida SET DEFAULT nextval('tipobebida_idtipobebida_seq'::regclass);


--
-- Name: idtipoprato; Type: DEFAULT; Schema: restaurante; Owner: 201319030386
--

ALTER TABLE ONLY tipoprato ALTER COLUMN idtipoprato SET DEFAULT nextval('tipoprato_idtipoprato_seq'::regclass);


--
-- Data for Name: atendimento; Type: TABLE DATA; Schema: restaurante; Owner: 201319030386
--

INSERT INTO atendimento VALUES (1, '00000000001', '2016-07-05 12:00:00');
INSERT INTO atendimento VALUES (2, '00000000002', '2016-07-05 12:00:00');


--
-- Data for Name: atendimento_has_bebida; Type: TABLE DATA; Schema: restaurante; Owner: 201319030386
--

INSERT INTO atendimento_has_bebida VALUES (1, 1, 7);
INSERT INTO atendimento_has_bebida VALUES (2, 1, 3.5);


--
-- Name: atendimento_idatendimento_seq; Type: SEQUENCE SET; Schema: restaurante; Owner: 201319030386
--

SELECT pg_catalog.setval('atendimento_idatendimento_seq', 2, true);


--
-- Data for Name: bebida; Type: TABLE DATA; Schema: restaurante; Owner: 201319030386
--

INSERT INTO bebida VALUES (1, 1, 1, 'Coca Cola', 3.5);


--
-- Name: bebida_idbebida_seq; Type: SEQUENCE SET; Schema: restaurante; Owner: 201319030386
--

SELECT pg_catalog.setval('bebida_idbebida_seq', 1, true);


--
-- Data for Name: fabricante; Type: TABLE DATA; Schema: restaurante; Owner: 201319030386
--

INSERT INTO fabricante VALUES (1, 'FEMSA', 'BRA');


--
-- Name: fabricante_idfabricante_seq; Type: SEQUENCE SET; Schema: restaurante; Owner: 201319030386
--

SELECT pg_catalog.setval('fabricante_idfabricante_seq', 1, true);


--
-- Data for Name: funcionario; Type: TABLE DATA; Schema: restaurante; Owner: 201319030386
--

INSERT INTO funcionario VALUES ('00000000001', 'Augusto Ribas', 'garcom', 880, 'M');
INSERT INTO funcionario VALUES ('00000000002', 'Bruno Nazario', 'garcom', 880, 'M');


--
-- Data for Name: item; Type: TABLE DATA; Schema: restaurante; Owner: 201319030386
--

INSERT INTO item VALUES (1, 'hamburguer');
INSERT INTO item VALUES (2, 'pao');


--
-- Name: item_iditem_seq; Type: SEQUENCE SET; Schema: restaurante; Owner: 201319030386
--

SELECT pg_catalog.setval('item_iditem_seq', 2, true);


--
-- Data for Name: mesa; Type: TABLE DATA; Schema: restaurante; Owner: 201319030386
--

INSERT INTO mesa VALUES (1, B'0', 8);
INSERT INTO mesa VALUES (2, B'0', 6);


--
-- Data for Name: mesa_has_atendimento; Type: TABLE DATA; Schema: restaurante; Owner: 201319030386
--

INSERT INTO mesa_has_atendimento VALUES (1, 1);
INSERT INTO mesa_has_atendimento VALUES (2, 2);


--
-- Data for Name: prato; Type: TABLE DATA; Schema: restaurante; Owner: 201319030386
--

INSERT INTO prato VALUES (1, 1, 'Hamburguer Simples', 10);


--
-- Data for Name: prato_has_atendimento; Type: TABLE DATA; Schema: restaurante; Owner: 201319030386
--

INSERT INTO prato_has_atendimento VALUES (1, 1, 12);
INSERT INTO prato_has_atendimento VALUES (1, 2, 12);


--
-- Data for Name: prato_has_item; Type: TABLE DATA; Schema: restaurante; Owner: 201319030386
--

INSERT INTO prato_has_item VALUES (1, 1);
INSERT INTO prato_has_item VALUES (1, 2);


--
-- Name: prato_idprato_seq; Type: SEQUENCE SET; Schema: restaurante; Owner: 201319030386
--

SELECT pg_catalog.setval('prato_idprato_seq', 1, true);


--
-- Data for Name: tipobebida; Type: TABLE DATA; Schema: restaurante; Owner: 201319030386
--

INSERT INTO tipobebida VALUES (1, 'Refrigerante');


--
-- Name: tipobebida_idtipobebida_seq; Type: SEQUENCE SET; Schema: restaurante; Owner: 201319030386
--

SELECT pg_catalog.setval('tipobebida_idtipobebida_seq', 1, true);


--
-- Data for Name: tipoprato; Type: TABLE DATA; Schema: restaurante; Owner: 201319030386
--

INSERT INTO tipoprato VALUES (1, 'sanduiche');


--
-- Name: tipoprato_idtipoprato_seq; Type: SEQUENCE SET; Schema: restaurante; Owner: 201319030386
--

SELECT pg_catalog.setval('tipoprato_idtipoprato_seq', 1, true);


--
-- Name: atendimento_has_bebida_pkey; Type: CONSTRAINT; Schema: restaurante; Owner: 201319030386; Tablespace: 
--

ALTER TABLE ONLY atendimento_has_bebida
    ADD CONSTRAINT atendimento_has_bebida_pkey PRIMARY KEY (atendimento_idatendimento, bebida_idbebida);


--
-- Name: atendimento_pkey; Type: CONSTRAINT; Schema: restaurante; Owner: 201319030386; Tablespace: 
--

ALTER TABLE ONLY atendimento
    ADD CONSTRAINT atendimento_pkey PRIMARY KEY (idatendimento);


--
-- Name: bebida_pkey; Type: CONSTRAINT; Schema: restaurante; Owner: 201319030386; Tablespace: 
--

ALTER TABLE ONLY bebida
    ADD CONSTRAINT bebida_pkey PRIMARY KEY (idbebida);


--
-- Name: fabricante_pkey; Type: CONSTRAINT; Schema: restaurante; Owner: 201319030386; Tablespace: 
--

ALTER TABLE ONLY fabricante
    ADD CONSTRAINT fabricante_pkey PRIMARY KEY (idfabricante);


--
-- Name: funcionario_pkey; Type: CONSTRAINT; Schema: restaurante; Owner: 201319030386; Tablespace: 
--

ALTER TABLE ONLY funcionario
    ADD CONSTRAINT funcionario_pkey PRIMARY KEY (cpf);


--
-- Name: item_pkey; Type: CONSTRAINT; Schema: restaurante; Owner: 201319030386; Tablespace: 
--

ALTER TABLE ONLY item
    ADD CONSTRAINT item_pkey PRIMARY KEY (iditem);


--
-- Name: mesa_has_atendimento_pkey; Type: CONSTRAINT; Schema: restaurante; Owner: 201319030386; Tablespace: 
--

ALTER TABLE ONLY mesa_has_atendimento
    ADD CONSTRAINT mesa_has_atendimento_pkey PRIMARY KEY (mesa_id, atendimento_idatendimento);


--
-- Name: mesa_pkey; Type: CONSTRAINT; Schema: restaurante; Owner: 201319030386; Tablespace: 
--

ALTER TABLE ONLY mesa
    ADD CONSTRAINT mesa_pkey PRIMARY KEY (id);


--
-- Name: prato_has_atendimento_pkey; Type: CONSTRAINT; Schema: restaurante; Owner: 201319030386; Tablespace: 
--

ALTER TABLE ONLY prato_has_atendimento
    ADD CONSTRAINT prato_has_atendimento_pkey PRIMARY KEY (prato_idprato, atendimento_idatendimento);


--
-- Name: prato_has_item_pkey; Type: CONSTRAINT; Schema: restaurante; Owner: 201319030386; Tablespace: 
--

ALTER TABLE ONLY prato_has_item
    ADD CONSTRAINT prato_has_item_pkey PRIMARY KEY (prato_idprato, item_iditem);


--
-- Name: prato_pkey; Type: CONSTRAINT; Schema: restaurante; Owner: 201319030386; Tablespace: 
--

ALTER TABLE ONLY prato
    ADD CONSTRAINT prato_pkey PRIMARY KEY (idprato);


--
-- Name: tipobebida_pkey; Type: CONSTRAINT; Schema: restaurante; Owner: 201319030386; Tablespace: 
--

ALTER TABLE ONLY tipobebida
    ADD CONSTRAINT tipobebida_pkey PRIMARY KEY (idtipobebida);


--
-- Name: tipoprato_pkey; Type: CONSTRAINT; Schema: restaurante; Owner: 201319030386; Tablespace: 
--

ALTER TABLE ONLY tipoprato
    ADD CONSTRAINT tipoprato_pkey PRIMARY KEY (idtipoprato);


--
-- Name: atendimento_cpf_idx; Type: INDEX; Schema: restaurante; Owner: 201319030386; Tablespace: 
--

CREATE INDEX atendimento_cpf_idx ON atendimento USING btree (funcionario_cpf);


--
-- Name: criaAtendimentoAtualizaMesa; Type: TRIGGER; Schema: restaurante; Owner: 201319030386
--

CREATE TRIGGER "criaAtendimentoAtualizaMesa" AFTER INSERT OR UPDATE ON mesa_has_atendimento FOR EACH ROW EXECUTE PROCEDURE "atualizaMesa"();


--
-- Name: atendimento_funcionario_cpf_fkey; Type: FK CONSTRAINT; Schema: restaurante; Owner: 201319030386
--

ALTER TABLE ONLY atendimento
    ADD CONSTRAINT atendimento_funcionario_cpf_fkey FOREIGN KEY (funcionario_cpf) REFERENCES funcionario(cpf) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: atendimento_has_bebida_atendimento_idatendimento_fkey; Type: FK CONSTRAINT; Schema: restaurante; Owner: 201319030386
--

ALTER TABLE ONLY atendimento_has_bebida
    ADD CONSTRAINT atendimento_has_bebida_atendimento_idatendimento_fkey FOREIGN KEY (atendimento_idatendimento) REFERENCES atendimento(idatendimento) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: atendimento_has_bebida_bebida_idbebida_fkey; Type: FK CONSTRAINT; Schema: restaurante; Owner: 201319030386
--

ALTER TABLE ONLY atendimento_has_bebida
    ADD CONSTRAINT atendimento_has_bebida_bebida_idbebida_fkey FOREIGN KEY (bebida_idbebida) REFERENCES bebida(idbebida) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: bebida_fabricante_idfabricante_fkey; Type: FK CONSTRAINT; Schema: restaurante; Owner: 201319030386
--

ALTER TABLE ONLY bebida
    ADD CONSTRAINT bebida_fabricante_idfabricante_fkey FOREIGN KEY (fabricante_idfabricante) REFERENCES fabricante(idfabricante) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: bebida_tipobebida_idtipobebida_fkey; Type: FK CONSTRAINT; Schema: restaurante; Owner: 201319030386
--

ALTER TABLE ONLY bebida
    ADD CONSTRAINT bebida_tipobebida_idtipobebida_fkey FOREIGN KEY (tipobebida_idtipobebida) REFERENCES tipobebida(idtipobebida) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: mesa_has_atendimento_atendimento_idatendimento_fkey; Type: FK CONSTRAINT; Schema: restaurante; Owner: 201319030386
--

ALTER TABLE ONLY mesa_has_atendimento
    ADD CONSTRAINT mesa_has_atendimento_atendimento_idatendimento_fkey FOREIGN KEY (atendimento_idatendimento) REFERENCES atendimento(idatendimento) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: mesa_has_atendimento_mesa_id_fkey; Type: FK CONSTRAINT; Schema: restaurante; Owner: 201319030386
--

ALTER TABLE ONLY mesa_has_atendimento
    ADD CONSTRAINT mesa_has_atendimento_mesa_id_fkey FOREIGN KEY (mesa_id) REFERENCES mesa(id) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: prato_has_atendimento_atendimento_idatendimento_fkey; Type: FK CONSTRAINT; Schema: restaurante; Owner: 201319030386
--

ALTER TABLE ONLY prato_has_atendimento
    ADD CONSTRAINT prato_has_atendimento_atendimento_idatendimento_fkey FOREIGN KEY (atendimento_idatendimento) REFERENCES atendimento(idatendimento) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: prato_has_atendimento_prato_idprato_fkey; Type: FK CONSTRAINT; Schema: restaurante; Owner: 201319030386
--

ALTER TABLE ONLY prato_has_atendimento
    ADD CONSTRAINT prato_has_atendimento_prato_idprato_fkey FOREIGN KEY (prato_idprato) REFERENCES prato(idprato) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: prato_has_item_item_iditem_fkey; Type: FK CONSTRAINT; Schema: restaurante; Owner: 201319030386
--

ALTER TABLE ONLY prato_has_item
    ADD CONSTRAINT prato_has_item_item_iditem_fkey FOREIGN KEY (item_iditem) REFERENCES item(iditem) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: prato_has_item_prato_idprato_fkey; Type: FK CONSTRAINT; Schema: restaurante; Owner: 201319030386
--

ALTER TABLE ONLY prato_has_item
    ADD CONSTRAINT prato_has_item_prato_idprato_fkey FOREIGN KEY (prato_idprato) REFERENCES prato(idprato) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: prato_tipoprato_idtipoprato_fkey; Type: FK CONSTRAINT; Schema: restaurante; Owner: 201319030386
--

ALTER TABLE ONLY prato
    ADD CONSTRAINT prato_tipoprato_idtipoprato_fkey FOREIGN KEY (tipoprato_idtipoprato) REFERENCES tipoprato(idtipoprato) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: public; Type: ACL; Schema: -; Owner: postgres
--

REVOKE ALL ON SCHEMA public FROM PUBLIC;
REVOKE ALL ON SCHEMA public FROM postgres;
GRANT ALL ON SCHEMA public TO postgres;
GRANT ALL ON SCHEMA public TO PUBLIC;


--
-- PostgreSQL database dump complete
--

