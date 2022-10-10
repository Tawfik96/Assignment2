#ifndef Q_H
#define Q_H
template <class t>
class Queue
{
private:
	int end;
	int size;
	t* customers;
public:
	Queue(int s = 0)
	{
		end = -1;
		size = s;
		customers = new t[size];
	}

	int get_size()
	{
		return end + 1;
	}
	bool isfull()
	{
		if (end == size - 1)
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
		for (int i = end; i > indx; i--)
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
		t temp = customers[0];
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
			cout << i + 1 << "- " << customers[i].get_name() << " is with osta " << customers[i].get_mechanical_name() << " at  [" << customers[i].get_appointment().hours << ":" << customers[i].get_appointment().mins << "]";
			cout << "\n------------------------------------\n";
		}
	}
};
#endif // !Q_H

