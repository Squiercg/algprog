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
    CONSTRAINT checa_ano CHECK ((ano > 2002))
);


--
-- Name: automoveis_2012; Type: VIEW; Schema: public; Owner: -
--

CREATE VIEW automoveis_2012 AS
    SELECT automoveis.codigo, automoveis.fabricante, automoveis.modelo, automoveis.ano, automoveis.pais, automoveis.preco_tabela FROM automoveis WHERE (automoveis.ano >= 2012);


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
-- Name: consumidoras; Type: VIEW; Schema: public; Owner: -
--

CREATE VIEW consumidoras AS
    SELECT consumidores.identidade, consumidores.nome, consumidores.sobrenome, consumidores.sexo FROM consumidores WHERE ((consumidores.sexo)::text = 'F'::text);


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
-- Name: revendedoras_ms; Type: VIEW; Schema: public; Owner: -
--

CREATE VIEW revendedoras_ms AS
    SELECT revendedoras.cgc, revendedoras.nome, revendedoras.nome_proprietario, revendedoras.cidade, revendedoras.estado FROM revendedoras WHERE ((revendedoras.estado)::text = 'MS'::text);


--
-- Data for Name: automoveis; Type: TABLE DATA; Schema: public; Owner: -
--

COPY automoveis (codigo, fabricante, modelo, ano, pais, preco_tabela) FROM stdin;
1	Tesla	S	2012	Estados Unidos	237000
1	Tesla	X	2013	Estados Unidos	412000
1	Tesla	3	2016	Estados Unidos	500000
\.


--
-- Data for Name: consumidores; Type: TABLE DATA; Schema: public; Owner: -
--

COPY consumidores (identidade, nome, sobrenome, sexo) FROM stdin;
3	Zildamara	Holsback	F
3482	Augusto	Ribas	M
9452	Luiz	Gustavo	M
\.


--
-- Data for Name: negocios; Type: TABLE DATA; Schema: public; Owner: -
--

COPY negocios (identidade_consumidor, cgc_revenda, codigo_auto, ano_auto, data, preco) FROM stdin;
3	3	1	2016	2016-08-10 20:53:18.433073	500000
3482	2	1	2012	2016-08-10 20:53:18.398306	250000
9452	1	1	2013	2016-08-10 20:53:18.415914	500000
\.


--
-- Data for Name: revendedoras; Type: TABLE DATA; Schema: public; Owner: -
--

COPY revendedoras (cgc, nome, nome_proprietario, cidade, estado) FROM stdin;
1	Vila Ipiranga Motors	João Silva	Campo Grande	Mato Grosso do Sul
2	UFMS Carros	José Silva	Campo Grande	Mato Grosso do Sul
3	Tesla Brasil	Arnaldo Cesar Coelho	São Paulo	São Paulo
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
-- Name: automoveis; Type: ACL; Schema: public; Owner: -
--

REVOKE ALL ON TABLE automoveis FROM PUBLIC;
REVOKE ALL ON TABLE automoveis FROM "201319030386";
GRANT ALL ON TABLE automoveis TO "201319030386";


--
-- Name: automoveis_2012; Type: ACL; Schema: public; Owner: -
--

REVOKE ALL ON TABLE automoveis_2012 FROM PUBLIC;
REVOKE ALL ON TABLE automoveis_2012 FROM "201319030386";
GRANT ALL ON TABLE automoveis_2012 TO "201319030386";


--
-- Name: consumidoras; Type: ACL; Schema: public; Owner: -
--

REVOKE ALL ON TABLE consumidoras FROM PUBLIC;
REVOKE ALL ON TABLE consumidoras FROM "201319030386";
GRANT ALL ON TABLE consumidoras TO "201319030386";


--
-- Name: revendedoras_ms; Type: ACL; Schema: public; Owner: -
--

REVOKE ALL ON TABLE revendedoras_ms FROM PUBLIC;
REVOKE ALL ON TABLE revendedoras_ms FROM "201319030386";
GRANT ALL ON TABLE revendedoras_ms TO "201319030386";


--
-- PostgreSQL database dump complete
--

