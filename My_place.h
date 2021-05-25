#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
//����������� ���� ̳��� 
class My_place {
public:
	//������������
	My_place();
	My_place(int square, int count_of_people);
	// ������ 
	int get_square();
	int get_count_of_people();
	virtual string get_oblast_name();
	virtual string get_name();
	virtual vector<string> get_city_list();
	virtual string get_body();
	//������
	void set_square(int square);
	void set_count_of_people(int count_of_people);
	virtual void set_oblast_name(string oblast_name);
	virtual void set_name(string name);
	virtual void set_city_list(vector<string> city_list);
	//�������, �� �������� ��� ��'���� �� �����
	virtual void pprint(ostream& my_place);
	//������������ ��������� ��� ���������� ����� �� ������ � ������
	friend ostream& operator<<(ostream& out, My_place& my_place);
	friend istream& operator >> (istream& in, My_place& my_place);
	//³��������� ����������
	virtual ~My_place();
protected:
	int square = 0; //�����
	int count_of_people = 0;//ʳ������ �����
	string body;//�� � ����� ��'����, �������� ��� �������� ���(�������) �������� ���������
};