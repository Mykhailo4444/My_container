#include "Double_connect_list.h"
#include <nlohmann/json.hpp> //��� ����������� � ������ json
Element::Element() {}
//�������, ��� � ��'��� �������� ����� ���� �������� ���(�������, ����)
void Element::set_body(My_place* place)
{
	this->body = place;
}
My_place* Element::get_body()
{
	return body;
}
//�������, �� ������ ��������� ����� �� ���������, ��������� ��������(� ��� ������������ � ���'�� ���)
void Element::show_links()
{
	cout << "Prevoius: " << this->previous << " Personal: " << this->personal << " Next: " << this->next << endl;
}
Element::~Element() {}
Double_connect_list::Double_connect_list() {}
//�������, �� ������� ��'��� ��������, ����� ��������� ���, � ������ ������� ��� ��������� � ���������
void Double_connect_list::add_to_list(My_place* object)
{
	Element* it = new Element();
	it->set_body(object);
	if (this->first == NULL)
	{
		this->first = this->last = it;
		this->tmp = it;
	}
	//��������, ���� � ����� ���� �������
	else if (this->first == this->last)
	{
		this->first = this->tmp;
		this->last = it;
		this->first->next = this->last;
		this->last->previous = this->first;
	}
	//���� ��� � ����� � ����� ��������
	else
	{
		this->last->next = it;
		it->previous = this->last;
		this->last = it;
	}
}
Element* Double_connect_list::get_first() {
	return this->first;
}
Element* Double_connect_list::get_last() {
	return this->last;
}
//�������, �� ��������� �� ��'����, �� �������� � ���������, � ���� ���� �� �����, ����� ���� ���'���
int Double_connect_list::showing_all()
{
	this->tmp = this->first;
	//�������� �� ���������
	if (this->tmp == NULL) 
	{
		cout << "There are no elements in your list" << endl;
		return 0;
	}
	else 
	{
		while (this->tmp != NULL)
		{
			cout << *this->tmp->get_body();
			this->tmp->show_links();
			this->tmp = this->tmp->next;
		}
		return 1;
	}
	this->tmp = this->first;
}
//������� ��� ��������� ��������� ��������(�� ��������) � ����������
void Double_connect_list::delete_element(int index)
{
	if (index < 0) {
		cout << "There are no minus indexes" << endl;
	}
	else 
	{
		this->tmp = this->first;
		//�������� �� ��������� ��������
		if (this->tmp == NULL)
		{
			cout << "There are no elements in your list" << endl;
		}
		else
		{
			Element* next;
			Element* previous;
			int counter = 0;
			//���� ��� �������� ������� �������� � ���������
			while (this->tmp != NULL)
			{
				counter++;
				this->tmp = this->tmp->next;
			}
			if (index > counter) {
				cout << "The list is too short, there isn`t such index" << endl;
			}
			else
			{
				this->tmp = this->first;

				for (int i = 0; i < counter; i++)
				{
					//��� ��������� 0 �������
					if (0 == index) {
						//��������, ���� � ��������� ����� ���� �������
						if (this->first == this->last)
						{
							cout << this->tmp->personal << " was deleted successfuly " << endl;
							this->first = this->last = NULL;
							break;
						}
						else
						{
							cout << this->tmp->personal << " was deleted successfuly " << endl;
							this->first = this->first->next;
							this->first->previous = NULL;
							break;
						}
					}
					//��� ��������� ���������� �������
					else if (counter - 1 == index)
					{
						cout << this->last->personal << " was deleted successfuly " << endl;
						this->last = this->last->previous;
						this->last->next = NULL;
						break;
					}
					//��������� ����� �������
					else if (i == index)
					{
						cout << this->tmp->personal << " was deleted successfuly " << endl;
						previous = this->tmp->previous;
						next = this->tmp->next;
						previous->next = next->personal;
						next->previous = previous->personal;
						break;
					}
					else
					{
						this->tmp = this->tmp->next;
					}
				}
			}
		}
	}
	this->tmp = this->first;
}
/*������� ��� ���������� �������� ������� �������, ����� �� �������� �� ��������� ��������(�� ����� ������)
 ������ ������ ����� � ������������� ����� �� �������� ��������� ������*/
