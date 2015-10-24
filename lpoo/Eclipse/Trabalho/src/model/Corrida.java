package model;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import dao.ModalidadeDao;
import dao.Corrida_ModalidadeDao;
import dao.InscricaoDao;

public class Corrida {
	private int id_corrida;
	private String nome;
	private Date data;
	private String local;
	private ArrayList<Modalidade> modalidades;
	private ArrayList<Inscricao> inscricoes;
	
	public int getId_corrida() {
		return id_corrida;
	}
	public void setId_corrida(int id_corrida) {
		this.id_corrida = id_corrida;
	}
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public Date getData() {
		return data;
	}
	public void setData(Date data) {
		this.data = data;
	}
	public String getLocal() {
		return local;
	}
	public void setLocal(String local) {
		this.local = local;
	}	
	public ArrayList<Modalidade> getModalidades(String caminho) throws SQLException {
		// Criacão dos Daos
		Corrida_ModalidadeDao corrida_modalidadeDao = new Corrida_ModalidadeDao(caminho);
		ModalidadeDao modalidadeDao = new ModalidadeDao(caminho);
		
		// Criação do filtro para buscar somente as modalidades dessa corrida
		Map<String, Object> mapCorMod = new HashMap<String, Object>();
		mapCorMod.put("id_corrida", this.getId_corrida());
		
		// Busca na tabela de Corrida_Modalidade e cria um filtro para trazer as modalidades
		Map<String, Object> mapModalidade = new HashMap<String, Object>();
		for(Corrida_Modalidade corMod : corrida_modalidadeDao.findBy(mapCorMod)){
			mapModalidade.put("id_modalidade", corMod.getId_modalidade());
		}	
		
		this.setModalidades(modalidadeDao.findBy(mapModalidade));
		
		return modalidades;
	}
	public void setModalidades(ArrayList<Modalidade> modalidades){
		this.modalidades = modalidades;
	}	
	public ArrayList<Inscricao> getInscricoes(String caminho) throws SQLException {
		InscricaoDao inscricaoDao = new InscricaoDao(caminho);
		Map<String, Object> map = new HashMap<String, Object>();
		map.put("id_corrida", this.getId_corrida());
		
		this.setInscricoes(inscricaoDao.findBy(map));
		
		return inscricoes;
	}
	public void setInscricoes(ArrayList<Inscricao> inscricoes){
		this.inscricoes = inscricoes;
	}
	
	public Corrida(){

	}
	
	public Corrida(int id_corrida, String nome, Date data, String local){
		this.setId_corrida(id_corrida);
		this.setNome(nome);
		this.setData(data);
		this.setLocal(local);
	}
	
}
