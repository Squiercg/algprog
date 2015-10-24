package dao;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import model.Inscricao;
import model.Date;

public class InscricaoDao {
	private GenericDao dao;
	private String nomeClasse;

	public InscricaoDao(String caminho) throws SQLException{
		nomeClasse = this.getClass().getName().replaceAll("Dao", "").replaceAll("dao.", "");
		dao = new GenericDao(caminho, nomeClasse);
	}
	
	public boolean insert(Inscricao inscricao) throws SQLException{
		Map<String,Object> map = new HashMap<String,Object>();
		map.put("tamanho_camiseta", inscricao.getTamanho_camiseta());
		map.put("data", inscricao.getData().toString());
		map.put("id_corredor", inscricao.getId_corredor());
		map.put("id_corrida", inscricao.getId_corrida());
		map.put("id_modalidade", inscricao.getId_modalidade());
		
		return dao.insert(map);
	}
	
	public boolean remove(int id) throws SQLException{
		Map<String,Object> map = new HashMap<String,Object>();
		map.put("id_inscricao", id);
		return dao.remove(map);
	}

	public boolean update(Inscricao inscricao, int id) throws SQLException{
		Map<String,Object> updateMap = new HashMap<String,Object>();
		
		// Verifica se os campos foram preenchidos para fazer o update nos valores
		if(inscricao.getTamanho_camiseta() != null)
			updateMap.put("tamanho_camiseta", inscricao.getTamanho_camiseta());
		
		if(inscricao.getData() != null )
			updateMap.put("data", inscricao.getData().toString());
		
		if(inscricao.getId_corredor() > 0)
			updateMap.put("id_corredor", inscricao.getId_corredor());
		
		if(inscricao.getId_corrida() > 0)
			updateMap.put("id_corrida", inscricao.getId_corrida());
		
		if(inscricao.getId_modalidade() > 0)
			updateMap.put("id_modalidade", inscricao.getId_modalidade());
		
		if (!updateMap.isEmpty())
		{		
			// Faz o update pelo ID
			Map<String,Object> whereMap = new HashMap<String,Object>();
			whereMap.put("id_inscricao", id);
			
			return dao.update(updateMap, whereMap);
		}
		
		return false;
	}
	
	public ArrayList<Inscricao> all() throws SQLException{
		ArrayList<Inscricao> retorno = new ArrayList<Inscricao>();		
		for(String lista : dao.all())
		{
			String inscricao[] = new String[6];
			inscricao = lista.split(",");
			String data[] = new String[3];
			data = inscricao[2].split("/");			
			retorno.add(new Inscricao(Integer.parseInt(inscricao[0]),
							inscricao[1],
							new Date(Integer.parseInt(data[0]), Integer.parseInt(data[1]), Integer.parseInt(data[2])),
							Integer.parseInt(inscricao[3]),
							Integer.parseInt(inscricao[4]),
							Integer.parseInt(inscricao[5])));
		}
		return retorno;		
	}
	
	public ArrayList<Inscricao> findBy(Map<String,Object> map) throws SQLException{
		ArrayList<Inscricao> retorno = new ArrayList<Inscricao>();		
		for(String lista : dao.findBy(map))
		{
			String inscricao[] = new String[5];
			inscricao = lista.split(",");
			String data[] = new String[3];
			data = inscricao[2].split("/");			
			retorno.add(new Inscricao(Integer.parseInt(inscricao[0]),
							inscricao[1],
							new Date(Integer.parseInt(data[0]), Integer.parseInt(data[1]), Integer.parseInt(data[2])),
							Integer.parseInt(inscricao[3]),
							Integer.parseInt(inscricao[4]),
							Integer.parseInt(inscricao[5])));
		}
		return retorno;		
	}
	
}
