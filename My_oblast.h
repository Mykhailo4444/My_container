#pragma once
#include "My_place.h"
#include <vector>
//���� ������� �������
class My_oblast : public My_place
{
public:
	//������������
	My_oblast();
	My_oblast(int square, int count_of_people, string oblast_name, vector<string> city_list);
	//������
	string get_oblast_name();
	vector<string> get_city_list();
	string get_body();
	//������
	void set_oblast_name(string oblast_name);
	void set_city_list(vector<string> city_list);
	//�������, �� �������� ��� ��'���� �� �����
	void pprint(ostream& my_oblast);
	//������������ ��������� ��� ���������� ����� �� ������ � ������
	friend ostream& operator<<(ostream& out, My_oblast& my_oblast);
	friend istream& operator >> (istream& in, My_oblast& my_oblast);
	//����������
	~My_oblast();
private:
	string body = "oblast";
	string oblast_name ; //����� ������
	vector<string> city_list; //̳����� � ��� ����� ���, �� ������� �� ���� ������
};