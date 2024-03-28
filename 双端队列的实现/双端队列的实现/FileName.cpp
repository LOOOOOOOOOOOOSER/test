#include<iostream>
using namespace std;

typedef char Type;
#define MAX 8
typedef struct {
    Type data[MAX];
    int front, rear;
} SqQueue;


void InitQueue(SqQueue& Q) {
    Q.front = 0;
    Q.rear = 0;
}

bool EnQueue(SqQueue& Q, Type x) {
    if ((Q.rear + 1) % MAX == Q.front) {
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MAX;
    return true;
}


bool DeQueue(SqQueue& Q, Type& x) {
    if (Q.front == Q.rear) {
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MAX;
    return true;
}


bool QueueEmpty(SqQueue Q) {
    if (Q.front == Q.rear) {
        return true;
    }
    return false;
}

int length(SqQueue Q) {
    return (Q.rear + MAX - Q.front) % MAX;
}


int main() {
    SqQueue queue;
    InitQueue(queue);
    char chs[7] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g' };
    for (int i = 0; i < 7; i++) {
        EnQueue(queue, chs[i]);
    }
    if (!EnQueue(queue, 'x')) {
        cout << "队列已满，入队失败" << endl;
    }
    cout << queue.front << " " << queue.rear << endl;

    //出队四次
    Type x;
    DeQueue(queue, x);
    cout << x << endl;
    DeQueue(queue, x);
    cout << x << endl;
    DeQueue(queue, x);
    cout << x << endl;
    DeQueue(queue, x);
    cout << x << endl;

    cout << "队列元素个数为 " << length(queue) << endl;
    //入队两次
    EnQueue(queue, 'h');
    EnQueue(queue, 'i');
    cout << "队列元素个数为 " << length(queue) << endl;

    cout << queue.front << " " << queue.rear << endl;

    while (!QueueEmpty(queue)) {
        DeQueue(queue, x);
        cout << x << " ";
    }

    return 0;
}


