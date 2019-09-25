#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct node{
	int id,grade;
	char name[10];
}st[maxn]; 
bool cmp1(node a,node b){
	return a.id<b.id;
}
bool cmp2(node a,node b){
	if(strcmp(a.name,b.name)!=0) return strcmp(a.name,b.name)<0;
	else return a.id<b.id;
}
bool cmp3(node a,node b){
	if(a.grade!=b.grade) return a.grade<b.grade;
	else return a.id<b.id;
}
int n,c;
int main(){
	scanf("%d %d",&n,&c);
	int id,grade;
	char name[10];
	for(int i=0;i<n;i++){
		scanf("%d %s %d",&id,name,&grade);
		st[i].id = id;
		st[i].grade = grade;
		strcpy(st[i].name,name);
	}
	switch(c){
		case 1:
			sort(st,st+n,cmp1);
			break;
		case 2:
			sort(st,st+n,cmp2);
			break;
		case 3:
			sort(st,st+n,cmp3);
			break;
		default:
			break;
	}
	for(int i =0;i<n;i++){
		printf("%06d %s %d\n",st[i].id,st[i].name,st[i].grade);
	}
	return 0;
}
