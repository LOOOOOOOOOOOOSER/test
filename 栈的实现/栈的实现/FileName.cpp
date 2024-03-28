#include"Sequence_Stack.h"
#include<iostream>

using namespace std;

int main()

{
	MyStack a(3);
	a.Print_Stack();		//遍历栈元素

	int b = 10;
	a.Push_Stack(b);		//插入栈顶元素

	cout << "插入后遍历:" << endl;
	a.Print_Stack();

	cout << "栈顶元素:" << a.Top_Stack() << endl;
	a.Pop_Stack();			//	出栈

	a.Pop_Stack(b);

	cout << "删除后遍历:" << endl;
	a.Print_Stack();

	cout << "栈的大小:" << a.Stack_length() << endl;
	system("pause");
	return 0;
}
