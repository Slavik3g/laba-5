#pragma once
#include <iostream>

class Human
{
	friend std::ostream& operator<<(std::ostream& out, const Human& man);
private:
	std::string name;
	std::string pathranomic;
	int age;
	int id;
public:
	Human();
	Human(std::string, std::string, int, int);
	std::string get_name();
	std::string get_pathranomic();
	int get_age();
	int get_id();
	void set_name(std::string);
	void set_pathranomic(std::string);
	void set_age(int);
	void set_id(int);
	void showinfo();
};


