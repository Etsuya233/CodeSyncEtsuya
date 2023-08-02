package com.etsuya.java7;

import org.junit.Test;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.*;
import java.util.function.Consumer;
import java.util.function.Function;
import java.util.function.Supplier;
import java.util.stream.Collectors;
import java.util.stream.Stream;

/**
 * ClassName: ReferenceTest
 * Package: com.etsuya.java7
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/26 22:21
 * @Version: 1.0
 */
public class ReferenceTest {
	@Test
	public void test1(){
	    //1,默认
		Consumer<String> c1 = new Consumer<String>() {
			@Override
			public void accept(String s) {
				System.out.println(s);
			}
		};
		//2,λ表达式
		Consumer<String> c2 = s -> System.out.println(s);
		//3,方法引用:
		//Consumer需要实现的抽象方法形参只有一个String且返回void，而方法体里的形参与返回值与前面的相同，则可使用方法引用
		Consumer<String> c3 = System.out::println;

		c3.accept("nmsl method reference");
	}
	
	@Test
	public void test2(){
		Employee employee = new Employee("Mike", 23, 10001);
		//1,
		Supplier<Integer> s1 = new Supplier<Integer>() {
			@Override
			public Integer get() {
				return employee.getSalary();
			}
		};
		//2,
		Supplier<Integer> s2 = () -> employee.getSalary();
		//3,Supplier需要实现的抽象方法无形参且有一个Integer的返回值，而方法体里的语句也如此
		Supplier<Integer> s3 = employee::getSalary;
	}
	
	@Test
	public void test3(){
		//1,
	    Comparator<Integer> c1 = new Comparator<Integer>() {
			@Override
			public int compare(Integer o1, Integer o2) {
				return Integer.compare(o1, o2);
			}
		};
		//2,
		Comparator<Integer> c2 = (o1, o2) -> Integer.compare(o1, o2);
		//3,
		Comparator<Integer> c3 = Integer::compare;
	}

	@Test
	public void test4(){
	    //1,
		Comparator<Integer> c1 = new Comparator<Integer>() {
			@Override
			public int compare(Integer o1, Integer o2) {
				//抽象方法有两个参数，第一个对应下面方法的调用者，剩下的对应下面方法的参数
				return o1.compareTo(o2);
			}
		};
		//2,
		Comparator<Integer> c2 = (o1, o2) -> o1.compareTo(o2);
		//3,
		Comparator<Integer> c3 = Integer::compareTo;
	}
	
	@Test
	public void test5(){
		//1,
	    Supplier<Employee> newEmployee = new Supplier<Employee>() {
			@Override
			public Employee get() {
				return new Employee();
			}
		};
		//2,
		Supplier<Employee> newEmployee1 = () -> new Employee();
		//3,
		Supplier<Employee> newEmployee2 = Employee::new;
	}

	@Test
	public void test6(){
	    //1,
		Function<String, Employee> func1 = new Function<String, Employee>() {
			@Override
			public Employee apply(String s) {
				return new Employee(s);
			}
		};
		//2,
		Function<String, Employee> func2 = str -> new Employee(str);
		//3,
		Function<String, Employee> func3 = Employee::new;
	}
	
	@Test
	public void test7(){
	    Function<Integer, String[]> func1 = String[]::new;
		String[] arr = func1.apply(12);

	}
	
	@Test
	public void test8(){
		EmployeeManager employeeManager = new EmployeeManager();
		ArrayList<Employee> list = employeeManager.all;
		//在列表中输出年龄大于二十的，且跳过前两个
		list.stream().filter(employee -> employee.getAge() > 20).skip(2).forEach(System.out::println);
		//取出列表中的年龄并进行筛选并输出
		list.stream().map(Employee::getAge).filter(age -> age > 20).forEach(System.out::println);

	}
	
	@Test
	public void test9(){
		Stream<Double> stream = Stream.generate(Math::random);
		stream.limit(20).forEach(System.out::println);
	}

