package com.etsuya.prac3;

import org.junit.Test;

public class Tesuto {
	@Test
	public void test1() {
		Object obj1 = true ? Integer.valueOf(12) : Double.valueOf(1.0);
		System.out.println(obj1);
		
		Integer a1 = Integer.valueOf(12);
	}
}
