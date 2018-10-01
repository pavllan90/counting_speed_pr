#ifndef MOVE_H
#define MOVE_H
#include <iostream>

using namespace std;

struct Time //Структура времени (часы:минуты:секунды)
{
    Time() : hours(1), minutes(24), seconds(36) { } //Конструктор по умолчанию, вызывается при Time a;
    Time(int _hours, int _minutes, int _seconds) : //Конструктор инициализации, вызывается при Time a(1,2,3);
         hours(_hours >= 0 ? _hours : Time().hours), // Проверки на корректность введенных данных,
         minutes(_minutes >= 0 && _minutes < 60 ? _minutes : Time().minutes), //в случае некорректных данные берутся из конструктора по умолчанию
         seconds(_seconds >= 0 && _seconds < 60 ? _seconds : Time().seconds) { }
    Time(const Time &copy) : hours(copy.hours), minutes(copy.minutes), seconds(copy.seconds) { } // Конструктор копирования
    int hours;
    int minutes;
    int seconds;
};

class Move //Класс команды движения по заданию варианта
{
public:
    Move(); //Конструктор по умолчанию, вызывается при Time a;
    Move(Time _time, float _speed); //Конструктор инициализации, вызывается при Time a(1,2,3);
    Move(int _hours, int minutes, int _seconds, float _speed);//Конструктор инициализации, вызывается при Time a(1,2,3);
    Move(const Move &copy); // Конструктор копирования
    ~Move(); // Деструктор
    //Сеттеры
    void setSpeed(float _speed); //Функция установки нового значения переменной speed
    void setTime(Time _time); //Функция установки нового значения переменной time (принимает Time)
    void setTime(int _hours, int _minutes, int _seconds); //Функция установки нового значения переменной time (принимает часы, минуты, секунды)
    //Геттеры
    float getSpeed(); //Функция получения значения переменной speed, без возможности его изменить
    Time getTime(); //Функция получения значения переменной time, без возможности его изменить
    void show(); //Функция вывода полей класса в командную строку
private:
    Time time; //Поле времени
    float speed; // Поле скорости
};

#endif // MOVE_H
