package com.etsuya.exer3;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * ClassName: StudentTest
 * Package: com.etsuya.exer3
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/2/28 21:24
 * @Version: 1.0
 */
public class StudentTest {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		List list = new ArrayList();
		while(true){
			String name, id;
			Gender gender;
			name = scan.next();
			id = scan.next();
			try{
				gender = Gender.valueOf(scan.next());
				list.add(new Student(name, id, gender));
			} catch (IllegalArgumentException e){
				System.out.println(e.getMessage());
			}
			System.out.println("Do you want to continue?");
			int opera = scan.nextInt();
			if(opera == 0) break;
		}
		System.out.println(list);
	}
}
