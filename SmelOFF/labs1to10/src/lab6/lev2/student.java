package lab6.lev2;
import lab6.person;
import java.util.Date;

public interface student extends person {
    void setFirstDate(Date d);    // установить дат поступления в вуз
    Date getFirstDate();          //  получить дату поступления в вуз
    void setUniversity(String u); // установить имя вуза
    String getUniversity();       // получить имя вуза
    int LimitUniversityLength = 15;  // максимальное количество символов в наименовании вуза
}
