#include<iostream>
using namespace std;
#include<fstream>
#include<string>
#include<vector>

class Person {
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


class Customer :public Person {
private:
	string mechanical_name;                        //it is an int
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


class Mechanic :public Person
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
		cout << "\b\b }"<<endl<<endl;
	}

};

template <class t>
class Queue
{
private:
	int end;
	int size;
	t* customers;
public:
	Queue(int s=0)
	{
		end = -1;
		size = s;
		customers = new t[size];
	}
	
	int get_size()
	{
		return end+1;
	}
	bool isfull()
	{
		if (end == size-1)
			return true;
		else
			return false;
	}
	bool isempty()
	{
		if (end == -1)
			return true;
		else
			return false;
	}
	void insert(int indx, const t& b)
	{
		for (int i = end; i>indx ;i--)
		{
			customers[i] = customers[i - 1];
		}
		customers[indx] = b;
	}
	void push(t c)
	{
		if (!isfull())
		{
			customers[++end] = c;
			for (int i = 0; i < end; i++)
			{
				if (c < customers[i])   // --> c came first.
				{
					insert(i, c);
					return;
				}
			}
		}
		else
		{
			cout << "Queue is full!\n";
		}
	
		
	}
	t pop()
	{
		t temp= customers[0];
		for (int i = 0; i <= end; i++)
		{
			customers[i] = customers[i + 1];
		}
		end--;
		return temp;
	}

	void display()
	{
		
		for (int i = 0; i <= end; i++)
		{
			cout  <<i+1<<"- "<< customers[i].get_name() << " is with osta " << customers[i].get_mechanical_name() << " at  [" << customers[i].get_appointment().hours << ":" << customers[i].get_appointment().mins << "]";
				cout << "\n------------------------------------\n";
		}
	}
};

int main()
{
	string tempWORD;
	int tempINT1;
	int tempINT2;			//Fstream temporary variables.
	int tempINT3;

	int mechanincs_number=3;
	int customer_numbers=6;

	Customer* cus = new Customer[customer_numbers];
	Mechanic* mech = new Mechanic[mechanincs_number];			



	ifstream read_c;
	read_c.open("customers.txt");					//reading customers data
	for (int i = 0; i < customer_numbers; i++)
	{
		read_c >> tempWORD;
		cus[i].set_name(tempWORD);
		read_c >> tempWORD;
		cus[i].set_id(tempWORD);
		read_c >> tempINT1;
		cus[i].set_age(tempINT1);
		read_c >> tempINT2;
		read_c >> tempINT3;
		cus[i].set_appointment(tempINT2, tempINT3);
		//cus[i].print();
	}
	read_c.close();


												//loading mechanics data.
	ifstream read_m;
	read_m.open("mechanics.txt");
	for (int i = 0; i < 3; i++)
	{
		read_m >> tempWORD;
		mech[i].set_name(tempWORD);
		read_m >> tempINT1;
		mech[i].set_age(tempINT1);
		read_m >> tempWORD;
		mech[i].set_id(tempWORD);
		read_m >> tempINT1;
		mech[i].set_count(tempINT1);
		for (int j = 0; j < tempINT1; j++)
		{
			read_m >> tempINT2;
			read_m >> tempINT3;
			mech[i].add_appointment(tempINT2, tempINT3);
		}
		//mech[i].print();
	}
	read_m.close();
	

	Queue<Customer>Qcustomers(customer_numbers);
	
	cout << "Customers' appointments:-\n\n";
	for (int i = 0; i < customer_numbers; i++)
	{
		for (int j = i%3; j < mechanincs_number; j++)
		{
			if (mech[j].is_available(cus[i].get_appointment()))
			{
				mech[j].add_appointment(cus[i].get_appointment());
				cus[i].set_mechanical_name(mech[j].get_name());
				Qcustomers.push(cus[i]);
				j = 3;
			}
			else if (j == 2)   //if no mechanic is availabe
			{
				cout << " ##There are no avialable appointments for customer " << cus[i].get_name() << " at " << cus[i].get_appointment().hours<<":"<<cus[i].get_appointment().mins << " ##\n\n";
			}
		}
	}
	
	Qcustomers.display();
	delete[]mech;
	delete[]cus;
	return 0;
}
