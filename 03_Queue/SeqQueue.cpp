#include<iostream>
using namespace std;

#define MAXSIZE 100

typedef int Elemtype;

typedef struct
{
    Elemtype data[MAXSIZE];
    int rear;
    int front;



}sqqueue;


void initqueue(sqqueue &q)
{   
    q.front=0;
    q.rear=0;

}

bool isempty(sqqueue q)
{
    if(q.front==q.rear)
        return true;
    return false;


}

bool isfull(sqqueue q)
{   

    //这里采用牺牲一个存储单元用于判断队满
    if((q.rear+1)%MAXSIZE==q.front)
        return true;
    return false;




}

//rear指向的是队尾的下一个元素
bool enqueue(sqqueue &q,Elemtype e)
{   
    if((q.rear%MAXSIZE)==q.front)
        return false;
    q.data[q.rear]=e;

    q.rear=(q.rear+1)%MAXSIZE;
    return true;
}

bool dequeue(sqqueue &q,Elemtype &e)
{
    
    if(q.front==q.rear)
        return false;
    e=q.data[q.front];
    q.front=(q.front+1)%MAXSIZE;

    return true;
}


bool getfirst(sqqueue q,Elemtype e)
{
    if(q.front==q.rear)
        return false;
    e=q.data[q.front];

    return true;
}

int getlength(sqqueue q)
{

    int len=0;
    len=(q.front-q.rear+MAXSIZE)%MAXSIZE;
}
