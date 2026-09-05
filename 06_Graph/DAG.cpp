#include<iostream>
using namespace std;


#define maxs 100

typedef struct arcnode
{
    int weight;
    int adjvex;

    struct arcnode *next;




}arcnode;


typedef struct vnode
{
    int vertex;

    arcnode *first;




}vnode;



typedef struct graph
{
    int numedges;

    int numvertices;

    vnode verticeslist[maxs];

}graph;





void toposort(graph g)
{

    int degree[maxs]={0};
    for(int i=0;i<g.numvertices;i++)
    {
        arcnode *p=g.verticeslist[i].first;
        //统计每个顶点的入度
        while(p!=NULL)
        {
            degree[p->adjvex]++;
            p=p->next;


        }

    }



    //构建一个辅助队列。入度为零的入队再出队

        //出队一个顶点访问它，并将他的那条出边所指向的顶点入度减一
    int queue[maxs],front=0,rear=0;

    for (int i=0;i<g.numvertices;i++)
    {
        if(degree[i]==0)
        {
            //入度是0就入队
            queue[rear++]=i;


        }

    }


    while(front<rear)
    {
        int u=queue[front];
        front++;
        cout<<g.verticeslist[u].vertex<<" ";


        //p指向出队节点的第一条边，并判断是不是空
        for(arcnode *p=g.verticeslist[u].first;p!=NULL;p=p->next)
        {
            //v保存当前的节点的值
            //目前p是第一条边，v就是当前p的这一条边的弧尾节点
            //判断这个节点的入度，等于0要入队
            int v=p->adjvex;
            degree[v]--;
            if(degree[v]==0)
            {
                queue[rear++]=v;


            }




        }

    }



    if(rear<g.numvertices)
    {
        cout<<"有环";
    }


}