	@Test
	public void test10(){
		//输出大于等于四小于等于八的数字
		System.out.println(Stream.of(0, 1, 2, 3, 4, 5, 6, 7, 8, 9).filter(num -> num <= 8 && num >= 4).count());
		//输出1+2+...+10的和
		Integer reduce = Stream.of(1, 2, 3, 4, 5, 6, 7, 8, 9, 10).reduce(0, (t1, t2) -> t1 + t2);
		System.out.println(reduce);
		//求最大值
		System.out.println(Stream.of(1, 33, 22, 55, 2, 44, 666, 222).reduce(-1000, (t1, t2) -> (t1 > t2) ? t1 : t2));

	}
	
	@Test
	public void test11(){
		ArrayList<String> a = new ArrayList<>();
		a.add("迪丽热巴");
		a.add("俺俩");
		a.add("丽热");
		a.add("迪丽");
		a.add("巴");
		a.add("迪丽而且我热巴");
		a.add("丽werw热巴");
		a.add("丽热巴");

		List<String> collect = a.stream().limit(3).collect(Collectors.toList());
		collect.forEach(System.out::println);

		List<String> strings = a.stream().filter(str -> str.charAt(0) == 'a').skip(2).toList();

		List<String> strings1 = Stream.concat(collect.stream(), strings.stream()).toList();
		List<Person> people = strings1.stream().map(Person::new).toList();

	}

	@Test
	public void test12() {
		//JDK7以前：
		FileInputStream fis = null;
		try {
			fis = new FileInputStream("file.txt");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} finally {
			try {
				if (fis != null) {
					fis.close();
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		//JDK7及以后：离开try-catch后会自动关闭实现了AutoClosable接口的类
		try (FileInputStream fis1 = new FileInputStream("file.txt");) {
			fis.read();
		} catch (IOException e) {
			e.printStackTrace();
		}
		//JDK9及以后：
		FileInputStream fis2;
		FileOutputStream fos2;
		try {
			fis2 = new FileInputStream("file.txt");
			fos2 = new FileOutputStream("file.txt");
		} catch (FileNotFoundException e) {
			throw new RuntimeException(e);
		}
		try (fis2; fos2) {

		} catch (IOException e) {
			e.printStackTrace();
		}


	}


	@Test
	public void test13(){
		//1.局部变量的实例化
		var list = new ArrayList<String>();

		var set = new LinkedHashSet<Integer>();

		//2.增强for循环中的索引
		for (var v : list) {
			System.out.println(v);
		}

		//3.传统for循环中
		for (var i = 0; i < 100; i++) {
			System.out.println(i);
		}

		//4. 返回值类型含复杂泛型结构
		var iterator = set.iterator();
		//Iterator<Map.Entry<Integer, Student>> iterator = set.iterator();


	}

	@Test
	public void test15(){
	    Fruit fruit = Fruit.ORANGE;
		int ret = switch(fruit){
			case ORANGE, BANANA -> 1;
			case APPLE -> 2;
			case MANGO -> 3;
			default -> 4;
		};
		//or
		int ret1 = switch(fruit){
			case ORANGE, BANANA:
				yield 1;
			case APPLE:
				yield 2;
			case MANGO:
				yield 3;
			default:
				yield 4;
		};

//		Employee a = new Employee();
//		Object o = a;
//		switch(o){
//			case Employee e -> System.out.println("Employee!");
//			case EmployeeManager e -> System.out.println("EmployeeManager");
//			case Integer e -> System.out.println("Integer!");
//		}
	}
	
	@Test
	public void test16(){
		String s = """
    a i u e o
    ka ki ku ke ko
				""";
		System.out.println(s);

	}

	@Test
	public void test17(){

	}
}

class Person{
	private String name;

	public Person() {
	}

	public Person(String name) {
		this.name = name;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	@Override
	public boolean equals(Object o) {
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;
		Person person = (Person) o;
		return Objects.equals(name, person.name);
	}

	@Override
	public int hashCode() {
		return Objects.hash(name);
	}
}

record Point(int x, int y){
	Point(){
		this(0, 0);
	}
}
