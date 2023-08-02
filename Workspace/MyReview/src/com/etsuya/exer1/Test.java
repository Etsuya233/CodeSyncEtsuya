package com.etsuya.exer1;

public class Test {
	public static void main(String[] args) {

	}
}

abstract class Employee{
	private String name, number;
	private MyDate birthday;

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getNumber() {
		return number;
	}

	public void setNumber(String number) {
		this.number = number;
	}

	public MyDate getBirthday() {
		return birthday;
	}

	public void setBirthday(MyDate birthday) {
		this.birthday = birthday;
	}

	abstract public double earnings();
	abstract public String toString();
}

class SalariedEmployee extends Employee{
	private double monthlySalary;

	public double earnings(){
		return monthlySalary;
	}

	public String toString(){
		return "Name: " + getName() + "; Number: " + getNumber() + "; Birthday: " + getBirthday();
	}
}

class MyDate{
	private int year, month, day;

	public MyDate(int year, int month, int day) {
		this.year = year;
		this.month = month;
		this.day = day;
	}

	public int getYear() {
		return year;
	}

	public void setYear(int year) {
		this.year = year;
	}

	public int getMonth() {
		return month;
	}

	public void setMonth(int month) {
		this.month = month;
	}

	public int getDay() {
		return day;
	}

	public void setDay(int day) {
		this.day = day;
	}

	public String toDateString(){
		return year + "/" + month + "/" + day;
	}
}

class HourlyEmployee extends Employee{
	private double wage;
	private int hour;

	@Override
	public double earnings() {
		return wage * hour;
	}

	public String toString(){
		return "Name: " + getName() + "; Number: " + getNumber() + "; Birthday: " + getBirthday();
	}
}

class PayrollSystem{
	Employee arr[] = new Employee[10];

	public void Travesal(){
		for(int i = 0; arr[i] != null; i++){
			System.out.println(arr[i].toString());
		}
	}


}