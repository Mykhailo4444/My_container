#pragma once
#include "My_place.h"
//Клас нащадок Місто
class My_city : public My_place
{
public:
	//Конструктори
	My_city();
	My_city(int square, int count_of_people, string oblast_name, string name);
	//Гетери
	string get_oblast_name();
	string get_name();
	string get_body();
	//Сетери
	void set_oblast_name(string oblast);
	void set_name(string name);
	//Функція, що виводить дані об'єкта на екран
	void pprint(ostream& my_city);
	//Перегруження операторів для потокового вводу та виводу з консолі
	friend ostream& operator<<(ostream& out, My_city& my_city);
	friend istream& operator >> (istream& in, My_city& my_city);
	//Деструктор
	~My_city();
private:
	string oblast_name;//Ім'я області, в якй знаходиться місто
	string name;//Назва міста
	string body = "city";
};

