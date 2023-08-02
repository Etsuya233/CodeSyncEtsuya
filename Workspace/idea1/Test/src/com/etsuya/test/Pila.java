package com.etsuya.test;

import java.util.Scanner;

public class Pila {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int amount = scan.nextInt();
        String[] code = new String[amount];
        int[][] position = new int[amount][2];
        new DatabaseManage().input(code, position, amount);
        int amount2Search = scan.nextInt();
        for(int i = 0; i < amount2Search; i++){
            int pussy = scan.nextInt();
            new DatabaseManage().print(code, position, pussy, amount);
        }

    }
}

class DatabaseManage{
    public void input(String[] code, int[][] position, int amount){
        Scanner scan = new Scanner(System.in);
        for(int i = 0; i < amount; i++){
            code[i] = scan.next();
            position[i][0] = scan.nextInt();
            position[i][1] = scan.nextInt();
        }
    }

    public void print(String[] code, int[][] position, int pussy, int amount){
        for(int i = 0; i < amount; i++){
            if(position[i][0] == pussy){
                System.out.print(code[i] + " " + position[i][1]);
                System.out.println();
                break;
            }
        }
    }
}