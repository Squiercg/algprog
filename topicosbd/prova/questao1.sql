--
-- PostgreSQL database dump
--

SET statement_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SET check_function_bodies = false;
SET client_min_messages = warning;

--
-- Name: plpgsql; Type: EXTENSION; Schema: -; Owner: -
--

CREATE EXTENSION IF NOT EXISTS plpgsql WITH SCHEMA pg_catalog;


--
-- Name: EXTENSION plpgsql; Type: COMMENT; Schema: -; Owner: -
--

COMMENT ON EXTENSION plpgsql IS 'PL/pgSQL procedural language';


SET search_path = public, pg_catalog;

SET default_tablespace = '';

SET default_with_oids = false;

--
-- Name: automoveis; Type: TABLE; Schema: public; Owner: -; Tablespace: 
--

CREATE TABLE automoveis (
    codbanco integer NOT NULL,
    agencia integer NOT NULL,
    numconta integer NOT NULL,
    cpf character varying(11) NOT NULL
);


--
-- Name: autor; Type: TABLE; Schema: public; Owner: -; Tablespace: 
--

CREATE TABLE autor (
    idautor integer NOT NULL,
    formacaopoetica character varying(200) NOT NULL,
    cpf character varying(11) NOT NULL
);


--
-- Name: autor_compoe_musica; Type: TABLE; Schema: public; Owner: -; Tablespace: 
--

CREATE TABLE autor_compoe_musica (
    idautor integer NOT NULL,
    idmusica integer NOT NULL
);


--
-- Name: autor_escreve_letra_musica; Type: TABLE; Schema: public; Owner: -; Tablespace: 
--

CREATE TABLE autor_escreve_letra_musica (
    idautor integer NOT NULL,
    idmusica integer NOT NULL
);


--
-- Name: autor_idautor_seq; Type: SEQUENCE; Schema: public; Owner: -
--

CREATE SEQUENCE autor_idautor_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: autor_idautor_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: -
--

ALTER SEQUENCE autor_idautor_seq OWNED BY autor.idautor;


--
-- Name: autor_pertence_escritorio; Type: TABLE; Schema: public; Owner: -; Tablespace: 
--

CREATE TABLE autor_pertence_escritorio (
    idautor integer NOT NULL,
    idesc integer NOT NULL
);


--
-- Name: cantor; Type: TABLE; Schema: public; Owner: -; Tablespace: 
--

CREATE TABLE cantor (
    idcantor integer NOT NULL,
    grupo character varying(200) NOT NULL,
    estilo character varying(200) NOT NULL,
    empresario character varying(200) NOT NULL,
    valorcache double precision NOT NULL,
    cpf character varying(11) NOT NULL
);


--
-- Name: cantor_grava_unidade; Type: TABLE; Schema: public; Owner: -; Tablespace: 
--

CREATE TABLE cantor_grava_unidade (
    idcantor integer NOT NULL,
    idunidade integer NOT NULL
);


--
-- Name: cantor_idcantor_seq; Type: SEQUENCE; Schema: public; Owner: -
--

CREATE SEQUENCE cantor_idcantor_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: cantor_idcantor_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: -
--

ALTER SEQUENCE cantor_idcantor_seq OWNED BY cantor.idcantor;


--
-- Name: cantor_pertence_gravadora; Type: TABLE; Schema: public; Owner: -; Tablespace: 
--

CREATE TABLE cantor_pertence_gravadora (
    idcantor integer NOT NULL,
    idgravadora integer NOT NULL
);


--
-- Name: cantor_regrava_musica; Type: TABLE; Schema: public; Owner: -; Tablespace: 
--

CREATE TABLE cantor_regrava_musica (
    idcantor integer NOT NULL,
    idmusica integer NOT NULL,
    dataregravacao timestamp without time zone
);


--
-- Name: cantor_toca_instrumento; Type: TABLE; Schema: public; Owner: -; Tablespace: 
--

CREATE TABLE cantor_toca_instrumento (
    idcantor integer NOT NULL,
    nome_instrumento character varying(100) NOT NULL
);


--
-- Name: escritorio; Type: TABLE; Schema: public; Owner: -; Tablespace: 
--

