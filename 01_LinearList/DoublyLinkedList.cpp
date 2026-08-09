#include<iostream>
using namespace std;
typedef int Elemtype;
typedef struct Dnode
{
    Elemtype data;
    struct Dnode *next,*prior;
}Dnode,*Dlinklist;

bool Initlist(Dlinklist &L)
{
    L=(Dnode*)malloc(sizeof(Dnode));
    L->next=NULL;
    L->prior=NULL;
    return true;
}

int getlength(Dlinklist L)
{
    int len=0;
    Dnode *p=L;//带头结点，指向第一个有效的节点

    while(p->next!=NULL)
    {
        p=p->next;
        //用指针p的意义就是防止修改L防止链表断开
        len++;
    }
    return len;

}
//按照序号查找节点

Dnode *getelem(Dlinklist L,int i)
{
    int j=0;
    Dnode *p=L;
    while(j<i&&p!=NULL)    //j从0开始0-位置1，1-位置2，2-位置3……，当j等于i-1时候就是第i个位置的
    {
        p=p->next;
        j++;
    }
    return p;


}

Dnode *locatelem(Dlinklist L,Elemtype e)
{
    Dnode *p=L->next;
    while(p!=NULL&&p->data!=e)
    {
        p=p->next;
    }
    return p;
}


//只是对比单链表多了一点条件判断以及最后插入变成了四条语句
 bool insert(Dlinklist &L,int i,Elemtype e)
 {
    Dnode *p=L;
    
    int j=0;
    if (i<1)
    {
        return false;
    }
    while(p!=NULL&&j<i-1)
    {
        p=p->next;
        j++;
    }
    if(p==NULL)
    {
        return false;

    }
    Dnode *s=(Dnode *)malloc(sizeof(Dnode));
    s->data=e;
    s->next=p->next;
    if(p->next!=NULL)
    {
    p->next->prior=s;
    }
    s->prior=p;
    p->next=s;
    return true;

 }

bool deletenode (Dlinklist &L,int i,Elemtype e)
{
    Dnode *p=L;
    int j=0;
    while (p->next!=NULL&&j<i)//因为是双链表不需要用前驱删除，找到要删除的节点就行了，有双向指针
    {
        p=p->next;
        j++;
    }
    e=p->data;
    p->prior->next=p->next;
    if(p->next!=NULL)
    {
    p->next->prior=p->prior;
    }
    free(p);
    return true;
}
//头插法建立双链表
Dlinklist headinsert(Dlinklist &L)
{
    L=(Dnode*)malloc(sizeof(Dnode));
    L->next=NULL;
    L->prior=NULL;
    Elemtype x;
    cin>>x;
    while(x!=9999)
    {
        Dnode *s=(Dnode*)malloc(sizeof(Dnode));
        s->data=x;
        s->next=L->next;
        if(L->next!=NULL)
        {
            L->next->prior=s;
        }
        L->next=s;
        s->prior=L;
        cin>>x;
    }
    return L;
}

Dlinklist tailinsert(Dlinklist &L)
{
    L=(Dnode*)malloc(sizeof(Dnode));
    L->next=NULL;
    L->prior=NULL;
    Dnode*r=L;

    Elemtype x;
    cin>>x;
    while(x!=9999)
    {
        Dlinklist s=(Dnode*)malloc(sizeof(Dnode));
        s->data=x;
        r->next=s;
        s->prior=r;
        s->next=NULL;
        r=s;//更改尾指针的位置
        cin>>x;


    }

    return L;

}

void printDlist(Dlinklist L)
{
    Dnode*p=L;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

