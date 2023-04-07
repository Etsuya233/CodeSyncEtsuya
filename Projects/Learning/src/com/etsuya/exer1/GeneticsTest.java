package com.etsuya.exer1;

import org.junit.Test;

import java.sql.Array;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.List;

/**
 * ClassName: GeneticsTest
 * Package: com.etsuya.exer1
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/9 17:10
 * @Version: 1.0
 */
public class GeneticsTest {
	@Test
	public void test(){
		ArrayList<Object> arrayList = new ArrayList<>();
		ArrayList<String> arrayList1 = new ArrayList<>();
		ArrayList<?> arrayList2;
		arrayList2 = arrayList;
		arrayList2 = arrayList1;
	}
}

class DAO<T>{
	HashMap<String, T> map = new HashMap<String, T>();

	public void save(String id, T entity){
		map.put(id, entity);
	}

	public T get(String id){
		if(map.containsKey(id)){
			return map.get(id);
		} else throw new RuntimeException("找不到哇");
	}

	public List<T> list(){
		Collection<T> ret = map.values();
		return new ArrayList<T>(ret);
	}


}