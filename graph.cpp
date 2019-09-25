#include <cstdio>
#include <cstdlib>
#define maxSize 999
/*
*	邻接矩阵定义 
*/
typedef struct{
	int no; 	//顶点编号
	char info; 	//顶点信息 
}VertexType;
typedef struct{
	int edges[maxSize][maxSize];	//若为有权图，将int改为float 
	int n,e;	//分别为顶点数和边数
	VertexType vex[maxSize];	//存放节点信息 
}MGraph;
/*
*	邻接表定义
*/ 
typedef struct ArcNode{ 
	in adjvex;	//该边所指向的节点位置 
	struct ArcNode *nextarc;	//指向下一条边的指针 
	int info;	//该边的相关信息，如权值 
}; 
typedef struct{
	char data;	//顶点信息
	ArcNode *firstarc; 
}VNode;
typedef struct{
	VNode adjlist[maxSize];	//邻接表
	int n,e;	//顶点数和边数 
}AGraph; 
/*
*	深度优先搜索
*/
int visit[maxSize];	//标记以访问节点，初始值为0
void DFS(AGraph *G,int v){
	ArcNode *p;
	visit[v]=1;	//置以访问标记 
	printf("%d ",v);	//访问 
	p=G->adjlist[v].firstarc;	//p指向顶点v的第一条边 
	while(p!=NULL){
		if(visit[p->adjvex]==0)	//若顶点未访问，则递归访问它 
			DFS(G,p->adjvex);
		p=p->nextarc;	//p指向顶点v的下一条边 
	}
} 
/*
*	广度优先搜索
*/
void BFS(AGraph *G,int v){
	ArcNode *p;
	int que[maxSize],front=0,rear=0;	//队列定义 
	int j;
	visit[v]=1;	
	printf("%d ",v);
	rear = (rear+1)%maxSize;	// 
	que[rear]=v;				//当前节点进队 
	while(rear!=front){
		front = (front+1)%maxSize;
		j = que[front];
		p=G->adjlist[j].firstarc;
		while(p!=NULL){
			if(visit[p->adjvex]==0){
				visit[p->adjvex]=1;
				printf("%d ",p->adjvex);
				rear = (rear+1)%maxSize;
				que[rear] = p->adjvex;
			}
			p=p->nextarc
		}
	}
} 
