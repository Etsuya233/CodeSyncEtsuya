package com.etsuya.java3;

import org.junit.Test;

import java.io.*;
import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.Objects;

/**
 * ClassName: IOTest1
 * Package: com.etsuya.java3
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/15 22:25
 * @Version: 1.0
 */
public class IOTest1 {
	@Test
	public void test() {
		//用字节流来复制视频
		File file = new File("D:\\Etsuya");
		File src = new File(file, "LieAll_20221002_130715908-01.jpeg");
		File dest = new File(file, "LieAll_20221002_130715908-01_copy.jpeg");

		FileOutputStream fos = null;
		FileInputStream fis = null;
		BufferedOutputStream bos = null;
		BufferedInputStream bis = null;
		try {
			fos = new FileOutputStream(dest);
			fis = new FileInputStream(src);
			bos = new BufferedOutputStream(fos);
			bis = new BufferedInputStream(fis);

			int len;
			byte[] arr = new byte[50];
			while ((len = (bis.read(arr))) != -1) {
				bos.write(arr, 0, len);
			}
			System.out.println("Copy Succeed!");
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if(bos != null)
					bos.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
			try {
				if(bis != null)
					bis.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}


	}
	
	
	@Test
	public void test1() throws IOException {
	    //实现文本文件从GBK到UTF-8
		File file = new File("D:\\Etsuya\\Programming\\Test");
		File gbkfile = new File(file, "gbk.txt");
		File utf8file = new File(file, "utf8.txt");

		FileInputStream fis = new FileInputStream(gbkfile);
		FileOutputStream fos = new FileOutputStream(utf8file);
		//使用转换流包装字节流
		InputStreamReader isr = new InputStreamReader(fis, "GBK");
		OutputStreamWriter osw = new OutputStreamWriter(fos, "UTF8");
		//创建char型数组加快访问速度
		char[] cBuffer = new char[1024];
		int len;
		while((len = isr.read(cBuffer)) != -1){
			osw.write(cBuffer, 0, len);
		}
		//关闭流
		osw.close();
		isr.close();

	}

	@Test
	public void test2() throws IOException, ClassNotFoundException {
		File file = new File("D:\\Etsuya\\Programming\\Test");
		File file1 = new File(file, "data.dat");
		Person p1 = new Person("Mike", 12, "UK");
		Person p2 = new Person("Taylor", 33, "USA");
		//使用对象流将对象传入文件中
		FileOutputStream fos = new FileOutputStream(file1);
		ObjectOutputStream oos = new ObjectOutputStream(fos);
		oos.writeObject(p1);
		oos.writeObject(p2);
		oos.flush();
		//使用对象流将文件中的对象输出到内存中
		FileInputStream fis = new FileInputStream(file1);
		ObjectInputStream ois = new ObjectInputStream(fis);
		Object o1 = ois.readObject();
		Object o2 = ois.readObject();
		System.out.println(o1);
		System.out.println(o2);

		ois.close();
		oos.close();
	}
	
	@Test
	public void test3(){
	    //File Encryption
		File file = new File("D:\\Etsuya\\Programming\\Test");
		File original = new File(file, "photo.jpg");
		File encrypted = new File(file, "photo_encrypted.jpg");

		BufferedInputStream bis = null;
		BufferedOutputStream bos = null;

		try {
			bis = new BufferedInputStream(new FileInputStream(original));
			bos = new BufferedOutputStream(new FileOutputStream(encrypted));

			byte[] buffer = new byte[1024];
			int len;
			while((len = bis.read(buffer)) != -1){
				for(int i = 0; i < len; i++){
					buffer[i] = (byte) (buffer[i] ^ 5);
				}
				bos.write(buffer, 0, len);
			}
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if(bos != null)
					bos.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
			try {
				if(bis != null)
					bis.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}

		System.out.println("File Encrypted!");

	}

	@Test
	public void test4() {
		//File Decryption
		File file = new File("D:\\Etsuya\\Programming\\Test");
		File encrypted = new File(file, "photo_encrypted.jpg");
		File decrypted = new File(file, "photo_decrypted.jpg");

		BufferedInputStream bis = null;
		BufferedOutputStream bos = null;

		try {
			bis = new BufferedInputStream(new FileInputStream(encrypted));
			bos = new BufferedOutputStream(new FileOutputStream(decrypted));
			byte[] buffer = new byte[1024];
			int len;
			while((len = bis.read(buffer)) != -1){
				for (int i = 0; i < len; i++) {
					buffer[i] = (byte) (buffer[i] ^ 5);
				}
				bos.write(buffer, 0, len);
			}
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if(bos != null)
					bos.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
			try {
				if(bis != null)
					bis.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		System.out.println("File Decrypted!");

	}

	@Test
	public void test5(){
		try {
			InetAddress byName = InetAddress.getByName("www.google.com");
			System.out.println(byName.getHostName());
			System.out.println(byName.getHostAddress());
		} catch (UnknownHostException e) {
			e.printStackTrace();
		}
	}

}

class Person implements Serializable{
	static final long serialVersionUID = 10086112004L;

	String name;
	int age;
	transient String country;

	public Person() {
	}

	public Person(String name, int age, String country) {
		this.name = name;
		this.age = age;
		this.country = country;
	}

	@Override
	public String toString() {
		return "Person{" +
				"name='" + name + '\'' +
				", age=" + age +
				", country='" + country + '\'' +
				'}';
	}
	
	
}