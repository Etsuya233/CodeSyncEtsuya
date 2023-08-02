package com.etsuya.study2;

public class AbstractTest {
	public static void main(String[] args) {

	}
}

abstract class Employee{
	String name;
	int id;
	int salary;

	public Employee(){

	}
	public Employee(String name, int id, int salary){
		this.name = name;
		this.id = id;
		this.salary = salary;
	}

	abstract public void work();
}

class CommonEmployee extends Employee{
	int bonus;
	public CommonEmployee(){

	}
	public CommonEmployee(String name, int id, int salary){
		super(name, id, salary);
	}

	public void work(){
		System.out.println("Common Employee is working.");
	}
}