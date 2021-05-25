#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
//Абстрактний Клас Місце 
class My_place {
public:
	//Конструктори
	My_place();
	My_place(int square, int count_of_people);
	// Гетери 
	int get_square();
	int get_count_of_people();
	virtual string get_oblast_name();
	virtual string get_name();
	virtual vector<string> get_city_list();
	virtual string get_body();
	//Сетери
	void set_square(int square);
	void set_count_of_people(int count_of_people);
	virtual void set_oblast_name(string oblast_name);
	virtual void set_name(string name);
	virtual void set_city_list(vector<string> city_list);
	//Функція, що виводить дані об'єкта на екран
	virtual void pprint(ostream& my_place);
	//Перегруження операторів для потокового вводу та виводу з консолі
	friend ostream& operator<<(ostream& out, My_place& my_place);
	friend istream& operator >> (istream& in, My_place& my_place);
	//Віртуальний Деструктор
	virtual ~My_place();
protected:
	int square = 0; //Площа
	int count_of_people = 0;//Кількість людей
	string body;//Не є полем об'єкта, створено для перевірки тіла(начинки) елемента контенера
};