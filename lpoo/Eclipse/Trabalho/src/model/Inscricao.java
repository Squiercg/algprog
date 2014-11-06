package model;

import java.sql.SQLException;
import java.util.HashMap;
import java.util.Map;
import dao.CorridaDao;
import dao.CorredorDao;
import dao.ModalidadeDao;

public class Inscricao {
	private int id_inscricao;
	private String tamanho_camiseta;
	private Date data;
	private int id_corrida;
	private Corrida corrida;
	private int id_corredor;
	private Corredor corredor;
	private int id_modalidade;
	private Modalidade modalidade;
	
	public int getId_inscricao() {
		return id_inscricao;
	}
	public void setId_inscricao(int id_inscricao) {
		this.id_inscricao = id_inscricao;
	}
	public String getTamanho_camiseta() {
		return tamanho_camiseta;
	}
	public void setTamanho_camiseta(String tamanho_camiseta) {
		this.tamanho_camiseta = tamanho_camiseta;
	}
	public Date getData() {
		return data;
	}
	public void setData(Date data) {
		this.data = data;
	}
	public int getId_corrida() {
		return id_corrida;
	}
	public void setId_corrida(int id_corrida) {
		this.id_corrida = id_corrida;
	}
	public int getId_corredor() {
		return id_corredor;
	}
	public void setId_corredor(int id_corredor) {
		this.id_corredor = id_corredor;
	}
	public int getId_modalidade() {
		return id_modalidade;
	}
	public void setId_modalidade(int id_modalidade) {
		this.id_modalidade = id_modalidade;
	}	
	public Corrida getCorrida(String caminho) throws SQLException{
		CorridaDao corridaDao = new CorridaDao(caminho);
		Map<String, Object> map = new HashMap<String, Object>();
		map.put("id_corrida", this.getId_corrida());
		
		this.setCorrida(corridaDao.findBy(map).get(0));
		
		return corrida;
	}
	public void setCorrida(Corrida corrida){
		this.corrida = corrida;
	}	
	public Modalidade getModalidade(String caminho) throws SQLException{
		ModalidadeDao mocalidadeDao = new ModalidadeDao(caminho);
		Map<String, Object> map = new HashMap<String, Object>();
		map.put("id_modalidade", this.getId_modalidade());
		
		this.setModalidade(mocalidadeDao.findBy(map).get(0));
		
		return modalidade;
	}
	public void setModalidade(Modalidade modalidade){
		this.modalidade = modalidade;
	}	
	public Corredor getCorredor(String caminho) throws SQLException{
		CorredorDao corredorDao = new CorredorDao(caminho);
		Map<String, Object> map = new HashMap<String, Object>();
		map.put("id_corredor", this.getId_corredor());
		
		this.setCorredor(corredorDao.findBy(map).get(0));
		
		return corredor;
	}
	public void setCorredor(Corredor corredor){
		this.corredor = corredor;
	}
	
	public Inscricao(){
		
	}
	
	public Inscricao(int id_inscricao, String tamanho_camiseta, Date data, 
			int id_corrida, int id_corredor, int id_modalidade)
	{
		this.setId_inscricao(id_inscricao);
		this.setTamanho_camiseta(tamanho_camiseta);
		this.setData(data);
		this.setId_corrida(id_corrida);
		this.setId_corredor(id_corredor);
		this.setId_modalidade(id_modalidade);
	}
	
}
