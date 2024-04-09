#pragma once
#include <string>

using namespace std;

/// @brief Базовый класс
class Car
{
private:
    /// @brief счетчик объектов класса
    static int count_;

protected:
    /// @brief марка
    string name_;

    /// @brief число цилиндров
    int cylinder_;

    /// @brief мощность
    int power_;

public:
    /// @brief конструктор по умолчанию (без параметров)
    Car()
        : name_("oka"), cylinder_(2), power_(33)
    {
        // делаем инкремент счетчика объектов при создании нового объекта
        ++count_;
    }

    /// @brief конструктор с параметрами
    /// @param theName
    /// @param cylinders
    /// @param power
    Car(const string &theName, int cylinders, int power)
        : name_(theName), cylinder_(cylinders), power_(power)
    {
        // делаем инкремент счетчика объектов при создании нового объекта
        ++count_;
    }

    /// @briefконструктор копирования
    /// @param new_car
    Car(const Car &new_car)
        : name_(new_car.name_), cylinder_(new_car.cylinder_), power_(new_car.power_)
    {
        // делаем инкремент счетчика объектов при создании нового объекта
        ++count_;
    }

    /// @brief получить количество созданных объектов
    /// @return
    friend int count(const Car& car);

    /// @brief назначить марку
    /// @param name
    void setName(const string &name);

    /// @brief получить марку
    /// @return
    const string &getName() const;

    /// @brief назначить мощность
    /// @param theCylinder
    void setCylinder(int cylinder);

    /// @brief получить значение мощности
    /// @return
    int getCylinder() const;

    /// @brief назначить мощность
    /// @param power
    void setPower(int power);

    /// @brief получить значение мощности
    /// @return
    int getPower() const;

    /// @brief деструктор
    ~Car()
    {
    }
};

inline int Car::count_ = 0;