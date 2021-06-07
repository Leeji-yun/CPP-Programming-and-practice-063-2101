#ifndef _LOAN_ITEM_
#define _LOAN_ITEM_
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class LoanItem
{
private:
	double LoanRate; 
	int LoanLimit;    
	int Period;
	string PayBackWay; 
public:
	LoanItem(double r, int l, int p, string pb);
	void LoanItemInfo(int ChoiceNumber);
	double getLoanRate();
	int getPeriod();
	string getPayBackWay();
};


#endif
