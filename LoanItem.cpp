#include "LoanItem.h"


LoanItem::LoanItem(double r, int l, int p, string pb) {
	LoanRate = r;
	LoanLimit = l;
	Period = p;
	PayBackWay = pb;

}



void LoanItem::LoanItemInfo(int n) {
	cout << "======================" << endl;
	cout << "< " << n + 1 << "번 대출 상품 정보 >" << endl;
	cout << "대출시 연 금리 :  연" << LoanRate << " %" << endl;
	cout << "최대 한도 :  " << LoanLimit << " 원" << endl;
	cout << "대출 기간 :  " << Period << " 년" << endl;
	cout << "상환 방법 :  " << PayBackWay << endl;
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