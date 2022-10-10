#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"
class Customer :
	public Person
{
private:
	string mechanical_name;
	Appointment appointment;

public:
	Customer(string mechName = "", int hours = 0, int mins = 0, string n = "", string id = "", int a = 0) :Person(n, id, a)
	{
		set_mechanical_name(mechName);
		appointment.hours = hours;
		appointment.mins = mins;
	}

	void set_mechanical_name(string id)
	{
		mechanical_name = id;
	}
	void set_appointment(int hours, int mins)
	{
		if (hours < 0 || hours >24 || mins < 0 || mins>60)
		{
			cout << "Undefined time." << endl;
		}
		else
		{
			appointment.hours = hours;
			appointment.mins = mins;
		}
	}
	string get_mechanical_name()
	{
		return mechanical_name;
	}
	Appointment get_appointment()
	{
		return appointment;
	}
	bool operator > (const Customer& b)
	{
		if (appointment.hours > b.appointment.hours)
			return true;
		else if (appointment.hours == b.appointment.hours && appointment.mins > b.appointment.mins)
			return true;
		else
			return false;
	}
	bool operator < (const Customer& b)
	{
		if (appointment.hours < b.appointment.hours)
			return true;
		else if (appointment.hours == b.appointment.hours && appointment.mins < b.appointment.mins)
			return true;
		else
			return false;
	}
	bool operator == (const Customer& b)
	{
		if (appointment.hours == b.appointment.hours && appointment.mins == b.appointment.mins)
			return true;
		else
			return false;
	}
	virtual void print()
	{
		cout << "Customer info:- \n";
		cout << "Name: " << name << endl;
		cout << "ID: " << ID << endl;
		cout << "Age: " << age << endl;
		cout << "Appointment: ";
		cout << appointment.hours << ":" << appointment.mins << "\n";
		//cout << "\t with mechanic " << mechanical_name;
		cout << endl;
	}

};

#endif // !PERSON_H


