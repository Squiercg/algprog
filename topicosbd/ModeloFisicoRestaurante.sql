--
-- PostgreSQL database dump
--
--
-- Name: restaurante; Type: SCHEMA; Schema: -; Owner: -
--

CREATE SCHEMA restaurante;


--
-- Name: plpgsql; Type: PROCEDURAL LANGUAGE; Schema: -; Owner: -
--

CREATE PROCEDURAL LANGUAGE plpgsql;


SET search_path = restaurante, pg_catalog;

--
-- Name: sexo; Type: DOMAIN; Schema: restaurante; Owner: -
--

CREATE DOMAIN sexo AS character(1) NOT NULL
	CONSTRAINT sexo_chk CHECK ((VALUE = ANY (ARRAY['M'::bpchar, 'F'::bpchar])));


--
-- Name: atualizaMesa(); Type: FUNCTION; Schema: restaurante; Owner: -
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
        WHERE atendimento_idatendimento = NEW.idatendimento
    );

END;
$$;


SET default_tablespace = '';

SET default_with_oids = false;

--
-- Name: atendimento; Type: TABLE; Schema: restaurante; Owner: -; Tablespace: 
--

CREATE TABLE atendimento (
    idatendimento integer NOT NULL,
    funcionario_cpf character varying(11) NOT NULL,
    datahora timestamp without time zone DEFAULT now() NOT NULL
);


--
-- Name: atendimento_has_bebida; Type: TABLE; Schema: restaurante; Owner: -; Tablespace: 
--

CREATE TABLE atendimento_has_bebida (
    atendimento_idatendimento integer NOT NULL,
    bebida_idbebida integer NOT NULL,
    preco_pago double precision NOT NULL
);


--
-- Name: atendimento_idatendimento_seq; Type: SEQUENCE; Schema: restaurante; Owner: -
--

CREATE SEQUENCE atendimento_idatendimento_seq
    START WITH 1
    INCREMENT BY 1
    NO MAXVALUE
    NO MINVALUE
    CACHE 1;


--
-- Name: atendimento_idatendimento_seq; Type: SEQUENCE OWNED BY; Schema: restaurante; Owner: -
--

ALTER SEQUENCE atendimento_idatendimento_seq OWNED BY atendimento.idatendimento;


--
-- Name: atendimento_idatendimento_seq; Type: SEQUENCE SET; Schema: restaurante; Owner: -
--

SELECT pg_catalog.setval('atendimento_idatendimento_seq', 1, false);


--
-- Name: bebida; Type: TABLE; Schema: restaurante; Owner: -; Tablespace: 
--

CREATE TABLE bebida (
    idbebida integer NOT NULL,
    tipobebida_idtipobebida integer NOT NULL,
    fabricante_idfabricante integer,
    nome character varying(64) NOT NULL,
    preco_venda double precision NOT NULL
);


--
-- Name: bebida_idbebida_seq; Type: SEQUENCE; Schema: restaurante; Owner: -
--

CREATE SEQUENCE bebida_idbebida_seq
    START WITH 1
    INCREMENT BY 1
    NO MAXVALUE
    NO MINVALUE
    CACHE 1;


--
-- Name: bebida_idbebida_seq; Type: SEQUENCE OWNED BY; Schema: restaurante; Owner: -
--

ALTER SEQUENCE bebida_idbebida_seq OWNED BY bebida.idbebida;


--
-- Name: bebida_idbebida_seq; Type: SEQUENCE SET; Schema: restaurante; Owner: -
--

SELECT pg_catalog.setval('bebida_idbebida_seq', 1, false);


--
-- Name: fabricante; Type: TABLE; Schema: restaurante; Owner: -; Tablespace: 
--

CREATE TABLE fabricante (
    idfabricante integer NOT NULL,
    nome character varying(128) NOT NULL,
    nacionalidade character(3) NOT NULL
);


--
-- Name: fabricante_idfabricante_seq; Type: SEQUENCE; Schema: restaurante; Owner: -
--

CREATE SEQUENCE fabricante_idfabricante_seq
    START WITH 1
    INCREMENT BY 1
    NO MAXVALUE
    NO MINVALUE
    CACHE 1;


--
-- Name: fabricante_idfabricante_seq; Type: SEQUENCE OWNED BY; Schema: restaurante; Owner: -
--

ALTER SEQUENCE fabricante_idfabricante_seq OWNED BY fabricante.idfabricante;


--
-- Name: fabricante_idfabricante_seq; Type: SEQUENCE SET; Schema: restaurante; Owner: -
--

SELECT pg_catalog.setval('fabricante_idfabricante_seq', 1, false);


