#include <iostream>

#define MAXSIZE	20
typedef int ElemType;
typedef struct {		//静态顺序表
	ElemType data[MAXSIZE];
	int lenth;
}SqList;

//初始化静态顺序表，长度不可变
void InitSqList(SqList& L)
{
	L.lenth = 6; //设定初始顺序表有6个数据
	for (int i = 0; i < L.lenth; i++) {
		L.data[i] = i + 1;
	}
}
//输出顺序表
void PrintList(SqList L)
{
	for (int i = 0; i < L.lenth; i++) {
		std::cout << "data[" << i << "]:" << L.data[i] << "     ";
	}
	std::cout << std::endl;
}
//顺序表第i个位置插入元素e
bool SqListInsert(SqList& L, int i, ElemType e)
{
	if (i < 1 || i > L.lenth + 1)	return false;	//超出范围不能插入
	if (L.lenth >= MAXSIZE)	return false;	//表满不能插入
	for (int j = L.lenth; j >= i; j--) {
		L.data[j] = L.data[j - 1];	//第i个位置之后的元素后移
	}
	L.data[i - 1] = e;
	L.lenth++;
	return true;
}
//删除第i个元素，并返回删除的元素e
bool SqListDelete(SqList& L, int i, ElemType& e)
{
	if (i < 1 || i > L.lenth)	return false;	//超出范围不能删除
	if (L.lenth == 0)	return false;	//表空不能删除
	e = L.data[i - 1];
	for (int j = i; j < L.lenth; j++) {
		L.data[j - 1] = L.data[j];//第i个位置之后的元素前移
	}
	L.lenth--;
	return true;
}
//按值查找元素，并返回位序
int SqListLocateItem(SqList L, ElemType e)
{
	for (int i = 0; i < L.lenth; i++) {
		if (L.data[i] == e)
			return i + 1;
	}
	return -1;	//查找失败
}

int main()
{
	SqList L1, L2;
	int e, temp;

	/*******************************插入、删除、查找成功***************************/
	printf("插入、删除、查找成功测试：\n");
	InitSqList(L1);
	printf("初始化顺序表成功！原顺序表为：\n");
	PrintList(L1);
	if (SqListInsert(L1, 3, 100)) {//第3个位置插入100
		printf("在第3个位置插入100成功！新顺序表为：\n");
		PrintList(L1);
	}
	else {
		printf("在第3个位置插入100失败！\n");
	}

	if (SqListDelete(L1, 5, e)) {//删除第5个位置的数据，并输出删除数据
		printf("删除第5个位置的元素成功！删除的元素为：%d，新顺序表为：\n", e);
		PrintList(L1);
	}
	else {
		printf("删除第5个位置的元素失败！\n");
	}

	temp = SqListLocateItem(L1, 6);
	if (temp != -1) {//查找6，并返回位序
		printf("查找元素“6”成功！位序为：%d\n", temp);
	}
	else {
		printf("查找失败！\n");
	}
	/****************************************************************************/

	/*******************************插入、删除、查找失败***************************/
	printf("\n插入、删除、查找失败测试：\n");
	InitSqList(L2);
	printf("初始化顺序表成功！原顺序表为：\n");
	PrintList(L2);
	if (SqListInsert(L2, 9, 999)) {//第9个位置插入999
		printf("在第9个位置插入999成功！新顺序表为：\n");
		PrintList(L2);
	}
	else {
		printf("在第9个位置插入999失败！\n");
	}

	if (SqListDelete(L2, 8, e)) {//删除第8个位置的数据，并输出删除数据
		printf("删除第8个位置的元素成功！删除的元素为：%d，新顺序表为：\n", e);
		PrintList(L2);
	}
	else {
		printf("删除第8个位置的元素失败！\n");
	}

	temp = SqListLocateItem(L2, 123);
	if (temp != -1) {//查找123，并返回位序
		printf("查找元素“123”成功！位序为：%d", temp);
	}
	else {
		printf("查找元素“123”失败！\n");
	}
	/****************************************************************************/

	system("pause");
	return 0;
}