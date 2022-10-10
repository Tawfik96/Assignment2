#ifndef PERSON_H
#define PERSON_H

#include<iostream>
using namespace std;
class Person
{
protected:
	struct Appointment
	{
		int hours;
		int mins;
	};

	string name;
	string ID;
	int age;


public:
	Person(string n = "", string id = "", int a = 0)		//->constuctor
	{
		set_age(a);
		set_id(id);
		set_name(n);
	}
	int get_age()
	{
		return age;
	}
	string get_id()
	{
		return ID;
	}
	string get_name()
	{
		return name;
	}

	void set_age(int a)
	{

		age = a;

	}
	void set_id(string id)
	{
		ID = id;
	}
	void set_name(string n)
	{
		Person::name = n;
	}

	virtual void print() = 0;


};


#endif // !PERSON_H