void Double_connect_list::sort_choice(string oblast_name)
{
	this->tmp = this->first;
	//�������� �� ��������� ��������
	if (this->tmp == NULL)
	{
		cout << "There are no elements in your list" << endl;
	}
	else
	{
		int counter = 0;
		//�������� �� ������� �������� � �����
		while (this->tmp != NULL)
		{
			counter++;
			this->tmp = this->tmp->next;
		}
		/*��������� ������ ���� Element** �� ���������� ���� ���������� ������ ���������� �����
		���������� ������������ ������� �������*/
		Element** array1 = new Element * [counter];
		this->tmp = this->first;
		for (int i = 0; i < counter; i++)
		{
			array1[i] = this->tmp;
			this->tmp = this->tmp->next;
		}
		// ���������� �������������� ������ ������� �������
		for (int i = 1; i < counter; i++)
		{
			for (int j = i; j > 0; j--)
			{
				string answer1;
				string answer2;
				answer1 = array1[j]->get_body()->get_oblast_name();
				answer2 = array1[j - 1]->get_body()->get_oblast_name();
				if (answer1 < answer2)
				{
					Element* tmp1;
					tmp1 = array1[j];
					array1[j] = array1[j - 1];
					array1[j - 1] = tmp1;
				}
				else
					break;
			}
		}
		//��������� ������� ����������
		delete_all();
		string new_answer;
		//��������� ������ ���������� �� ����� ��� ������������ �������� ������ ������
		for (int i = 0; i < counter; i++)
		{
			My_place* place = new My_place();
			place = array1[i]->get_body();
			this->tmp = this->first;
			add_to_list(place);
		}
		// ��������� ������ � ���� ��������
		for (int i = 0; i < counter; i++)
		{
			delete array1[i];
		}
		delete[] array1;
		cout << "Sorted objects by alphabet(oblast)" << endl;
		//������������ ������ ������������� ����������
		showing_all();
		this->tmp = this->first;
		cout << "All cities from this oblast" << endl;
		int counter1 = 0;
		//��������� 볳����� ������ �� ����������
		for (int i = 0; i < counter; i++)
		{
			new_answer = this->tmp->get_body()->get_body();
			//�������� �� ��, ��� ��� �������� �������� ������
			if (new_answer == "city")
			{
				//���� ���� - �������� ����� ����, ���� �������� � �������� �������
				if (this->tmp->get_body()->get_oblast_name() == oblast_name)
				{
					cout << this->tmp->get_body()->get_name() << endl;
					counter1++;
				}
			}
			else
			{
				//���� ������� - �������� ����� ��� ��� � ���� ������, ���� ����� ������ �������� � �����
				if (this->tmp->get_body()->get_oblast_name() == oblast_name)
				{
					for (int j = 0; j < this->tmp->get_body()->get_city_list().size(); j++)
					{
						cout << this->tmp->get_body()->get_city_list()[j] << endl;
					}
					counter1++;
				}
			}
			this->tmp = this->tmp->next;
		}
		//�������� �� ���� �������� ���� � ������ ������
		if (counter1 == 0)
		{
			cout << "There  are no cities in this oblast" << endl;
		}
		this->tmp = this->first;
	}
}
//������ ��� ��������� ��� �������� ����������
void Double_connect_list::delete_all()
{
	this->tmp = this->first;
	while (this->tmp != NULL)
	{
		this->tmp->personal = NULL;
		this->tmp = this->tmp->next;
	}
	this->first = NULL;
	this->tmp = NULL;
	this->last = NULL;
}
//����������, �� ��� ������� �� �������� ����������
Double_connect_list::~Double_connect_list()
{ 
	this->tmp = this->first;
	while(this->tmp != NULL)
	{
		this->tmp->personal = NULL;
		this->tmp = this->tmp->next;
	}
	this->first = NULL;
	this->tmp = NULL;
	this->last = NULL;
}

