#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct node{
	char name[11],id[11];
	int grade;
}; 
int n;
node st[maxn];
node tmp[maxn];
int temp;
bool cmp(node a,node b){
	return a.id>b.id;
}
int main(){
	scanf("%d",&n);
	for(int i =0;i<n;i++){
		scanf("%s %s %d",st[i].name,st[i].id,&st[i].grade);
	}
	int g1,g2;
	scanf("%d %d",&g1,&g2);
	for(int i =0;i<n;i++){
		if(st[i].grade>=g1&&st[i].grade<=g2){
			tmp[temp++] = st[i];
		}
	}
	sort(tmp,tmp+temp,cmp);
	if(temp ==0)printf("NONE");
	else{
		for(int i =0;i<temp;i++){
			printf("%s %s",tmp[i].name,tmp[i].id);
			if(i!=temp-1) printf("\n"); 
		}
	}
	return 0;
} 