CREATE TABLE escritorio (
    idesc integer NOT NULL,
    nome character varying(100) NOT NULL,
    local character varying(100) NOT NULL
);


--
-- Name: escritorio_idesc_seq; Type: SEQUENCE; Schema: public; Owner: -
--

CREATE SEQUENCE escritorio_idesc_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: escritorio_idesc_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: -
--

ALTER SEQUENCE escritorio_idesc_seq OWNED BY escritorio.idesc;


--
-- Name: gravadora; Type: TABLE; Schema: public; Owner: -; Tablespace: 
--

CREATE TABLE gravadora (
    idgravadora integer NOT NULL,
    nome character varying(100) NOT NULL
);


--
-- Name: gravadora_idgravadora_seq; Type: SEQUENCE; Schema: public; Owner: -
--

CREATE SEQUENCE gravadora_idgravadora_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: gravadora_idgravadora_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: -
--

ALTER SEQUENCE gravadora_idgravadora_seq OWNED BY gravadora.idgravadora;


--
-- Name: instrumento; Type: TABLE; Schema: public; Owner: -; Tablespace: 
--

CREATE TABLE instrumento (
    nome_instrumento character varying(100) NOT NULL,
    classe character varying(100) NOT NULL,
    notabaixa character varying(100) NOT NULL,
    nota_alta character varying(100) NOT NULL
);


--
-- Name: midia; Type: TABLE; Schema: public; Owner: -; Tablespace: 
--

CREATE TABLE midia (
    idmidia integer NOT NULL,
    tipo character varying(100) NOT NULL
);


--
-- Name: midia_idmidia_seq; Type: SEQUENCE; Schema: public; Owner: -
--

CREATE SEQUENCE midia_idmidia_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: midia_idmidia_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: -
--

ALTER SEQUENCE midia_idmidia_seq OWNED BY midia.idmidia;


--
-- Name: musica; Type: TABLE; Schema: public; Owner: -; Tablespace: 
--

CREATE TABLE musica (
    idmusica integer NOT NULL,
    nome character varying(100) NOT NULL,
    tipo character varying(100) NOT NULL,
    dataregistro character varying(100) NOT NULL
);


--
-- Name: musica_idmusica_seq; Type: SEQUENCE; Schema: public; Owner: -
--

CREATE SEQUENCE musica_idmusica_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: musica_idmusica_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: -
--

ALTER SEQUENCE musica_idmusica_seq OWNED BY musica.idmusica;


--
-- Name: musica_participa_unidade; Type: TABLE; Schema: public; Owner: -; Tablespace: 
--

CREATE TABLE musica_participa_unidade (
    idmusica integer NOT NULL,
    idunidade integer NOT NULL
);


--
-- Name: pessoa; Type: TABLE; Schema: public; Owner: -; Tablespace: 
--

CREATE TABLE pessoa (
    cpf character varying(11) NOT NULL,
    rg character varying(8) NOT NULL,
    nome character varying(200) NOT NULL,
    formacaomusical character varying(200) NOT NULL,
    endereco character varying(200) NOT NULL,
    localnasc character varying(200) NOT NULL,
    datanasc timestamp without time zone NOT NULL
);


--
-- Name: unidade; Type: TABLE; Schema: public; Owner: -; Tablespace: 
--

CREATE TABLE unidade (
    idunidade integer NOT NULL,
    datalancamento character varying(100) NOT NULL,
    idmidia integer
);


--
-- Name: unidade_gravada_musica; Type: TABLE; Schema: public; Owner: -; Tablespace: 
--

CREATE TABLE unidade_gravada_musica (
    idunidade integer NOT NULL,
    idmusica integer NOT NULL
);


--
-- Name: unidade_idunidade_seq; Type: SEQUENCE; Schema: public; Owner: -
--

CREATE SEQUENCE unidade_idunidade_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: unidade_idunidade_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: -
--

ALTER SEQUENCE unidade_idunidade_seq OWNED BY unidade.idunidade;


--
-- Name: idautor; Type: DEFAULT; Schema: public; Owner: -
--

ALTER TABLE ONLY autor ALTER COLUMN idautor SET DEFAULT nextval('autor_idautor_seq'::regclass);


--
-- Name: idcantor; Type: DEFAULT; Schema: public; Owner: -
--

