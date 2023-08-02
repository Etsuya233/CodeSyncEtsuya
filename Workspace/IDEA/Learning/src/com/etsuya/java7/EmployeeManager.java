package com.etsuya.java7;

import java.util.ArrayList;
import java.util.function.Predicate;

/**
 * ClassName: EmployeeManager
 * Package: com.etsuya.java7
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/26 15:20
 * @Version: 1.0
 */
public class EmployeeManager {
	ArrayList<Employee> all;

	public EmployeeManager() {
		all = new ArrayList<>();
		all.add(0, new Employee("Mike", 23, 10001));
		all.add(1, new Employee("Alice", 23, 10));
		all.add(2, new Employee("Joe", 30, 100011));
		all.add(3, new Employee("Taylor", 34, 123101));
		all.add(4, new Employee("Ariana", 28, 1001));
		all.add(5, new Employee("Adele", 33, 101));
	}

	ArrayList<Employee> get(Predicate<Employee> p){
		ArrayList<Employee> ret = new ArrayList<>();
		all.forEach(employee -> {
			if(p.test(employee)) ret.add(employee);
		});
		return ret;
	}
}