--
-- Name: funcionario; Type: TABLE; Schema: restaurante; Owner: -; Tablespace: 
--

CREATE TABLE funcionario (
    cpf character varying(11) NOT NULL,
    nome character varying(128) NOT NULL,
    funcao character varying(64) NOT NULL,
    salario double precision NOT NULL,
    sexo sexo NOT NULL
);


--
-- Name: item; Type: TABLE; Schema: restaurante; Owner: -; Tablespace: 
--

CREATE TABLE item (
    iditem integer NOT NULL,
    nome character varying(128) NOT NULL
);


--
-- Name: item_iditem_seq; Type: SEQUENCE; Schema: restaurante; Owner: -
--

CREATE SEQUENCE item_iditem_seq
    START WITH 1
    INCREMENT BY 1
    NO MAXVALUE
    NO MINVALUE
    CACHE 1;


--
-- Name: item_iditem_seq; Type: SEQUENCE OWNED BY; Schema: restaurante; Owner: -
--

ALTER SEQUENCE item_iditem_seq OWNED BY item.iditem;


--
-- Name: item_iditem_seq; Type: SEQUENCE SET; Schema: restaurante; Owner: -
--

SELECT pg_catalog.setval('item_iditem_seq', 1, false);


--
-- Name: mesa; Type: TABLE; Schema: restaurante; Owner: -; Tablespace: 
--

CREATE TABLE mesa (
    id integer NOT NULL,
    disponibilidade bit(1) NOT NULL,
    capacidade integer NOT NULL
);


--
-- Name: mesa_has_atendimento; Type: TABLE; Schema: restaurante; Owner: -; Tablespace: 
--

CREATE TABLE mesa_has_atendimento (
    mesa_id integer NOT NULL,
    atendimento_idatendimento integer NOT NULL
);


--
-- Name: prato; Type: TABLE; Schema: restaurante; Owner: -; Tablespace: 
--

CREATE TABLE prato (
    idprato integer NOT NULL,
    tipoprato_idtipoprato integer NOT NULL,
    nome character varying(128) NOT NULL,
    preco_venda double precision NOT NULL
);


--
-- Name: prato_has_atendimento; Type: TABLE; Schema: restaurante; Owner: -; Tablespace: 
--

CREATE TABLE prato_has_atendimento (
    prato_idprato integer NOT NULL,
    atendimento_idatendimento integer NOT NULL,
    preco_pago double precision NOT NULL
);


--
-- Name: prato_has_item; Type: TABLE; Schema: restaurante; Owner: -; Tablespace: 
--

CREATE TABLE prato_has_item (
    prato_idprato integer NOT NULL,
    item_iditem integer NOT NULL
);


--
-- Name: prato_idprato_seq; Type: SEQUENCE; Schema: restaurante; Owner: -
--

CREATE SEQUENCE prato_idprato_seq
    START WITH 1
    INCREMENT BY 1
    NO MAXVALUE
    NO MINVALUE
    CACHE 1;


--
-- Name: prato_idprato_seq; Type: SEQUENCE OWNED BY; Schema: restaurante; Owner: -
--

ALTER SEQUENCE prato_idprato_seq OWNED BY prato.idprato;


--
-- Name: prato_idprato_seq; Type: SEQUENCE SET; Schema: restaurante; Owner: -
--

SELECT pg_catalog.setval('prato_idprato_seq', 1, false);


--
-- Name: tipobebida; Type: TABLE; Schema: restaurante; Owner: -; Tablespace: 
--

CREATE TABLE tipobebida (
    idtipobebida integer NOT NULL,
    nome character varying(128) NOT NULL
);


--
-- Name: tipobebida_idtipobebida_seq; Type: SEQUENCE; Schema: restaurante; Owner: -
--

CREATE SEQUENCE tipobebida_idtipobebida_seq
    START WITH 1
    INCREMENT BY 1
    NO MAXVALUE
    NO MINVALUE
    CACHE 1;


--
-- Name: tipobebida_idtipobebida_seq; Type: SEQUENCE OWNED BY; Schema: restaurante; Owner: -
--

ALTER SEQUENCE tipobebida_idtipobebida_seq OWNED BY tipobebida.idtipobebida;


--
-- Name: tipobebida_idtipobebida_seq; Type: SEQUENCE SET; Schema: restaurante; Owner: -
--

SELECT pg_catalog.setval('tipobebida_idtipobebida_seq', 1, false);


--
-- Name: tipoprato; Type: TABLE; Schema: restaurante; Owner: -; Tablespace: 
--

CREATE TABLE tipoprato (
    idtipoprato integer NOT NULL,
    nome character varying(128) NOT NULL
);


