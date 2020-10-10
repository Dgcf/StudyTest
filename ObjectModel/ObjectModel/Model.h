#pragma once
#include "common.h"
//class Model
//{
//};
//
//class Base
//{
//public:
//	Base(int a, char c);
//
//private:
//	int a_;
//	char c_;
//};
//
//class Derived1 : Base
//{
//public:
//	Derived1(int b);
//private:
//	int b_;
//};
//
//class Point2d
//{
//public:
//	
//protected:
//	float _x, _y;
//};
//
////class Point3d
////{
////public:
////	Point3d();
////public:
////	//static Point3d origin;
////	float x, y, _z;
////};
//
//class Vertex
//{
//public:
//
//protected:
//	Vertex* next;
//};
//
//class Vertex3d :public Point3d, public Vertex
//{
//public:
//
//protected:
//	float mumble;
//};
//
////class Point
////{
////public:
////	virtual ~Point();
////	float x();
////	float y();
////	virtual float z();
////};
//
//class Abstract_Base
//{
//public:
//	virtual ~Abstract_Base();
//	virtual void interface() const = 0;
//	const char *mumble() const { return _mumble; }
//
//protected:
//	Abstract_Base(char* pc);
//private:
//	char* _mumble;
//};
//
//class Point
//{
//public:
//	Point(float x = 0.0, float y = 0.0);
//	Point(const Point&);
//	Point& operator=(const Point&);
//	virtual ~Point();
//	virtual float z() { return 0.0; }
//
//protected:
//	float _x, _y;
//};
//
//class Line
//{
//	Point _begin, _end;
//
//public:
//	Line(float = 0.0, float = 0.0, float = 0.0, float = 0.0);
//	Line(const Point&, const Point&);
//};
//
//class Point3d :public virtual Point
//{
//public:
//
//};
//
//class Point1 
//{
//public:
//	Point1(float x = 0.0, float y = 0.0);
//protected:
//	float _x, _y;
//};
//
//class Y
//{
//public:
//	Y();
//	~Y();
//	bool operator=(const Y&) const;
//};
//
//class X
//{
//public:
//	X();
//	~X();
//	operator Y() const;
//	X getValue();
//};

// 运算符重载
class Wrap
{
public:
	Wrap(const char* _s)
	{
		memset(s, 0, sizeof(s));
		strncpy(s, _s, sizeof(s));
	}

	operator const char* ()
	{
		return s;
	}

private:
	char s[64];
};

void test_warp();


/**
 * 函数对象:只读文件打开/关闭操作
 */
class FileOp
{
public:
	FILE* operator()(const char* file_name)
	{
		cout << "Enter in operator()" << endl;
		fp = fopen(file_name, "wb");
		return fp;
	}

	~FileOp()
	{
		cout << "~FileOp" << endl;
		if (fp)
		{
			fclose(fp);
			fp = nullptr;
		}
	}

private:
	FILE* fp;
};

inline void FileOpTest()
{
	FILE* fp = FileOp()("./hello.txt");
	cout << "Leave FileOpTest" << endl;
}

