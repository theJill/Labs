package lab5.lev2.lev3.lev4;

public class Level4 {
    int level;

    public Level4(int level) {
        this.level = level;
    }

    public void classInfoOutput(){
        System.out.println(this.getClass().getSimpleName() + "'s field value equals " + this.level);
    }
}
