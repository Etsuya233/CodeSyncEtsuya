package com.etsuya.test;

import com.etsuya.pojo.Car;
import com.etsuya.util.SqlSessionUtil;
import org.apache.ibatis.session.SqlSession;
import org.junit.Test;

import java.util.HashMap;
import java.util.List;

public class CarMapperTest {
	@Test
	public void insertThroughMap(){
		SqlSession sqlSession = SqlSessionUtil.openSession();
		HashMap hashMap = new HashMap();
		hashMap.put("car_num", 12);
		hashMap.put("brand", "NMSLA");
		sqlSession.insert("insertCar", hashMap);
		sqlSession.commit();
		sqlSession.close();
	}

	@Test
	public void insertThroughPojo(){
		Car car = new Car(null, "189", "Tencent", 20.6, "2020-11-11", "zxlnmslcar");
		SqlSession sqlSession = SqlSessionUtil.openSession();
		sqlSession.insert("insertCar", car);
		sqlSession.commit();
		sqlSession.close();
	}

	@Test
	public void deleteTest(){
		SqlSession sqlSession = SqlSessionUtil.openSession();
		sqlSession.delete("deleteCarById", 177);
		sqlSession.commit();
		sqlSession.close();
	}

	@Test
	public void insertThroughPojo2(){
		Car car = new Car(null, "196", "Olia", 12.5, "2020-12-12", "sanlunche");
		SqlSession sqlSession = SqlSessionUtil.openSession();
		sqlSession.insert("insertCar", car);
		sqlSession.commit();
		sqlSession.close();
	}

	@Test
	public void updateTest(){
		Car car = new Car(178L, "114511", "nmsl", 11.0, "2020-12-12", "nmslcaasd");
		SqlSession sqlSession = SqlSessionUtil.openSession();
		sqlSession.update("updateCarById", car);
		sqlSession.commit();
		sqlSession.close();
	}

	@Test
	public void testSelectCar(){
		SqlSession sqlSession = SqlSessionUtil.openSession();
		Object car = sqlSession.selectOne("selectCarById", 178);
		System.out.println(car);
	}

	@Test
	public void testSelectAll(){
		SqlSession sqlSession = SqlSessionUtil.openSession();
		List<Object> cars = sqlSession.selectList("selectAll");
		cars.forEach(System.out::println);
	}
}
