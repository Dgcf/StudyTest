#include "ForTest.h"

void print_var()
{
	// cout << "glo: " << glo << endl;
}

typedef WidgetManager<OptNewCreator> MyWidgetManager;

void test_policy1()
{
	MyWidgetManager wm;
	wm.test();
}

void test_typelist()
{
	cout << "typelist length: " << tl::TL_Length<TYPELIST_4(int, float, double, char)>::value << endl;
	cout << "TypeAt: " << typeid(tl::TypeAt<TYPELIST_4(int, float, double, char), 3>::Result).name() << endl;
	cout << "Index of: " << tl::IndexOf<TYPELIST_4(int, float, char, char), char>::value << endl;
	cout << "Append: " << typeid(tl::Append<TYPELIST_4(int, float, double, char), string>::Result).name() << endl;
	cout << "Erase: " << typeid(tl::Erase<TypeList<int, TypeList<float, TypeList<double, NullType>>>, float>::Result).name() << endl;
	cout << "Erase NoDuplicates: " << typeid(tl::NoDuplicates<TYPELIST_4(int, float, double, float)>::Result).name() << endl;
}

template<typename>
class T1 {};

void test_GenScatterHierarchy()
{
	typedef tl::GenScatterHierarchy<TYPELIST_3(int, string, Widget), Holder> WidgetInfo;
	//WidgetInfo obj;
	//tl::GenScatterHierarchy<TypeList<int, TypeList<TypeList<string,double>, NullType>>, Holder> obj;
	//Holder<int> h = static_cast<Holder<int>>(obj);
	
	//string n = Field(obj);
	tl::GenScatterHierarchy<TypeList<int, TypeList<string, NullType>>, Holder> w;
	Holder<int> h1 = static_cast<Holder<int>>(w);
}

void TestFunction(int& i, double d)
{
	cout << "TestFunction(" << i << ", " << d << ") called." << endl;
}

void TestFunctorHandle()
{

}

void test_functor()
{
	TestFunctor f;
	Functor<void, TYPELIST_2(int, double)> cmd(f);
	int x = 4;
	cmd(x, 4.5);

	// 这里如果直接把TestFunction传给cmd1编译报错，如果给函数指针类型再传递给cmd1就OK
	MY_FUNC* f0 = TestFunction;
	Functor<void, TYPELIST_2(int, double)> cmd1(f0);
	cmd1(3, 3.5);
}

void test_abstractenemyfactory()
{
	//AbstractEnemyFactory* p
}

void test_visitor()
{
	MyConcreteVisitor visitor;
	Paragraph par;
	DocElement* d = &par;
	d->Accept(visitor);
}

void test_typetraits()
{
	bool iterIsPtr = TypeTraits<vector<int>::iterator>::isPointer;
	cout << "vector<int>::iterator is " << (iterIsPtr ? "fast" : "smart") << "\n";

	typedef void(TestTypeTraits::* FuncType)();
	bool isMemPtr = TypeTraits<FuncType>::isMemPtr;
	cout << "FuncType isMemPtr:  " << (isMemPtr ? "is member ptr" : "is not member ptr") << "\n";

	isMemPtr = TypeTraits<int>::isMemPtr;
	cout << "int isMemPtr:  " << (isMemPtr ? "is member ptr" : "is not member ptr") << "\n";
}


