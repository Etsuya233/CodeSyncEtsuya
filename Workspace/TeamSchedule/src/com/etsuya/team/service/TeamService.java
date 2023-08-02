package com.etsuya.team.service;

import com.etsuya.team.domain.Architect;
import com.etsuya.team.domain.Designer;
import com.etsuya.team.domain.Employee;
import com.etsuya.team.domain.Programmer;

import static com.etsuya.team.service.Status.BUSY;
import static com.etsuya.team.service.Status.FREE;


public class TeamService {
	private static int counter = 1;
	private final int MAX_MEMBER = 6;
	private Programmer[] team = new Programmer[MAX_MEMBER];
	public int total = 0;
	private int programmer = 0, designer = 0, architect = 0;

	public Programmer[] getTeam(){
		return team;
	}

	public void addMember(Employee e) throws TeamException{
		if(total == MAX_MEMBER) throw new TeamException("成员已满，无法添加");
		if(!(e instanceof Programmer)) throw new TeamException("该成员不是开发人员，无法添加");
		if(isExist(((Programmer) e).getMemberId())) throw new TeamException("该员工已在本开发团队中");
		if(((Programmer)e).getStatus().equals("BUSY")) throw new TeamException("该员工已是某团队成员");
		if(((Programmer)e).getStatus().equals("VOCATION")) throw new TeamException("该员正在休假，无法添加");
		if(e instanceof Architect){
			if(architect < 1) architect++;
			else throw new TeamException("团队中至多只能有一名架构师");
		} else if(e instanceof Designer){
			if(designer < 2) designer++;
			else throw new TeamException("团队中至多只能有两名设计师");
		} else {
			if(programmer < 3) programmer++;
			else throw new TeamException("团队中至多只能有三名程序员");
		}
		team[total] = (Programmer) e;
		team[total].setMemberId(counter);
		team[total].setStatus(BUSY);
		total ++;
		counter ++;
	}

	public void removeMember(int memberId) throws TeamException{
		int loc = 0;
		for(; loc < total; loc++){
			if(team[loc].getMemberId() == memberId) break;
		}
		if(loc >= total) throw new TeamException("找不到指定memberId的员工，删除失败");
		team[loc].setStatus(FREE);
		if(team[loc] instanceof Architect){
			architect--;
		} else if(team[loc] instanceof Designer){
			designer--;
		} else {
			programmer--;
		}
		for(int i = loc; i < total - 1; i++){
			team[i] = team[i + 1];
		}
		total --;
	}

	private boolean isExist(int memberId){
		for(int i = 0; i < total; i++){
			if(team[i].getMemberId() == memberId) return true;
		}
		return false;
	}
}
