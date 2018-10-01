#include "move.h"

//Конструкторы с доп проверками корректности данных
//Проверки корректности времени осуществляются в конструкторе инициализации структуры Time

Move::Move() : time(Time()), speed(78.87) { }

Move::Move(Time _time, float _speed) : time(_time), speed (_speed >= 0 ? _speed : Move().speed) { }

Move::Move(int _hours, int _minutes, int _seconds, float _speed) :
           time(Time(_hours, _minutes, _seconds)),
           speed(_speed >= 0 ? _speed : Move().speed) { }

Move::Move(const Move &copy) : time(copy.time), speed(copy.speed) { }

Move::~Move() { }

//Сеттеры

void Move::setSpeed(float _speed)
{
    speed = _speed >= 0 ? _speed : speed;
}

void Move::setTime(Time _time)
{
    time = _time;
}

void Move::setTime(int _hours, int _minutes, int _seconds)
{
    time = Time(_hours, _minutes, _seconds);
}

//Геттеры

float Move::getSpeed()
{
    return speed;
}

Time Move::getTime()
{
    return time;
}

//Вывод

void Move::show()
{
    cout<<"Current time: "<<time.hours<<":"<<time.minutes<<":"<<time.seconds<<endl;
    cout<<"Current speed: "<<speed<<" kPH"<<endl;
}
