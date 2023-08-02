package com.etsuya.java3;

import org.junit.Test;
import org.junit.rules.TestRule;

import java.io.*;
import java.sql.SQLOutput;

/**
 * ClassName: IOTest
 * Package: com.etsuya.java3
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/13 21:41
 * @Version: 1.0
 */
public class IOTest {
	@Test
	public void test(){
		File file1 = new File("test");
		File file2 = new File(file1, "test.txt");

		System.out.println(file1.getParent());
		System.out.println(file1.getAbsoluteFile().getPath());
		System.out.println(file2.getAbsoluteFile());
		System.out.println(file2.getAbsolutePath());
		System.out.println(file2.getName());
		System.out.println(file2.getPath());
		System.out.println(file2.getParent());
		System.out.println(file2.length());
		System.out.println(file2.lastModified());
	}

	@Test
	public void test2(){
		//IOTest文件夹里的所有文件夹与文件
		File file = new File("D:\\Etsuya\\Study\\Atguigu\\IOTest");
		String[] list = file.list();
		for(String str: list){
			System.out.println(str);
		}
	}

	@Test
	public void test3(){
		File file = new File("D:\\Etsuya\\Study\\Atguigu\\IOTest");
		File file1 = new File(file, "qwqwqwqw.txt");
		System.out.println(file1.isDirectory());
	}
	
	@Test
	public void test4(){
		File file = new File("D:\\Etsuya\\Study\\Atguigu\\IOTest");
		tree(file, 1);
	}

	public void tree(File file, int table){
		if(file.isFile()){
			for(int i = 0; i < table; i++){
				System.out.print("--");
			}
			System.out.print("> ");
			System.out.println(file.getName());
		} else {
			for(int i = 0; i < table; i++){
				System.out.print("--");
			}
			System.out.print("> ");
			System.out.println(file.getName());
			File[] files = file.listFiles();
			for(File f : files){
				tree(f, table + 1);
			}
		}
	}

	@Test
	public void test5(){
		File file = new File("D:\\Etsuya\\Study\\Atguigu\\IOTest");
		File[] files = file.listFiles(new FilenameFilter() {
			@Override
			public boolean accept(File dir, String name) {
				if (name.endsWith(".jpg")) return true;
				else return false;
			}
		});
	}

	@Test
	public void test6(){
	    File dir = new File("test");
		File src = new File(dir, "test.txt");
		File dest = new File(dir, "test_copy.txt");
		FileReader fr = null;
		FileWriter fw = null;
		try {
			fr = new FileReader(src);
			fw = new FileWriter(dest);
			char[] arr = new char[5];
			int len;
			while((len = fr.read(arr)) != -1){
//				fw.write(arr); 错误写法！！
				fw.write(arr, 0, len);
			}
			System.out.println("Copy Succeed!");
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if(fw != null)
					fw.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
			try {
				if(fr != null)
					fr.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}

	}
}
