#include "LoanItem.h"


LoanItem::LoanItem(double r, int l, int p, string pb) {
	LoanRate = r;
	LoanLimit = l;
	Period = p;
	PayBackWay = pb;

}



void LoanItem::LoanItemInfo(int n) {
	cout << "======================" << endl;
	cout << "< " << n + 1 << "�� ���� ��ǰ ���� >" << endl;
	cout << "����� �� �ݸ� :  ��" << LoanRate << " %" << endl;
	cout << "�ִ� �ѵ� :  " << LoanLimit << " ��" << endl;
	cout << "���� �Ⱓ :  " << Period << " ��" << endl;
	cout << "��ȯ ��� :  " << PayBackWay << endl;
	cout << "======================" << endl;
}

double LoanItem::getLoanRate() {
	return LoanRate;
}


int LoanItem::getPeriod() {
	return Period;
}

string LoanItem::getPayBackWay() {
	return PayBackWay;
}