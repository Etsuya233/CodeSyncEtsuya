package com.etsuya.test1;

import java.util.Scanner;

public class L1_008_ToGetTheSum {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int head = scan.nextInt();
        int end = scan.nextInt();
        int crlfJudge = 0;
        int sum = 0;
        for(int i = head; i <= end; i++){
            System.out.printf("%5d", i);
            crlfJudge ++;
            sum += i;
            if(crlfJudge == 5) {
                System.out.println();
                crlfJudge = 0;
            }
        }
        if(crlfJudge != 0) System.out.println();
        System.out.println("Sum = " + sum);
    }
}
