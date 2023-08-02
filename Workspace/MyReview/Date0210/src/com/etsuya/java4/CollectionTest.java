package com.etsuya.java4;

import org.junit.Test;

import java.sql.Array;
import java.util.*;

/**
 * ClassName: CollectionTest
 * Package: com.etsuya.java4
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/2/27 21:05
 * @Version: 1.0
 */
public class CollectionTest {
	public static void main(String[] args) {

	}

	@Test
	public void test(){
		Collection coll = new ArrayList();
		Object obj = new Object();
		coll.add("1,2,3");
		coll.add(12);
		coll.add(obj);
//		System.out.println(coll);
		Collection coll1 = new ArrayList();
		coll1.add("1,2,3");
		coll1.add(12);
		coll1.add(obj);
		System.out.println(coll.containsAll(coll1));

		Collection coll2 = new ArrayList();
		coll2.add(new String("qwq"));
		Collection coll3 = new ArrayList();
		coll3.add(new String("qwq"));
		System.out.println(coll2 == coll3);
		coll2.equals(coll3);
	}

	@Test
	public void test2(){
	    int[] arr = new int[]{1, 4, 2, 6};
		List<int[]> list = Arrays.asList(arr);
		List<String> list1 = Arrays.asList("12", "qwq");
	}

	@Test
	public void test3(){
	    Integer[] arr1 = new Integer[]{1, 2, 3};
		int[] arr2 = new int[]{1, 2, 3};
		List<Integer> list1 = Arrays.asList(arr1);
		List<int[]> list2 = Arrays.asList(arr2);
		System.out.println(list1.size()); //3 因为装的是Integer对象
		System.out.println(list2.size()); //1 因为装的是int数组
		//为什么：可以看asList()的构造器
		//构造器里面装的是对象
	}

	@Test
	public void test4(){
	    Integer[] arr = new Integer[]{1, 5, 2};
		List<Integer> integers = Arrays.asList(arr);
		Iterator<Integer> iterator = integers.iterator();
		while(iterator.hasNext()){
			System.out.println(iterator.next());
		}
	}

	@Test
	public void test5(){
		Integer[] arr1 = new Integer[]{1, 2, 3};
		List<Integer> list1 = Arrays.asList(arr1);
		for(Object obj : list1){
			System.out.println(obj);
		}
	}
	
	@Test
	public void test6(){
	    Collection coll = new ArrayList();
		coll.add(new String("qwq"));
		System.out.println(coll.contains(new String("qwq")));
		coll.add(12);
		coll.add(new Object());
		System.out.println(coll.size());
//		coll.remove("qwq");
//		System.out.println(coll.size());
		Object arr[] = coll.toArray();
		for(Object obj : arr){
			System.out.println(obj);
		}
		System.out.println("----------------");
		Iterator iterator = coll.iterator();
		while (iterator.hasNext()){
			System.out.println(iterator.next());
		}


	}

	@Test
	public void test7(){
	    List list = new ArrayList();
		list.add("qwq");
		list.add(0, "aaa");
		System.out.println(list);
	}
}
