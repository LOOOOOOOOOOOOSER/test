#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

#define  ElemType char

#define MAXSIZE 40
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0                                               
#define INFEASIBLE -1
#define OVERFLOW -1

typedef struct {
	ElemType data[MAXSIZE];
	int length;
}Sqstring, * SqString;

void StrAssign(SqString& s, ElemType arr[]) {
	int i;
	for (i = 0; arr[i] != 0; i++) {
		s->data[i] = arr[i];
		s->length = i;
	}
}

int BF(SqString s, SqString t) {
	int i = 0, j = 0;
	while (i < s->length && j < t->length) {
		if (s->data[i] == t->data[j]) {
			i++;
			j++;
		}
		else {
			i = i - j + 1;//i回退1
			j = 0;
		}
	}
	if (j >= t->length) {
		return (i - t->length);
	}
	else
	{
		return (-1);
	}

}


int main() {

	char arr1[] = "diabjshaghsjdj";
	char arr2[] = "js";
	SqString s1;
	s1 = new Sqstring;
	StrAssign(s1, arr1);
	SqString s2;
	s2 = new Sqstring;
	StrAssign(s2, arr2);

	int location = BF(s1, s2);
	if (location == -1) {
		cout << "s中不存在与t相同的子串。" << endl;
	}
	else {
		cout << "s中与t相同子串的起始位置为：" << location << endl;
	}

}