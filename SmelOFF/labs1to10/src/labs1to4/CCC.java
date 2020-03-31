package labs1to4;

public class CCC {
    public static int x;
    public int getX() { return x; }
    public void setX(int newProperty){
        x = newProperty;
    }
    private static int y;
    public int getY() {
        return y;
    }
    public void setY(int newProperty){
        y = newProperty;
    }
    CCC(){
        this.x=0;
        this.y=0;
    }
    CCC(int x, int y){
        this.x=x;
        this.y=y;
    }
    public int sum(){
        return this.x+this.y;
    }
    public static int ssub(){
        return x-y;
    }
    public static int mult(){
        return x*y;
    }
}
