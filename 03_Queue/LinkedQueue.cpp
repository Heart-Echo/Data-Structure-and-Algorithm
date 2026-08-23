#include<iostream>
using namespace std;


typedef int Elemtype;
//定义链队节点
typedef struct  Qnode
{
    Elemtype data;
    struct Qnode *next;


}Qnode,*Qlist;


//注意区别，这里front，rear是Qnode结构体的指针，指向包含了data与next的节点
// front
// ↓
// [头结点] → [10] → [20] → [30]
//                               ↑
//                              rear
typedef struct
{
    Qlist front;
    Qlist rear;

}Linkq;

//q保存了链队的两个指针，front与rear，而不是一串节点
//q是一个结构体里面有front与rear，front指向了链队的头所以代表了链队
//front与rear又是Qnode类型的
//rear是Qnode结构体的指针，指向包含了data与next的节点
bool initq(Linkq &q)
{
    
    q.front=(Qnode*)malloc(sizeof(Qnode));

    if(q.front==NULL)
    {

        return false;
    }

    q.front->next=NULL;
    q.rear=q.front;
    return true;

}


bool isempty(Linkq q)
{
    if(q.front==q.rear)
    {
        return true;
    }
}

bool enqueue(Linkq &q,Elemtype e)
{
    Qnode *s=(Qnode*)malloc(sizeof(Qnode));

    if(s==NULL)
        return false;

    s->data=e;
    //入队是在队尾
    s->next=NULL;
    //在原来的队列上。rear是最后一个他的下一个指向s代表插入一个
    q.rear->next=s;
    //移动尾指针
    q.rear=s;

    return true;
}

bool dequeue(Linkq &q,Elemtype &e)
{
    if(q.front==q.rear)
        return false;

    Qnode *p=q.front->next;


    e=p->data;

    q.front->next=p->next;


    if(p==q.rear)
    {
        q.rear=q.front;

    }
    //为什么出队的时候要判断 p == Q.rear


// front
//  ↓
// [头] → [10]
//          ↑
//         rear

//删除之后头节点指向null。rear不可以还指向10，所以让他等于头节点
    free (p);
    return true;
}


bool gettop(Linkq q,Elemtype &e)
{
    if(q.front==q.rear)
        return false;

    e=q.front->next->data;
    return true;

}







