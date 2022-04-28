// hellooow
#include "My_city.h"
//Êîíñòðóêòîðè
My_city::My_city() {}
My_city::My_city(int square, int count_of_people, string oblast_name, string name) :My_place(square, count_of_people),
oblast_name(oblast_name), name(name)
{
}
//Ãåòåðè
string My_city::get_oblast_name(){ return this->oblast_name; }
string My_city::get_name() { return this->name; }
string My_city::get_body(){ return this->body; }
//Ñåòåðè
void My_city::set_oblast_name(string oblast_name) { this->oblast_name = oblast_name; }
void My_city::set_name(string name) { this->name = name; }
//Ôóíêö³ÿ, ùî âèâîäèòü äàí³ îá'ºêòà íà åêðàí
void My_city::pprint(ostream& my_city)
{
	cout << "Square: " << get_square() << " People: " << get_count_of_people() << " Oblast name: " << get_oblast_name() << " City name: " << get_name() << endl;
}
//Ïåðåãðóæåííÿ îïåðàòîð³â äëÿ ïîòîêîâîãî ââîäó òà âèâîäó ç êîíñîë³
ostream& operator<<(ostream& out, My_city& my_city) {
	my_city.pprint(out);
	return out;
}
istream& operator >> (istream& in, My_city& my_city) {
	cout << "Enter the square(Integer value):";
	int square1 = 0;
	cin >> square1;
	if (!cin) {
		cerr << "Error of entering the value" << endl;
	}
	else {
		my_city.square = square1;
		cout << "Enter the count of people(Integer value):";
		int count_of_people1 = 0;
		cin >> count_of_people1;
		if (!cin) {
			cerr << "Error of entering the value" << endl;
		}
		else {
			my_city.count_of_people = count_of_people1;
			cout << "Enter the oblast name(String value):";
			string oblast_name1;
			cin >> oblast_name1;
			my_city.oblast_name = oblast_name1;
			cout << "Enter the name(String value):";
			string name1;
			cin >> name1;
			my_city.name = name1;
			return in;
		}
	}
}
//Äåñòðóêòîð
My_city::~My_city() {}
