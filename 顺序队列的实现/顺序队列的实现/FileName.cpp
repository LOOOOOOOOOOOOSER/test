#include <iostream>
#include <string>

using namespace std;

#define MAX 5

template <typename T>
struct Queue
{
    T* data[MAX];
    int size;
    Queue(T* data);
    //入队列
    void pushQueue(T* t);
    //访问队首元素
    T* frontQueue();
    //访问队尾元素
    T* backQueue();
    //出队列
    void popQueue();
    //获取队列大小
    int sizeQueue();
    //清空队列
    void clearQueue();
};

struct Person
{
    string name;
    int age;
    Person(string name, int age);
};

void operator<<(ostream& out, Person* person)
{
    out << person->name << " " << person->age << endl;
}

template<typename T>
Queue<T>::Queue(T* data)
{
    size = 0;
}

template<typename T>
void Queue<T>::pushQueue(T* t)
{
    if (size == MAX)
    {
        return;
    }
    data[size] = t;
    size++;
}

template<typename T>
T* Queue<T>::frontQueue()
{
    if (size == 0)
    {
        return NULL;
    }
    return data[0];
}

template<typename T>
T* Queue<T>::backQueue()
{
    if (size == 0)
    {
        return NULL;
    }
    return data[size - 1];
}

template<typename T>
void Queue<T>::popQueue()
{
    if (size == 0)
    {
        return;
    }
    //移动元素
    for (int i = 0;i < size - 1;i++)
    {
        data[i] = data[i + 1];
    }
    size--;
}

template<typename T>
int Queue<T>::sizeQueue()
{
    return size;
}

template<typename T>
void Queue<T>::clearQueue()
{
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
    Queue<Person> queue(NULL);
    queue.pushQueue(&p1);
    queue.pushQueue(&p2);
    queue.pushQueue(&p3);
    queue.pushQueue(&p4);
    queue.pushQueue(&p5);
    //获取队尾元素
    cout << queue.backQueue();
    //获取队列大小
    cout << queue.sizeQueue() << endl;
    //输出
    cout << "------------------------------------" << endl;
    while (queue.sizeQueue() > 0)
    {
        cout << queue.frontQueue();
        queue.popQueue();
    }
    //获取队列大小
    cout << queue.sizeQueue() << endl;
    return 0;
}