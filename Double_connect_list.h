#pragma once
#include "My_oblast.h"
#include "My_city.h"
#include "My_place.h"
#include <fstream>

//Клас елементу, яким буде заповнюватись контейнер
class Element {
public:
	My_place* body = NULL; // Тіло елементу(начинка)
	Element* next = NULL;  // Силка на наступний елемент
	Element* previous = NULL;//Силка на попередній елемент
	class Element* personal = this;// Розташування в пам'яті конкретно даного елементу
	//Конструктор
	Element();
	//Методи класу
	void set_body(My_place* place);
	My_place* get_body();
	void show_links();
	//Деструктор
	~Element();
};
//Клас Контейнеру(Двузвязний лінійний список)
class Double_connect_list
{
private:
	Element* first = NULL;//Перший елемент контейнеру
	Element* last = NULL;//Останній елемент контейнеру
	Element* tmp = NULL;//Тимчасова змінна
public:
	//Конструктор
	Double_connect_list();
	//Методи класу
	Element* get_first();
	Element* get_last();
	void add_to_list(My_place* object);
	int showing_all();
	void delete_element(int index);
	void sort_choice(string oblast_name);
	void delete_all();
	//Деструктор
	~Double_connect_list();
	//Перевантаження операторів потокового вводу та виводу з файла
	friend ofstream& operator<<(ofstream& file, Double_connect_list& my_list);
	friend ifstream& operator>>(ifstream& file, Double_connect_list& my_list);
};
