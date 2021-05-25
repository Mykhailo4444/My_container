#pragma once
#include "My_oblast.h"
#include "My_city.h"
#include "My_place.h"
#include <fstream>

//���� ��������, ���� ���� ������������� ���������
class Element {
public:
	My_place* body = NULL; // ҳ�� ��������(�������)
	Element* next = NULL;  // ����� �� ��������� �������
	Element* previous = NULL;//����� �� ��������� �������
	class Element* personal = this;// ������������ � ���'�� ��������� ������ ��������
	//�����������
	Element();
	//������ �����
	void set_body(My_place* place);
	My_place* get_body();
	void show_links();
	//����������
	~Element();
};
//���� ����������(���������� ������ ������)
class Double_connect_list
{
private:
	Element* first = NULL;//������ ������� ����������
	Element* last = NULL;//������� ������� ����������
	Element* tmp = NULL;//��������� �����
public:
	//�����������
	Double_connect_list();
	//������ �����
	Element* get_first();
	Element* get_last();
	void add_to_list(My_place* object);
	int showing_all();
	void delete_element(int index);
	void sort_choice(string oblast_name);
	void delete_all();
	//����������
	~Double_connect_list();
	//�������������� ��������� ���������� ����� �� ������ � �����
	friend ofstream& operator<<(ofstream& file, Double_connect_list& my_list);
	friend ifstream& operator>>(ifstream& file, Double_connect_list& my_list);
};
