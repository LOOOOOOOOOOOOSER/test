/*
链式存储串的实现
*/
#include<iostream>
using namespace std;
const int MAX_N = 100;
//数据节点
class Node
{
public:
	char data;
	class Node* next;
};

//链串
class String
{
public:
	//构建
	String() {}
	//析构
	~String() {
		Node* pre = S, * p = pre->next;
		while (p != NULL) {
			free(pre);
			pre = p;
			p = p->next;
		}
		free(p);
	}
	//生成串(尾插法实现)
	void StrAssign(char str[]) {
		int i;
		Node* r, * p;
		S = (Node*)malloc(sizeof(Node));
		r = S;
		//生成链
		for (i = 0; str[i] != '\0'; i++) {
			p = (Node*)malloc(sizeof(Node));
			p->data = str[i];
			r->next = p;
			r = p;
		}
		r->next = NULL;
	}

	//复制串
	void StrCopy(String* str) {
		Node* r, * p;
		Node* t = str->GetS()->next;
		S = (Node*)malloc(sizeof(Node));
		r = S;
		while (t != NULL) {
			p = (Node*)malloc(sizeof(Node));
			p->data = t->data;
			r->next = p;
			r = p;
			t = t->next;
		}
		r->next = NULL;
	}

	//是否相等
	bool isEqual(String* str) {
		Node* p = S->next, * t = str->GetS()->next;
		//遍历判断
		while (p != NULL && t != NULL && p->data == t->data) {
			p = p->next;
			t = t->next;
		}
		//若满足条件则相等
		if (p == NULL && t == NULL) {
			return true;
		}
		//否则不相等
		else {
			return false;
		}
	}
	//串长度
	int StrLength() {
		int i = 0;
		Node* p = S->next;
		//头结点不存储数据
		while (p != NULL) {
			i++;
			p = p->next;
		}
		return i;
	}
	//串拼接,尾插法建立新串，返回其地址
	Node* Concat(String* t) {
		Node* str, * p = S->next, * r, * q;
		str = (Node*)malloc(sizeof(Node));
		r = str;
		//复制S串
		while (p != NULL) {
			q = (Node*)malloc(sizeof(Node));
			q->data = p->data;
			r->next = q;
			r = q;
			p = p->next;
		}
		//复制t串
		p = t->GetS()->next;
		while (p != NULL) {
			q = (Node*)malloc(sizeof(Node));
			q->data = p->data;
			r->next = q;
			r = q;
			p = p->next;
		}
		r->next = NULL;
		return str;
	}
	//求子串，返回串S中从位置i开始开始的j个字符，参数不正确时饭后空串，尾插法生成新串，返回地址
	Node* SubStr(int i, int j) {
		Node* str, * r, * p, * q = S->next;
		int k = 0;
		str = (Node*)malloc(sizeof(Node));
		r = str;
		//下标处理，不合法返回空串
		if (i <= 0 || i > StrLength() || j <= 0 || i + j - 1 > StrLength()) {
			r->next = NULL;
			return str;
		}
		else {
			//定位到位置i
			for (k = 0; k < i - 1; k++) {
				q = q->next;
			}
			//复制字符，产生新串
			for (k = 0; k < j;k++) {
				p = (Node*)malloc(sizeof(Node));
				p->data = q->data;
				r->next = p;
				r = p;
				q = q->next;
			}
			r->next = NULL;
			return str;
		}
	}
	//插入串s1到串S的位置i开始处，尾插法产生新串，参数不正确时返回空串，返回新串地址
	Node* InsertStr(String* s1, int i) {
		Node* q = S->next, * r, * p, * str;
		int j;
		str = (Node*)malloc(sizeof(Node));
		r = str;
		//下标不合法，返回空串
		if (i <= 0 || i > StrLength()) {
			r->next = NULL;
			return str;
		}
		//产生新串
		else {
			//复制S前i个字符
			for (j = 0; j < i - 1; j++) {
				p = (Node*)malloc(sizeof(Node));
				p->data = q->data;
				r->next = p;
				r = p;
				q = q->next;
			}
			//插入串s1
			Node* sq = s1->GetS()->next;
			while (sq != NULL) {
				p = (Node*)malloc(sizeof(Node));
				p->data = sq->data;
				r->next = p;
				r = p;
				sq = sq->next;
			}
			//复制S串剩下所有字符
			while (q != NULL) {
				p = (Node*)malloc(sizeof(Node));
				p->data = q->data;
				r->next = p;
				r = p;
				q = q->next;
			}
			r->next = NULL;
			return str;
		}
	}
	//删除串,将串S中从位置i开始的j个字符删除,生成新串并返回地址，参数错误时返回空串
	Node* DeleteStr(int i, int j) {
		Node* str, * q = S->next, * r, * p;
		str = (Node*)malloc(sizeof(Node));
		r = str;
		//下标不合法，返回空串
		if (i <= 0 || i > StrLength() || j<0 || i + j - 1>StrLength()) {
			r->next = NULL;
			return str;
		}
		//生成新串
		else {
			int k;
			//插入S前i个字符
			for (k = 0; k < i - 1; k++) {
				p = (Node*)malloc(sizeof(Node));
				p->data = q->data;
				r->next = p;
				r = p;
				q = q->next;
			}
			//跳过j个节点
			for (k = 0; k < j; k++) {
				q = q->next;
			}
			//插入剩下所有
			while (q != NULL) {
				p = (Node*)malloc(sizeof(Node));
				p->data = q->data;
				r->next = p;
				r = p;
				q = q->next;
			}
			r->next = NULL;
			return str;
		}
	}
	//替换串,将S串中位置i开始的j个字符替换成串t，产生新串，返回地址，参数不正确时返回空串
	Node* ReplaceStr(int i, int j, String* t) {
		Node* str, * r, * p, * q = S->next;
		str = (Node*)malloc(sizeof(Node));
		r = str;
		//下标不合法，返回空串
		if (i <= 0 || i > StrLength() || j<0 || i + j - 1>StrLength()) {
			r->next = NULL;
			return str;
		}
		//产生新串
		else {
			int k;
			//插入串S前i个字符
			for (k = 0; k < i - 1; k++) {
				p = (Node*)malloc(sizeof(Node));
				p->data = q->data;
				r->next = p;
				r = p;
				q = q->next;
			}
			//插入串t
			Node* pt = t->GetS()->next;
			while (pt != NULL) {
				p = (Node*)malloc(sizeof(Node));
				p->data = pt->data;
				r->next = p;
				r = p;
				pt = pt->next;
			}
			//跳过S中j个字符
			for (k = 0; k < j; k++) {
				q = q->next;
			}
			//插入S中剩下所有
			while (q != NULL) {
				p = (Node*)malloc(sizeof(Node));
				p->data = q->data;
				r->next = p;
				r = p;
				q = q->next;
			}
			r->next = NULL;
			return str;
		}
	}
	//输出串——无参数（类私有数据）
	void DisplayStr() {
		Node* p = S->next;
		while (p != NULL) {
			cout << p->data;
			p = p->next;
		}
		cout << endl;
	}
	//输出串——有参数（接收局部变量产生的串）
	void DisplayStr(Node* str) {
		Node* p = str->next;
		while (p != NULL) {
			cout << p->data;
			p = p->next;
		}
		cout << endl;
	}
private:
	Node* S;

