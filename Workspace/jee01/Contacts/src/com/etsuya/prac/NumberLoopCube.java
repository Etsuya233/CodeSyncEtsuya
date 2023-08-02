package com.etsuya.prac;

import java.util.Scanner;

public class NumberLoopCube {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		System.out.print("Please enter a number:");
		int number = scan.nextInt();
		int[][] cube = new int[number][number];
		int step = 0, endStep = number * number, direction = 1; //direction 1 right 2 down 3 left 4 up
		int row = 0, column = -1; //To remember the location where the pointer are
		while(step < endStep) {
			direction %= 4;
			if(direction == 0) direction = 4;
			switch (direction) {
			case 1:
				column++;
				cube[row][column] = ++step;
				if(column == number-1 || cube[row][column + 1]!=0) direction++;
				break;
			case 2:
				row++;
				cube[row][column] = ++step;
				if(row == number-1 || cube[row + 1][column]!=0) direction++;
				break;
			case 3:
				column--;
				cube[row][column] = ++step;
				if(column == 0 || cube[row][column - 1]!=0) direction++;
				break;
			case 4:
				row--;
				cube[row][column] = ++step;
				if(row == 0 || cube[row - 1][column]!=0) direction++;
				break;
			}
		}
		
		//Traverse the array cube
		for(int cnt = 0; cnt < number; cnt++) {
			for(int cnt1 = 0; cnt1 < number; cnt1++) {
				System.out.print(cube[cnt][cnt1] + " ");
				
			}
			System.out.println();
		}
	}
}
