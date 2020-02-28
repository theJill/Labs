package com.company;

import static java.lang.Math.pow;

public class Lab2 {
    //Task1
    int a1=5, b1=9;
    float a2=5f, b2=9f;
    double a3, b3, val1, val2, val3;
    public void task1(){
        a3=5.0;
        b3=9.0;
        val1 = pow(a1,2)+pow(b1,2);
        val2 = pow(a2,3)+pow(b2,3);
        val3 = pow(a3,4)+pow(b3,4);

        System.out.println("Int sum: "+ val1);
        System.out.println("Float sum: "+ val2);
        System.out.println("Double sum: "+ val3);}
    //Task2
    char a = 'a';
    char b = 'b';
    public void task2(){
        System.out.println(a+b);
        System.out.println(a-b);
    }
}