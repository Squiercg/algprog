package dao;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import model.Corrida;
import model.Date;

public class CorridaDao {
	private GenericDao dao;
	private String nomeClasse;
	
	public CorridaDao(String caminho) throws SQLException{
		nomeClasse = this.getClass().getName().replaceAll("Dao", "").replaceAll("dao.", "");
		dao = new GenericDao(caminho, nomeClasse);
	}
	
	public boolean insert(Corrida corrida) throws SQLException{
		Map<String,Object> map = new HashMap<String,Object>();
		map.put("nome", corrida.getNome());
		map.put("data", corrida.getData());
		map.put("local", corrida.getLocal());
		
		return dao.insert(map);
	}

	public boolean remove(int id) throws SQLException{
		Map<String,Object> map = new HashMap<String,Object>();
		map.put("id_corrida", id);
		return dao.remove(map);
	}
	
	public boolean update(Corrida corrida, int id) throws SQLException{
		Map<String,Object> updateMap = new HashMap<String,Object>();
		
		// Verifica se os campos foram preenchidos para fazer o update nos valores
		if(corrida.getNome() != null)
			updateMap.put("nome", corrida.getNome());
		
		if(corrida.getData() != null )
			updateMap.put("data", corrida.getData().toString());
		
		if(corrida.getLocal() != null)
			updateMap.put("local", corrida.getLocal());
		
		if (!updateMap.isEmpty())
		{		
			// Faz o update pelo ID
			Map<String,Object> whereMap = new HashMap<String,Object>();
			whereMap.put("id_corrida", id);
			
			return dao.update(updateMap, whereMap);
		}
		
		return false;
	}
	
	public ArrayList<Corrida> all() throws SQLException{
		ArrayList<Corrida> retorno = new ArrayList<Corrida>();		
		for(String lista : dao.all())
		{
			String corrida[] = new String[6];
			corrida = lista.split(",");
			String data[] = new String[3];
			data = corrida[2].split("/");			
			retorno.add(new Corrida(Integer.parseInt(corrida[0]),
							corrida[1],
							new Date(Integer.parseInt(data[0]), Integer.parseInt(data[1]), Integer.parseInt(data[2])),
							corrida[3]));
		}
		return retorno;		
	}
	
	public ArrayList<Corrida> findBy(Map<String, Object> map) throws SQLException{
		ArrayList<Corrida> retorno = new ArrayList<Corrida>();		
		for(String lista : dao.findBy(map))
		{
			String corrida[] = new String[6];
			corrida = lista.split(",");
			String data[] = new String[3];
			data = corrida[2].split("/");			
			retorno.add(new Corrida(Integer.parseInt(corrida[0]),
							corrida[1],
							new Date(Integer.parseInt(data[0]), Integer.parseInt(data[1]), Integer.parseInt(data[2])),
							corrida[3]));
		}
		return retorno;		
	}
	
}
