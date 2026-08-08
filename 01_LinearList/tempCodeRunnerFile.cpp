#include<iostream>
using namespace std;
typedef int Elemtype;

//stuct Lnode定义一个结构体，表示链表节点
//不加typedef以后定义都要写
//struct Lnode L
//但是加了typedef，取了名字叫做Lnode，所以这里Lnode=struct Lnode
//所以以后可以直接定义Lnode L,很方便
typedef struct Lnode{
    Elemtype data;
    struct Lnode *next;//指向自己结构体的指针


}Lnode,*Linklist;
//*linklist;对结构体的指针Lnode*取了一个名字，之后
//struct Lnode*L=linklist L;很方便
void printlink(Linklist L)
{
    Lnode *p=L->next;

    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }

    cout<<endl;
}
bool Initlist(Linklist &L)
{
    L=(Lnode*)malloc(sizeof(Lnode));
    L->next=NULL;
    return true;


}
//求表长
int getlength(Linklist L)
{   
    int len=0;
    Lnode *p=L;
    while(p->next!=NULL)
    {
        p=p->next;
        len++;
    }
    return len;
}
//按序号查找 节点！！！
Lnode *Getelem(Linklist L,int i)
{
    Lnode *p=L;
    int j=0;
    while(p!=NULL&&j<i)
    {
        p=p->next;//最后返回的是节点，直接指向下一个就行了
        j++;
    }
    return p;
}
//按照值查找
Lnode *locateelem(Linklist L,Elemtype e)
{

    //定义的时候是带头结点的，所以这里要从第一个有数据的节点开始
    //如果不是L->next头结点的data里面的随机值万一等于要查找的数值，那么就会直接返回，没有正确查找到
    //此外再打印的时候，可能会多打印一个头节点。
    Lnode *p=L->next;
    while (p!=NULL&&p->data!=e)
    {
        p=p->next;
    }
    return p;

}

//插入节点  参数（链表 插入的位置 要插入的值）
bool InsertLinklist (Linklist &L,int i,Elemtype e)
{  
    Lnode *p=L;//这个*p作为一个指针先指向L的头，接下来可以p->next指向下一个位置
    //否则要是要访问下一个位置就需要L->next->next->next……很麻烦
    int j=0;            //记录一下当前的位置
    while(p!=NULL&&j<i-1)//插入和查找不一样，插入是要在i号位置插入，插进去之后那个节点变成了i号
    //所以找的是i-1号节点
    {
        p=p->next;
        j++;
    }
    if(p==NULL)
    {
        return false;
    }
    Lnode *s=(Lnode *)malloc (sizeof(Lnode));//动态新建一个节点

    s->data=e;//别忘了值

    s->next=p->next;
    p->next=s;
/*
方法二偷梁换柱进行前插
正常情况下前插也是查找到他的前驱然后插入需要O（n）
如果给了一个指定的结点的话，还从头开始查会很慢，可以利用一个temp节点偷梁换柱，O（1）

Lnode *temp=(Lnode *)malloc (sizeof(Lnode));
要插入的节点是s，给定的节点是p，临时节点是temp

现在的结构是p-> -> ->
插入后      s->p-> ->
s->next=p->next;
p-next=s;
temp=p->data;
p->data=s->data;
s->data=temp;
先后插不用查找，然后交换数值，完成逻辑上前插


*/

    return true;
}
//删除第i号节点

bool listdelete(Linklist &L ,int i,Elemtype &e)
{
    Lnode *p=L;
    int j=0;
    while (p!=NULL&&j<i-1)//找删除的节点的前驱
    {p=p->next;
    j++;}

    if(p->next==NULL||j>i-1)
    {
        return false;
    }
    Lnode *q=p->next;//p的next是要删除的节点
    e=q->data;
    p->next=q->next;
    free(q);
    return true;
}


//头插法建立单链表
Linklist headinsert(Linklist &L)
{
    Lnode *s;int x;
    L=(Lnode *)malloc(sizeof(Lnode));
    L->next=NULL;
    cin >> x;
    while(x!=9999)
    {
        s=(Lnode *)malloc(sizeof(Lnode));
        s->data=x;
        s->next=L->next;
        L->next=s;//现在单链表不是空的了，把头指针指向刚刚插入的节点实现头插
        cin >>x;
    }
    return L;


}

Linklist tailinsert(Linklist &L)
{
    int x;
    L=(Lnode *)malloc (sizeof(Lnode));
    Lnode *s;
    Lnode *r=L;
    cin >>x;
    while(x!=9999){
    s=(Lnode *)malloc (sizeof(Lnode));
    s->data=x;
    r->next=s;
    r=s;//移动尾指针
    cin >>x;
    }
    r->next=NULL;
    return L;

}

int main()
{
    Linklist L;

    cout<<"A"<<endl;

    Initlist(L);

    cout<<"B"<<endl;

    cout<<getlength(L)<<endl;

    cout<<"C"<<endl;


    InsertLinklist(L,1,985);

    cout<<"D"<<endl;


    return 0;
}

