package com.etsuya.db.view;

import java.sql.*;

/**
 * ClassName: ResultGetter
 * Package: com.etsuya.db.view
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/5/1 20:33
 * @Version: 1.0
 */
public class ResultGetter {
	public static Object[] getFromDB(String ipAddress, String port, String database, String user, String password, String table) throws ClassNotFoundException, SQLException {
		String[][] data = null;
		String[] columnList = null;
		Object[] ret = new Object[2];

		Class.forName("com.mysql.cj.jdbc.Driver");
		String url = "jdbc:mysql://" + ipAddress + ":" + port + "/" + database;
		Connection connection = DriverManager.getConnection(url, user, password);

//		PreparedStatement preparedStatement = connection.prepareStatement("select * from ?");
//		preparedStatement.setObject(1, table);
//		ResultSet resultSet = preparedStatement.executeQuery();


		//getRowSum
		Statement statement1 = connection.createStatement();
		int row;
		statement1.executeQuery("select count(*) from " + table);
		ResultSet resultSet1 = statement1.getResultSet();
		resultSet1.next();
		row = resultSet1.getInt(1);
		resultSet1.close();
		statement1.close();

		Statement statement = connection.createStatement();
		ResultSet resultSet = statement.executeQuery("select * from " + table);
		ResultSetMetaData resultSetMetaData = resultSet.getMetaData();
		int columnCount = resultSetMetaData.getColumnCount();
		data = new String[row][columnCount];
		columnList = new String[columnCount];
		for(int i = 0; i < columnCount; i++){
			columnList[i] = resultSetMetaData.getColumnName(i + 1);
		}

		int cnt = 0;
		while(resultSet.next()){
			for(int j = 0; j < columnCount; j++){
				data[cnt][j] = resultSet.getString(j + 1);
			}
			cnt++;
		}

		ret[0] = columnList;
		ret[1] = data;

		resultSet.close();
		statement.close();
		connection.close();

		return ret;
	}
}
