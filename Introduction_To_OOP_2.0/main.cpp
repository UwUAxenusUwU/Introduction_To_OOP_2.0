#include<iostream>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n-----------------------------------------------------\n"

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

	//Point()
	//{
	//	x = y = 0;
	//	cout << "Constructor:\t" << this << endl;
	//}
	//Point(double x)
	//{
	//	this->x = x;
	//	y = 0;
	//	cout << "1 Arg constructor:\t" << this << endl;
	//}
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//			Operators: 

	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment\t" << this << endl; 
		return *this;
	}

	//			Methods

	double distance(const Point& other)
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

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(x_distance * x_distance + y_distance * y_distance);
}

//#define STRUCT_POINT
//#define distance_check
//#define COSTRUCTORS_CHECK
//#define ASSIGNMENT_OPERATOR

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
	cout << delimiter << endl;
	cout << "Расстояние от точки А до точки В: " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками А и В: " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками B и A: " << distance(B, A) << endl;
	cout << delimiter << endl;
#endif // distance_check

#ifdef COSTRUCTORS_CHECK
	Point A;
	A.Print();

	Point B(2, 3);
	B.Print();

	Point C = 5;
	C.Print();

	Point D = C;	//Copy constructor 
	D.Print();

	Point E;
	E = D;			//Assignment operator
	E.Print();

#endif // COSTRUCTORS_CHECK

#ifdef ASSIGNMENT_OPERATOR
	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2, 3);
	cout << delimiter << endl;
	A.Print();
	B.Print();
	C.Print();
#endif // ASSIGNMENT_OPERATOR



}
