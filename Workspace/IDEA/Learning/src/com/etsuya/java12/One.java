package com.etsuya.java12;

import org.junit.Test;

import java.util.function.Consumer;
import java.util.function.Predicate;

/**
 * ClassName: One
 * Package: com.etsuya.java12
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/6/15 13:03
 * @Version: 1.0
 */
public class One {
	@Test
	public void test(){
	    Runnable a = () -> System.out.println("qwq");
		a.run();

		Consumer<String> b = System.out::println;
		b.accept("what???");

		Integer c = 1;
		System.out.println(c.compareTo(2));

		printRes(d -> d > 12, 11);

		int $qwq = 12;
		

		new Thread(() -> System.out.println("qwq")).start();
	}

	public void printRes(Predicate<Integer> rule, int toBeTest){
		System.out.println("The result is " + rule.test(toBeTest));
	}

	@Test
	public void test1(){
	    Tools.print("what");
	}
}
