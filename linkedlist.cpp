#include <cstdio>
#include <cstdlib>
struct node{
	int data;
	node* next;
};
node *create(int ary[],int n){
	node *p,*pre,*head;
	head = new node;
	head->next = NULL;
	pre = head;
	for(int i =0;i<n;i++){
		p = new node;
		p->data  = ary[i];
		p->next = NULL;
		pre->next = p;
		pre = p;
	}
	return head;
}
int search(node *head ,int x){
	int count;
	node *temp = head->next;
	while(temp){
		if(temp->data == x)
			count++;
		temp = temp->next;
	}
	return count;
}
void insert(node *head,int pos,int x){
	node *p = head;
	for(int i =0;i<pos-1;i++)
		p = p->next;
	node *q = new node;
	q->data = x;
	q->next = p->next;
	p->next = q;
}
void del(node *head,int x){
	node *p = head->next;
	node *pre = head;
	while(p){
		if(p->data == x){
			pre->next = p->next;
			delete(p);
			p = pre->next; 
		}
		else{
			pre = p;
			p = p->next;
		}
	}
}
int main(){
	int a[5] = {1,2,5,4,5};
	node *L = create(a,5);
	node *LL  = L->next;
	while(LL){
		printf("%d ",LL->data);
		LL = LL->next;
	}
	printf("\n");
	int c = search(L,5);
	printf("%d",c);
	return 0;
}
