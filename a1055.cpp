#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct node{
	char name[10];
	int age,worth;
};
node total[maxn];
node temp[maxn];
int tmp;
int n,k;
int m,in,ax;
bool cmp(node a,node b){
	if(a.worth!=b.worth) return a.worth>b.worth;
	else if(a.age!=b.age) return a.age<b.age;
	else return strcmp(a.name,b.name)<0;
}
void query(int m,int min,int max){
	tmp =0;
	for(int i =0;i<n&&tmp!=m;i++){
		if(total[i].age>=min&&total[i].age<=max){
			temp[tmp++] = total[i];
		}
	}
	if(tmp==0) printf("None\n");
	else 
		for(int i =0;i<tmp;i++){
			printf("%s %d %d\n",temp[i].name,temp[i].age,temp[i].worth);
		}
}
int main(){
	scanf("%d %d",&n,&k);
	for(int i =0;i<n;i++){
		scanf("%s %d %d",total[i].name,&total[i].age,&total[i].worth);
	}
	sort(total,total+n,cmp);
	for(int i=0;i<k;i++){
		scanf("%d %d %d",&m,&in,&ax);
		printf("Case #%d:\n",i+1);
		query(m,in,ax);
	}
	return 0;
}
