#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int n,l,h;
struct node{
	int id,v,t;
	node(int _id=0,int _v=0,int _t=0):id(_id),v(_v),t(_t){}
};
bool cmp1(node a,node b){
	if(a.v+a.t!=b.v+b.t) return a.v+a.t>b.v+b.t;
	else if(a.v!=b.v) return a.v>b.v;
	else return a.id<b.id;
}
bool cmp2(node a,node b){
	return a.id<b.id;
}
node sages[maxn];
node nobles[maxn];
node fools[maxn];
node rest[maxn];
int sa,no,fo,re;
int main(){
	scanf("%d %d %d",&n,&l,&h);
	int id,v,t;
	for(int i =0;i<n;i++){
		scanf("%d %d %d",&id,&v,&t);
		node a = node(id,v,t);
		if(v>=h&&t>=h) sages[sa++] = a;
		else if(v>=h&&t>=l) nobles[no++] = a;
		else if(v>=l&&t>=l&&v>=t) fools[fo++] = a;
		else if(v>=l&&t>=l) rest[re++] = a;
	}
	sort(sages,sages+sa,cmp1);
	sort(nobles,nobles+no,cmp1);
	sort(fools,fools+fo,cmp1);
	sort(rest,rest+re,cmp1);
	printf("%d\n",sa+no+fo+re);
	for(int i =0;i<sa;i++){
		printf("%08d %d %d\n",sages[i].id,sages[i].v,sages[i].t);
	}
	for(int i =0;i<no;i++){
		printf("%08d %d %d\n",nobles[i].id,nobles[i].v,nobles[i].t);
	}
	for(int i =0;i<fo;i++){
		printf("%08d %d %d\n",fools[i].id,fools[i].v,fools[i].t);
	}
	for(int i =0;i<re;i++){
		printf("%08d %d %d\n",rest[i].id,rest[i].v,rest[i].t);
	}
	return 0;
}
