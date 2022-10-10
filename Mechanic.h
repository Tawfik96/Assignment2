#ifndef MECHANIC_H
#define MECHANIC_H
#include "Person.h"
#include<vector>
class Mechanic :
	public Person
{
private:
	int counter;
	vector<Appointment>reserved_appointments;

public:
	Mechanic(string n = "", string id = "", int a = 0) :Person(n, id, a)
	{
		counter = 0;
	}

	bool is_available(Appointment x)
	{
		for (int i = 0; i < reserved_appointments.size(); i++)
		{
			if (x.hours == reserved_appointments[i].hours && x.mins == reserved_appointments[i].mins)
			{
				return false;
			}
		}
		return true;
	}

	int get_counter()
	{
		return counter;
	}

	void set_count(int x)
	{
		counter = x;
	}

	void add_appointment(Appointment a)
	{
		reserved_appointments.push_back(a);
		counter++;
	}
	void add_appointment(int h, int m)
	{
		Appointment a;
		a.hours = h;
		a.mins = m;
		reserved_appointments.push_back(a);
	}

	virtual void print()
	{
		cout << "Mechanic info:- \n";
		cout << "Name: " << name << endl;
		cout << "ID: " << ID << endl;
		cout << "Age: " << age << endl;
		cout << "Reserved appointments: {  ";
		for (int i = 0; i < counter; i++)
		{
			cout << reserved_appointments[i].hours << ":" << reserved_appointments[i].mins << " | ";
		}
		cout << "\b\b }" << endl << endl;
	}


};

#endif // !MECHANIC_H