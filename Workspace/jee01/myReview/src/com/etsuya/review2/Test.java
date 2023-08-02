package com.etsuya.review2;

public class Test {
	public static void main(String[] args) {
		TestClass1 o1 = new TestClass1();
		TestClass2 o2 = (TestClass2)o1;
	}
}

class TestClass1{
	int a;
	int b;
	
	public void say(){
		System.out.println("Tobacco");
	}
}

class TestClass2 extends TestClass1{
	
}