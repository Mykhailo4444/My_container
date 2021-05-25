/*#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include "Double_connect_list.h"

BOOST_AUTO_TEST_CASE(add_elem)
{
  Double_connect_list my_list;
  BOOST_TEST(my_list.showing_all()==0);
  My_city* city = new My_city(1234, 4567, "Fastiv", "Kyivska");
  my_list.add_to_list(city);
  BOOST_TEST(my_list.showing_all() == 1);
}
BOOST_AUTO_TEST_CASE(delete_elem)
{
	Double_connect_list my_list;
	BOOST_TEST(my_list.showing_all() == 0);
	vector<string> city_list = {"Fastiv","Lviv"};
	My_oblast* oblast = new My_oblast(1234, 4567, "Fastiv", city_list);
	my_list.add_to_list(oblast);
	BOOST_TEST(my_list.showing_all() == 1);
	my_list.delete_element(0);
	BOOST_TEST(my_list.showing_all() == 0);
}
BOOST_AUTO_TEST_CASE(delete_all_elements)
{
	Double_connect_list my_list;
	BOOST_TEST(my_list.showing_all() == 0);
	vector<string> city_list = { "Fastiv","Lviv" };
	My_oblast* oblast = new My_oblast(1234, 4567, "Fastiv", city_list);
	my_list.add_to_list(oblast);
	My_city* city = new My_city(1234, 4567, "Fastiv", "Kyivska");
	my_list.add_to_list(city);
	BOOST_TEST(my_list.showing_all() == 1);
	my_list.delete_all();
	BOOST_TEST(my_list.showing_all() == 0);
}
BOOST_AUTO_TEST_CASE(sort_choise)
{
	Double_connect_list my_list;
	BOOST_TEST(my_list.showing_all() == 0);
	vector<string> city_list = { "Fastiv","Lviv" };
	My_oblast* oblast = new My_oblast(1234, 4567, "Lvivska", city_list);
	my_list.add_to_list(oblast);
	My_city* city = new My_city(1234, 4567, "Kyivska", "Fastiv");
	my_list.add_to_list(city);
	BOOST_TEST(my_list.get_first()->body->get_oblast_name() == "Lvivska");
	BOOST_TEST(my_list.get_last()->body->get_oblast_name() == "Kyivska");
	my_list.sort_choice("Harkivska");
	BOOST_TEST(my_list.get_first()->body->get_oblast_name() == "Kyivska");
	BOOST_TEST(my_list.get_last()->body->get_oblast_name() == "Lvivska");
}
BOOST_AUTO_TEST_CASE(from_to_file)
{
	Double_connect_list my_list;
	BOOST_TEST(my_list.showing_all() == 0);
	My_city* city = new My_city(1234, 4567, "Kyivska", "Fastiv");
	my_list.add_to_list(city);
	BOOST_TEST(my_list.showing_all() == 1);
	ofstream file("kursova.txt");
	file << my_list;
	file.close();
	Double_connect_list my_list1;
	ifstream file1("kursova.txt");
	file1 >> my_list1;
	BOOST_TEST(my_list1.showing_all() == 1);
	file.close();
}*/

