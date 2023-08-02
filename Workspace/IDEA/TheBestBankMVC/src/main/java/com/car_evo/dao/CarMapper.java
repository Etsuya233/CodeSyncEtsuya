package com.car_evo.dao;

import com.car_evo.pojo.Car;

public interface CarMapper {
	Car qqselectById(Long id);

	int insert(Car car);
}
