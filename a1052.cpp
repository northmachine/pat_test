#include <cstdio>
#include <algorithm>
#define maxn 100010
using namespace std;
struct Node{
	int address,key,next;
	bool flag;
}node[maxn];
bool cmp(Node a,Node b){
	if(!a.flag||!b.flag)
		return a.flag>b.flag;
	else 
		return a.key<b.key;
}
int main(){
	int n,a;
	scanf("%d%d",&n,&a);
	int add,x,to;
	for(int i =0;i<n;i++){
		scanf("%d%d%d",&add,&x,&to);
		node[add].key=x;
		node[add].next = to;
		node[add].address = add;
	}
	int temp = a;
	int count = 0;
	while(a!=-1){
		node[a].flag = true;
		++count; 
		a = node[a].next;
	}
	sort(node+0,node+maxn,cmp);
	if(count!=0)
		printf("%d %05d\n",count,node[0].address);
	else
		printf("%d -1\n",count,node[0].address);
	for(int i =0;i<count;i++){
		if(i!=count-1)
			printf("%05d %d %05d\n",node[i].address,node[i].key,node[i+1].address);
		else
			printf("%05d %d -1\n",node[i].address,node[i].key,node[i+1].address);
	}
	return 0;
}

