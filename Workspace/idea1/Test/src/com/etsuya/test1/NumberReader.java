package com.etsuya.test1;

import java.util.Scanner;

public class NumberReader {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String number = scan.next();
        for(int i = 0; i < number.length(); i++){
            new NumUtil().numPinYin(number.charAt(i));
            if(i == number.length() - 1) break;
            System.out.print(" ");
        }
    }
}

class NumUtil{
    public void numPinYin(char num){
        switch(num){
            case 45:
                System.out.print("fu");
                break;
            case 48:
                System.out.print("ling");
                break;
            case 49:
                System.out.print("yi");
                break;
            case 50:
                System.out.print("er");
                break;
            case 51:
                System.out.print("san");
                break;
            case 52:
                System.out.print("si");
                break;
            case 53:
                System.out.print("wu");
                break;
            case 54:
                System.out.print("liu");
                break;
            case 55:
                System.out.print("qi");
                break;
            case 56:
                System.out.print("ba");
                break;
            case 57:
                System.out.print("jiu");
                break;
        }
    }
}
