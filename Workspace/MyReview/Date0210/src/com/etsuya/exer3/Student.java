package com.etsuya.exer3;

/**
 * ClassName: Student
 * Package: com.etsuya.exer3
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/2/28 21:24
 * @Version: 1.0
 */
public class Student {
	private String name, id;
	private Gender gender;

	public Student(String name, String id, Gender gender) {
		this.name = name;
		this.id = id;
		this.gender = gender;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public Gender getGender() {
		return gender;
	}

	public void setGender(Gender gender) {
		this.gender = gender;
	}

	@Override
	public String toString() {
		return "Student{" +
				"name='" + name + '\'' +
				", id='" + id + '\'' +
				", gender=" + gender +
				'}';
	}
}
