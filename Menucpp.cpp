#include "Double_connect_list.h"

class Menu {
public:
	static Menu& Ok() 
	{
		static Menu m;
		return m;
	}
	void START()
	{
		int answer = 0;
		Double_connect_list my_list;
		cout << "1 - create an element; 2-show all elements;" << endl;
		cout << "3-write elements to file; 4 - read element from file;" << endl;
		cout << "5 - delete the elment; 6 - delete all elements" << endl;
		cout << "7 - `Insert Sort` and linear finding the city; 8 - end of the program" << endl;
		cin >> answer;
		if (!cin) {
			cerr << "You Entered something wrong!!" << endl;
		}
		else {
			while (answer != 8) {
				if (answer == 7)
				{
					string oblast_find;
					cout << "Enter the oblast in wich will be showed all cities" << endl;
					cin >> oblast_find;
					my_list.sort_choice(oblast_find);
				}
				else if (answer == 1)
				{
					int current_answer = 0;
					cout << "1-to create a City object; 2- Oblast object" << endl;
					cin >> current_answer;
					if (!cin) {
						cerr << "You Entered something wrong!!" << endl;
						break;
					}
					else {
						if (current_answer == 1)
						{
							My_city* city = new My_city;
							cin >> *city;
							my_list.add_to_list(city);
						}
						else if (current_answer == 2) {
							My_oblast* oblast = new My_oblast;
							cin >> *oblast;
							my_list.add_to_list(oblast);
						}
						else
							cout << "Cant anderstand your command(" << endl;
					}
				}
				else if (answer == 2) {
					my_list.showing_all();
				}
				else if (answer == 3) {
					ofstream file("kursova.txt");
					try {
						file << my_list;
					}
					catch (const exception& ex)
					{
						cout << ex.what() << endl;
						cout << "Something was wrong with opening the file((" << endl;
					}
				}
				else if (answer == 4) {
					ifstream file("kursova.txt");
					try {
						file >> my_list;
						cout << "Elements was read from the file" << endl;
					}
					catch (const exception& ex)
					{
						cout << ex.what() << endl;
						cout << "Something was wrong with opening the file((" << endl;
					}
				}
				else if (answer == 5) {
					cout << "Enter the index yo`d like to delete BUT NOTE!!!!  first element has index 0 ! " << endl;
					int index;
					cin >> index;
					if (!cin) {
						cerr << "You Entered something wrong!!" << endl;
						break;
					}
					else
						my_list.delete_element(index);
				}
				else if (answer == 6) {
					my_list.delete_all();
					cout << "All elements was deleted" << endl;
				}
				else {
					cout << "You Entered something wrong!!  " << endl;
				}
				cout << "1 - create an element; 2-show all elements;" << endl;
				cout << "3-write elements to file; 4 - read element from file;" << endl;
				cout << "5 - delete the elment; 6 - delete all elements" << endl;
				cout << "7 - `Insert Sort` and linear finding the city; 8 - end of the program" << endl;
				cin >> answer;
				if (!cin) {
					cerr << "You Entered something wrong!!" << endl;
					break;
				}
			}
			cout << "Have a good day bro" << endl;
		}
	}
};

int main() 
{
	Menu& M = Menu::Ok();
	M.START();
}