ALTER TABLE ONLY cantor ALTER COLUMN idcantor SET DEFAULT nextval('cantor_idcantor_seq'::regclass);


--
-- Name: idesc; Type: DEFAULT; Schema: public; Owner: -
--

ALTER TABLE ONLY escritorio ALTER COLUMN idesc SET DEFAULT nextval('escritorio_idesc_seq'::regclass);


--
-- Name: idgravadora; Type: DEFAULT; Schema: public; Owner: -
--

ALTER TABLE ONLY gravadora ALTER COLUMN idgravadora SET DEFAULT nextval('gravadora_idgravadora_seq'::regclass);


--
-- Name: idmidia; Type: DEFAULT; Schema: public; Owner: -
--

ALTER TABLE ONLY midia ALTER COLUMN idmidia SET DEFAULT nextval('midia_idmidia_seq'::regclass);


--
-- Name: idmusica; Type: DEFAULT; Schema: public; Owner: -
--

ALTER TABLE ONLY musica ALTER COLUMN idmusica SET DEFAULT nextval('musica_idmusica_seq'::regclass);


--
-- Name: idunidade; Type: DEFAULT; Schema: public; Owner: -
--

ALTER TABLE ONLY unidade ALTER COLUMN idunidade SET DEFAULT nextval('unidade_idunidade_seq'::regclass);


--
-- Data for Name: automoveis; Type: TABLE DATA; Schema: public; Owner: -
--

COPY automoveis (codbanco, agencia, numconta, cpf) FROM stdin;
\.


--
-- Data for Name: autor; Type: TABLE DATA; Schema: public; Owner: -
--

COPY autor (idautor, formacaopoetica, cpf) FROM stdin;
\.


--
-- Data for Name: autor_compoe_musica; Type: TABLE DATA; Schema: public; Owner: -
--

COPY autor_compoe_musica (idautor, idmusica) FROM stdin;
\.


--
-- Data for Name: autor_escreve_letra_musica; Type: TABLE DATA; Schema: public; Owner: -
--

COPY autor_escreve_letra_musica (idautor, idmusica) FROM stdin;
\.


--
-- Name: autor_idautor_seq; Type: SEQUENCE SET; Schema: public; Owner: -
--

SELECT pg_catalog.setval('autor_idautor_seq', 1, false);


--
-- Data for Name: autor_pertence_escritorio; Type: TABLE DATA; Schema: public; Owner: -
--

COPY autor_pertence_escritorio (idautor, idesc) FROM stdin;
\.


--
-- Data for Name: cantor; Type: TABLE DATA; Schema: public; Owner: -
--

COPY cantor (idcantor, grupo, estilo, empresario, valorcache, cpf) FROM stdin;
\.


--
-- Data for Name: cantor_grava_unidade; Type: TABLE DATA; Schema: public; Owner: -
--

COPY cantor_grava_unidade (idcantor, idunidade) FROM stdin;
\.


--
-- Name: cantor_idcantor_seq; Type: SEQUENCE SET; Schema: public; Owner: -
--

SELECT pg_catalog.setval('cantor_idcantor_seq', 1, false);


--
-- Data for Name: cantor_pertence_gravadora; Type: TABLE DATA; Schema: public; Owner: -
--

COPY cantor_pertence_gravadora (idcantor, idgravadora) FROM stdin;
\.


--
-- Data for Name: cantor_regrava_musica; Type: TABLE DATA; Schema: public; Owner: -
--

COPY cantor_regrava_musica (idcantor, idmusica, dataregravacao) FROM stdin;
\.


--
-- Data for Name: cantor_toca_instrumento; Type: TABLE DATA; Schema: public; Owner: -
--

COPY cantor_toca_instrumento (idcantor, nome_instrumento) FROM stdin;
\.


--
-- Data for Name: escritorio; Type: TABLE DATA; Schema: public; Owner: -
--

COPY escritorio (idesc, nome, local) FROM stdin;
\.


--
-- Name: escritorio_idesc_seq; Type: SEQUENCE SET; Schema: public; Owner: -
--

SELECT pg_catalog.setval('escritorio_idesc_seq', 1, false);


--
-- Data for Name: gravadora; Type: TABLE DATA; Schema: public; Owner: -
--

