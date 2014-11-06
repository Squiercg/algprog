package dao;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import model.Modalidade;

public class ModalidadeDao {
	private GenericDao dao;
	private String nomeClasse;
	
	public ModalidadeDao(String caminho) throws SQLException{
		nomeClasse = this.getClass().getName().replaceAll("Dao", "").replaceAll("dao.", "");
		dao = new GenericDao(caminho, nomeClasse);
	}
	
	public boolean insert(Modalidade modalidade) throws SQLException{
		Map<String,Object> map = new HashMap<String,Object>();
		map.put("quantidade_km", modalidade.getQuantidade_km());
		
		return dao.insert(map);
	}

	public boolean remove(int id) throws SQLException{
		Map<String,Object> map = new HashMap<String,Object>();
		map.put("id_modalidade", id);
		return dao.remove(map);
	}
	
	public boolean update(Modalidade modalidade, int id) throws SQLException{
		Map<String,Object> updateMap = new HashMap<String,Object>();
		
		// Verifica se os campos foram preenchidos para fazer o update nos valores
		if(modalidade.getQuantidade_km() > 0)
			updateMap.put("quantidade_km", modalidade.getQuantidade_km());
		
		if (!updateMap.isEmpty())
		{		
			// Faz o update pelo ID
			Map<String,Object> whereMap = new HashMap<String,Object>();
			whereMap.put("id_modalidade", id);
			
			return dao.update(updateMap, whereMap);
		}
		
		return false;
	}
	
	public ArrayList<Modalidade> all() throws SQLException{
		ArrayList<Modalidade> retorno = new ArrayList<Modalidade>();		
		for(String lista : dao.all())
		{
			String mocalidade[] = new String[2];
			mocalidade = lista.split(",");			
			retorno.add(new Modalidade(Integer.parseInt(mocalidade[0]),	Double.parseDouble(mocalidade[1])));
		}
		return retorno;		
	}
	
	public ArrayList<Modalidade> findBy(Map<String, Object> map) throws SQLException{
		ArrayList<Modalidade> retorno = new ArrayList<Modalidade>();		
		for(String lista : dao.findBy(map))
		{
			String mocalidade[] = new String[2];
			mocalidade = lista.split(",");			
			retorno.add(new Modalidade(Integer.parseInt(mocalidade[0]),	Double.parseDouble(mocalidade[1])));
		}
		return retorno;		
	}
	
}
