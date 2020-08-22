#include "list.h"

using namespace std;

int main()
{
	roll b;
	
	int l = 0;
	cout << "Enter the fuction you want to perform:\n"
		<< "1. Enter and print the book list on the screen\n"
		<< "2. Sort the book list up follow the book'price\n"
		<< "3. Find the book whose the number of page less than k and has the highest price. Allow the user to enter k number\n"
		<< "4. Add a book to the roll. allow the user to enter the position and book's information. check the validity of the location that the user added\n"
		<< "5. remove the books whose publication year before the assigned year from the list\n";
	cin >> l;
	switch (l)
	{
	case 1:
	{
		input_roll(b);
	    output_roll(b);
		break;
	}
	case 2:
	{
		input_roll(b);
		sort_ypl(b);
		cout << "the list after being sorting:\n";
		output_roll(b);
		break;
	}
	case 3:
	{
		int k = 0;
		input_roll(b);
		cout << "Enter k: ";
		cin >> k;
		less_k_page_costest(b, k);
		break;
	}
	case 4:
	{
		int po = 0;
		cout << "enter the position: ";
		cin >> po;
		if (po > 0 && po <= b.n)
		{
			add_book(b, po);
		}
		else cout << "ilegal position!";
		cout << "list after add";
		output_roll(b);
		break;
	}
	case 5:
	{
		int y=0;
		input_roll(b);
		cout << "Enter the assighed year: ";
		cin >> y;
		remove_bk_ypl(b, y);
		cout << "the final roll:\n";
		output_roll(b);
	}
	}
	
	return (0);
}  