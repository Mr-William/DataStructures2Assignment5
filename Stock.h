//***********************************************************
//
//	File:		 Stock.h
//	
//	Description: Header file for stock class
//
//***********************************************************

#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <string>

class Stock
{
private:
	std::string name;
	std::string symbol;
	double price;
	double freq;
public:
	Stock();
	Stock(std::string, std::string, double, double);
	Stock(const Stock&);
	void display() const;
	std::string getName() const { return name; };
	std::string getSymbol() const { return symbol; };
	double getPrice() const { return price; };
	double getFreq() const { return freq; };
	int hash(int size) { return size % 10; };
	bool operator ==(const Stock& rhs) const { return rhs.symbol == symbol; };
	bool operator !=(const Stock& rhs) const { return !(rhs.symbol == symbol); };
	bool operator <(const Stock& r) const { return r.symbol < symbol; };
	bool operator >(const Stock&r) const { return !(r.symbol < symbol); };
	friend std::ostream& operator <<(std::ostream&, const Stock&);
	friend std::istream& operator >>(std::istream&, Stock&);
};

#endif