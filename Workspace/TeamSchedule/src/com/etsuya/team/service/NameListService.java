package com.etsuya.team.service;

import com.etsuya.team.domain.*;

public class NameListService {
	private Employee[] employee;

	public NameListService(){
		employee = new Employee[Data.EMPLOYEES.length];
		for(int i = 0; i < Data.EMPLOYEES.length; i++){
			int id = Integer.parseInt(Data.EMPLOYEES[i][1]);
			int age = Integer.parseInt(Data.EMPLOYEES[i][3]);
			double salary = Double.parseDouble(Data.EMPLOYEES[i][4]);
			String name = Data.EMPLOYEES[i][2];
			switch(Integer.parseInt(Data.EMPLOYEES[i][0])){
				case Data.EMPLOYEE -> employee[i] = new Employee(id, age, salary, name);
				case Data.PROGRAMMER -> employee[i] = new Programmer(id, age, salary, name, createEquipment(i));
				case Data.DESIGNER -> employee[i] = new Designer(id, age, salary, name, createEquipment(i), Double.parseDouble(Data.EMPLOYEES[i][5]));
				case Data.ARCHITECT -> employee[i] = new Architect(id, age, salary, name, createEquipment(i), Double.parseDouble(Data.EMPLOYEES[i][5]), Integer.parseInt(Data.EMPLOYEES[i][6]));
			}
		}
	}

	public Equipment createEquipment(int index){
		int type = Integer.parseInt(Data.EQUIPMENTS[index][0]);
		Equipment ret = null;
		switch(type){
			case Data.PC -> ret = new PC(Data.EQUIPMENTS[index][1], Data.EQUIPMENTS[index][2]);
			case Data.NOTEBOOK -> ret = new NoteBook(Data.EQUIPMENTS[index][1], Integer.parseInt(Data.EQUIPMENTS[index][2]));
			case Data.PRINTER -> ret = new PC(Data.EQUIPMENTS[index][1], Data.EQUIPMENTS[index][2]);
		}
		return ret;
	}

	public Employee[] getAllEmployee(){
		return employee;
	}

	public Employee getEmployee(int id) throws TeamException{
		int i = 0;
		for(; i < employee.length; i++){
			if(employee[i].getId() == id) return employee[i];
		}
		throw new TeamException("找不到啊草泥马");
	}

	public int career(Employee e){
		if(e instanceof Architect){
			return 3;
		} else if(e instanceof Designer){
			return 2;
		} else if(e instanceof Programmer){
			return 1;
		} else return 0;
	}


}