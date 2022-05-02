//***********************************************************
//
//	File:		 Stock.cpp
//
//	Description: Function definitions for Stock class.
//
//***********************************************************

#include "Stock.h"

Stock::Stock()
{
	name = "";
	symbol = "";
	price = 0;
	freq = 0;
}

Stock::Stock(std::string n, std::string s, double p, double f)
{
	name = n;
	symbol = s;
	price = p;
	freq = f;
}

Stock::Stock(const Stock& s)
{
	name = s.name;
	symbol = s.symbol;
	price = s.price;
	freq = s.freq;
}

void Stock::display()const
{
	std::cout << getName() << getSymbol() << getPrice() << getFreq() << std::endl;
}

std::ostream& operator <<(std::ostream& os, const Stock& s)
{
	os << "Name: " << s.getName() << std::endl;
	os << "Symbol: " << s.getSymbol() << std::endl;
	os << "Price: " << s.getPrice() << std::endl;
	os << "Frequency: " << s.getFreq() << std::endl;

	return os;
}

std::istream& operator >>(std::istream& is, Stock& s)
{
	getline(is, s.name);
	getline(is, s.symbol);
	is >> s.price;
	is.ignore();
	is >> s.freq;
	is.ignore();

	return is;
}