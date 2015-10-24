package classes;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.HashSet;

import dao.CorridaDao;
import dao.Corrida_ModalidadeDao;

public class Modalidade {
	private int id_modalidade;	
	private int quantidade_km;
	
	public Modalidade() {
	}
	public Modalidade(int id_modalidade, int quantidade_km) {
		this.id_modalidade = id_modalidade;
		this.quantidade_km = quantidade_km;
	}	
	
	public int getId_modalidade() {
		return id_modalidade;
	}
	public void setId_modalidade(int id_modalidade) {
		this.id_modalidade = id_modalidade;
	}
	public int getQuantidade_km() {
		return quantidade_km;
	}
	public void setQuantidade_km(int quantidade_km) {
		this.quantidade_km = quantidade_km;
	}
	
	public ArrayList<Corrida> getCorridas(Corrida_ModalidadeDao corrida_modalidadedao, CorridaDao corridadao) throws SQLException{
		ArrayList<Integer> lista_corridas = corrida_modalidadedao.findBy_idmodalidade_corridas(this.id_modalidade);

		//Eliminando elementos repetidos
		HashSet<Integer> hs = new HashSet<Integer>();
		hs.addAll(lista_corridas);
		lista_corridas.clear();
		lista_corridas.addAll(hs);
		
		
		ArrayList<Corrida> saida = new ArrayList<Corrida>();
		
		for(int item : lista_corridas) {
			saida.add(corridadao.findBy_id(item));
		}
		
		return saida;
		
	}
	
	@Override
	public String toString() {
		return "Modalidade [Id = " + id_modalidade
				+ ", Distancia = " + quantidade_km + " km ]";
	}	

}
