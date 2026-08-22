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
void initq(Linkq &q)
{
    q.front=(Qnode*)malloc(sizeof(Qnode));
    q.front->next=NULL;
    q.rear=q.front;

}