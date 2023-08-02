package com.etsuya.utils;

import java.sql.Connection;
import java.sql.Driver;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.ResourceBundle;

public class DBUtil {
	private DBUtil(){}

	public static final ResourceBundle bundle = ResourceBundle.getBundle("mysql.properties");
	public static final String driver = bundle.getString("driver");
	public static final String username = bundle.getString("username");
	public static final String password = bundle.getString("password");
	public static final String url = bundle.getString("url");

	static {
		try {
			Class.forName(driver);
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
	}

	public Connection getConnection() throws SQLException {
		return DriverManager.getConnection(url, username, password);
	}

}
