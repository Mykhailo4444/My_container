#include "My_oblast.h"
//Конструктори
My_oblast::My_oblast() {}
My_oblast::My_oblast(int square, int count_of_people, string oblast_name, vector<string> city_list) :My_place(square, count_of_people),
oblast_name(oblast_name), city_list(city_list)
{
}
//Гетери
string My_oblast::get_oblast_name(){ return this->oblast_name; }
string My_oblast::get_body() { return this->body; }
vector<string> My_oblast::get_city_list()  { return this->city_list; }
//Сетери
void My_oblast::set_oblast_name(string oblast_name) { this->oblast_name = oblast_name; }
void My_oblast::set_city_list(vector<string> city_list) { this->city_list = city_list; }
//Функція, що виводить дані об'єкта на екран
void My_oblast::pprint(ostream& my_oblast)
{
	cout << "Square: " << get_square() << " People: " << get_count_of_people() << " Oblast name: " << get_oblast_name() << " Cities in oblast: ";
	for (int i = 0; i < get_city_list().size(); i++) {
		cout << get_city_list()[i] << " ";
	}
	cout << endl;
}
//Перегруження операторів для потокового вводу та виводу з консолі
ostream& operator<<(ostream& out, My_oblast& my_oblast) {
	my_oblast.pprint(out);
	return out;
}
istream& operator >> (istream& in, My_oblast& my_oblast) {
	cout << "Enter the square(Integer value):";
	int square1 = 0;
	cin >> square1;
	if (!cin) {
		cerr << "Error of entering the value" << endl;
	}
	else {
		my_oblast.square = square1;
		cout << "Enter the count of people(Integer value):";
		int count_of_people1 = 0;
		cin >> count_of_people1;
		if (!cin) {
			cerr << "Error of entering the value" << endl;
		}
		else {
			my_oblast.count_of_people = count_of_people1;
			cout << "Enter the oblast name(String value):";
			string oblast_name1;
			cin >> oblast_name1;
			my_oblast.oblast_name = oblast_name1;
			cout << "How many cities will be in this oblast:";
			vector<string> city_list = {};
			int count_of_cities = 0;
			cout << "How many cities will be in this oblast?(Integer value)" << endl;
			cin >> count_of_cities;
			if (!cin || count_of_cities <= 0) {
				cerr << "Error of entering the value" << endl;
			}
			else {
				string city_for_oblast;
				for (int i = 0; i < count_of_cities; i++) {
					cout << "Enter the name of the city(String value) # " << i + 1 << endl;
					cin >> city_for_oblast;
					if (count_of_cities == 1) {
						city_list.push_back(city_for_oblast);
						break;
					}
					else {
						city_list.push_back(city_for_oblast);
					}
				}
				my_oblast.city_list = city_list;
				return in;
			}
		}
	}
}
//Деструктор
My_oblast::~My_oblast() {}