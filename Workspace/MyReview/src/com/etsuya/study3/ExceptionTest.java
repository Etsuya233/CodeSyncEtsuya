package com.etsuya.study3;

import org.junit.Test;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.Scanner;

public class ExceptionTest {
	public static void main(String[] args) {
		Student s = new Student();
		s.register(1001);
		System.out.println(s);
	}


	@Test
	public void test1(){
		System.out.println("qwq");
	}

	@Test
	public void test2(){
		FileInputStream fis = null;

		try {
			File file = new File("hello.txt");
			fis = new FileInputStream(file);

			int data = fis.read();
			while(data != -1){
				System.out.print((char)data);
				data = fis.read();
			}
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try{
				if(fis != null)
					fis.close();
			} catch(IOException e){
				e.printStackTrace();
			}
		}
	}
}

class Exception2{
	public void method(){
		try{
			method1();
		} catch(IOException e){
			e.printStackTrace();
		} 
	}
	public void method1() throws IOException{
		method2();
	}
	public void method2() throws IOException{
	}
}

class Student{
	private int id;

	public void register(int id){
		if(id >= 0) this.id = id;
		else throw new InputMismatchException();
	}

	@Override
	public String toString() {
		return "Student{" +
				"id=" + id +
				'}';
	}
}