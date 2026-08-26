#include<iostream>
#include<queue>
using namespace std;
typedef int Elemtype;
//二叉树节点的定义

//一个数据
//一个btnode类型的左孩子指针和一个右孩子指针
typedef struct btnode
{
    Elemtype data;

    struct btnode *lchild;
    struct btnode *rchild;
}btnode,*bitree;


void init(bitree &t)
{
    t=NULL;
}

bitree creatnode(Elemtype e)
{
    bitree t=(btnode*)malloc(sizeof(btnode));

    t->data=e;

    t->lchild=NULL;
    t->rchild=NULL;

}

//创建二叉树:根据键盘输入的值构建二叉树
bitree creatree()
{
    Elemtype x;
    //从键盘输入要创建的节点的值，如果输入的值是-1代表是空节点
    cin>>x;

    if(x=-1)
        return NULL;

    bitree t=creatnode(x);
    //调用上面的创建节点从根节点开始创建，这里用的是先序。
    t->lchild=creatree();
    //对左孩子一样从键盘输入值代表创建节点，如果输入的是-1就代表空节点没有左孩子
    t->rchild=creatree();
    //同理
    return t;

}



//中序遍历
void inorder(bitree t)
{
    if(t==NULL)
        return;
    inorder(t->lchild);

    cout<<t->data<<" ";

    inorder(t->rchild);
}




//先序遍历

void preorder(bitree t)
{
    if(t==NULL)
        return;

    cout<<t->data<<" ";

    preorder(t->lchild);

    preorder(t->rchild);
}





//后跟遍历

void postorder(bitree t)
{
    if(t==NULL)
        return;

    postorder(t->lchild);
    postorder(t->rchild);

    cout<<t->data<< " ";
}




//层序遍历
//根本就是从根节点开始把自己左孩子有孩子依次入队再出队

void levelorder(bitree t)
{   
    if(t==NULL)
        return ;
    //定义容器，本质就是使用标准库的queue不用自己定义了
    queue<bitree> q;

    q.push(t);


    //这里调用的是标准库里面的函数
    //和之前自己写的一样判断空 返回值是bool类型
    //这里代表队列非空进入循环
    while(!q.empty())
    {   
        //创建一个指针指向队头
        bitree s=q.front();

        q.pop();

        cout<<s->data<<" ";

        if(s->lchild!=NULL)
            //把出队节点的左右孩子一次入队
            q.push(s->lchild);

        if(s->rchild!=NULL)
            q.push(s->rchild);
    }

//总的逻辑：根节点入队，根节点出队。左右孩子依次入队
//只要队列非空就下一次循环。从队头开始循环

    cout<<endl;

}


void getcount(bitree t, int &count)
{
    if(t == NULL)
        return;

    //不能直接定义局部变量在里面++，因为这样子每一次调用都会重新创建
    //让count一直是初始值，所以要引用
    //除非直接在函数外面定义count
    count++;

    getcount(t->lchild, count);
    getcount(t->rchild, count);
}

//int count = 0;   // 全局变量

// void getcount(bitree t)
// {
//     if(t == NULL)
//         return;
        //全局变量，每一次递归的时候都保证了正确的
//     count++;

//     getcount(t->lchild);
//     getcount(t->rchild);
// }

//求叶子节点数量
void getleaf(bitree t, int &count)
{
    if(t == NULL)
        return;

    if(t->lchild == NULL &&
       t->rchild == NULL)
    {
        count++;
        return;
    }

    getleaf(t->lchild, count);
    getleaf(t->rchild, count);
}

//求树的高度
int gethigh(bitree t)
{
    if(t==NULL)
        return 0;



    int left =gethigh(t->lchild);
    int right=gethigh(t->rchild);

    return max(right,left)+1;

//假设只有一个，gethigh左孩子右孩子都是null
//left：return0    right：return 0；，最终max（0，0）+1=1；数的高度就是一


//两个节点                      
//         1                        先gethigh(1)，get1调用gethigh(2)
//      2                           gethigh(2)左右子树null，返回max（0，0）+1=1
//                                  所以gethigh(2)=1
//                                  那么gethigh（1）左子树高度1，右子树0
//return maxsize（1，0）+1=2

}




//按值查找

bitree locatelem(bitree t,Elemtype e)
{
    if(t==NULL)
        return NULL;
    //直接查到就是根节点。直接返回了
    if(t->data==e)
        return t;

    //定义一个指针接受递归返回的结果
    //先查根节点再查左子树。如果不是null就代表查到了
    bitree p=locatelem(t->lchild,e);
    if(p!=NULL)
        return p;

    //左边没查到，去查右边
    //现在只剩右子树了要么成功要么失败直接返回
    return locatelem(t->rchild,e);
}