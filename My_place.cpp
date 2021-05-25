#include "My_place.h"

using namespace std;
//Конструктори
My_place::My_place() {}
My_place::My_place(int square, int count_of_people):square(square),count_of_people( count_of_people )
{
}
//Гетери
int My_place::get_square(){ return this->square; }
int My_place::get_count_of_people() { return this->count_of_people; }
string My_place::get_body() { return this->body; }
string My_place::get_oblast_name() { return ""; }
string My_place::get_name() { return ""; }
vector<string> My_place::get_city_list()
{
	vector<string> a;
	return a;
}
//Сетери
void My_place::set_square(int square) { this->square = square; }
void My_place::set_count_of_people(int count_of_people) { this->count_of_people = count_of_people; }
void My_place::set_oblast_name(string oblast_name){}
void My_place::set_name(string name){}
void My_place::set_city_list(vector<string> city_list){}
//Функція, що виводить дані об'єкта на екран
void My_place::pprint(ostream& my_place){cout << get_square() << " " << get_count_of_people() << endl;}
//Перегруження операторів для потокового вводу та виводу з консолі
ostream& operator<<(ostream& out, My_place& my_place)
{
	my_place.pprint(out);
	return out;
}
istream& operator >> (istream& in, My_place& my_place)
{
	cout << "Enter the square:";
	int square1 = 0;
	cin >> square1;
	if (!cin) {
		cerr << "Error of entering the value" << endl;
	}
	else {
		my_place.square = square1;
		cout << "Enter the count of people:";
		int count_of_people1 = 0;
		cin >> count_of_people1;
		if (!cin) {
			cerr << "Error of entering the value" << endl;
		}
		else {
			my_place.count_of_people = count_of_people1;
			return in;
		}
	}
}
//Віртуальний Деструктор
My_place::~My_place() {};

