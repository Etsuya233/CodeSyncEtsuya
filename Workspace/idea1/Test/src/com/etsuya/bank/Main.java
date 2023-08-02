package com.etsuya.bank;

public class Main {
	public static void main(String[] args) {
		Bank BOC = new Bank();
		BOC.addCustomer("Ariana", "Grande");
		BOC.addCustomer("Taylor", "Swift");
		System.out.println(BOC.getNumberOfCustomers());
		System.out.println(BOC.getCustomer(1).getFirstName());
	}
}

class Account{
	private int id;
	private double balance;
	private double annualInterestRate;

	public Account(int id, double balance, double annualInterestRate){
		this.id =id;
		this.balance = balance;
		this.annualInterestRate = annualInterestRate;
	}

	public int getId(){
		return id;
	}

	public double getBalance(){
		return balance;
	}

	public double getAnnualInterestRate(){
		return annualInterestRate;
	}

	public void setId(int id){
		this.id = id;
	}

	public void setBalance(double balance){
		this.balance = balance;
	}

	public void setAnnualInterestRate(double annualInterestRate){
		this.annualInterestRate = annualInterestRate;
	}

	public void withdraw(double amount){
		if(amount > balance){
			System.out.println("Fail to withdraw! U R poor!");
		} else {
			balance -= amount;
			System.out.println("Withdraw successfully：" + amount);
		}
	}

	public void deposit(double amount){
		balance += amount;
		System.out.println("Deposit successfully: " + amount);
	}
}

class Customer{
	private String firstName;
	private String lastName;
	private Account account;

	public Customer(String f, String l){
		firstName = f;
		lastName = l;
	}

	public String getFirstName(){
		return firstName;
	}

	public String getLastName(){
		return lastName;
	}

	public Account getAccount(){
		return account;
	}

	public void setAccount(Account account){
		this.account = account;
	}
}

class Bank{
	private Customer[] customers = new Customer[10];
	int numberOfCustomers = 0;

	public Bank(){

	}

	public void addCustomer(String f, String l){
		Customer temp = new Customer(f, l);
		numberOfCustomers++;
		customers[numberOfCustomers - 1] = temp;
	}

	public int getNumberOfCustomers(){
		return numberOfCustomers;
	}

	public Customer getCustomer(int index){
		return customers[index];
	}
}