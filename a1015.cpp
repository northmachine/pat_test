#include <cstdio>
#include <vector>
using namespace std;
bool isPrime(int x){
	if(x<=1) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
	return true;
}
int rev(int x,int radix){
	vector<int> ary;
	while(x!=0){
		ary.push_back(x%radix);
		x/=radix;
	}
	int r =1;
	for(int i =ary.size()-1;i>=0;i--){
		x+= r*ary[i];
		r*=radix;
	}
	return x;
}
int main(){
	int d=0,n=0;
	scanf("%d",&n);
	while(n>=0){
		scanf("%d",&d);
		if(isPrime(n)&&isPrime(rev(n,d))) printf("Yes\n");
		else printf("No\n");
		scanf("%d",&n);
	}
	return 0;
} 
