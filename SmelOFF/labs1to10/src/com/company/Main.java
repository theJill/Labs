package com.company;

public class Main {

    public static void main(String[] args) {
	    Lab2 lab2 = new Lab2();
	    lab2.task1();
	    lab2.task2();

	    Lab3 lab3 = new Lab3();
	    System.out.println("Task 1");
	    lab3.task1();
		System.out.println("Task 2");
		lab3.task2();
		System.out.println("Task 3");
		lab3.task3();
		System.out.println("Task 4");
		lab3.task4();
		System.out.println("Task 5");
		lab3.task5();
		System.out.println("Task 6");
		lab3.task6();
		lab3.task6();
		System.out.println(lab3.staticvar);

		//Lab4
		//Task1
		CCC ccc1 = new CCC();
		System.out.println(ccc1.getX() + " " + ccc1.getY());
		CCC ccc2 = new CCC(3,4);
		System.out.println(ccc2.getX() + " " + ccc2.getY());
		ccc1.setX(5);
		ccc2.setY(7);
		System.out.println(ccc1.getX() + " " + ccc2.getY());
		System.out.println(ccc1.ssub());
		//Task2
		DDD ddd1 = new DDD();
		System.out.println(ddd1.getX() + " " + ddd1.getY());
		DDD ddd2 = new DDD(2,2);
		System.out.println(ddd2.getX() + " " + ddd2.getY());
		System.out.println(ddd2.calc());
	}
}
