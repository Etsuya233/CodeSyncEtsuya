package com.bank.utils;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;

import java.io.IOException;

public class SqlSessionUtil {
	private SqlSessionUtil(){}

	private static SqlSessionFactory sqlSessionFactory = null;

	private static ThreadLocal<SqlSession> threadLocal = new ThreadLocal<>();

	static{
		try {
			sqlSessionFactory = new SqlSessionFactoryBuilder().build(Resources.getResourceAsStream("mybatis-config.xml"));
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	public static SqlSession openSession(){
		SqlSession sqlSession = threadLocal.get();
		if(sqlSession == null){
			sqlSession = sqlSessionFactory.openSession();
			threadLocal.set(sqlSession);
		}
		return sqlSession;
	}

	public static void closeSession() {
		SqlSession sqlSession = threadLocal.get();
		if(sqlSession != null){
			sqlSession.close();
			threadLocal.remove();
		}
	}

	public static void commitSession(){
		SqlSession sqlSession = threadLocal.get();
		if(sqlSession != null){
			sqlSession.commit();
		}
	}
}
