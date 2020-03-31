package lab6;

public interface person {
    public int Limityyyy = 1900;
    public void setSurname (String surname);
    public void setName (String name);
    public void setFathername (String fathername);
    public void setBirthday (int yyyy, int mm, int dd);
    public String getSurname();
    public String getName();
    public String getFathername();
    public java.util.Date getBirthday();
}
