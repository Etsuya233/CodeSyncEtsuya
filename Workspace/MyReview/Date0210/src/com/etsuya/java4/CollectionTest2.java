package com.etsuya.java4;

import com.sun.source.tree.Tree;
import org.junit.Test;

import java.sql.Array;
import java.util.*;

/**
 * ClassName: CollectionTest2
 * Package: com.etsuya.java4
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/2 21:01
 * @Version: 1.0
 */
public class CollectionTest2 {
	public static void main(String[] args) {
//		ArrayList arrayList = new ArrayList();
//		Integer[] arr = new Integer[]{1, 0, 0, 8, 6};
//		arrayList.addAll(Arrays.asList(arr));
//		ArrayList arrayList1 = new ArrayList();
//		Integer[] arr1 = new Integer[]{1, 0, 0, 8, 7};
//		arrayList1.add("qwq");
//		arrayList1.addAll(Arrays.asList(arr1));
//		System.out.println(arrayList1);
//		arrayList1.retainAll(arrayList);
//		System.out.println(arrayList1);




	}

	@Test
	public void test(){
		HashSet hashSet = new HashSet();
		hashSet.add(2);
		hashSet.add(3);
		hashSet.add(2);
		System.out.println(hashSet); // 2 3

	}
	
	@Test
	public void test2(){
		HashSet hashSet = new HashSet();
		Random random = new Random();
		while(hashSet.size() < 20){
			int number = random.nextInt(20);
		}
	}

	@Test
	public void test3(){
		Random random = new Random();
		for (int i = 0; i < 20; i++) {
			System.out.println(random.nextInt(20));
			/*
			这样子生成的是[0, 20)内的数。
			Returns a pseudorandom, uniformly distributed int value between 0 (inclusive)
			and the specified value (exclusive), drawn from this random number generator's sequence.
			 */
			int a = 20, b = 50;
			System.out.println(random.nextInt(b - a));
			//这样子就可以了
		}
	}

	@Test
	public void test4(){
		Comparator comparator = new Comparator() {
			@Override
			public int compare(Object o1, Object o2) {
				if(o1 instanceof Person && o2 instanceof Person){
					if(o1 == o2) return 0;
					Person p1 = (Person) o1;
					Person p2 = (Person) o2;
					int value = p1.name.compareTo(p2.name);
					if(value != 0){
						return -value;
					}
					return p1.age - p2.age;
				}
				throw new RuntimeException("类型不匹配");
			}
		};
		Person p1 = new Person(12, "Tony");
		Person p2 = new Person(13, "Sakura");
		Person p3 = new Person(15, "Sakura");
		Person p4 = new Person(11, "Opera");
		Person p5 = new Person(12, "Taylor");
		TreeSet hashSet = new TreeSet(comparator);
		hashSet.add(p1);
		hashSet.add(p2);
		hashSet.add(p3);
		hashSet.add(p4);
		hashSet.add(p5);
		System.out.println(hashSet);


	}
}

class Person implements Comparable{
	int age;
	String name;

	public Person() {
	}

	public Person(int age, String name) {
		this.age = age;
		this.name = name;
	}

	@Override
	public boolean equals(Object o) {
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;
		Person person = (Person) o;
		return age == person.age && Objects.equals(name, person.name);
	}

	@Override
	public int hashCode() {
		return Objects.hash(age, name);
	}

	@Override
	public int compareTo(Object o) {
		if(this == o) return 0;
		if(o instanceof Person){
			Person oo = (Person)o;
			int value = this.name.compareTo(oo.name);
			if(value != 0){
				return value;
			}
			return this.age - oo.age;
		}
		throw new RuntimeException("类型不匹配");
	}

	@Override
	public String toString() {
		return "Person{" +
				"age=" + age +
				", name='" + name + '\'' +
				"}\n";
	}
}