//���������� ���������� ����� � ����
ofstream& operator<<(ofstream& file, Double_connect_list& my_list) 
{
	my_list.tmp = my_list.first;
	//�������� �� ���� ���������� ��� ������ �������� � ����
	if (my_list.tmp == NULL)
	{
		cout << "There are no elements in your container to write them in file(" << endl;
	}
	else
	{
		try
		{
			while (my_list.tmp != NULL)
			{
				//��������� ��'���� json, � ���� ������, �� �������� � �� ����������� ��������
				nlohmann::json j{};
				//�������� �� ���� ��� �������� ����������
				if (my_list.tmp->body->get_body() == "city")
				{
					j["square"] = my_list.tmp->body->get_square();
					j["count_of_people"] = my_list.tmp->body->get_count_of_people();
					j["oblast_name"] = my_list.tmp->body->get_oblast_name();
					j["name"] = my_list.tmp->body->get_name();
					string object = j.dump();
					// 1 - ������, �� ��������� ��'��� - ����
					file << "1" << "\n" << object << "\n";
				}
				else
				{
					j["square"] = my_list.tmp->body->get_square();
					j["count_of_people"] = my_list.tmp->body->get_count_of_people();
					j["oblast_name"] = my_list.tmp->body->get_oblast_name();
					j["city_list"] = my_list.tmp->body->get_city_list();
					string object = j.dump();
					// 2 - ������, �� ��������� ��'��� - �������
					file << "2" << "\n" << object << "\n";
				}
				my_list.tmp = my_list.tmp->next;
			}
			cout << "Elements was written to the file" << endl;
		}
		//�� ������� ������� �� ������� � ���� �� ��������� json
		catch (const exception& ex)
		{
			cout << ex.what() << endl;
			cout << "Something was wrong with creating json or writing to the file((" << endl;
		}
	}
	file.close();
	my_list.tmp = my_list.first;
	return file;
}
//���������� ���������� ������� � �����
ifstream& operator>>(ifstream& file, Double_connect_list& my_list)
{
	string object;
	string answer = "";
	try 
	{
		if (file.peek() == EOF)
		{
			cout << "There are no elements in your file((" << endl;
		}
		else
		{
			while (getline(file, object))
			{
				//�������� �� ����� ���� � ����
				if (object == "1") {
					answer = "city";
					continue;
				}
				//�������� �� ����� ������ � ����
				else if (object == "2")
				{
					answer = "oblast";
					continue;
				}
				else if (answer == "city")
				{
					//���������� ������� ���� � �����, ��������� ���� � ���������
					Element* it = new Element();
					My_city* city = new My_city;
					it->set_body(city);
					nlohmann::json j = nlohmann::json::parse(object);
					it->body->set_square(j["square"].get<int>());
					it->body->set_count_of_people(j["count_of_people"].get<int>());
					it->body->set_oblast_name(j["oblast_name"].get<string>());
					it->body->set_name(j["name"].get<string>());
					my_list.add_to_list(it->body);
				}
				else {
					//���������� ������� ������� � �����, ��������� ���� � ���������
					Element* it = new Element();
					My_oblast* place = new My_oblast;
					it->set_body(place);
					nlohmann::json j = nlohmann::json::parse(object);
					it->body->set_square(j["square"].get<int>());
					it->body->set_count_of_people(j["count_of_people"].get<int>());
					it->body->set_oblast_name(j["oblast_name"].get<string>());
					it->body->set_city_list(j["city_list"].get<vector<string>>());
					my_list.add_to_list(it->body);
				}
			}
		}
	}
	// �� ������� ������� �� ���������� �����
	catch(const exception& ex)
	{
		cout << ex.what() << endl;
		cout << "Something was wrong with reading the file(( May be your file is empty!!" << endl;
	}
	file.close();
	return file;
}

