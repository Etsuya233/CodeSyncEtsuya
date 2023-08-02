package com.etsuya.team.view;

import com.etsuya.team.domain.*;
import com.etsuya.team.service.NameListService;
import com.etsuya.team.service.TeamException;
import com.etsuya.team.service.TeamService;


public class TeamView {
	public static void main(String[] args) {
		TeamView a = new TeamView();
		while(true){
			a.enterMainMenu();
		}
	}

	private NameListService listSvc = new NameListService();
	private TeamService teamSvc = new TeamService();

	public void enterMainMenu(){
		System.out.printf("-------------------------------------开发团队调度软件--------------------------------------\n");
		listAllEmployee();
		System.out.println("----------------------------------------------------------------------------------------------");
		System.out.print("1-团队列表  2-添加团队成员  3-删除团队成员 4-退出   请选择(1-4)：");
		int select = TSUtility.readMenuSelection();
		switch(select){
			case '1': getTeam();break;
			case '2': addMember();break;
			case '3':deleteMember();break;
		}

	}

	private void listAllEmployee(){
		Employee[] arr = listSvc.getAllEmployee();
		System.out.printf("ID\t\t姓名\t\t年龄\t工资\t\t职位\t\t状态\t\t奖金\t\t股票\t\t领用设备\n");
		for(int i = 0; i < listSvc.getAllEmployee().length; i++){
			System.out.printf("%d\t\t%s\t\t%d\t", arr[i].getId(), arr[i].getName(), arr[i].getAge(), arr[i].getSalary());
			int career = listSvc.career(arr[i]);
			switch(career){
				case 1:
					Programmer temp = (Programmer) arr[i];
					System.out.printf("程序员\t\t%s\t\t\t\t\t\t%s", temp.getStatus(), temp.getEquipment().getDescription());
					break;
				case 2:
					Designer temp1 = (Designer) arr[i];
					System.out.printf("设计师 %s %.1f        %s", temp1.getStatus(), temp1.getBonus(), temp1.getEquipment().getDescription());
					break;
				case 3:
					Architect temp2 = (Architect) arr[i];
					System.out.printf("构架师 %s %.1f  %d   %s", temp2.getStatus(), temp2.getBonus(), temp2.getStock(), temp2.getEquipment().getDescription());
					break;
			}
			System.out.println();
		}
	}

	private void getTeam(){
		Programmer[] arr = teamSvc.getTeam();
		if(teamSvc.total == 0) System.out.print("无成员这里");
		else {
			for (int i = 0; i < teamSvc.total; i++) {
				System.out.printf("%s\t %d\t%d\n", arr[i].getName(), arr[i].getMemberId(), arr[i].getId());
			}
		}
		System.out.println();
	}

	private void addMember(){
		System.out.println("---------------------添加成员---------------------");
		System.out.printf("请输入要添加的员工ID: ");
		int id = TSUtility.readInt();
		try {
			teamSvc.addMember(listSvc.getEmployee(id));
		} catch (TeamException e){
			System.out.println(e.getMessage());
		}
	}

	private void deleteMember(){
		System.out.println("---------------------添加成员---------------------");
		System.out.printf("请输入要杀掉的员工MemberID: ");
		int id = TSUtility.readInt();
		try {
			teamSvc.removeMember(id);
		} catch (TeamException e){
			System.out.println(e.getMessage());
		}
	}
}
