#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

struct Poly {
	int cof;
	int exp;
	Poly* next;
};

Poly* addPoly(Poly* a, Poly* b);
void Add(int result, int exp , Poly*& last);
void printPoly(Poly* c);

int main() {
	//a+b
	Poly* a = new Poly();
	Poly* b = new Poly();
	Poly* ptra, *ptrb, *temp , *c;
	ptra = a;
	ptrb = b;
	int n,cof,exp;

	cout << " n = > ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		Poly* temp = new Poly();
		cin >> cof >> exp;
		temp->cof = cof;
		temp->exp = exp;
		temp->next = NULL;
		ptra->next = temp;
		ptra = temp;
	}

	cout << " n = > ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		Poly* temp = new Poly();
		cin >> cof >> exp;
		temp->cof = cof;
		temp->exp = exp;
		temp->next = NULL;
		ptrb->next = temp;
		ptrb = temp;
	}
	a = a->next;
	b = b->next;
	
	c=addPoly(a, b);

	printPoly(c);
	delete a;
	delete b;
	return 0;
}

Poly * addPoly(Poly* a, Poly* b) {

	Poly* front = new Poly();
	Poly* last;
	last = front;

	while (a && b) {
		if (a->exp < b->exp) {
			Add(b->cof, b->exp, last);
			b = b->next;
		}
		else if (a->exp > b->exp) {
			Add(a->cof, a->exp, last);
			a = a->next;
		}
		else {
			Add(a->cof + b->cof, a->exp, last);
			a = a->next;
			b = b->next;
		}
	}

	for (; a; a = a->next) {
		Add(a->cof, a->exp, last);
	}

	for (; b; b = b->next) {
		Add(b->cof, b->exp, last);
	}
	last->next = NULL;
	front = front->next;
	//delete last;

	return front ;
}

//要改變指向的東西*& ，*只能改變指向的內容
void Add(int result, int exp , Poly*& last) {

	Poly* temp = new Poly();
	temp->cof = result;
	temp->exp = exp;
	temp->next = NULL;
	last->next = temp;
	last = temp;
}

void printPoly(Poly* c) {
	while (c) {
		if (c->cof != 0) {
			if (c->exp == 0) {
				printf("%d", c->cof);
			}
			else if (c->cof == 1 && c->exp != 0) {
				printf("x%d", c->exp);
			}
			else {
				printf("%dx%d", c->cof, c->exp);
			}

			if (c->next) {
				cout << " + ";
			}
		}
		c = c->next;
		
	}
}