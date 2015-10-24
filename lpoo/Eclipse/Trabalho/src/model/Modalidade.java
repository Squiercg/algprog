package model;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import dao.InscricaoDao;
import dao.Corrida_ModalidadeDao;
import dao.CorridaDao;

public class Modalidade {
	private int id_modalidade;
	private double quantidade_km;
	private ArrayList<Inscricao> inscricoes;
	private ArrayList<Corrida> corridas;
	
	public int getId_modalidade() {
		return id_modalidade;
	}
	public void setId_modalidade(int id_modalidade) {
		this.id_modalidade = id_modalidade;
	}
	public double getQuantidade_km() {
		return quantidade_km;
	}
	public void setQuantidade_km(double quantidade_km) {
		this.quantidade_km = quantidade_km;
	}	
	public ArrayList<Inscricao> getInscricoes(String caminho) throws SQLException {
		InscricaoDao inscricaoDao = new InscricaoDao(caminho);
		Map<String, Object> map = new HashMap<String, Object>();
		map.put("id_modalidade", this.getId_modalidade());
		
		this.setInscricoes(inscricaoDao.findBy(map));
		
		return inscricoes;
	}
	public void setInscricoes(ArrayList<Inscricao> inscricoes){
		this.inscricoes = inscricoes;
	}	
	public ArrayList<Corrida> getCorridas(String caminho) throws SQLException {
		// Criacão dos Daos
		Corrida_ModalidadeDao corrida_modalidadeDao = new Corrida_ModalidadeDao(caminho);
		CorridaDao corridaDao = new CorridaDao(caminho);
		
		// Criação do filtro para buscar somente as corridas dessa modalidade 
		Map<String, Object> mapCorMod = new HashMap<String, Object>();
		mapCorMod.put("id_modalidade", this.getId_modalidade());
		
		// Busca na tabela de Corrida_Modalidade e cria um filtro para trazer as corridas
		Map<String, Object> mapCorrida = new HashMap<String, Object>();
		for(Corrida_Modalidade corMod : corrida_modalidadeDao.findBy(mapCorMod)){
			mapCorrida.put("id_corrida", corMod.getId_corrida());
		}
		
		this.setCorridas(corridaDao.findBy(mapCorrida));
				
		return corridas;
	}
	public void setCorridas(ArrayList<Corrida> corridas){
		this.corridas = corridas;
	}
	
	public Modalidade(){
		
	}
	
	public Modalidade(int id_modalidade, double quantidade_km){
		this.setId_modalidade(id_modalidade);
		this.setQuantidade_km(quantidade_km);
	}
	
}
