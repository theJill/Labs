package com.company;

public class DDD extends CCC {
    public static int x;
    public int getX() {
        return x;
    }
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
    DDD(){
        this.x=1;
        this.y=1;
    }
    DDD(int x, int y){
        super(x, y);
        this.x=x;
        this.y=y;
    }
    public int sum(){
        return super.sum() + this.sum();
    }
    public static int mult(){
        return x*y;
    }
    public int calc(){
        return super.getX()*super.getY() + this.getX()*this.getY();
    }
}
