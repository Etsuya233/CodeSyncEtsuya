package com.etsuya.study;

import java.util.Scanner;

public class Hanoi {
    static int times = 0;

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int stack = scan.nextInt();
        hanoiGo(stack, 'A', 'B','C');
    }

    public static void hanoiGo(int amount, char a, char b, char c){
        if(amount == 1){
            hanoiMove(amount , a , c);
        }else {
            hanoiGo(amount - 1, a, c, b);
            hanoiMove(amount, a, c);
            hanoiGo(amount - 1, b, a, c);
        }
    }

    public static void hanoiMove(int n, char a, char b){
        System.out.println("The " + (times++) + " is " + a + " to " + b);
    }
}
