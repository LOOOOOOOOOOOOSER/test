#include<iostream>
using namespace std;
#define MAXSIZE 100 //定义最大存储空间

//顺序表的定义
struct SqList
{
	int* Elme; //动态数组
	int Length; //元素个数

};

//初始化
bool initList_Sq(SqList& L)
{
	L.Elme = new int[MAXSIZE]; //为顺序表分配空间
	if (!L.Elme)
	{
		exit(0); //分配失败退出系统
	}
	L.Length = 0; //空表长度为0
	return true; //分配成功返回1
}

//插入
bool Listinsert_Sq(SqList& L, int i, int e)
{
	if (i < 1 || i > L.Length + 1) //判断输入的i释放合法
	{
		return false;
	}

	if (L.Length == MAXSIZE) //判断空间是否已满
	{
		return false;
	}

	for (int j = L.Length - 1; j >= i - 1; j--)
	{
		L.Elme[j + 1] = L.Elme[j]; //将插入位置及之后的元素后移
	}
	L.Elme[i - 1] = e; //将元素e放入位置i
	L.Length++; //表长加一
	return true;

}

//遍历
void ListPrint_Sq(SqList L)
{
	for (int j = 0; j < L.Length; j++)
	{
		cout << L.Elme[j] << " ";
	}
	cout << endl;
}

//线性表有序表的合并
void MergeList_Sq(SqList La, SqList Lb, SqList& Lc)
{
	//指针pa,pb,pc的初值分别指向两个表的第一个元素
	int* pa = La.Elme;
	int* pb = Lb.Elme;
	Lc.Length = La.Length + Lb.Length; //新表长度等于两表之和
	Lc.Elme = new int[Lc.Length]; //为新表分配存储空间
	int* pc = Lc.Elme;
	//pa_last、pb_last分别指向表中最后一个元素
	int* pa_last = &La.Elme[La.Length - 1];
	int* pb_last = &Lb.Elme[Lb.Length - 1];

	//判断两表是否为空，或当其中一表摘取完，则停止循环
	while (pa <= pa_last && pb <= pb_last)
	{
		if (*pa <= *pb) //依次摘取两表中值较小的结点
		{
			*pc++ = *pa++;
		}
		else
		{
			*pc++ = *pb++;
		}
	}

	//如果条件为真，表明Lb表已经到达表尾，将La中剩余元素加入Lc
	while (pa <= pa_last)
	{
		*pc++ = *pa++;
	}

	//如果条件为真，表明La表已经到达表尾，将Lb中剩余元素加入Lc
	while (pb <= pb_last)
	{
		*pc++ = *pb++;
	}

}

int main()
{
	SqList La; //创建线性表La
	initList_Sq(La); //初始化
	//创建数组并把数组中元素插入到La中
	int arr1[3] = { 1,7,8 };
	for (int i = 1; i <= 3; i++)
	{
		Listinsert_Sq(La, i, arr1[i - 1]);
	}
	cout << "合并前La中元素：" << endl;
	ListPrint_Sq(La); //遍历La

	SqList Lb;//创建线性表Lb
	initList_Sq(Lb); //初始化
	//创建数组并把数组中元素插入到Lb中
	int arr2[6] = { 2,4,6,8,10,11 };
	for (int i = 1; i <= 6; i++)
	{
		Listinsert_Sq(Lb, i, arr2[i - 1]);
	}
	cout << "合并前Lb中元素：" << endl;
	ListPrint_Sq(Lb); //遍历La

	SqList Lc;
	MergeList_Sq(La, Lb, Lc); //合并La、Lb到Lc中
	cout << "合并后Lc中元素：" << endl;
	ListPrint_Sq(Lc); //遍历Lc


	system("pause");
	return 0;
}