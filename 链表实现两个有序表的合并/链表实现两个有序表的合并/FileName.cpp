#include<iostream>
using namespace std;


//结点
struct Lnode
{
	int Data; //数据域
	Lnode* Next; //指针域
};

typedef Lnode* LinkList; //将LinkList定义为Lnode*类型

//初始化
void Listinit_L(LinkList& L)
{
	L = new Lnode;
	L->Next = NULL;
}

//插入
bool Listinsert_L(LinkList& L, int i, int e)
{
	Lnode* p = L;
	int j = 0;
	while (p && j < i - 1) //利用循环找到i-1的结点
	{
		p = p->Next;
		++j;
	}

	if (!(p) || j > i - 1)//判断输入的i是否合法
	{
		return false;
	}
	else
	{
		Lnode* s = new Lnode; //创建新结点s
		s->Data = e; //将输入的元素e存入s的数据域
		s->Next = p->Next; //s指向第i个结点
		p->Next = s; //i-1结点指向s地址
		return true;
	}

}

//打印
void ListPrint_L(LinkList L)
{
	Lnode* p = L->Next; //p指向第一个元素
	while (p)
	{
		cout << p->Data << " ";
		p = p->Next;
	}
	cout << endl;
}


//有序表的合并
void MergeList_L(LinkList La, LinkList Lb, LinkList& Lc)
{
	Lnode* pa = La->Next;//pa指向La中第一个元素
	Lnode* pb = Lb->Next;//pb指向Lb中第一个元素
	Lnode* pc = Lc = La;//使用La的头结点作为Lc的头结点
	while (pa && pb) //pa或pb为空时停止循环
	{
		//判断pa的值是否小于等于pb的值，为真插入pa的值，不为真插入pb的值
		if (pa->Data <= pb->Data)
		{
			pc->Next = pa;
			pc = pa;
			pa = pa->Next;
		}
		else
		{
			pc->Next = pb;
			pc = pb;
			pb = pb->Next;
		}
	}

	pc->Next = pa ? pa : pb; //利用三目运算插入pa或pb中剩余内容
	delete Lb; //释放Lb头结点
}

int main()
{
	//1.创建单链表La
	LinkList La;
	Listinit_L(La); //初始话
	//将数组中的数据插入La
	int arr1[3] = { 1,7,8 };
	for (int i = 1; i <= 3; i++)
	{
		Listinsert_L(La, i, arr1[i - 1]);
	}
	cout << "合并前La中的数据为：" << endl;
	ListPrint_L(La);


	//2.创建单链表Lb
	LinkList Lb;
	Listinit_L(Lb); //初始话
	//将数组中的数据插入Lb
	int arr2[6] = { 2,4,6,8,10,11 };
	for (int i = 1; i <= 6; i++)
	{
		Listinsert_L(Lb, i, arr2[i - 1]);
	}
	cout << "合并前Lb中的数据为：" << endl;
	ListPrint_L(Lb);

	//3.创建Lc，将La与Lb中的值合并到Lc
	LinkList Lc;
	MergeList_L(La, Lb, Lc);
	cout << "合并后Lc的值为：" << endl;
	ListPrint_L(Lc);




	system("pause");
	return 0;
}