COPY gravadora (idgravadora, nome) FROM stdin;
\.


--
-- Name: gravadora_idgravadora_seq; Type: SEQUENCE SET; Schema: public; Owner: -
--

SELECT pg_catalog.setval('gravadora_idgravadora_seq', 1, false);


--
-- Data for Name: instrumento; Type: TABLE DATA; Schema: public; Owner: -
--

COPY instrumento (nome_instrumento, classe, notabaixa, nota_alta) FROM stdin;
\.


--
-- Data for Name: midia; Type: TABLE DATA; Schema: public; Owner: -
--

COPY midia (idmidia, tipo) FROM stdin;
\.


--
-- Name: midia_idmidia_seq; Type: SEQUENCE SET; Schema: public; Owner: -
--

SELECT pg_catalog.setval('midia_idmidia_seq', 1, false);


--
-- Data for Name: musica; Type: TABLE DATA; Schema: public; Owner: -
--

COPY musica (idmusica, nome, tipo, dataregistro) FROM stdin;
\.


--
-- Name: musica_idmusica_seq; Type: SEQUENCE SET; Schema: public; Owner: -
--

SELECT pg_catalog.setval('musica_idmusica_seq', 1, false);


--
-- Data for Name: musica_participa_unidade; Type: TABLE DATA; Schema: public; Owner: -
--

COPY musica_participa_unidade (idmusica, idunidade) FROM stdin;
\.


--
-- Data for Name: pessoa; Type: TABLE DATA; Schema: public; Owner: -
--

COPY pessoa (cpf, rg, nome, formacaomusical, endereco, localnasc, datanasc) FROM stdin;
\.


--
-- Data for Name: unidade; Type: TABLE DATA; Schema: public; Owner: -
--

COPY unidade (idunidade, datalancamento, idmidia) FROM stdin;
\.


--
-- Data for Name: unidade_gravada_musica; Type: TABLE DATA; Schema: public; Owner: -
--

COPY unidade_gravada_musica (idunidade, idmusica) FROM stdin;
\.


--
-- Name: unidade_idunidade_seq; Type: SEQUENCE SET; Schema: public; Owner: -
--

SELECT pg_catalog.setval('unidade_idunidade_seq', 1, false);


--
-- Name: autor_compoe_musica_pkey; Type: CONSTRAINT; Schema: public; Owner: -; Tablespace: 
--

ALTER TABLE ONLY autor_compoe_musica
    ADD CONSTRAINT autor_compoe_musica_pkey PRIMARY KEY (idautor, idmusica);


--
-- Name: autor_escreve_letra_musica_pkey; Type: CONSTRAINT; Schema: public; Owner: -; Tablespace: 
--

ALTER TABLE ONLY autor_escreve_letra_musica
    ADD CONSTRAINT autor_escreve_letra_musica_pkey PRIMARY KEY (idautor, idmusica);


--
-- Name: autor_pertence_escritorio_pkey; Type: CONSTRAINT; Schema: public; Owner: -; Tablespace: 
--

ALTER TABLE ONLY autor_pertence_escritorio
    ADD CONSTRAINT autor_pertence_escritorio_pkey PRIMARY KEY (idautor, idesc);


--
-- Name: autor_pkey; Type: CONSTRAINT; Schema: public; Owner: -; Tablespace: 
--

ALTER TABLE ONLY autor
    ADD CONSTRAINT autor_pkey PRIMARY KEY (idautor);


--
-- Name: cantor_grava_unidade_pkey; Type: CONSTRAINT; Schema: public; Owner: -; Tablespace: 
--

ALTER TABLE ONLY cantor_grava_unidade
    ADD CONSTRAINT cantor_grava_unidade_pkey PRIMARY KEY (idcantor, idunidade);


--
-- Name: cantor_pertence_gravadora_pkey; Type: CONSTRAINT; Schema: public; Owner: -; Tablespace: 
--

ALTER TABLE ONLY cantor_pertence_gravadora
    ADD CONSTRAINT cantor_pertence_gravadora_pkey PRIMARY KEY (idcantor, idgravadora);


--
-- Name: cantor_pkey; Type: CONSTRAINT; Schema: public; Owner: -; Tablespace: 
--

