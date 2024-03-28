#include<iostream>

using namespace std;
//定义链表存放的数据类型
typedef int datatype;
//创建结点类
class Node
{
public:
	datatype data; //结点中的数据域
	Node* next;    //结点中的指针域，结点类型的指针
};
//创建循环链表类
class CircluLinkList
{
public:
	CircluLinkList();//构造函数
	~CircluLinkList();//析构函数
	bool empty();//判断链表是否为空，为空返回1，不为空返回0
	int size();//返回链表元素个数
	void traverse();//打印遍历整个链表
	void clear();//清空链表
	void push_front(datatype);//头插
	void push_back(datatype);//尾插
	void pop_front();//头删
	void pop_back();//尾删
	void insert(int, datatype);//任意位置插入
	void erase(int);//删除任意位置元素
	datatype at(int);//返回索引位置数据
	datatype operator[](int);//重载[]，返回索引位置数据

	int counter;//链表元素个数
	Node* head;//创建头结点指针，结点类型指针，当前未赋值
private:



};
//构造函数
CircluLinkList::CircluLinkList()
{
	this->head = new Node;    //给头结点指针实例化一个结点
	this->head->data = 0;   //头结点数据，头结点一般不存放数据
	this->head->next = this->head;  //头结点指针指向自己
	this->counter = 0;        //未插入数据前，元素个数为0
}
//析构函数
CircluLinkList::~CircluLinkList()
{
	if (this->counter == 0)
	{
		delete head;
	}
	else
	{
		Node* temp = this->head->next;
		Node* temp2 = NULL;


		while (temp != this->head)
		{
			temp2 = temp->next;
			delete temp;
			temp = temp2;
		}
		delete temp;
	}


}
//判断链表是否为空，为空返回1，不为空返回0
bool CircluLinkList::empty()
{
	if (this->head->next == this->head || this->head == NULL)//(头结点不算做链表中的元素，因此在此若只有头结点也算空链表)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//返回链表元素个数
int CircluLinkList::size()
{
	return this->counter;
}
//打印遍历整个链表
void CircluLinkList::traverse()
{
	Node* temp = this->head->next;//创建一个结点指针遍历每个结点
	while (temp != this->head)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
//清空链表
void CircluLinkList::clear()
{
	if (this->counter == 0)
	{
		return;
	}
	Node* temp = this->head->next;
	Node* temp2 = NULL;

	while (temp != this->head)
	{
		temp2 = temp->next;
		delete temp;
		temp = temp2;
	}
	this->head->next = head;
	this->counter = 0;
}
//头插
void CircluLinkList::push_front(datatype newelem)
{
	if (this->head == NULL)
	{
		return;
	}
	Node* newnode = new Node;
	newnode->data = newelem;
	newnode->next = this->head->next;
	this->head->next = newnode;
	this->counter = this->counter + 1;//元素个数加一
}
//尾插
void CircluLinkList::push_back(datatype newelem)
{
	if (this->head == NULL)
	{
		return;
	}
	Node* newnode = new Node;
	Node* temp = head;
	newnode->data = newelem;
	newnode->next = this->head;
	for (int i = 0; i < this->counter; i++)
	{
		temp = temp->next;
	}
	temp->next = newnode;
	this->counter = this->counter + 1;//元素个数加一
}
//头删
void CircluLinkList::pop_front()
{
	if (this->head == NULL || this->counter == 0)
	{
		return;
	}
	Node* temp = new Node;
	temp = this->head->next;
	this->head->next = temp->next;
	delete temp;
	this->counter = this->counter - 1;//元素个数减一
}
//尾删
void CircluLinkList::pop_back()
{
	if (this->head == NULL || this->counter == 0)
	{
		return;
	}
	Node* temp = this->head;
	Node* temp2 = new Node;
	for (int i = 1; i < this->counter; i++)
	{
		temp = temp->next;
	}
	temp2 = temp->next;
	temp->next = this->head;
	delete temp2;
	this->counter = this->counter - 1;//元素个数减一
}
//任意位置插入
void CircluLinkList::insert(int pos, datatype newelem)
{
	if (this->head == NULL || pos > this->counter)
	{
		return;
	}
	Node* newnode = new Node;
	Node* temp = head;
	newnode->data = newelem;
	for (int i = 1; i < pos; i++)
	{
		temp = temp->next;

	}
	newnode->next = temp->next;
	temp->next = newnode;
	this->counter = this->counter + 1;//元素个数加一
}
//任意位置删除
void CircluLinkList::erase(int pos)
{
	if (this->head == NULL || pos > this->counter)
	{
		return;
	}
	Node* temp = this->head;
	Node* temp2 = new Node;
	for (int i = 1; i < pos; i++)
	{
		temp = temp->next;
	}
	temp2 = temp->next;
	temp->next = temp2->next;
	delete temp2;
	this->counter = this->counter - 1;//元素个数减一
}
//返回索引位置数据
datatype CircluLinkList::at(int pos)
{
	if (this->head == NULL || pos > this->counter)
	{
		return 0;
	}
	Node* temp = head;
	for (int i = 0; i < pos; i++)
	{
		temp = temp->next;
	}
	return temp->data;
}
//重载[]，返回索引位置数据
datatype CircluLinkList::operator[](int pos)
{
	if (this->head == NULL || pos > this->counter)
	{
		return 0;
	}
	Node* temp = head;
	for (int i = 0; i < pos; i++)
	{
		temp = temp->next;
	}
	return temp->data;
}

int main()
{
	//Map map;
	//map.build_matrix(3, 6);

	CircluLinkList lst;//新建链表，实例化
	cout << lst.empty() << endl;//判断链表是否为空
	for (int i = 1; i < 3; i++)
	{
		lst.push_back(i);//尾插1-2两个元素
	}
	for (int i = 10; i < 12; i++)
	{
		lst.push_front(i);//头插10-11两个元素
	}
	lst.traverse();//遍历打印表中元素
	lst.pop_front();//头删1个元素
	lst.pop_back();//尾删1个元素
	lst.insert(2, 100);//在第2位插入100
	lst.erase(3);//删除第3位元素
	lst.traverse();//遍历打印表中元素
	cout << lst.empty() << endl;//判断链表是否为空
	cout << lst.size() << endl;//查看表中元素个数
	lst.clear();//清空链表
	for (int i = 1; i < 10; i++)
	{
		lst.push_back(i);//尾插0-9十个元素
	}
	lst.traverse();//遍历打印表中元素
	cout << lst.at(3) << endl;//查找第3位元素
	cout << lst[4] << endl;//查找第4位元素

	return 0;
}
