#include<iostream>
#include<string>

constexpr auto maxlist = 20;

using namespace std;

struct book
{
	char CODE[8];      // book code 
	char BKN[51];      //BOOK'NAME
	char WTN[51];      //WRITER'NAME
	char PLSN[51];     //PUBLISHER'NAME
	int price;
	int NBP ;        // NUMBER OF PAGE
	int YPL;        // the year of publishing 
};

struct roll
{
	int n;
	book bk[maxlist];
};
void input_a_book(book& b);
void output_a_book(book b);
bool bk_less_k_page(book b, int k);

void add_book(roll& ds, int& position);
void add_book(roll& ds, int& position);
void delete_a_book(roll& ds, int position);
void remove_bk_ypl(roll& ds, int year);

void input_roll(roll &ds);
void output_roll(roll ds);
void sort_ypl(roll &ds);
void swap(book &b1, book &b2);
void less_k_page_costest(roll ds, int k);


