package com.etsuya.exer1;

public class USBTest {
	public static void main(String[] args) {
		Computer leveno = new Computer("Leveno ThinkBook");
		WesternData myWork = new WesternData("High",512);
		leveno.dataTransfer(myWork);

	}
}

interface USB{
	int plugLength = 5;
	int plugWeight = 2;
	void start();
	void stop();
}

class Computer{
	private String model;

	public Computer(String model){
		this.model = model;
	}

	public String getModel() {
		return model;
	}

	public void setModel(String model) {
		this.model = model;
	}

	public void dataTransfer(USB device){
		device.start();
		System.out.println(this.model + ": USB devices data transferring...");
		device.stop();
	}
}

abstract class HardDisk implements USB{
	private String model;
	private int capacity;

	public String getModel() {
		return model;
	}

	public void setModel(String model) {
		this.model = model;
	}

	public int getCapacity() {
		return capacity;
	}

	public void setCapacity(int capacity) {
		this.capacity = capacity;
	}


	abstract public void start();
	abstract public void stop();
}

class WesternData extends HardDisk{

	public WesternData(String model, int capacity){
		this.setModel(model);
		this.setCapacity(capacity);
	}
	@Override
	public void start() {
		System.out.println("Western Data - " + getModel() + ": Starting services...");
	}

	@Override
	public void stop() {
		System.out.println("Western Data - " + getModel() + ": Stopping services...");
	}


}

