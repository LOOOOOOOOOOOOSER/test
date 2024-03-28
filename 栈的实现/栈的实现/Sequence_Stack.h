#pragma once
#include<iostream>


#define Stack_DataType int
#define Init_StackData 99

class Stack_Node
{
public:
	Stack_Node()
	{
		data = Init_StackData;
		next = NULL;
	}
	Stack_Node(Stack_DataType element) : data(element), next(NULL)
	{
	}

	Stack_DataType data;
	Stack_Node* next;

};

class MyStack
{
public:
	MyStack();
	MyStack(int size);
	~MyStack();

	void Init_Stack();	//初始化栈
	void Destory_Stack();	//摧毁栈
	void Clear_Stack();		//清空栈
	bool Stack_Empty();		//栈是否为空
	int Stack_length();		//栈的长度

	int Top_Stack();							//获取栈顶元素
	bool Push_Stack(Stack_DataType& value);		//插入栈顶元素

	bool Pop_Stack();							//出栈
	bool Pop_Stack(Stack_DataType& value);		//删除栈顶元素

	void Print_Stack();

private:
	Stack_Node* top;		//栈顶
	Stack_Node* bottom;		//栈底
};


