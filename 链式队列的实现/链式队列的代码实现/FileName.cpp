#include <iostream>
#include <string>

using namespace std;

struct LinkNode
{
    LinkNode* next;
};

struct Queue
{
    LinkNode* head;
    LinkNode* back;
    int size;
    Queue();
    ~Queue();
    //入队
    void pushQueue(LinkNode* node);
    //获取队首元素
    LinkNode* frontQueue();
    //获取队尾元素
    LinkNode* backQueue();
    //出队
    void popQueue();
    //获取队的大小
    int sizeQueue();
    //清空队列
    void clearQueue();
};

struct Person
{
    LinkNode node;
    string name;
    int age;
    Person(string name, int age);
};

void operator<<(ostream& out, LinkNode* node)
{
    Person* person = (Person*)node;
    out << person->name << " " << person->age << endl;
}

Queue::Queue()
{
    head = new LinkNode;
    head->next = NULL;
    back = new LinkNode;
    back->next = NULL;
    size = 0;
}

Queue::~Queue()
{
    delete head;
    delete back;
}

void Queue::pushQueue(LinkNode* node)
{
    if (size == 0)
    {
        head->next = node;
        back = node;
        size++;
        return;
    }
    back->next = node;
    back = node;
    size++;
}

LinkNode* Queue::frontQueue()
{
    if (size == 0)
    {
        return NULL;
    }
    return head->next;
}

LinkNode* Queue::backQueue()
{
    if (size == 0)
    {
        return NULL;
    }
    return back;
}

void Queue::popQueue()
{
    if (size == 0)
    {
        return;
    }
    head->next = head->next->next;
    size--;
}

int Queue::sizeQueue()
{
    return size;
}

void Queue::clearQueue()
{
    head->next = NULL;
    back = NULL;
    size = 0;
}

Person::Person(string name, int age)
{
    this->name = name;
    this->age = age;
}

int main()
{
    //初始化数据
    Person p1("A", 10);
    Person p2("B", 20);
    Person p3("C", 30);
    Person p4("D", 40);
    Person p5("E", 50);
    //初始化队列
    Queue queue;
    queue.pushQueue((LinkNode*)&p1);
    queue.pushQueue((LinkNode*)&p2);
    queue.pushQueue((LinkNode*)&p3);
    queue.pushQueue((LinkNode*)&p4);
    queue.pushQueue((LinkNode*)&p5);
    //获取队首元素
    cout << queue.frontQueue();
    //获取队尾元素
    cout << queue.backQueue();
    //获取队列大小
    cout << queue.sizeQueue() << endl;
    cout << "----------------------------------------" << endl;
    //输出
    while (queue.sizeQueue() > 0)
    {
        cout << queue.frontQueue();
        queue.popQueue();
    }
    //获取队列大小
    cout << queue.sizeQueue() << endl;

    return 0;
}