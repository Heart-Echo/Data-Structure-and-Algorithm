#include<iostream>
using namespace std;

typedef int Elemtype;

//这里的表示方法是对于普通的树的

//双亲表示法
//本质上是一个数组，节点里面的伪指针是双亲的数组下标，没有双亲用-1表示

//树的节点，就是保存在数组里面的元素，类型是一个struct
#define MAXSIZE 100
typedef struct 
{
    Elemtype data;

    int parent;
}treenode;

typedef struct
{
    //数组存放节点
    treenode nodes[MAXSIZE];

    int n;//节点数量

}tree;

void init(tree &t)
{
    t.n=0;
}

bool insert(tree &t,Elemtype e,int parent)
{
    if(t.n>MAXSIZE)
        return false;

    //数组的下标比n小一，所以插入的数组的下标就是n
    //在数组的n号插入e
    t.nodes[t.n].data=e;

    //指定要插入到那个节点下面，因为是树孩子数量没有规定
    t.nodes[t.n].parent=parent;

    t.n++;

    return true;
}


int locatelem(tree t,Elemtype e)
{   
    //本质就是数组的遍历


    for (int i=0;i<t.n;i++)
    {
        if(t.nodes[i].data==e)  
            return i;


    }
    return -1;
}

//查找父节点就是找下标是parent
//查找孩子不方便要所有遍历一样，看谁的parent指向的是自己，谁就是自己的孩子

void child(tree t,int i)
{

    for(int j=0;j<t.n;j++)
    {

        if(t.nodes[j].parent==i)
            cout<<"孩子："<<t.nodes[j].data<<" ";

    }
    cout <<endl;


}

//孩子表示法，类比散列表的拉链法，图的邻接表
//这三个数据结构都是三个结构体的定义
//首节点，孩子节点，数组本身





//孩子节点，从数组里面制出来的节点
typedef struct childnode
{

    int child;//本质上就是节点在数组里面的下标，所有节点都要进入数组
    //typedef这里还没有生效所以前面要加一个struct
    struct childnode *next;


}childnode;
//数组里面保存的节点，和纯孩子节点不一样
typedef struct ctnode
{
    Elemtype data;

    childnode *firstchild;
    

    
}ctnode;


typedef struct
{
    ctnode tree[MAXSIZE];


    int n;

}ctree;


void initree(ctree &t)
{
    t.n=0;

    for(int i=0;i<MAXSIZE;i++)
    {
        
        t.tree[i].firstchild=NULL;


    }

}



bool addnode(ctree &t,Elemtype e)
{
    if(t.n>MAXSIZE)
        return false;

    //每一个节点都要存到数组里面
    t.tree[t.n].data=e;
    //新节点没有孩子
    t.tree[t.n].firstchild=NULL;

    t.n++;
    return true;
}


//添加孩子  头插法
                        //           child是数组下标的编号，就是选一个节点当孩子
                        //把下标是child的节点加到下标是parent的节点的孩子链上
bool addchild(ctree &t,int parent,int child)
{

    childnode *s=
        (childnode*)malloc(sizeof(childnode));
    //s指向这个节点
    s->child=child;

    //用的是头插法插入链
    s->next=t.tree[parent].firstchild;

    t.tree[parent].firstchild=s;

}

typedef struct childsibling
{
    Elemtype data;

    struct childsibling* child,*sibling;


}childsibling,*cstree;

void initcstree(cstree &t)
{
    t=NULL;

}

//创建节点
cstree createnode(Elemtype e)
{

    cstree s=(childsibling*)malloc(sizeof(childsibling));

    s->data=e;
    s->child=NULL;
    s->sibling=NULL;
    return s;

}

//添加第一个孩子

void addfirsrchld(cstree t,cstree child)
{
    





}
