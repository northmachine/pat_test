#include <cstdio>
#include <algorithm>
#define maxn 100010
using namespace std;
struct Node{
	char c;
	int next;
	bool f;
}node[maxn];
int main(){
	int a,b,n;
	scanf("%d%d%d",&a,&b,&n);
	int add,to;
	char ch;
	for(int i =0;i<n;i++){
		scanf("%d %c %d",&add,&ch,&to);
		node[add].c = ch;
		node[add].next = to;
	}
	int temp = a;
	while(temp!=-1){
		node[temp].f = true;
		temp = node[temp].next;
	}
	temp = b;
	while(!node[temp].f&&temp!=-1) temp = node[temp].next;
	if(temp!=-1)
		printf("%05d",temp);
	else printf("-1");
	return 0;
}
