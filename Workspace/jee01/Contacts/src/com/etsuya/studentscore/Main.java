package com.etsuya.studentscore;

import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		Vector v = new Vector();
		
		int maxScore = -1;
		
		while(true) {
			Integer score = scan.nextInt();
			if(score < 0) {
				break;
			}
			if(score > 100) {
				System.out.println("The score you enter is invalid!");
				continue;
			}
			v.addElement(score);
			if(score > maxScore) maxScore = score;
			
			
		}
		for(int i = 0; i < v.size(); i++) {
			Integer a = (Integer)v.elementAt(i);
			System.out.println("Student - " + i + "'s score is " + a);
		}
		
		
	}
}
