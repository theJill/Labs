package lab5.lev2;

public class Level2 {
    int level;

    public Level2(int level) {
        this.level = level;
    }

    public void classInfoOutput(){
        System.out.println(this.getClass().getSimpleName() + "'s field value equals " + this.level);
    }
}
