#include "list.h"
#include<string>

using namespace std;

void input_a_book(book &b)
{
	//cin.ignore();
	cout << "Book,'s code: ";
	cin.getline(b.CODE,8);
	if (strlen(b.CODE) <= 7)
	{
		cout << "book's name:";
		cin.getline(b.BKN,51);
		cout << "writer's name:";
		cin.getline(b.WTN, 51);
		cout << "publisher's name:";
		cin.getline(b.PLSN, 51);
		cout << "the price:";
		cin >> b.price;
		cout << "the number of page: ";
		cin >> b.NBP;
		cout << "the year of publishing:";
		cin >> b.YPL;
	}
	else cout << "ilegle code!";
}
void output_a_book(book b)
{
	    cout << "Book's code: "<< b.CODE;
		cout << "\nBook's name: " << b.BKN;
		cout << "\nWriter's name: " << b.WTN;
		cout << "\nPublisher's name: "<<b.PLSN;
		cout << "\nThe price:"<< b.price;
		cout << "\nThe number of page: "<< b.NBP;
		cout << "\nThe year of publishing: "<< b.YPL;
}

void input_roll(roll &ds)
{
	cout << "Enter the number of book: ";
	cin >> ds.n;
	for (int i = 0; i < ds.n; i++)
	{
		cin.ignore();
		input_a_book(ds.bk[i]);
		cout << "\n";
	}
}
void output_roll(roll ds)
{
	for (int i = 0; i < ds.n; i++)
	{
		cout << "\n========================================\n";
		output_a_book(ds.bk[i]);
		cout << "\n========================================\n";
	}
}
void swap(book &b1, book &b2)
{
	book temp = b1;
	b1 = b2;
	b2 = temp;
}
void sort_ypl(roll &ds)  // sorting up follow the year of pulishing
{
	for (int i = 0; i < ds.n-1; i++)
		for (int j=i+1; j<ds.n;j++)
			if (ds.bk[i].YPL > ds.bk[j].YPL)
			{
				swap(ds.bk[i], ds.bk[j]);
			}
	         
}
bool bk_less_k_page(book b, int k)// check if the number of page less than k  
{
	if (b.NBP < k) return (true); else return (false);
}
void less_k_page_costest(roll ds, int k)
{
	int max = 0;
	int index = 0;
	for (int i = 0; i < ds.n; i++)
	{
		if (bk_less_k_page(ds.bk[i], k) && ds.bk[i].NBP >= max)
		{
			max = ds.bk[i].NBP;
			index = i;
		}
	}
	output_a_book(ds.bk[index]);
}
void add_book(roll &ds, int &position)//1 3 4 5 45 4 88 77 x
{
	ds.n = ds.n + 1;
	book b;
	cout << "enter book's information that you want to add to the list\n";
	cin.ignore();
	input_a_book(b);
	for (int i = ds.n; i > position; i--)
	{
		ds.bk[i] = ds.bk[i - 1];
	}
	ds.bk[position] = b;
}
void delete_a_book(roll& ds, int position)
{
	ds.n = ds.n - 1;
	for (int i = position; i < ds.n-1; i++)
	{
		ds.bk[i] = ds.bk[i + 1];
	}
	ds.n = ds.n - 1;
}
void remove_bk_ypl(roll& ds, int year)//remove the books whose publication year before the assigned year from the list
{
	for (int i = 0; i < ds.n; i++)
	{
		if (ds.bk[i].YPL < year)
		{
			delete_a_book(ds, i);
		}
	}
}