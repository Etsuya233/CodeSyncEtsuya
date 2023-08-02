package com.etsuya.study;

import java.util.Scanner;

public class FactorialCalc {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int num = scan.nextInt();
//        System.out.println(new FactorialCalc().factorial(num));
//        System.out.println(new FactorialCalc().sequence1(10));
        int num2 = scan.nextInt();
        System.out.println(new FactorialCalc().fibonacci(num2));
    }

    public int factorial(int num){
        if(num == 1){
            return 1;
        }else{
            return num * factorial(num - 1);
        }
    }

    public int sequence1(int num){
        if(num == 0){
            return 1;
        }else if(num == 1){
            return 4;
        }else{
            return 2*sequence1(num - 1) + sequence1(num - 2);
        }
    }

    public int fibonacci(int num){
        if(num == 1){
            return 1;
        }else if(num == 2){
            return 1;
        }else{
            return fibonacci(num - 1) + fibonacci(num - 2);
        }
    }
}
