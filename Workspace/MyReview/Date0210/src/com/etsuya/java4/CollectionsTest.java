package com.etsuya.java4;

import org.junit.Test;

import java.sql.Array;
import java.util.*;

/**
 * ClassName: CollectionsTest
 * Package: com.etsuya.java4
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/6 14:47
 * @Version: 1.0
 */
public class CollectionsTest {
	@Test
	public void test(){
		List list = Arrays.asList(1, 4, 2, 12, 45, 12, 56, 46, 23, 40);
		Comparator comparator = new Comparator() {
			@Override
			public int compare(Object o1, Object o2) {
				Integer a1 = (Integer) o1;
				Integer a2 = (Integer) o2;
				return a2 - a1;
			}
		};
		Collections.sort(list, comparator);
		System.out.println(list);
	}

	@Test
	public void test1(){
		List list = Arrays.asList(1, 4, 2, 12, 45, 12, 56, 46, 23, 40);
		//错误写法：会出现 java.lang.IndexOutOfBoundsException: Source does not fit in dest 异常。
		//查看源码可知，copy时dest的size一定要大于等于src的size
		//注意：这是里面的元素个数问题，而不是底层开辟数组大小的问题。
		List list1 = new ArrayList();
		Collections.copy(list1, list);
		//正确的写法（之一）：
		List list2 = Arrays.asList(new Object[list.size()]);
		Collections.copy(list2, list);

		List list3 = Collections.unmodifiableList(list);

	}
	
	@Test
	public void test2(){
	    String num[] = new String[]{"A", "1", "2", "3", "4", "5", "6", "7", "8", "9", "J", "Q", "k"};
		String color[] = new String[]{"方角", "梅花", "红桃", "大花"};
		ArrayList poker = new ArrayList();
		for(int i = 0; i < num.length; i++){
			for(int j = 0; j < color.length; j++){
				poker.add(color[j] + num[i]);
			}
		}
		poker.add("大王");
		poker.add("小王");
		System.out.println(poker);
		Collections.shuffle(poker);
		ArrayList player1 = (ArrayList) poker.subList(0, 12);

	}
}
