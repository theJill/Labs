package com.company;

public class Lab3 {
    public static void task1(){
        int[] xx = new int[10];
        for (int i=0; i < xx.length; i++){
            xx[i] = i;
            System.out.println(xx[i]);
        }
    }
    public static void task2(){
        int[][] xx = new int[5][5];
        for (int i = 0; i < xx.length; i++){
            for (int j = 0; j < xx[i].length; j++){
                xx[i][j] = i+j;
            }
        }
        for (int i = 0; i < xx.length; i++){
            System.out.println(" ");
            for (int j = 0; j < xx[i].length; j++){
                System.out.println(xx[i][j]);
            }
        }
    }
    public static void task3(){
        int x =8;
        System.out.println(8 >>> 2); // 1000 >>> 0010
        System.out.println(x <<= 2); // 1000
        System.out.println(x ^= 2);  // 0010 XOR
        System.out.println(8 & 2);   // 1000 & 0010
        System.out.println(~2);      // 0000 0010   1111 1101  +3=0000 0011 -3=flip +1 1111 1101
    }
    public static void task4(){
        boolean t = true;
        boolean f = false;
        boolean result = t||f;
        System.out.println(result);
        result = t&&f;
        System.out.println(result);
        result = (t||f)?true:false;
        System.out.println(result);
    }
    public static void task5(){
        String startString = "You told me you love me";
        if (startString.length()>10){
            System.out.println(startString);
        }
        else{
            System.out.println("No song for today");
        }
        int par=1;
        do {
            switch(par){

                case 1:
                    System.out.println("Why did you leave me all alone");
                    break;
                case 2:
                    System.out.println("Now you tell me you need me");
                    break;
                case 3:
                    System.out.println("When you call me on the phone");
                    break;
                default:
                    System.out.println("Girl, I refuse");
            }
            par++;
        } while (par<=4);
        while (par>1){
            switch(par){
                case 2:
                    System.out.println("Now it's your turn, to cry");
                    break;
                case 3:
                    System.out.println("The bridges were burned");
                    break;
                default:
                    System.out.println("You must have me confused with some other guy");
            }
            par--;
        }
        for (int i=0; i<3; i++){
            System.out.println("Cry me a river");
        }
    }
    static int staticvar = 7;
    public void task6(){
        staticvar++;
        System.out.println(staticvar);
    }
}
