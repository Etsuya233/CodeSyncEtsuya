package com.etsuya.java10;

import com.sun.source.tree.NewArrayTree;
import org.junit.Test;

import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

/**
 * ClassName: CompareTest
 * Package: com.etsuya.java10
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/6/10 19:00
 * @Version: 1.0
 */
public class CompareTest {
	public static void main(String[] args) {
		Person[] arr = new Person[]{new Person(12), new Person(15), new Person(13)};
		Arrays.sort(arr);
		for(int i = 0; i < 3; i++) System.out.println(arr[i]);

		Integer one = 1;
		System.out.println(one.compareTo(22));

		Integer[] arr1 = {2345,5654,2345,13456,536};
		Arrays.sort(arr1, Integer::compareTo);
		for(Integer a: arr1){
			System.out.println(a);
		}
	}

	@Test
	public void test1(){
		System.out.println(Math.random());
		Random random = new Random();
		System.out.println(random.nextInt(12, 33)); //[12, 33)
	}
	
	@Test
	public void test2() throws IOException {
		File file = new File("D:\\Etsuya\\Study");
		File file1 = new File(file, "qwq.txt");
		FileReader fr = new FileReader(file1);
		int a;
		while((a = fr.read()) != -1){
			System.out.print((char) a);
		}
	}
	
	@Test
	public void test3(){
	    
	}

}

class Person implements Comparable<Person>{
	int age;
	String name;

	public Person() {
	}

	public Person(int age) {
		this.age = age;
	}

	@Override
	public int compareTo(Person o) {//从小到大
		return this.age - o.age;
	}

	@Override
	public String toString() {
		return "Person{" +
				"age=" + age +
				", name='" + name + '\'' +
				'}';
	}
}