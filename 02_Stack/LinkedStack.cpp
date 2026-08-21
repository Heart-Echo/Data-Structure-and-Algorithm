#include<iostream>
using namespace std;

typedef int Elemtype;

typedef struct Lnode
{
    Elemtype data;
    struct Lnode *next;


}Lnode,*Linkstack;

//以下的s是用来专门保存栈顶节点的地址



void initstack(Linkstack &s)
{

    s=NULL;
}


bool isempty(Linkstack s)
{
    if(s==NULL)
        return true;
    return false;
}
//注意是不带头结点的头插法入站
bool push(Linkstack &s,Elemtype e)
{

    Lnode *p=(Lnode *)malloc(sizeof(Lnode));
    if(p==NULL)
        return false;
    //这里的判断是看申请成功了没
    p->data=e;
    //用的是头插法，s是开始的节点
    p->next=s;

    s=p;
    return false;
}


bool pop(Linkstack &s,Elemtype &e)
{
    if(s==NULL)
        return false;

    Lnode *p=s;//让一个指针指向s

    e=p->data;
    //s向后移动就是代表删除了
    s=s->next;

    free(p);
    return true;
}

bool gettop(Linkstack s,Elemtype e)
{
    if(s==NULL)
        return false;
    e=s->data;
    return true;

}

int getlength(Linkstack s)
{
    int len=0;

    Lnode *p=s;

    while(p!=NULL)
    {
        len++;
        p=p->next;
    }

    return len;
}