package com.etsuya.team.service;

public class TeamException extends Exception{
	@java.io.Serial
	static final long serialVersionUID = -338751699948L;

	public TeamException(){
		super();
	}

	public TeamException(String msg){
		super(msg);
	}
}
