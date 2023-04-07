package com.etsuya.java5;

/**
 * ClassName: ReflectionTest
 * Package: com.etsuya.java5
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/22 22:50
 * @Version: 1.0
 */
public class ReflectionTest {
	public static void main(String[] args) {
		Person tom = new Person("Tom", 21);

		//1，直接通过类
		Class clazz = Person.class;
		//2，通过实例对象
		Class clazz1 = tom.getClass();
		//3，是用Class类的forName(String className)静态方法（常用）
		try {
			Class clazz2 = Class.forName("com.etsuya.java5.Person");
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
		//4，其他
		try {
			Class clazz3 = ClassLoader.getSystemClassLoader().loadClass("com.etsuya.java5.Person");
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}

		int[][] arr1 = new int[3][3];
		int[] arr = new int[3];
		Class c1 = arr1.getClass();
		Class c2 = arr.getClass();
		System.out.println(c1 == c2);
	}
}

class Person<String>{
	String name;
	int age;
	String innerVoice;
	static int grade = 12;

	public Person() {
	}

	public Person(String name, int age) {
		this.name = name;
		this.age = age;
	}

	@MyAnnotation(msg = "this is what i say when im about to cum")
	private int fuck(){
		System.out.println("I'm gonna cum!!!");
		return 12;
	}

	public void say(String str, int times){
		for(int i = 0; i < times; i++){
			System.out.println(str);
		}
	}

	public static void sleep(){
		System.out.println("idk why its a static method");
	}
}