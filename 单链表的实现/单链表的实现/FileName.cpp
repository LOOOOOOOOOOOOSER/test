#include<iostream>
#include<string>

using namespace std;

/*
	单链表（带头结点）
*/

typedef int ElemType;
typedef int Status;

typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

//初始化 有头结点
Status InitList(LinkList& L)
{
	L = new LNode;
	L->next = NULL;
	return 1;
}

/*
	单链表的取值（按位序取值）: 时间复杂度O(n)
	参数一：要取值的单链表
	参数二：要取值的位置
	参数三：待保存的对象
	注意：成功：返回1；失败：返回0。
*/
Status GetElem(LinkList L, int i, ElemType& e)
{
	LNode* p = L->next;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
	{
		return 0;
	}
	e = p->data;
	return p->data;
}

/*
	单链表的查找（按位序查找）: 时间复杂度O(n)
	参数一：要查找的单链表
	参数二：要查找的数据
	注意：成功：返回下标地址；失败：返回NULL。
*/
LNode* LocateElem(LinkList L, ElemType e)//使用Book类型的外号ElemType作为传入参数e的类型，使用int类型的外号Status作为函数的返回值类型
{
	LNode* p = L->next;//创建新结点，并指向第一块数据
	while (p && p->data != e)//如果p不为空且data == e,返回p的地址
	{
		p = p->next;
	}
	return p;
}

/*
	单链表的插入（按位序插入（后插法））:  时间复杂度O(n)
	参数一：要插入的单链表
	参数二：要插入的位置
	参数三：要插入的数据
	注意：成功：返回1；失败：返回0。
*/
Status ListInsert(LinkList& L, int i, ElemType e)
{
	if (i < 1)
	{
		return 0;
	}
	LNode* p = L;//创建临时结点指向头结点，头结点不存数据
	int j = 0;//记录p指向的是第几个结点，第0个结点为头结点，头结点不存数据，只存地址
	while (p && (j < i - 1))//循环找到第i-1个结点
	{
		p = p->next;
		j++;
	}
	if (!p || j > i - 1)//如果地址p为NULL就退出，头结点的地址也不为空
	{
		return 0;
	}
	LNode* s = new LNode; //创建新结点
	s->data = e;//新结点存放新数据e
	s->next = p->next;//将p的指针指向的下一个数据地址赋值给新结点s的指针
	p->next = s;//p的指针指向新节点s

	return 1;
}

/*
	单链表的删除（按位序删除）: 时间复杂度O(n)
	参数一：要删除的单链表
	参数二：要删除的位置
	注意：成功：返回1；失败：返回0。
*/
Status ListDelete(LinkList& L, int i)
{
	LNode* p = L;//创建临时结点指向头结点，头结点不存数据
	int j = 0;//记录p指向的是第几个结点，第0个结点为头结点，头结点不存数据，只存地址
	while (p->next && (j < i - 1))//循环找到第i-1个结点的前一个结点
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || (j > i - 1))
	{
		return 0;
	}
	LNode* q = p->next;//创建新结点q,指向要删除的数据内存地址
	p->next = q->next;//p的指针指向q的指针指向的下一个数据地址
	delete q;//释放q结点

	return 1;
}

int main()
{
	LinkList L;
	//创建单链表
	//CreateList_H(L,5);
	//初始化单链表
	InitList(L);
	//插入单链表
	for (int i = 1; i < 6; i++)
	{
		ListInsert(L, 1, i);
	}
	//取值
	int e;
	for (int i = 1; i <= 5; i++)
	{
		cout << GetElem(L, i, e) << endl;
	}

	//查找
	cout << "5的地址为：" << LocateElem(L, 5) << endl;
	//删除
	ListDelete(L, 1);
	cout << "删除第一个元素5：" << endl;
	for (int i = 1; i < 5; i++)
	{
		cout << GetElem(L, i, e) << endl;
	}

	return 1;
}
