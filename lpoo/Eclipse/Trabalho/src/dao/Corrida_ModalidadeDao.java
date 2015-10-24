package dao;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import model.Corrida_Modalidade;

public class Corrida_ModalidadeDao {
	private GenericDao dao;
	private String nomeClasse;
	
	public Corrida_ModalidadeDao(String caminho) throws SQLException{
		nomeClasse = this.getClass().getName().replaceAll("Dao", "").replaceAll("dao.", "");
		dao = new GenericDao(caminho, nomeClasse);
	}
	
	public boolean insert(Corrida_Modalidade corrida_modalidade) throws SQLException{
		Map<String,Object> map = new HashMap<String,Object>();
		map.put("id_corrida", corrida_modalidade.getId_corrida());
		map.put("id_modalidade", corrida_modalidade.getId_modalidade());
		
		return dao.insert(map);
	}
	
	public boolean remove(Corrida_Modalidade corrida_modalidade) throws SQLException{
		Map<String,Object> map = new HashMap<String,Object>();
		map.put("id_corrida", corrida_modalidade.getId_corrida());
		map.put("id_modalidade", corrida_modalidade.getId_modalidade());
		
		return dao.remove(map);
	}
	
	public boolean update(Corrida_Modalidade corrida_modalidade, Corrida_Modalidade novo) throws SQLException{
		Map<String,Object> updateMap = new HashMap<String,Object>();
		
		// Verifica se os campos foram preenchidos para fazer o update nos valores
		if(corrida_modalidade.getId_corrida() > 0)
			updateMap.put("id_corrida", corrida_modalidade.getId_corrida());
		
		if(corrida_modalidade.getId_modalidade() > 0)
			updateMap.put("id_modalidade", corrida_modalidade.getId_modalidade());
		
		if (!updateMap.isEmpty())
		{		
			// Faz o update pelo ID
			Map<String,Object> whereMap = new HashMap<String,Object>();
			whereMap.put("id_corrida", corrida_modalidade.getId_corrida());
			whereMap.put("id_modalidade", corrida_modalidade.getId_modalidade());
			
			return dao.update(updateMap, whereMap);
		}
		
		return false;
	}
	
	public ArrayList<Corrida_Modalidade> all() throws SQLException{
		ArrayList<Corrida_Modalidade> retorno = new ArrayList<Corrida_Modalidade>();		
		for(String lista : dao.all())
		{
			String corrida_modalidade[] = new String[2];
			corrida_modalidade = lista.split(",");		
			retorno.add(new Corrida_Modalidade(Integer.parseInt(corrida_modalidade[0]),Integer.parseInt(corrida_modalidade[1])));
		}
		return retorno;		
	}
	
	public ArrayList<Corrida_Modalidade> findBy(Map<String, Object> map) throws SQLException{
		ArrayList<Corrida_Modalidade> retorno = new ArrayList<Corrida_Modalidade>();		
		for(String lista : dao.findBy(map))
		{
			String corrida_modalidade[] = new String[2];
			corrida_modalidade = lista.split(",");		
			retorno.add(new Corrida_Modalidade(Integer.parseInt(corrida_modalidade[0]),Integer.parseInt(corrida_modalidade[1])));
		}
		return retorno;		
	}
	
}
