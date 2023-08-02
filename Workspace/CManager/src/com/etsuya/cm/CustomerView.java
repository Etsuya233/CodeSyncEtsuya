package com.etsuya.cm;

import com.etsuya.cm.CustomerList;

public class CustomerView {
	public static void main(String[] args) {
		CustomerList list = new CustomerList(10);
		enterMainMenu(list);
	}

	public static void enterMainMenu(CustomerList list){
		boolean loopFlag = true;
		while(loopFlag){
			System.out.println("-----------------客户信息管理软件-----------------\n");
			System.out.println("                 1 添 加 客 户");
			System.out.println("                 2 修 改 客 户");
			System.out.println("                 3 删 除 客 户");
			System.out.println("                 4 客 户 列 表");
			System.out.println("                 5 退      出\n\n");
			System.out.print("                 请选择（1-5）：");
			char choise = CMUtility.readMenuSelection();
			System.out.println();
			switch (choise) {
				case '1' -> addNewCustomer(list);
				case '2' -> modifyCustomer(list);
				case '3' -> deleteCustomer1(list);
				case '4' -> listCustomer(list);
				case '5' -> loopFlag = false;
				default -> {
					System.out.println("检测到错误的输入，请再试一次！");
					continue;
				}
			}
		}
		System.out.println("感谢你的使用！");
	}

	private static void addNewCustomer(CustomerList list){
		System.out.println("---------------------添加客户---------------------");
		Customer cust = new Customer();
		System.out.print("姓名：");
		cust.setName(CMUtility.readString(15,"无名氏"));
		System.out.print("性别：");
		cust.setGender(CMUtility.readChar());
		System.out.print("年龄：");
		cust.setAge(CMUtility.readInt());
		System.out.print("电话：");
		cust.setPhone(CMUtility.readString(15));
		System.out.print("邮箱：");
		cust.setEmail(CMUtility.readString(20));
		System.out.println();
		if(list.addCustomer(cust)){
			System.out.println("---------------------添加成功---------------------");
		} else {
			System.out.println("---------------------添加失败---------------------");
		}

	}

	private static void modifyCustomer(CustomerList list){
		System.out.println("---------------------修改客户---------------------");
		System.out.print("请选择待修改客户编号(-1退出)：");
		int index = CMUtility.readInt();
		if(index > 0 && index <= list.getTotal()){
			Customer cust = new Customer();
			System.out.print("姓名（" + list.getCustomer(index).getName() + "）：");
			list.getCustomer(index).setName(CMUtility.readString(15,list.getCustomer(index).getName()));
			System.out.print("性别（" + list.getCustomer(index).getGender() + "）：");
			list.getCustomer(index).setGender(CMUtility.readChar(list.getCustomer(index).getGender()));
			System.out.print("年龄（" + list.getCustomer(index).getAge() + "）：");
			list.getCustomer(index).setAge(CMUtility.readInt(list.getCustomer(index).getAge()));
			System.out.print("电话（" + list.getCustomer(index).getPhone() + "）：");
			list.getCustomer(index).setPhone(CMUtility.readString(15,list.getCustomer(index).getPhone()));
			System.out.print("邮箱（" + list.getCustomer(index).getEmail() + "）：");
			list.getCustomer(index).setEmail(CMUtility.readString(15,list.getCustomer(index).getEmail()));
			list.replaceCustomer(index, cust);
			System.out.println("---------------------修改完成---------------------");
		} else if(index == -1) {
			System.out.println("---------------------退出修改---------------------");
		} else {
			System.out.println("---------------------修改失败---------------------");
		}
	}

	private static void deleteCustomer1(CustomerList list){
		System.out.println("---------------------删除客户---------------------");
		System.out.print("请选择待删除客户编号(-1退出)：");
		int index = CMUtility.readInt();
		if(index > 0 && index <= list.getTotal()){
			System.out.println("确认是否删除(Y/N)：");
			char choise = CMUtility.readChar('N');
			if(choise == 'Y'){
				list.deleteCustomer(index);
				System.out.println("---------------------删除成功---------------------");
			} else {
				System.out.println("---------------------删除失败---------------------");
			}
		} else {

		}
	}

	private static void listCustomer(CustomerList list){
		System.out.println("---------------------客户列表---------------------");
		System.out.println("编号	姓名		性别	年龄	电话		邮箱");
		for(int i = 1; i <= list.getTotal(); i++){
			System.out.println(i + "\t" + list.getCustomer(i).getName() + "\t");
		}
		System.out.println("---------------------列出完成---------------------");
	}

}
