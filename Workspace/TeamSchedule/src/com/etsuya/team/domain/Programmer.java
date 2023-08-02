package com.etsuya.team.domain;

import com.etsuya.team.service.Status;

import static com.etsuya.team.service.Status.*;

public class Programmer extends Employee{
	int memberId;
	Status status = FREE;
	Equipment equipment;

	public Programmer(int id, int age, double salary, String name, Equipment equipment) {
		super(id, age, salary, name);
		this.equipment = equipment;
	}

	public int getMemberId() {
		return memberId;
	}

	public void setMemberId(int memberId) {
		this.memberId = memberId;
	}

	public Status getStatus() {
		return status;
	}

	public void setStatus(Status status) {
		this.status = status;
	}

	public Equipment getEquipment() {
		return equipment;
	}

	public void setEquipment(Equipment equipment) {
		this.equipment = equipment;
	}
}
