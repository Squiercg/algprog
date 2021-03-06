package dao;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import model.Corredor;
import model.Date;

public class CorredorDao {
	private GenericDao dao;
	private String nomeClasse;
	
	public CorredorDao(String caminho) throws SQLException{
		nomeClasse = this.getClass().getName().replaceAll("Dao", "").replaceAll("dao.", "");
		dao = new GenericDao(caminho, nomeClasse);
	}
	
	public boolean insert(Corredor corredor) throws SQLException{
		Map<String,Object> map = new HashMap<String,Object>();
		map.put("nome", corredor.getNome());
		map.put("data_de_nascimento", corredor.getData_de_nascimento().toString());
		map.put("cpf", corredor.getCpf());
		
		return dao.insert(map);
	}
	
	public boolean remove(int id) throws SQLException{
		Map<String,Object> map = new HashMap<String,Object>();
		map.put("id_corredor", id);
		return dao.remove(map);
	}
	
	public boolean update(Corredor corredor, int id) throws SQLException{
		Map<String,Object> updateMap = new HashMap<String,Object>();
		
		// Verifica se os campos foram preenchidos para fazer o update nos valores
		if(corredor.getNome() != null)
			updateMap.put("nome", corredor.getNome());
		
		if(corredor.getData_de_nascimento() != null )
			updateMap.put("data_de_nascimento", corredor.getData_de_nascimento().toString());
		
		if(corredor.getCpf() != null)
			updateMap.put("cpf", corredor.getCpf());
		
		if (!updateMap.isEmpty())
		{		
			// Faz o update pelo ID
			Map<String,Object> whereMap = new HashMap<String,Object>();
			whereMap.put("id_corredor", id);
			
			return dao.update(updateMap, whereMap);
		}
		
		return false;
	}

	public ArrayList<Corredor> all() throws SQLException{
		ArrayList<Corredor> retorno = new ArrayList<Corredor>();
		for(String lista : dao.all())
		{			
			String corredor[] = new String[4];
			corredor = lista.split(",");
			
			String data[] = new String[3];
			data = corredor[2].split("/");
			
			retorno.add(new	Corredor(Integer.parseInt(corredor[0]), 
								corredor[1], 
								new Date(Integer.parseInt(data[0]), Integer.parseInt(data[1]), Integer.parseInt(data[2])), 
								corredor[3]));
		}
		return retorno;		
	}
	
	public ArrayList<Corredor> findBy(Map<String, Object> mapping) throws SQLException{
		ArrayList<Corredor> retorno = new ArrayList<Corredor>();
		for(String lista : dao.findBy(mapping))
		{			
			String corredor[] = new String[4];
			corredor = lista.split(",");
			
			String data[] = new String[3];
			data = corredor[2].split("/");
			
			retorno.add(new	Corredor(Integer.parseInt(corredor[0]), 
								corredor[1], 
								new Date(Integer.parseInt(data[0]), Integer.parseInt(data[1]), Integer.parseInt(data[2])), 
								corredor[3]));
		}
		return retorno;		
	}
	
}
