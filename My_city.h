#pragma once
#include "My_place.h"
//���� ������� ̳���
class My_city : public My_place
{
public:
	//������������
	My_city();
	My_city(int square, int count_of_people, string oblast_name, string name);
	//������
	string get_oblast_name();
	string get_name();
	string get_body();
	//������
	void set_oblast_name(string oblast);
	void set_name(string name);
	//�������, �� �������� ��� ��'���� �� �����
	void pprint(ostream& my_city);
	//������������ ��������� ��� ���������� ����� �� ������ � ������
	friend ostream& operator<<(ostream& out, My_city& my_city);
	friend istream& operator >> (istream& in, My_city& my_city);
	//����������
	~My_city();
private:
	string oblast_name;//��'� ������, � ��� ����������� ����
	string name;//����� ����
	string body = "city";
};

