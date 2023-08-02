package com.etsuya.java7;

import org.junit.Test;

import java.lang.reflect.Array;
import java.util.*;
import java.util.function.Supplier;

/**
 * ClassName: LambdaTest
 * Package: com.etsuya.java7
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/26 13:24
 * @Version: 1.0
 */
public class LambdaTest {
	@Test
	public void test(){
		List<String> list = Arrays.asList("12", "42", "what?", "pixel");
		ArrayList<String> arrayList = new ArrayList<>(list);

		list.forEach((str) -> System.out.println(str.toUpperCase()));

		list.forEach(str -> System.out.println(str));

		callSomething(() -> System.out.println("fucku bitch"));
		callSomething(() -> System.out.println("nmsl"));
	}

	public void callSomething(Call call){
		call.call();
	}
	
	@Test
	public void test2(){
		HashMap<Integer, Employee> my = new HashMap<>();
		my.put(0, new Employee("Mike", 23, 10001));
		my.put(1, new Employee("Alice", 23, 10));
		my.put(2, new Employee("Joe", 30, 100011));
		my.put(3, new Employee("Taylor", 34, 123101));
		my.put(4, new Employee("Ariana", 28, 1001));
		my.put(5, new Employee("Adele", 33, 101));

		my.forEach((a, b) -> System.out.println(a + " -> " + b));
		my.replaceAll((a, b) -> {
			if(b.getSalary() < 10000){
				b.setSalary(10000);
			}
			return b;
		});
		my.forEach((a, b) -> System.out.println(a + " -> " + b));

	}

	@Test
	public void test3(){
	    EmployeeManager em = new EmployeeManager();
		ArrayList<Employee> employees = em.get(employee -> {
			if (employee.getSalary() > 10000) return true;
			return false;
		});
		for(Employee employee: employees){
			System.out.println(employee);
		}
	}
}

@FunctionalInterface
interface Call{
	public void call();
}