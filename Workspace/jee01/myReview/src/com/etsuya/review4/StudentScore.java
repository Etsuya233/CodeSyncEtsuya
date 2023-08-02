package com.etsuya.review4;

import java.util.Vector;
import java.util.Scanner;

public class StudentScore {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		Vector my = new Vector();
		int max = -1;
		while(true) {
			int score = scan.nextInt();
			if(score < 0) break;
			else my.addElement(score);
			max = (score > max)? score: max;
		}
		System.out.println(max);
	}
}

