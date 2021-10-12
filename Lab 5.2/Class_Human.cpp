#pragma once
#include "Human.h"

Human::Human()
{
	name = "empty";
	pathranomic = "empty";
	age = 0;
	id = 0;
}

Human::Human(std::string name, std::string pathranomic, int age, int id)
{
	this->name = name;
	this->pathranomic = pathranomic;
	this->age = age;
	this->id = id;
}

std::string Human::get_name()
{
	return name;
}

std::string Human::get_pathranomic()
{
	return pathranomic;
}


void Human::set_name(std::string name)
{
	this->name = name;
}

void Human::set_pathranomic(std::string pathranomic)
{
	this->pathranomic = pathranomic;
}

void Human::set_age(int age)
{
	this->age = age;
}

void Human::set_id(int id)
{
	this->id = id;
}

int Human::get_age()
{
	return age;
}

int Human::get_id()
{
	return id;
}

std::ostream& operator<<(std::ostream& out, const Human& man)
{
	out << "Имя:" << man.name  << std::endl;
	out << "Фамилия:" << man.pathranomic << std::endl;
	out << "Возраст:" << man.age << std::endl;
	out << "Id:" << man.id << std::endl << std::endl;
	return out;
}