--
-- Name: tipoprato_idtipoprato_seq; Type: SEQUENCE; Schema: restaurante; Owner: -
--

CREATE SEQUENCE tipoprato_idtipoprato_seq
    START WITH 1
    INCREMENT BY 1
    NO MAXVALUE
    NO MINVALUE
    CACHE 1;


--
-- Name: tipoprato_idtipoprato_seq; Type: SEQUENCE OWNED BY; Schema: restaurante; Owner: -
--

ALTER SEQUENCE tipoprato_idtipoprato_seq OWNED BY tipoprato.idtipoprato;


--
-- Name: tipoprato_idtipoprato_seq; Type: SEQUENCE SET; Schema: restaurante; Owner: -
--

SELECT pg_catalog.setval('tipoprato_idtipoprato_seq', 1, false);


--
-- Name: idatendimento; Type: DEFAULT; Schema: restaurante; Owner: -
--

ALTER TABLE ONLY atendimento ALTER COLUMN idatendimento SET DEFAULT nextval('atendimento_idatendimento_seq'::regclass);


--
-- Name: idbebida; Type: DEFAULT; Schema: restaurante; Owner: -
--

ALTER TABLE ONLY bebida ALTER COLUMN idbebida SET DEFAULT nextval('bebida_idbebida_seq'::regclass);


--
-- Name: idfabricante; Type: DEFAULT; Schema: restaurante; Owner: -
--

ALTER TABLE ONLY fabricante ALTER COLUMN idfabricante SET DEFAULT nextval('fabricante_idfabricante_seq'::regclass);


--
-- Name: iditem; Type: DEFAULT; Schema: restaurante; Owner: -
--

ALTER TABLE ONLY item ALTER COLUMN iditem SET DEFAULT nextval('item_iditem_seq'::regclass);


--
-- Name: idprato; Type: DEFAULT; Schema: restaurante; Owner: -
--

ALTER TABLE ONLY prato ALTER COLUMN idprato SET DEFAULT nextval('prato_idprato_seq'::regclass);


--
-- Name: idtipobebida; Type: DEFAULT; Schema: restaurante; Owner: -
--

ALTER TABLE ONLY tipobebida ALTER COLUMN idtipobebida SET DEFAULT nextval('tipobebida_idtipobebida_seq'::regclass);


--
-- Name: idtipoprato; Type: DEFAULT; Schema: restaurante; Owner: -
--

ALTER TABLE ONLY tipoprato ALTER COLUMN idtipoprato SET DEFAULT nextval('tipoprato_idtipoprato_seq'::regclass);


--
-- Data for Name: atendimento; Type: TABLE DATA; Schema: restaurante; Owner: -
--

COPY atendimento (idatendimento, funcionario_cpf, datahora) FROM stdin;
\.


--
-- Data for Name: atendimento_has_bebida; Type: TABLE DATA; Schema: restaurante; Owner: -
--

COPY atendimento_has_bebida (atendimento_idatendimento, bebida_idbebida, preco_pago) FROM stdin;
\.


--
-- Data for Name: bebida; Type: TABLE DATA; Schema: restaurante; Owner: -
--

COPY bebida (idbebida, tipobebida_idtipobebida, fabricante_idfabricante, nome, preco_venda) FROM stdin;
\.


--
-- Data for Name: fabricante; Type: TABLE DATA; Schema: restaurante; Owner: -
--

COPY fabricante (idfabricante, nome, nacionalidade) FROM stdin;
\.


--
-- Data for Name: funcionario; Type: TABLE DATA; Schema: restaurante; Owner: -
--

COPY funcionario (cpf, nome, funcao, salario, sexo) FROM stdin;
\.


--
-- Data for Name: item; Type: TABLE DATA; Schema: restaurante; Owner: -
--

COPY item (iditem, nome) FROM stdin;
\.


--
-- Data for Name: mesa; Type: TABLE DATA; Schema: restaurante; Owner: -
--

COPY mesa (id, disponibilidade, capacidade) FROM stdin;
\.


--
-- Data for Name: mesa_has_atendimento; Type: TABLE DATA; Schema: restaurante; Owner: -
--

COPY mesa_has_atendimento (mesa_id, atendimento_idatendimento) FROM stdin;
\.


--
-- Data for Name: prato; Type: TABLE DATA; Schema: restaurante; Owner: -
--

COPY prato (idprato, tipoprato_idtipoprato, nome, preco_venda) FROM stdin;
\.


--
-- Data for Name: prato_has_atendimento; Type: TABLE DATA; Schema: restaurante; Owner: -
--

