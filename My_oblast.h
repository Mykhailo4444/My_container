#pragma once
#include "My_place.h"
#include <vector>
//Клас нащадок Область
class My_oblast : public My_place
{
public:
	//Конструктори
	My_oblast();
	My_oblast(int square, int count_of_people, string oblast_name, vector<string> city_list);
	//Гетери
	string get_oblast_name();
	vector<string> get_city_list();
	string get_body();
	//Сетери
	void set_oblast_name(string oblast_name);
	void set_city_list(vector<string> city_list);
	//Функція, що виводить дані об'єкта на екран
	void pprint(ostream& my_oblast);
	//Перегруження операторів для потокового вводу та виводу з консолі
	friend ostream& operator<<(ostream& out, My_oblast& my_oblast);
	friend istream& operator >> (istream& in, My_oblast& my_oblast);
	//Деструктор
	~My_oblast();
private:
	string body = "oblast";
	string oblast_name ; //Назва області
	vector<string> city_list; //Містить в собі назви міст, що входять до даної області
};