ALTER TABLE ONLY cantor
    ADD CONSTRAINT cantor_pkey PRIMARY KEY (idcantor);


--
-- Name: cantor_regrava_musica_pkey; Type: CONSTRAINT; Schema: public; Owner: -; Tablespace: 
--

ALTER TABLE ONLY cantor_regrava_musica
    ADD CONSTRAINT cantor_regrava_musica_pkey PRIMARY KEY (idcantor, idmusica);


--
-- Name: cantor_toca_instrumento_pkey; Type: CONSTRAINT; Schema: public; Owner: -; Tablespace: 
--

ALTER TABLE ONLY cantor_toca_instrumento
    ADD CONSTRAINT cantor_toca_instrumento_pkey PRIMARY KEY (idcantor, nome_instrumento);


--
-- Name: escritorio_pkey; Type: CONSTRAINT; Schema: public; Owner: -; Tablespace: 
--

ALTER TABLE ONLY escritorio
    ADD CONSTRAINT escritorio_pkey PRIMARY KEY (idesc);


--
-- Name: gravadora_pkey; Type: CONSTRAINT; Schema: public; Owner: -; Tablespace: 
--

ALTER TABLE ONLY gravadora
    ADD CONSTRAINT gravadora_pkey PRIMARY KEY (idgravadora);


--
-- Name: instrumento_pkey; Type: CONSTRAINT; Schema: public; Owner: -; Tablespace: 
--

ALTER TABLE ONLY instrumento
    ADD CONSTRAINT instrumento_pkey PRIMARY KEY (nome_instrumento);


--
-- Name: midia_pkey; Type: CONSTRAINT; Schema: public; Owner: -; Tablespace: 
--

ALTER TABLE ONLY midia
    ADD CONSTRAINT midia_pkey PRIMARY KEY (idmidia);


--
-- Name: musica_participa_unidade_pkey; Type: CONSTRAINT; Schema: public; Owner: -; Tablespace: 
--

ALTER TABLE ONLY musica_participa_unidade
    ADD CONSTRAINT musica_participa_unidade_pkey PRIMARY KEY (idmusica, idunidade);


--
-- Name: musica_pkey; Type: CONSTRAINT; Schema: public; Owner: -; Tablespace: 
--

ALTER TABLE ONLY musica
    ADD CONSTRAINT musica_pkey PRIMARY KEY (idmusica);


--
-- Name: pessoa_pkey; Type: CONSTRAINT; Schema: public; Owner: -; Tablespace: 
--

ALTER TABLE ONLY pessoa
    ADD CONSTRAINT pessoa_pkey PRIMARY KEY (cpf);


--
-- Name: unidade_gravada_musica_pkey; Type: CONSTRAINT; Schema: public; Owner: -; Tablespace: 
--

ALTER TABLE ONLY unidade_gravada_musica
    ADD CONSTRAINT unidade_gravada_musica_pkey PRIMARY KEY (idunidade, idmusica);


--
-- Name: unidade_pkey; Type: CONSTRAINT; Schema: public; Owner: -; Tablespace: 
--

ALTER TABLE ONLY unidade
    ADD CONSTRAINT unidade_pkey PRIMARY KEY (idunidade);


