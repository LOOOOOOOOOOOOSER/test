#include <iostream>
using namespace std;
#define MAXSIZE 100

typedef struct QueNode {  //定义链队列存储结构
    int data;
    QueNode* next;
}QNode, * QuePtr;

typedef struct {  //定义链队列指针
    QuePtr front;  //队头指针
    QuePtr rear;  //队尾指针
}LinkQue;

bool InitQue(LinkQue& Q) {  //初始化
    Q.front = Q.rear = new QNode;
    if (!Q.front) return false;
    Q.front->next = NULL;
    return true;
}

bool DestoryQue(LinkQue& Q) {  //销毁表
    while (Q.front) {
        Q.rear = Q.front->next;
        delete(Q.front);
        Q.front = Q.rear;
    }
    return true;
}

bool EnQue(LinkQue& Q, int e) {  //入队
    QuePtr p = new QNode;
    if (!p) return false;
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return true;
}

bool OutQue(LinkQue& Q, int e) {  //出队
    if (Q.front == Q.rear) return false;  //队空
    QuePtr p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) Q.rear = Q.front;
    delete p;
    return true;
}

bool GetHead(LinkQue Q, int& e) {  //取队头元素
    if (Q.front == Q.rear) return false;
    e = Q.front->next->data;
    return true;
}

void ShowList(LinkQue Q) {   //输出链队
    QuePtr p = Q.front->next;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    LinkQue Q;
    int e;
    int choose = -1;
    cout << "1.入队-------------------2.出队" << endl;
    cout << "3.取头元素---------------4.销毁" << endl;
    cout << "5.输出链队---------------0.退出" << endl;
    InitQue(Q);
    while (choose != 0) {
        cout << "请选择功能：";
        cin >> choose;
        switch (choose) {
        case 1:
            cout << "请输入入队元素：";
            cin >> e;
            if (EnQue(Q, e))
                cout << "入队成功" << endl;
            break;
        case 2:
            if (OutQue(Q, e))
                cout << "出队成功" << endl;
            break;
        case 3:
            if (GetHead(Q, e))
                cout << "队头元素为" << e << endl;
            break;
        case 4:
            if (DestoryQue(Q))
                cout << "销毁成功" << endl;
            break;
        case 5:
            cout << "队列元素为：";
            ShowList(Q);
            break;
        }
    }
    return 0;
}