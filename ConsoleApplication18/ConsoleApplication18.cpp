#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
struct machine
{
    string name;
    int visota_pos;
    double ob_engine;
    int power_engine;
    int diam_wheel;
    string color;
    string type_kr_per;
};
void setting_values(machine car[], int i)
{
    cout << "Введите название машины -";
    cin >> car[i].name;
    cout << "Введите высоту посадки - ";
    cin >> car[i].visota_pos;
    cout << "Введите объем двигателя - ";
    cin >> car[i].ob_engine;
    cout << "Введите мощность двигателя - ";
    cin >> car[i].power_engine;
    cout << "Введите диаметр колес - ";
    cin >> car[i].diam_wheel;
    cout << "Введите цвет - ";
    cin >> car[i].color;
    cout << "Введите тип коробки передач - ";
    cin >> car[i].type_kr_per;
}
void show(machine car[], int i)
{
    int choice;
    cout << "Выберите машину:\n";
    for (int j = 0; j <= i; j++)
    {
        cout << j << ")" <<  car[j].name << endl;
    }
    cin >> choice;
    cout << "\nВысота посадки - " << car[choice].visota_pos;
    cout << "\nОбъем двигателя - " << car[choice].ob_engine;
    cout << "\nМощность двигателя - " << car[choice].power_engine;
    cout << "\nДиаметр колес - " << car[choice].diam_wheel;
    cout << "\nЦвет - " << car[choice].color;
    cout << "\nТип коробки передач - " << car[choice].type_kr_per;

}
void showing(machine car[], int i)
{
    cout << "Название авто - " << car[i].name;
    cout << "\nВысота посадки - " << car[i].visota_pos;
    cout << "\nОбъем двигателя - " << car[i].ob_engine;
    cout << "\nМощность двигателя - " << car[i].power_engine;
    cout << "\nДиаметр колес - " << car[i].diam_wheel;
    cout << "\nЦвет - " << car[i].color;
    cout << "\nТип коробки передач - " << car[i].type_kr_per;

}
void find(machine car[], int i)
{
    int choice;
    do
    {
        cout << "Выберите параметр:\n";
        cout << "1 - название машины\n";
        cout << "2 - высота посадки\n";
        cout << "3 - объем двигателя\n";
        cout << "4 - мощность двигателя\n";
        cout << "5 - диаметр колес\n";
        cout << "6 - цвет\n";
        cout << "7 - тип коробки передачи";
        cin >> choice;
    } while (choice < 1 || choice > 7);
    bool p = false;
    if (choice == 1 || choice == 6 || choice == 7)
    {
        string choice2;
        cout << "Введите значение - ";
        cin >> choice2;
        for (int j = 0; j <= i; j++)
        {
            if (choice2 == car[j].name || choice2 == car[j].color || choice2 == car[j].type_kr_per)
            {
                cout << "Есть такое)\n";
                cout << "Данные по машине:\n";
                showing(car, j);
                p = true;
            }
        }
        if (p == false)cout << "Ничего не найдено(";
    }
    else
    {
        double choice2;
        cout << "Введите значение - ";
        cin >> choice2;
        p = false;
        for (int j = 0; j <= i; j++)
        {
            if (choice2 == car[j].diam_wheel || choice2 == car[j].ob_engine || choice2 == car[j].power_engine || choice2 == car[j].visota_pos)
            {
                cout << "Есть такое)\n";
                cout << "Данные по машине:\n";
                showing(car, j);
                p = true;
            }
        }
        if (p == false)cout << "Ничего не найдено(";
    }
}
int main()
{
    system("color 6");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    machine car[10];
    car[0] = { "Mitsubishi",140,2,295,18,"красный","механика"};
    car[1] = { "Toyota",140,3,324,16,"белый","механика"};
    car[2] = { "Hyundai",160,1.6,123,15,"синий","автомат" };
    int choice;
    int i = 2;
    do
    {
        cout << "\nВыберите действие:";
        cout << "\n1 - Задать значение";
        cout << "\n2 - Вывести значения";
        cout << "\n3 - Найти значение";
        cout << "\n0 - Выход";
        cin >> choice;
        if (choice == 1)
        {
            i++;
            setting_values(car, i);
        }
        else if (choice == 2)show(car,i);
        else if (choice == 3)find(car,i);
        else cout << "Нет такого";
    } while (choice != 0);
}