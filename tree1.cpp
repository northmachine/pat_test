#include <cstdio>
#include <cstdlib>
#define maxSize 999
typedef struct BTNode{
	int data;
	BTNode *lchild;
	BTNode *rchild;
}BTNode;
void preorderNonrecursion(BTNode *bt){
	if(bt!=NULL){
		BTNode *Stack[maxSize];
		int top = -1;
		BTNode *p=bt;
		Stack[++top]=p;
		while(p!=NULL&&top!=-1){
			while(p!=NULL){
				printf("%d",p->data);
				p=p->lchild;
				Stack[++top]=p;
			}
			if(top!=-1){
				p=Stack[top--];
				p=p->rchild;
			}
		}
	}
} 
