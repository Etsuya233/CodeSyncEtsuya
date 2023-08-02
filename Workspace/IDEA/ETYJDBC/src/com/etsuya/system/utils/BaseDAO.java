package com.etsuya.system.utils;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.sql.*;
import java.util.ArrayList;

/**
 * ClassName: BaseDAO
 * Package: com.etsuya.system.utils
 * Description: DAO the base
 *
 * @Author: Etsuya
 * @Create: 2023/5/5 15:56
 * @Version: 1.0
 */
public abstract class BaseDAO {

	protected int update(String sql, Object... args) throws SQLException {
		Connection connection = JDBCUtils.getConnection();
		PreparedStatement preparedStatement = connection.prepareStatement(sql);
		for(int i = 0; i < args.length; i++){
			preparedStatement.setObject(i + 1, args[i]);
		}
		int i = preparedStatement.executeUpdate();
		preparedStatement.close();
		if(connection.getAutoCommit()){
			JDBCUtils.freeConnection();
		}
		return i;
	}

	protected <T> ArrayList<T> query(Class<T> tClass, String sql, Object... args) throws SQLException, NoSuchMethodException, InvocationTargetException, InstantiationException, IllegalAccessException, NoSuchFieldException {
		Connection connection = JDBCUtils.getConnection();
		PreparedStatement preparedStatement = connection.prepareStatement(sql);
		for(int i = 0; i < args.length; i++){
			preparedStatement.setObject(i + 1, args[i]);
		}
		ResultSet resultSet = preparedStatement.executeQuery();
		ResultSetMetaData metaData = resultSet.getMetaData();
		int columnCount = metaData.getColumnCount();
		ArrayList<T> ret = new ArrayList<>();
		Constructor<T> constructor = tClass.getConstructor();
		while(resultSet.next()){
			T t = constructor.newInstance();
			for(int i = 1; i <= columnCount; i++){
				Field field = tClass.getDeclaredField(metaData.getColumnName(i));
				field.setAccessible(true);
				field.set(t, resultSet.getObject(i));
			}
			ret.add(t);
		}
		resultSet.close();
		preparedStatement.close();
		if(connection.getAutoCommit()){
			connection.close();
		}
		return ret;
	}


}
