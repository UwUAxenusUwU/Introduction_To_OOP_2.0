#include<iostream>
using namespace std;

#define delimiter "\n----------------------------------------\n"

class Fraction
{
	int ts;
	int ch;
	int zn;
public:
	int get_ts()const
	{
		return ts;
	}
	int get_ch()const
	{
		return ch;
	}
	int get_cn()const
	{
		return zn;
	}
	void set_ts(int ts)
	{
		this->ts = ts;
	}
	void set_ch(int ch)
	{
		this->ch = ch;
	}
	void set_zn(int zn)
	{
		this->zn = zn;
	}
	Fraction()
	{
		ts = ch = zn = 0;
		cout << "Constructor EMPTY\t" << this << endl;
	}
	Fraction(int ts)
	{
		this->ts = ts;
		this->ch = 0;
		this->zn = 0;
		cout << "Constructor only TS\t" << this << endl;
	}
	Fraction(int ch, int zn)
	{
		this->ts = 0;
		this->ch = ch;
		this->zn = zn;
		cout << "Constructor wothout TS\t" << this << endl;
	}
	Fraction(int ts, int ch, int zn)
	{
		this->ts = ts;
		this->ch = ch;
		this->zn = zn;
		cout << "Constructor FULL fraction\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->ts = other.ts;
		this->ch = other.ch;
		this->zn = other.zn;
		cout << "Copy Constructor\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor\t" << this << endl;
	}

	//Operators

	Fraction operator+(const Fraction& other)
	{
		return Fraction(this->ts + other.ts, this->ch * other.zn + other.ch * this->zn, this->zn * other.zn);
	}

	//Methods

	void Print()
	{
		if (ch == 0 || zn == 0) cout << ts << endl;
		else if (ts == 0)  
			cout << ch << " / " << zn << endl; 
		else 
			cout << ts << " ( " << ch << " / " << zn << " ) " << endl;
		return;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	Fraction A(2,3);
	Fraction B(3, 4, 5);
	A.Print();
	B.Print();
	Fraction C = B;
	C.Print();
	cout << delimiter << endl;
	Fraction D = A + B;
	D.Print();


}