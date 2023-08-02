package com.etsuya.system.bean;

/**
 * ClassName: Emp
 * Package: com.etsuya.system.bean
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/5/5 16:25
 * @Version: 1.0
 */
public class Emp {
	private int id, age;
	private String name;

	public Emp() {
	}

	public Emp(int id, int age, String name) {
		this.id = id;
		this.age = age;
		this.name = name;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
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
}
