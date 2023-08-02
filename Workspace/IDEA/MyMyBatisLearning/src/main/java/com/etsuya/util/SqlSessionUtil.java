package com.etsuya.util;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;

import java.io.IOException;

public class SqlSessionUtil {
	static SqlSessionFactoryBuilder sqlSessionFactoryBuilder = null;
	static SqlSessionFactory sqlSessionFactory = null;

	static {
		sqlSessionFactoryBuilder = new SqlSessionFactoryBuilder();
		try {
			sqlSessionFactory = sqlSessionFactoryBuilder.build(Resources.getResourceAsStream("mybatis-config.xml"));
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	public static SqlSession openSession(){
		return sqlSessionFactory.openSession();
	}

}