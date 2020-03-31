package lab5;

public class Main {
    public static void main(){
        lab5.Level1 level1 = new lab5.Level1(1);
        lab5.lev2.Level2 level2 = new lab5.lev2.Level2(2);
        lab5.lev2.Level22 level22 = new lab5.lev2.Level22(22);
        lab5.lev2.lev3.lev4.Level4 level4 = new lab5.lev2.lev3.lev4.Level4(4);
        lab5.lev2.lev3.lev4.Level44 level44 = new lab5.lev2.lev3.lev4.Level44(44);

        level1.classInfoOutput();
        level2.classInfoOutput();
        level22.classInfoOutput();
        level4.classInfoOutput();
        level44.classInfoOutput();
    }
}
