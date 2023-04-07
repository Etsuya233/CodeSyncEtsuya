package com.etsuya.java6;

/**
 * ClassName: MyReader
 * Package: com.etsuya.java6
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/24 21:28
 * @Version: 1.0
 */
public class MyReader {
	public MyReader() {
	}

	public void reader(FileNeed2BeRead f){
		MyAnnotation declaredAnnotation = f.getClass().getDeclaredAnnotation(MyAnnotation.class);
		String table = declaredAnnotation.table();
		System.out.println("reading " + table + " ...");
	}
}
