package com.etsuya.java2;

import org.junit.Test;

import java.io.UnsupportedEncodingException;

/**
 * ClassName: StringTest
 * Package: com.etsuya.java2
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/2/20 20:06
 * @Version: 1.0
 */
public class StringTest {
	@Test
	public void test1(){
		String a = "hello";
		String b = "hello";
		a = a.concat("World");
		b = b.concat("World");
		System.out.println(a == b);

	}

	@Test
	public void test2(){
		String a = new String("abc");
		String b = "abc";
		System.out.println(a == b); // false
		a = a.intern();
		System.out.println(a == b);  // true
	}

	@Test
	public void test3(){
	    String s1 = "赤那";
		try {
			byte[] c1 = s1.getBytes("gbk");
		} catch (UnsupportedEncodingException e) {
			throw new RuntimeException(e);
		}
	}

	@Test
	public void test4(){
	    while(true){

		}
	}
}

