package com.etsuya.cm;

import java.util.Arrays;

public class CustomerList {

	public static void main(String[] args) {

//		CustomerList list = new CustomerList(10);
//		Customer cust1 = new Customer();
//		cust1.setAge(1);
//		Customer cust2 = new Customer();
//		cust2.setAge(2);
//		Customer cust3 = new Customer();
//		cust3.setAge(3);
//		Customer cust4 = new Customer();
//		cust4.setAge(4);
//		list.addCustomer(cust1);
//		list.addCustomer(cust2);
//		list.addCustomer(cust3);
//		list.addCustomer(cust4);
//
//		System.out.println(list.getCustomer(3).getAge());
//		System.out.println(list.getCustomer(4).getAge());
//
//		list.deleteCustomer(3);
//
//		System.out.println(list.getCustomer(3).getAge());
//		System.out.println(list.getCustomer(4).getAge());


	}


	private Customer[] customers;
	private int total = 0;

	public CustomerList(int totalCustomer){
		customers = new Customer[totalCustomer];
	}

	public boolean addCustomer(Customer customer){
		if(total < customers.length){
			customers[total++] = customer;
			return true;
		} else {
			return false;
		}
	}
	public boolean replaceCustomer(int index, Customer cust){
		if(index > 0 && index <= customers.length){
			customers[index - 1] = cust;
			return true;
		} else {
			return false;
		}
	}
	public boolean deleteCustomer(int index){
		if(index > 0 && index <= total){
			Customer[] after = Arrays.copyOf(customers, customers.length);
			for(int i = index; i < total; i++){
				customers[index - 1] = after[index];

			}
			customers[total - 1] = null;
			total --;
			return true;
		} else {
			return false;
		}

	}
	public Customer[] getAllCustomers(){
		Customer[] after = Arrays.copyOf(customers, customers.length);
		return after;
	}
	public Customer getCustomer(int index){
		return customers[index - 1];
	}
	public int getTotal(){
		return total;
	}
}
