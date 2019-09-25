#include <cstdio>
#include <cstdlib>
#define maxSize 999
/*
*	�ڽӾ����� 
*/
typedef struct{
	int no; 	//������
	char info; 	//������Ϣ 
}VertexType;
typedef struct{
	int edges[maxSize][maxSize];	//��Ϊ��Ȩͼ����int��Ϊfloat 
	int n,e;	//�ֱ�Ϊ�������ͱ���
	VertexType vex[maxSize];	//��Žڵ���Ϣ 
}MGraph;
/*
*	�ڽӱ���
*/ 
typedef struct ArcNode{ 
	in adjvex;	//�ñ���ָ��Ľڵ�λ�� 
	struct ArcNode *nextarc;	//ָ����һ���ߵ�ָ�� 
	int info;	//�ñߵ������Ϣ����Ȩֵ 
}; 
typedef struct{
	char data;	//������Ϣ
	ArcNode *firstarc; 
}VNode;
typedef struct{
	VNode adjlist[maxSize];	//�ڽӱ�
	int n,e;	//�������ͱ��� 
}AGraph; 
/*
*	�����������
*/
int visit[maxSize];	//����Է��ʽڵ㣬��ʼֵΪ0
void DFS(AGraph *G,int v){
	ArcNode *p;
	visit[v]=1;	//���Է��ʱ�� 
	printf("%d ",v);	//���� 
	p=G->adjlist[v].firstarc;	//pָ�򶥵�v�ĵ�һ���� 
	while(p!=NULL){
		if(visit[p->adjvex]==0)	//������δ���ʣ���ݹ������ 
			DFS(G,p->adjvex);
		p=p->nextarc;	//pָ�򶥵�v����һ���� 
	}
} 
/*
*	�����������
*/
void BFS(AGraph *G,int v){
	ArcNode *p;
	int que[maxSize],front=0,rear=0;	//���ж��� 
	int j;
	visit[v]=1;	
	printf("%d ",v);
	rear = (rear+1)%maxSize;	// 
	que[rear]=v;				//��ǰ�ڵ���� 
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