--
-- Name: automoveis_cpf_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY automoveis
    ADD CONSTRAINT automoveis_cpf_fkey FOREIGN KEY (cpf) REFERENCES pessoa(cpf) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: autor_compoe_musica_idautor_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY autor_compoe_musica
    ADD CONSTRAINT autor_compoe_musica_idautor_fkey FOREIGN KEY (idautor) REFERENCES autor(idautor) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: autor_compoe_musica_idmusica_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY autor_compoe_musica
    ADD CONSTRAINT autor_compoe_musica_idmusica_fkey FOREIGN KEY (idmusica) REFERENCES musica(idmusica) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: autor_cpf_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY autor
    ADD CONSTRAINT autor_cpf_fkey FOREIGN KEY (cpf) REFERENCES pessoa(cpf) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: autor_escreve_letra_musica_idautor_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY autor_escreve_letra_musica
    ADD CONSTRAINT autor_escreve_letra_musica_idautor_fkey FOREIGN KEY (idautor) REFERENCES autor(idautor) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: autor_escreve_letra_musica_idmusica_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY autor_escreve_letra_musica
    ADD CONSTRAINT autor_escreve_letra_musica_idmusica_fkey FOREIGN KEY (idmusica) REFERENCES musica(idmusica) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: autor_pertence_escritorio_idautor_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY autor_pertence_escritorio
    ADD CONSTRAINT autor_pertence_escritorio_idautor_fkey FOREIGN KEY (idautor) REFERENCES autor(idautor) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: autor_pertence_escritorio_idesc_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY autor_pertence_escritorio
    ADD CONSTRAINT autor_pertence_escritorio_idesc_fkey FOREIGN KEY (idesc) REFERENCES escritorio(idesc) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: cantor_cpf_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY cantor
    ADD CONSTRAINT cantor_cpf_fkey FOREIGN KEY (cpf) REFERENCES pessoa(cpf) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: cantor_grava_unidade_idcantor_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY cantor_grava_unidade
    ADD CONSTRAINT cantor_grava_unidade_idcantor_fkey FOREIGN KEY (idcantor) REFERENCES cantor(idcantor) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: cantor_grava_unidade_idunidade_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY cantor_grava_unidade
    ADD CONSTRAINT cantor_grava_unidade_idunidade_fkey FOREIGN KEY (idunidade) REFERENCES unidade(idunidade) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: cantor_pertence_gravadora_idcantor_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY cantor_pertence_gravadora
    ADD CONSTRAINT cantor_pertence_gravadora_idcantor_fkey FOREIGN KEY (idcantor) REFERENCES cantor(idcantor) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: cantor_pertence_gravadora_idgravadora_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY cantor_pertence_gravadora
    ADD CONSTRAINT cantor_pertence_gravadora_idgravadora_fkey FOREIGN KEY (idgravadora) REFERENCES gravadora(idgravadora) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: cantor_regrava_musica_idcantor_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY cantor_regrava_musica
    ADD CONSTRAINT cantor_regrava_musica_idcantor_fkey FOREIGN KEY (idcantor) REFERENCES cantor(idcantor) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: cantor_regrava_musica_idmusica_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY cantor_regrava_musica
    ADD CONSTRAINT cantor_regrava_musica_idmusica_fkey FOREIGN KEY (idmusica) REFERENCES musica(idmusica) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: cantor_toca_instrumento_idcantor_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY cantor_toca_instrumento
    ADD CONSTRAINT cantor_toca_instrumento_idcantor_fkey FOREIGN KEY (idcantor) REFERENCES cantor(idcantor) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: cantor_toca_instrumento_nome_instrumento_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY cantor_toca_instrumento
    ADD CONSTRAINT cantor_toca_instrumento_nome_instrumento_fkey FOREIGN KEY (nome_instrumento) REFERENCES instrumento(nome_instrumento) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: musica_participa_unidade_idmusica_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY musica_participa_unidade
    ADD CONSTRAINT musica_participa_unidade_idmusica_fkey FOREIGN KEY (idmusica) REFERENCES musica(idmusica) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: musica_participa_unidade_idunidade_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY musica_participa_unidade
    ADD CONSTRAINT musica_participa_unidade_idunidade_fkey FOREIGN KEY (idunidade) REFERENCES unidade(idunidade) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: unidade_gravada_musica_idmusica_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY unidade_gravada_musica
    ADD CONSTRAINT unidade_gravada_musica_idmusica_fkey FOREIGN KEY (idmusica) REFERENCES musica(idmusica) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: unidade_gravada_musica_idunidade_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY unidade_gravada_musica
    ADD CONSTRAINT unidade_gravada_musica_idunidade_fkey FOREIGN KEY (idunidade) REFERENCES unidade(idunidade) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: unidade_idmidia_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY unidade
    ADD CONSTRAINT unidade_idmidia_fkey FOREIGN KEY (idmidia) REFERENCES midia(idmidia) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: public; Type: ACL; Schema: -; Owner: -
--

REVOKE ALL ON SCHEMA public FROM PUBLIC;
REVOKE ALL ON SCHEMA public FROM postgres;
GRANT ALL ON SCHEMA public TO postgres;
GRANT ALL ON SCHEMA public TO PUBLIC;


--
-- PostgreSQL database dump complete
--

