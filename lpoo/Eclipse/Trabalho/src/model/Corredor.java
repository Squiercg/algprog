package model;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import dao.InscricaoDao;

public class Corredor {
	private int id_corredor;
	private String nome;
	private Date data_de_nascimento;
	private String cpf;
	private ArrayList<Inscricao> inscricoes;
	
	public int getId_corredor() {
		return id_corredor;
	}
	public void setId_corredor(int id_corredor) {
		this.id_corredor = id_corredor;
	}
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public Date getData_de_nascimento() {
		return data_de_nascimento;
	}
	public void setData_de_nascimento(Date data_de_nascimento) {
		this.data_de_nascimento = data_de_nascimento;
	}
	public String getCpf() {
		return cpf;
	}
	public void setCpf(String cpf) {
		this.cpf = cpf;
	}	
	public ArrayList<Inscricao> getInscricoes(String caminho) throws SQLException {
		InscricaoDao inscricaoDao = new InscricaoDao(caminho);
		Map<String, Object> map = new HashMap<String, Object>();
		map.put("id_corredor", this.getId_corredor());
		
		this.setInscricoes(inscricaoDao.findBy(map));
		
		return inscricoes;
	}
	private void setInscricoes(ArrayList<Inscricao> inscricoes) {
		this.inscricoes = inscricoes;		
	}
	
	public Corredor(){
		
	}
	
	public Corredor(int id_corredor, String nome, Date data_de_nascimento, String cpf){
		this.setId_corredor(id_corredor);
		this.setNome(nome);
		this.setData_de_nascimento(data_de_nascimento);
		this.setCpf(cpf);
	}
	
	public String toString(){
		return "[Id = " + this.getId_corredor() + ", Nome = " + this.getNome() +
				", Data de nascimento: " + this.getData_de_nascimento() + ", CPF: " + this.getCpf() + "]";
	}
	
}
