package lab5;

public class Level1 {
    int level;

    public Level1(int level) {
        this.level = level;
    }

    public void classInfoOutput(){
        System.out.println(this.getClass().getSimpleName() + "'s field value equals " + this.level);
    }
}
