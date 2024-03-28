#include"Sequence_Stack.h"
#include<iostream>

MyStack::MyStack()
{
	Init_Stack();
}

MyStack::MyStack(int size)
{
	Init_Stack();
	Stack_DataType temp_data = Init_StackData;
	for (int i = 0; i < size; i++)
	{
		std::cout << "输入第" << i + 1 << "元素" << std::endl;
		std::cin >> temp_data;
		Push_Stack(temp_data);
	}
}

MyStack::~MyStack()
{
	Clear_Stack();
	Destory_Stack();
}

void MyStack::Init_Stack()
{
	Stack_Node* temp = new Stack_Node;
	if (temp == 0)
	{
		std::exit(1);
	}
	top = temp;
	bottom = temp;
}

void MyStack::Destory_Stack()
{
	delete(bottom);
}

void MyStack::Clear_Stack()
{
	if (bottom == top)
	{
		return;
	}
	Stack_Node* cur = bottom->next;
	Stack_Node* next = cur->next;

	while (cur != NULL)
	{
		delete(cur);
		if (next == NULL)
		{
			break;
		}
		cur = next;
		next = next->next;
	}
	top = bottom;
}

bool MyStack::Stack_Empty()
{
	return (bottom == top) ? true : false;
}

int MyStack::Stack_length() {

	int num = 0;
	Stack_Node* cur = bottom;

	while (cur != top) {
		num++;
		cur = cur->next;
	}
	return num;
}

int MyStack::Top_Stack()
{
	if (bottom == top)
		return false;
	int value = top->data;
	return value;
}

bool MyStack::Push_Stack(Stack_DataType& value)
{
	Stack_Node* temp = new(std::nothrow) Stack_Node(value);
	if (temp == 0) {
		return false;
	}

	top->next = temp;
	top = temp;
	return true;
}

bool MyStack::Pop_Stack()
{
	if (top == bottom)
		return false;
	Stack_Node* prior = bottom;
	while (prior->next != top) {    //  找到栈顶第二个元素
		prior = prior->next;
	}

	delete(top);
	top = prior;
	top->next = NULL;
	return true;
}

bool MyStack::Pop_Stack(Stack_DataType& value)
{
	if (top == bottom)
		return false;
	Stack_Node* prior = bottom;

	while (prior->next != top) {
		prior = prior->next;
	}
	value = top->data;
	delete(top);
	top = prior;
	top->next = NULL;
	return true;
}

void MyStack::Print_Stack()
{
	Stack_Node* cur = bottom->next;

	while (cur != top) {
		std::cout << cur->data << std::endl;
		cur = cur->next;
	}

	std::cout << top->data << std::endl;
}
