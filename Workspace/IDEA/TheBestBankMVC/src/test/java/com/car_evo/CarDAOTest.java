package com.car_evo;

import com.bank.utils.SqlSessionUtil;
import com.car_evo.dao.CarMapper;
import com.car_evo.pojo.Car;
import org.junit.Test;

public class CarDAOTest {
	@Test
	public void testAddCar(){
		CarMapper carMapper = SqlSessionUtil.openSession().getMapper(CarMapper.class);
		Car car = new Car(10082L, "粤你妈10010", "习近平", 12315.11, "2020-12-12", "11路");
		carMapper.insert(car);
		Car car1 = carMapper.selectById(10082L);
		System.out.println(car1);
	}
}
