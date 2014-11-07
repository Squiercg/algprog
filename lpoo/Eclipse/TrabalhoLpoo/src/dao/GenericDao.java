package dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.Map;

public abstract class GenericDao {
	private String databaseUrl;
	private String tableName;
	
	public GenericDao(String databaseUrl, String tableName) throws SQLException {
		DriverManager.registerDriver(new org.sqlite.JDBC());
		this.databaseUrl = databaseUrl;
		this.tableName = tableName;
	}
	
	public  ArrayList<String> all() throws SQLException {
		Connection connection = DriverManager.getConnection("jdbc:sqlite:" + databaseUrl);
		Statement statement = connection.createStatement();
		
		ArrayList<String> result = new ArrayList<String>();
		ResultSet resultSet = statement.executeQuery("select * from " + tableName);
		int numberOfColumns = resultSet.getMetaData().getColumnCount();
		
		while(resultSet.next()) {
			String stringResult = "";
			int i;
			for(i = 1 ; i < numberOfColumns ; i++) {
				stringResult += resultSet.getString(i);
				stringResult += ",";
			}
			stringResult += resultSet.getString(i);
			result.add(stringResult);
		}
		
		statement.close();
		connection.close();
		return result;
	}
	
	private Object fixString(Object value) {
		return value instanceof String ? "'" + value + "'" : value;  	
	}
	
	public ArrayList<String> findBy(Map<String, Object> mapping) throws SQLException {
		Connection connection = DriverManager.getConnection("jdbc:sqlite:" + databaseUrl);
		Statement statement = connection.createStatement();
		
		int i;
		/* Where clause */
		String whereClause = "";
		Object keys[] = mapping.keySet().toArray();
		for(i = 0 ; i < keys.length - 1 ; i++) {
			whereClause = whereClause + keys[i] + " = " + fixString(mapping.get(keys[i])) + " AND ";
		}
		whereClause = whereClause + keys[i] + " = " + fixString(mapping.get(keys[i]));
		
		ArrayList<String> result = new ArrayList<String>();
		ResultSet resultSet = statement.executeQuery("select * from " + tableName + " where " + whereClause);
		int numberOfColumns = resultSet.getMetaData().getColumnCount();
		
		while(resultSet.next()) {
			String stringResult = "";
			for(i = 1 ; i < numberOfColumns ; i++) {
				stringResult += resultSet.getString(i);
				stringResult += ",";
			}
			stringResult += resultSet.getString(i);
			result.add(stringResult);
		}
		
		statement.close();
		connection.close();
		
		return result;
	}
	
	public boolean insert(Map<String, Object> mapping) {
		
		return true;
	}
	
	public boolean remove(Map<String, Object> mapping){
		
		return true;
	}
}
