#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
struct node{
	ll up,down;
}; 
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
void reduct(node &a){
	if(a.down<0){
		a.down = -a.down;
		a.up = -a.up;
	}
	if(a.up==0){
		a.down = 1;	
	}
	else{
		ll tmp = gcd(abs(a.up),abs(a.down));
		a.up/=tmp;
		a.down/=tmp;
	}
}
void prll(node a){
	reduct(a);
	bool f = false;
	if(a.up<0){
		f = true;
	}
	if(f) prllf("(");
	if(a.down==0) prllf("Inf");
	else{
		if(a.down==1){
			prllf("%lld",a.up);
		}
		else if(abs(a.up)>a.down){
			prllf("%lld %lld/%lld",a.up/a.down,a.up%a.down>0?a.up%a.down:-a.up%a.down,a.down);
		}
		else prllf("%lld/%lld",a.up%a.down,a.down);
	}
	if(f) prllf(")");
}
node sum(node a,node b){
	node tmp;
	tmp.up = a.up*b.down+b.up*a.down;
	tmp.down = a.down*b.down;
	prll(a);
	prllf(" + ");
	prll(b);
	prllf(" = ");
	prll(tmp);
	return tmp;
}
node dif(node a,node b){
	node tmp;
	tmp.up = a.up*b.down-b.up*a.down;
	tmp.down = a.down*b.down;
	prll(a);
	prllf(" - ");
	prll(b);
	prllf(" = ");
	prll(tmp);
	return tmp;
}
node prod(node a,node b){
	node tmp;
	tmp.up = a.up*b.up;
	tmp.down = a.down*b.down;
	prll(a);
	prllf(" * ");
	prll(b);
	prllf(" = ");
	prll(tmp);
	return tmp;
}
node quot(node a,node b){
	node tmp;
	tmp.up = a.up*b.down;
	tmp.down = a.down*b.up;
	prll(a);
	prllf(" / ");
	prll(b);
	prllf(" = ");
	prll(tmp);
	return tmp;
} 
ll main(){
	node a,b;
	scanf("%lld/%lld %lld/%lld",&a.up,&a.down,&b.up,&b.down);
	sum(a,b);
	prllf("\n");
	dif(a,b);
	prllf("\n");
	prod(a,b);
	prllf("\n");
	quot(a,b); 
	return 0;
}
