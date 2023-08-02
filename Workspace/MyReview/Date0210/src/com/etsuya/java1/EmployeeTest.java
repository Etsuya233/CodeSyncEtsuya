package com.etsuya.java1;

/**
 * ClassName: EmployeeTest
 * Package: com.etsuya.java1
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/2/14 22:22
 * @Version: 1.0
 */
public class EmployeeTest {
	public static void main(String[] args) {
		Employee xiaoMing = new Employee("Xiao Ming", 23, EmployeeStatus.FREE);
		xiaoMing.show();
		@SuppressWarnings("unused") int num = 0;
	}
}

class Employee{
	private String name;
	private int age;
	private EmployeeStatus status;


	public Employee(String name, int age, EmployeeStatus status) {
		this.name = name;
		this.age = age;
		this.status = status;
	}

	void show(){
		System.out.println(status.toString() + " " + status.description);
	}
}

enum EmployeeStatus implements MustHaveDescription{
	BUSY("我很忙"),
	FREE("我免费了");

	String description;

	EmployeeStatus(String description){
		this.description = description;
	}

	@Override
	public void show() {
		System.out.println("Employee: " + description);
	}

	public String toString(){
		return this.name();
	}
}

interface MustHaveDescription{

	void show();
}