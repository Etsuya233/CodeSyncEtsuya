import org.junit.Test;

import java.util.*;

/**
 * ClassName: ${NAME}
 * Package:
 * Description:
 *
 * @Author: Etsuya
 * @Create: ${DATE} ${TIME}
 * @Version: 1.0
 */
public class Main {
	public static void main(String[] args) {
		//示例1：
		HashMap<String, Integer> hashMap1 = new HashMap<>();
		HashMap<String, Integer> hashMap = new HashMap<>(); //jdk7新特性，类型推断

		//示例2：
		Set<Map.Entry<String, Integer>> entries = hashMap.entrySet(); //注意返回值类型，Entry是个内部类，Entry也有泛型
		Iterator<Map.Entry<String, Integer>> iterator = entries.iterator();
		while(iterator.hasNext()){
			Map.Entry<String, Integer> next = iterator.next();
			String key = next.getKey();
			Integer value = next.getValue();
		}

		//关于类型推断，在jdk10中引入了一个新特性：var
		Iterator<Map.Entry<String, Integer>> iterator1 = entries.iterator();
		var iterator2 = entries.iterator();
		//这样可以提高阅读性，因为类型太长，不过不能随便用
	}

	@Test
	public void test(){
		Employee e1 = new Employee(12, "Tom");
		Employee e2 = new Employee(14, "Jerry");
		Employee e3 = new Employee(11, "Rose");
		TreeSet<Employee> employees = new TreeSet<>();
		employees.add(e1);
		employees.add(e2);
		employees.add(e3);
		System.out.println(employees);
		Comparator<Employee> comparator = new Comparator<>() {
			@Override
			public int compare(Employee o1, Employee o2) {
				return o1.getName().compareTo(o2.getName());
			}
		};

	}
}

class Employee implements Comparable<Employee> {
	private int age;
	private String name;
	public Employee(){

	}

	public Employee(int age, String name) {
		this.age = age;
		this.name = name;
	}

	public int getAge() {
		return age;
	}

	public void setAge(int age) {
		this.age = age;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}


	@Override
	public int compareTo(Employee o) {
		return this.name.compareTo(o.name);
	}

	@Override
	public String toString() {
		return "Employee{" +
				"age=" + age +
				", name='" + name + '\'' +
				'}';
	}
}