	//获取串首地址
	Node* GetS() {
		return S;
	}
};
int main()
{
	int i, n, locate, strlength;
	char a[MAX_N];
	//生成串
	cout << "Create String." << endl;
	cout << "Input Length:";
	cin >> n;
	cout << "Input " << n << " characters." << endl;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	a[i] = '\0';
	String str1;
	str1.StrAssign(a);
	//输出串
	cout << "Diaplay String." << endl;
	str1.DisplayStr();
	//拷贝串
	cout << "Copy String." << endl;
	cout << "Input n:";
	cin >> n;
	cout << "Input " << n << " characters." << endl;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	a[i] = '\0';
	String str2;
	str2.StrAssign(a);
	str1.StrCopy(&str2);
	str1.DisplayStr();
	//是否相等
	cout << "Is Equal." << endl;
	cout << "Input n:";
	cin >> n;
	cout << "Input " << n << " characters." << endl;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	a[i] = '\0';
	str2.StrAssign(a);
	if (str1.isEqual(&str2)) {
		cout << "YES." << endl;
	}
	else {
		cout << "NO." << endl;
	}
	//串长度
	cout << "String Length." << endl;
	cout << str1.StrLength() << endl;
	//连接串
	cout << "Concat String." << endl;
	cout << "Input n:" << endl;
	cin >> n;
	cout << "Input " << n << " characters." << endl;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	a[i] = '\0';
	str2.StrAssign(a);
	str1.DisplayStr(str1.Concat(&str2));
	//获取子串
	cout << "Get SubStr." << endl;
	cout << "Input locate, string length:";
	cin >> locate >> strlength;
	str1.DisplayStr(str1.SubStr(locate, strlength));
	//插入串
	cout << "Insert String." << endl;
	cout << "Input n:";
	cin >> n;
	cout << "Input " << n << " characters." << endl;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	a[i] = '\0';
	str2.StrAssign(a);
	cout << "Input locate:";
	cin >> locate;
	str1.DisplayStr(str1.InsertStr(&str2, locate));
	//删除串
	cout << "Delete String." << endl;
	cout << "Input locate,string length:";
	cin >> locate >> strlength;
	str1.DisplayStr(str1.DeleteStr(locate, strlength));
	//替换串
	cout << "Replace String." << endl;
	cout << "Input n:";
	cin >> n;
	cout << "Input " << n << " characters." << endl;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	a[i] = '\0';
	str2.StrAssign(a);
	cout << "input locate, string length:";
	cin >> locate >> strlength;
	str1.DisplayStr(str1.ReplaceStr(locate, strlength, &str2));
	return 0;
}