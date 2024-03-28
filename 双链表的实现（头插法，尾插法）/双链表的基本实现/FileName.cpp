#include<iostream>
#include <stdio.h>
#include <string>

using namespace std;

typedef struct DNode {//定义双链表节点结构体
	DNode* pre;//前驱指针
	int data;//数据域
	DNode* next;//后继指针
}DNode, * LinkList;//定义双链表节点和双链表

//1.初始化双链表节点
bool InitList(LinkList& L) {
	L = new DNode;
	if (!L) {
		cout << "申请节点失败！" << endl;
		return false;
	}
	else {
		L->next = NULL;//初始化后继指针
		L->pre = NULL;//初始化前驱指针
		//cout << "申请节点成功！" << endl;
		return true;
	}
}
//2.打印双链表
bool PrintList(LinkList& L) {
	if (L->next == NULL) {
		cout << "该双链表不存在！" << endl;
		return false;
	}//判断是否是空链表
	DNode* p = L->next;
	while (p)
	{
		cout << p->data << " ";//打印数据
		p = p->next;//向后移动指针
	}
	cout << endl;
	return true;
}
//3.获取有效长度
int Length(LinkList& L) {
	DNode* p = L->next;//申请一个新节点
	int lenth = 0;//该变量用来保存长度
	while (p) {//p不为空时执行
		lenth++;//长度加1
		p = p->next;//节点向后移动
	}
	cout << endl;//只是为了换行
	return lenth;
}
//4.创建双链表
//（1）采用头插入法
bool ListHeadInsert(LinkList& L) {
	int x;
	cout << "请输入元素的个数:";
	cin >> x;
	if (x <= 0) {
		cout << "您输入的值无意义!" << endl;
		return false;
	}
	cout << "请依次输入元素的值！" << endl;
	while (x) {
		DNode* p = new DNode;//申请一个新节点
		cin >> p->data;//为新节点输入数据
		p->next = L->next;//将头节点的后继指针赋给新节点
		p->pre = L;//再让新节点的前驱指针指向头节点
		L->next = p;//移动头节点
		x--;//判断循环条件
	}
	cout << "采用头插法成功创建的双链表结果为：";
	PrintList(L);//打印双链表
	return true;
}
//（2）尾插入法
bool TailInsert(LinkList& L) {
	DNode* p = new DNode;//申请一个节点
	InitList(p);//初始化新节点
	L = p;//让新节点赋给头节点
	int x;
	cout << "请输入元素的个数:";
	cin >> x;
	if (x <= 0) {
		cout << "您输入的值无意义!" << endl;
		return false;
	}
	cout << "请依次输入元素的值！" << endl;
	while (x) {
		DNode* r = new DNode;//再申请一个新节点
		InitList(r);//初始化这个新节点
		cin >> r->data;//为这个新节点添加数据
		p->next = r;//让头节点之后的第一个节点指向这个新节点
		r->pre = p;//让新节点的前驱指针指向头节点
		p = p->next;//让头节点向后移动，目的是为了连接所有的节点
		x--;//判断循环并退出
	}
	cout << "采用尾插法成功创建的双链表结果为：";
	PrintList(L);//打印双链表
	return true;
}
// 5.查找双链表
//（1）按值查找
bool GetValueElem(LinkList& L) {
	DNode* p = L->next;
	int x;
	cout << "请输入你要查找的值！" << endl;
	cin >> x;
	while (p) {
		if (p->data == x) {
			cout << "您要查找的值" << x << "存在!" << endl;
			return true;
		}
		p = p->next;
	}
	cout << "抱歉！您要查找的值" << x << "不存在!" << endl;
	return false;
}
//（2）按位查找
bool GetBitElem(LinkList& L) {
	DNode* p = L->next;
	int x;
	cout << "请输入你要查找的位：";
	cin >> x;
	int t = Length(L);
	if (x<1 || x>t) {
		cout << "你要查的位不存在或无意义！" << endl;
		return false;
	}
	else {
		while (p)
		{
			x--;
			p = p->next;
			if (x == 1) {
				cout << "按位查找成功！且该数据为：" << p->data << endl;
				return true;
			}
		}
	}
}
bool Insert(LinkList& L) {
	int x;
	cout << "请输入你要插入的位数！" << endl;
	cin >> x;
	if (x<1 || x>Length(L)) {
		cout << "你要插入的位数不存在或无意义！" << endl;
		return false;
	}
	int Value;
	cout << "请输入你要插入的值：";
	cin >> Value;
	DNode* p = L;
	DNode* r;
	InitList(r);
	while (x) {
		if (x == 1) {//成功找到了要插入的节点的前一个节点
			r->data = Value;//将数据保存到新节点中
			r->next = p->next;//让新节点指向第一个节点
			p->next->pre = r;//让第二个节点的前驱指针指向新节点
			r->pre = p;//让新节点的前驱指针指向第一个节点
			p->next = r;//让第一个节点的后继指针指向新节点
			cout << "添加成功后的双链表是";
			PrintList(L);//打印单链表
		}
		else p = p->next;//没有找到想要插入的节点，向后移动节点
		x--;
	}
	return false;
}
//7.删除节点
bool Delete(LinkList& L) {
	int x;
	cout << "请输入你要删除的节点;";
	cin >> x;
	if (x<1 || x>Length(L)) {
		cout << "您想删除的节点不存在或无意义！" << endl;
		return false;
	}
	else {
		DNode* p = L;
		DNode* r;
		InitList(r);
		while (x)
		{
			if (x == 1) {
				r->next = p->next;//新节点指向要删除的节点
				p->next->pre = r;//让要删除节点的前驱指针指向新节点
				p->next = r->next->next;//让被删除节点的前一个指向要删除的后一个节点
				free(r);
				cout << "删除成功！" << endl;
				cout << "删除后的双链表是";
				PrintList(L);//打印单链表
				return true;
			}
			p = p->next;//没有找到想要插入的节点，向后移动节点
			x--;
		}
		return false;
	}
}


int main() {
	LinkList L;//定义一个双链表L
	InitList(L);//为链表L初始化
	ListHeadInsert(L);//使用头插法创建双链表
	TailInsert(L);//使用尾插法创建双链表
	GetValueElem(L);//按值查找
	GetBitElem(L);	//按位查找
	Insert(L);	//插入数据
	Delete(L);		//删除数据

}