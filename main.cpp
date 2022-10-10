
#include"Customer.h"
#include"Mechanic.h"
#include"Q.h"
#include<fstream>


int main()
{
	string tempWORD;
	int tempINT1;
	int tempINT2;			//Fstream temporary variables.
	int tempINT3;

	int mechanincs_number = 3;
	int customer_numbers = 6;

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
		cus[i].print();
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
		for (int j = i % 3; j < mechanincs_number; j++)
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
				cout << " ##There are no avialable appointments for customer " << cus[i].get_name() << " at " << cus[i].get_appointment().hours << ":" << cus[i].get_appointment().mins << " ##\n\n";
			}
		}
	}

	Qcustomers.display();

	delete[]mech;
	delete[]cus;
	return 0;
}
