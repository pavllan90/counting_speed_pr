#include <iostream>
#include <cassert>
#include "move.h"

using namespace std;

int main()
{
    //Функция assert() проверяет условие в скобках и прерывает программу в случае невыполнения
    //с помощью нее проверяется корректность работы программы
    cout<<"A: "<<endl;
    Move a;
    assert(a.getTime().hours == 1 &&
           a.getTime().minutes == 24 &&
           a.getTime().seconds == 36); // проверка конструктора по умолчанию
    a.show();

    Move b(4, 69, -23, 54.43);
    assert(b.getTime().hours == 4 &&
           b.getTime().minutes == 24 &&
           b.getTime().seconds == 36); // проверка конструктора инициализации
    cout<<"B: "<<endl;
    b.show();

    Move copy = b;
    cout<<"Copy: "<<endl;
    assert(b.getTime().hours == copy.getTime().hours &&
           b.getTime().minutes == copy.getTime().minutes &&
           b.getTime().seconds == copy.getTime().seconds); // проверка конструктора копирования
    copy.show();

    cout<<"New B: "<<endl;
    b.setTime(-3, 66, 32);
    b.setSpeed(32.93);
    assert(b.getTime().hours == 1 &&
           b.getTime().minutes == 24 &&
           b.getTime().seconds == 32); // проверка сеттеров времени (В случае ввода времени как часы, минуты, секунды)
    b.show();
    b.setTime(Time());

    cout<<"Another B: "<<endl;
    assert(b.getTime().hours == 1 &&
           b.getTime().minutes == 24 &&
           b.getTime().seconds == 36);// проверка сеттеров времени (В случае ввода времени как Time)
    b.show();

    return 0;
}