COPY prato_has_atendimento (prato_idprato, atendimento_idatendimento, preco_pago) FROM stdin;
\.


--
-- Data for Name: prato_has_item; Type: TABLE DATA; Schema: restaurante; Owner: -
--

COPY prato_has_item (prato_idprato, item_iditem) FROM stdin;
\.


--
-- Data for Name: tipobebida; Type: TABLE DATA; Schema: restaurante; Owner: -
--

COPY tipobebida (idtipobebida, nome) FROM stdin;
\.


--
-- Data for Name: tipoprato; Type: TABLE DATA; Schema: restaurante; Owner: -
--

COPY tipoprato (idtipoprato, nome) FROM stdin;
\.


--
-- Name: atendimento_has_bebida_pkey; Type: CONSTRAINT; Schema: restaurante; Owner: -; Tablespace: 
--

ALTER TABLE ONLY atendimento_has_bebida
    ADD CONSTRAINT atendimento_has_bebida_pkey PRIMARY KEY (atendimento_idatendimento, bebida_idbebida);


--
-- Name: atendimento_pkey; Type: CONSTRAINT; Schema: restaurante; Owner: -; Tablespace: 
--

ALTER TABLE ONLY atendimento
    ADD CONSTRAINT atendimento_pkey PRIMARY KEY (idatendimento);


--
-- Name: bebida_pkey; Type: CONSTRAINT; Schema: restaurante; Owner: -; Tablespace: 
--

ALTER TABLE ONLY bebida
    ADD CONSTRAINT bebida_pkey PRIMARY KEY (idbebida);


--
-- Name: fabricante_pkey; Type: CONSTRAINT; Schema: restaurante; Owner: -; Tablespace: 
--

ALTER TABLE ONLY fabricante
    ADD CONSTRAINT fabricante_pkey PRIMARY KEY (idfabricante);


--
-- Name: funcionario_pkey; Type: CONSTRAINT; Schema: restaurante; Owner: -; Tablespace: 
--

ALTER TABLE ONLY funcionario
    ADD CONSTRAINT funcionario_pkey PRIMARY KEY (cpf);


--
-- Name: item_pkey; Type: CONSTRAINT; Schema: restaurante; Owner: -; Tablespace: 
--

ALTER TABLE ONLY item
    ADD CONSTRAINT item_pkey PRIMARY KEY (iditem);


--
-- Name: mesa_has_atendimento_pkey; Type: CONSTRAINT; Schema: restaurante; Owner: -; Tablespace: 
--

ALTER TABLE ONLY mesa_has_atendimento
    ADD CONSTRAINT mesa_has_atendimento_pkey PRIMARY KEY (mesa_id, atendimento_idatendimento);


--
-- Name: mesa_pkey; Type: CONSTRAINT; Schema: restaurante; Owner: -; Tablespace: 
--

ALTER TABLE ONLY mesa
    ADD CONSTRAINT mesa_pkey PRIMARY KEY (id);


--
-- Name: prato_has_atendimento_pkey; Type: CONSTRAINT; Schema: restaurante; Owner: -; Tablespace: 
--

ALTER TABLE ONLY prato_has_atendimento
    ADD CONSTRAINT prato_has_atendimento_pkey PRIMARY KEY (prato_idprato, atendimento_idatendimento);


--
-- Name: prato_has_item_pkey; Type: CONSTRAINT; Schema: restaurante; Owner: -; Tablespace: 
--

ALTER TABLE ONLY prato_has_item
    ADD CONSTRAINT prato_has_item_pkey PRIMARY KEY (prato_idprato, item_iditem);


--
-- Name: prato_pkey; Type: CONSTRAINT; Schema: restaurante; Owner: -; Tablespace: 
--

ALTER TABLE ONLY prato
    ADD CONSTRAINT prato_pkey PRIMARY KEY (idprato);


--
-- Name: tipobebida_pkey; Type: CONSTRAINT; Schema: restaurante; Owner: -; Tablespace: 
--

ALTER TABLE ONLY tipobebida
    ADD CONSTRAINT tipobebida_pkey PRIMARY KEY (idtipobebida);


--
-- Name: tipoprato_pkey; Type: CONSTRAINT; Schema: restaurante; Owner: -; Tablespace: 
--

ALTER TABLE ONLY tipoprato
    ADD CONSTRAINT tipoprato_pkey PRIMARY KEY (idtipoprato);


--
-- Name: atendimento_cpf_idx; Type: INDEX; Schema: restaurante; Owner: -; Tablespace: 
--

CREATE INDEX atendimento_cpf_idx ON atendimento USING btree (funcionario_cpf);


