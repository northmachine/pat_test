#include <cstdio>
#include <cmath>
using namespace std;
const int maxn = 110;
typedef long long LL;
struct node{
	LL num=0,dnum=1;
};
node a;
int n;
LL gcd(LL a,LL b){
	return b==0?a:gcd(b,a%b);
}
node add(node a,node b){
	LL tmp;
	node t;
	t.num = a.num*b.dnum+b.num*a.dnum;
	t.dnum = a.dnum*b.dnum;
//	printf("%lld/%lld\n",t.num,t.dnum);
	tmp = gcd(abs(t.num),abs(t.dnum));
//	printf("%lld\n",tmp);
	t.dnum/=tmp;
	t.num/=tmp;
	return t;
}
int main(){
	scanf("%d",&n);
	node ans;
	for(int i =0;i<n;i++){
		scanf("%lld/%lld",&a.num,&a.dnum);
	//	printf("%lld/%lld\n",a.num,a.dnum);
		ans = add(ans,a);
	}
	if(ans.num/ans.dnum!=0){
		printf("%lld",ans.num/ans.dnum);
		if(ans.num%ans.dnum!=0)printf(" ");
	}
	if(ans.num%ans.dnum!=0)printf("%lld/%lld",ans.num%ans.dnum,ans.dnum);
	if(ans.num/ans.dnum==0&&ans.num%ans.dnum==0) printf("0");
	return 0;
}
