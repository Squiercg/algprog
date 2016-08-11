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
    codigo integer NOT NULL,
    fabricante character varying(200) NOT NULL,
    modelo character varying(200) NOT NULL,
    ano integer NOT NULL,
    pais character varying(50) NOT NULL,
    preco_tabela numeric NOT NULL,
    CONSTRAINT automoveis_preco_tabela_check CHECK ((preco_tabela >= (0)::numeric)),
    CONSTRAINT checa_ano CHECK ((ano > 2000))
);


--
-- Name: consumidores; Type: TABLE; Schema: public; Owner: -; Tablespace: 
--

CREATE TABLE consumidores (
    identidade integer NOT NULL,
    nome character varying(200) NOT NULL,
    sobrenome character varying(200) NOT NULL,
    sexo character varying(200) NOT NULL,
    CONSTRAINT consumidores_sexo_check CHECK (((sexo)::text = ANY ((ARRAY['F'::character varying, 'M'::character varying])::text[])))
);


--
-- Name: negocios; Type: TABLE; Schema: public; Owner: -; Tablespace: 
--

CREATE TABLE negocios (
    identidade_consumidor integer NOT NULL,
    cgc_revenda integer NOT NULL,
    codigo_auto integer NOT NULL,
    ano_auto integer NOT NULL,
    data timestamp without time zone DEFAULT now() NOT NULL,
    preco numeric NOT NULL,
    CONSTRAINT negocios_preco_check CHECK ((preco >= (0)::numeric))
);


--
-- Name: revendedoras; Type: TABLE; Schema: public; Owner: -; Tablespace: 
--

CREATE TABLE revendedoras (
    cgc integer NOT NULL,
    nome character varying(200) NOT NULL,
    nome_proprietario character varying(200) NOT NULL,
    cidade character varying(200) NOT NULL,
    estado character varying(200) NOT NULL
);


--
-- Data for Name: automoveis; Type: TABLE DATA; Schema: public; Owner: -
--

COPY automoveis (codigo, fabricante, modelo, ano, pais, preco_tabela) FROM stdin;
\.


--
-- Data for Name: consumidores; Type: TABLE DATA; Schema: public; Owner: -
--

COPY consumidores (identidade, nome, sobrenome, sexo) FROM stdin;
\.


--
-- Data for Name: negocios; Type: TABLE DATA; Schema: public; Owner: -
--

COPY negocios (identidade_consumidor, cgc_revenda, codigo_auto, ano_auto, data, preco) FROM stdin;
\.


--
-- Data for Name: revendedoras; Type: TABLE DATA; Schema: public; Owner: -
--

COPY revendedoras (cgc, nome, nome_proprietario, cidade, estado) FROM stdin;
\.


--
-- Name: automoveis_pkey; Type: CONSTRAINT; Schema: public; Owner: -; Tablespace: 
--

ALTER TABLE ONLY automoveis
    ADD CONSTRAINT automoveis_pkey PRIMARY KEY (codigo, ano);


--
-- Name: consumidores_pkey; Type: CONSTRAINT; Schema: public; Owner: -; Tablespace: 
--

ALTER TABLE ONLY consumidores
    ADD CONSTRAINT consumidores_pkey PRIMARY KEY (identidade);


--
-- Name: negocios_pkey; Type: CONSTRAINT; Schema: public; Owner: -; Tablespace: 
--

ALTER TABLE ONLY negocios
    ADD CONSTRAINT negocios_pkey PRIMARY KEY (identidade_consumidor, cgc_revenda, codigo_auto, ano_auto);


--
-- Name: revendedoras_pkey; Type: CONSTRAINT; Schema: public; Owner: -; Tablespace: 
--

ALTER TABLE ONLY revendedoras
    ADD CONSTRAINT revendedoras_pkey PRIMARY KEY (cgc);


--
-- Name: negocios_cgc_revenda_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY negocios
    ADD CONSTRAINT negocios_cgc_revenda_fkey FOREIGN KEY (cgc_revenda) REFERENCES revendedoras(cgc) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: negocios_codigo_auto_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY negocios
    ADD CONSTRAINT negocios_codigo_auto_fkey FOREIGN KEY (codigo_auto, ano_auto) REFERENCES automoveis(codigo, ano) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: negocios_identidade_consumidor_fkey; Type: FK CONSTRAINT; Schema: public; Owner: -
--

ALTER TABLE ONLY negocios
    ADD CONSTRAINT negocios_identidade_consumidor_fkey FOREIGN KEY (identidade_consumidor) REFERENCES consumidores(identidade) ON UPDATE CASCADE ON DELETE RESTRICT;


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