--
-- Name: criaAtendimentoAtualizaMesa; Type: TRIGGER; Schema: restaurante; Owner: -
--

CREATE TRIGGER "criaAtendimentoAtualizaMesa"
    AFTER INSERT OR UPDATE ON atendimento
    FOR EACH ROW
    EXECUTE PROCEDURE "atualizaMesa"();


--
-- Name: atendimento_funcionario_cpf_fkey; Type: FK CONSTRAINT; Schema: restaurante; Owner: -
--

ALTER TABLE ONLY atendimento
    ADD CONSTRAINT atendimento_funcionario_cpf_fkey FOREIGN KEY (funcionario_cpf) REFERENCES funcionario(cpf) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: atendimento_has_bebida_atendimento_idatendimento_fkey; Type: FK CONSTRAINT; Schema: restaurante; Owner: -
--

ALTER TABLE ONLY atendimento_has_bebida
    ADD CONSTRAINT atendimento_has_bebida_atendimento_idatendimento_fkey FOREIGN KEY (atendimento_idatendimento) REFERENCES atendimento(idatendimento) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: atendimento_has_bebida_bebida_idbebida_fkey; Type: FK CONSTRAINT; Schema: restaurante; Owner: -
--

ALTER TABLE ONLY atendimento_has_bebida
    ADD CONSTRAINT atendimento_has_bebida_bebida_idbebida_fkey FOREIGN KEY (bebida_idbebida) REFERENCES bebida(idbebida) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: bebida_fabricante_idfabricante_fkey; Type: FK CONSTRAINT; Schema: restaurante; Owner: -
--

ALTER TABLE ONLY bebida
    ADD CONSTRAINT bebida_fabricante_idfabricante_fkey FOREIGN KEY (fabricante_idfabricante) REFERENCES fabricante(idfabricante) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: bebida_tipobebida_idtipobebida_fkey; Type: FK CONSTRAINT; Schema: restaurante; Owner: -
--

ALTER TABLE ONLY bebida
    ADD CONSTRAINT bebida_tipobebida_idtipobebida_fkey FOREIGN KEY (tipobebida_idtipobebida) REFERENCES tipobebida(idtipobebida) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: mesa_has_atendimento_atendimento_idatendimento_fkey; Type: FK CONSTRAINT; Schema: restaurante; Owner: -
--

ALTER TABLE ONLY mesa_has_atendimento
    ADD CONSTRAINT mesa_has_atendimento_atendimento_idatendimento_fkey FOREIGN KEY (atendimento_idatendimento) REFERENCES atendimento(idatendimento) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: mesa_has_atendimento_mesa_id_fkey; Type: FK CONSTRAINT; Schema: restaurante; Owner: -
--

ALTER TABLE ONLY mesa_has_atendimento
    ADD CONSTRAINT mesa_has_atendimento_mesa_id_fkey FOREIGN KEY (mesa_id) REFERENCES mesa(id) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: prato_has_atendimento_atendimento_idatendimento_fkey; Type: FK CONSTRAINT; Schema: restaurante; Owner: -
--

ALTER TABLE ONLY prato_has_atendimento
    ADD CONSTRAINT prato_has_atendimento_atendimento_idatendimento_fkey FOREIGN KEY (atendimento_idatendimento) REFERENCES atendimento(idatendimento) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: prato_has_atendimento_prato_idprato_fkey; Type: FK CONSTRAINT; Schema: restaurante; Owner: -
--

ALTER TABLE ONLY prato_has_atendimento
    ADD CONSTRAINT prato_has_atendimento_prato_idprato_fkey FOREIGN KEY (prato_idprato) REFERENCES prato(idprato) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: prato_has_item_item_iditem_fkey; Type: FK CONSTRAINT; Schema: restaurante; Owner: -
--

ALTER TABLE ONLY prato_has_item
    ADD CONSTRAINT prato_has_item_item_iditem_fkey FOREIGN KEY (item_iditem) REFERENCES item(iditem) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: prato_has_item_prato_idprato_fkey; Type: FK CONSTRAINT; Schema: restaurante; Owner: -
--

ALTER TABLE ONLY prato_has_item
    ADD CONSTRAINT prato_has_item_prato_idprato_fkey FOREIGN KEY (prato_idprato) REFERENCES prato(idprato) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: prato_tipoprato_idtipoprato_fkey; Type: FK CONSTRAINT; Schema: restaurante; Owner: -
--

ALTER TABLE ONLY prato
    ADD CONSTRAINT prato_tipoprato_idtipoprato_fkey FOREIGN KEY (tipoprato_idtipoprato) REFERENCES tipoprato(idtipoprato) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- PostgreSQL database dump complete
--

