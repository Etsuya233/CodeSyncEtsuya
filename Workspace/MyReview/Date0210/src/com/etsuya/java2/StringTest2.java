package com.etsuya.java2;

import org.junit.Test;

/**
 * ClassName: StringTest2
 * Package: com.etsuya.java2
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/2/20 20:23
 * @Version: 1.0
 */
public class StringTest2 {
	String str = new String("good");
	char[] ch = { 't', 'e', 's', 't' };

	public void change(String str, char ch[]) {
		str = "test ok";
		ch[0] = 'b';
	}

	@Test
	public void test3() {
		com.etsuya.java2.StringTest2 ex = new com.etsuya.java2.StringTest2();
		ex.change(ex.str, ex.ch);
		System.out.print(ex.str + " and ");//
		System.out.println(ex.ch);
	}
}
