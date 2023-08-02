package com.etsuya.review5;

import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class BankTest {
	@Test
	public void testFact() {
		assertEquals(1, Bank.factorial(1));
		assertEquals(2, Bank.factorial(2));
		assertEquals(6, Bank.factorial(3));
		assertEquals(24, Bank.factorial(4));
		assertEquals(120, Bank.factorial(5));
	}
}
