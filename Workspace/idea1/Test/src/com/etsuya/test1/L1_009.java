package com.etsuya.test1;

import java.util.Scanner;

public class L1_009 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int sumA = 0, sumB = 0;
        int cnt = scan.nextInt();
        for(int i = 0; i < cnt; i++){
            String number = scan.next();    //Need 2 Comprehend
            String[] afterSplit = number.split("/");
            int a = Integer.parseInt(afterSplit[0]);
            int b = Integer.parseInt(afterSplit[1]);

            if(i == 0){
                sumA = a;
                sumB = b;
                continue;
            }

            int lcm = new Calc().getLCM(sumB, b);
            sumA = lcm / sumB * sumA;
            a = lcm / b * a;
            sumB = lcm;
            b = lcm;
            sumA += a;

            int gcd = new Calc().getGCD(sumA, sumB);
            sumA /= gcd;
            sumB /= gcd;
        }

        int front = 0;
        if(sumA >= sumB){
            front = sumA / sumB;
            sumA -= front * sumB;
            if(sumA == 0){
                System.out.println(front);
            }else{
                System.out.println(front + " " + sumA + "/" + sumB);
            }
        }else{
            System.out.println(sumA + "/" + sumB);
        }

    }
}

class Calc{
    public int getGCD(int a, int b){
        int gcd = 0;
        int small = (a<b)?a:b;
        for(int i = small; i > 0; i--){
            if(a % i == 0 && b % i == 0){
                gcd = i;
                break;
            }
        }
        return gcd;
    }

    public int getLCM(int a, int b){
        int big = (a>b)?a:b;
        int lcm;
        for(int i = big; ;i++){
            if(i % a == 0 && i % b == 0){
                lcm = i;
                break;
            }
        }
        return lcm;
    }


}