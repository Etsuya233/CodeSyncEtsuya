package com.etsuya;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;

import java.io.IOException;

/**
 * ClassName: MyBatisIntroduction
 * Package: com.etsuya.day1
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/7/18 21:28
 * @Version: 1.0
 */
public class MyBatisIntroduction {
	public static void main(String[] args) {
		SqlSession sqlSession = null;
		try {
			SqlSessionFactoryBuilder sqlSessionFactoryBuilder = new SqlSessionFactoryBuilder();
			SqlSessionFactory sqlSessionFactory = sqlSessionFactoryBuilder.build(Resources.getResourceAsStream("mybatis-config.xml"));

			sqlSession = sqlSessionFactory.openSession();

			int count = sqlSession.insert("insertCar");
			System.out.println("插入了" + count);

			sqlSession.commit();

		} catch (IOException e) {
			throw new RuntimeException(e);
		} finally {
			if(sqlSession != null)
				sqlSession.close();
		}

	}
}
