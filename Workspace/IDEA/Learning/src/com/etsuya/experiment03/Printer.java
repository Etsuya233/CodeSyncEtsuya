package com.etsuya.experiment03;

public abstract class Printer {
	final int MAX_SIZE = 100;
	protected String[] buffer = new String[MAX_SIZE];

	public Printer() {
	}

	public abstract void load(String[] contents) throws Exception;

	public abstract void print();
}