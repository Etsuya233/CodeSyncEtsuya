package com.etsuya.system.utils;

import com.alibaba.druid.pool.DruidDataSource;
import com.alibaba.druid.pool.DruidDataSourceFactory;

import javax.sql.DataSource;
import java.io.IOException;
import java.io.InputStream;
import java.sql.Connection;
import java.sql.SQLException;
import java.util.Properties;

/**
 * ClassName: JDBCUtils
 * Package: com.etsuya.system.utils
 * Description: Utility of JDBC
 *
 * @Author: Etsuya
 * @Create: 2023/5/5 15:47
 * @Version: 1.0
 */
public class JDBCUtils {
	private static DataSource ds;
	private static ThreadLocal<Connection> tl = new ThreadLocal<>();

	static{
		Properties properties = new Properties();
		InputStream ras = JDBCUtils.class.getClassLoader().getResourceAsStream("druid.properties");
		try {
			properties.load(ras);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		try {
			ds = DruidDataSourceFactory.createDataSource(properties);
		} catch (Exception e) {
			throw new RuntimeException(e);
		}
	}

	public static Connection getConnection() throws SQLException {
		Connection ret = tl.get();
		if(ret == null){
			ret = ds.getConnection();
			tl.set(ret);
		}
		return ret;
	}

	public static void freeConnection() throws SQLException {
		Connection connection = tl.get();
		if(connection != null){
			tl.remove();
			connection.setAutoCommit(true);
			connection.close();
		}
	}
}
