package com.etsuya.cm;

public class Customer {
	private String name;
	private char gender;
	private int age;
	private String phone;
	private String email;

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public char getGender() {
		return gender;
	}

	public void setGender(char gender) {
		if(gender == '男' || gender == '女'){
			this.gender = gender;
		} else {
			this.gender = '男';
			System.out.println("性别输入错误，已设为默认值男！");
		}
	}

	public int getAge() {
		return age;
	}

	public void setAge(int age) {
		if(age > 0){
			this.age = age;
		} else {
			this.age = 0;
			System.out.println("年龄输入错误，已设为默认值0！");
		}
	}

	public String getPhone() {
		return phone;
	}

	public void setPhone(String phone) {
		this.phone = phone;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}
}
