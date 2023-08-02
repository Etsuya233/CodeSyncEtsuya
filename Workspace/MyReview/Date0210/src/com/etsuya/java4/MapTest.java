package com.etsuya.java4;

import com.etsuya.java2.StringTest3;
import org.junit.Test;

import java.util.*;

/**
 * ClassName: MapTest
 * Package: com.etsuya.java4
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/4 21:33
 * @Version: 1.0
 */
public class MapTest{
	@Test
	public void test(){
		HashMap hashMap = new HashMap();
		hashMap.put(12, 23);
		hashMap.put("qwq", 33);
		hashMap.put(new Object(), "nmsl");
		hashMap.put(1.23, "what");
		//1，遍历Entry方式一（推荐）
		Set keySet = hashMap.keySet();
		for(Object key: keySet){
			System.out.println(key + "--->" + hashMap.get(key));
		}
		//2，遍历Entry方式二（不推荐）
		Set keySet1 = hashMap.keySet();
		Collection values = hashMap.values();
		Iterator iterator = values.iterator();
		for(Object key: keySet1){
			System.out.println(key + "--->" + iterator.next());
		}
		//3，遍历Entry方式三
		Set entrySet = hashMap.entrySet();
		for(Object entry: entrySet){
			Map.Entry entry1 = (Map.Entry) entry; //因为entrySet()返回的是装满Entry的Set，
			// 而且Entry是Map里的一个内部接口，所以要用Map.Entry来访问此接口
			System.out.println(entry1);
		}
	}

	@Test
	public void test2(){
		HashMap<String, String> hashMap = new HashMap<String, String>() {
			{
				put("a", "e");
				put("b", "p");
				put("d", "qu");
				put("e", "a");
				put("f", "t");
				put("g", "l");
			}
		};
	}

	@Test
	public void test3(){

		String str = "qwq";
		System.out.println(str.charAt(3));
	}
}
