#include<iostream>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//Constructors

	Point()
	{
		x = y = 0;
		cout << "Constructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		y = 0;
		cout << "1 Arg constructor:\t" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "2 Arg constructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}
	double distance(Point other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	void Print()
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(x_distance * x_distance + y_distance * y_distance);
}

//#define STRUCT_POINT
//#define distance_check

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	//members
	Point A;

	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif

#ifdef distance_check
	Point A, B;
	A.set_x(2);
	A.set_y(3);
	B.set_x(7);
	B.set_y(8);
	//cout << A.get_x() << "\t" << A.get_y() << endl;
	//cout << B.get_x() << "\t" << B.get_y() << endl;
	A.Print();
	B.Print();
	cout << "���������� �� ����� � �� ����� �: " << A.distance(B) << endl;
	cout << "���������� �� ����� B �� ����� A: " << B.distance(A) << endl;
	cout << "���������� ����� ������� � � �: " << distance(A, B) << endl;
	cout << "���������� ����� ������� B � A: " << distance(B, A) << endl;
#endif // distance_check

	Point A;
	A.Print();
	Point B(2, 3);
	B.Print();
	Point C = 5;
	C.Print();
}
