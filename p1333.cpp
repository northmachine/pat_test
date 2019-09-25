#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <cctype>
#define For(i,a,b) for(i=(a);i<=(b);++i)
#define Forward(i,a,b) for(i=(a);i>=(b);--i)
using namespace std;
using namespace __gnu_pbds;
template<typename T>inline void read(T &x){
	T s = 0,f =1;char k = getchar();
	while(!isdigit(k)&&k^'-') k = getchar();
	if(!isdigit(k)){f = -1;k=getchar();}
	while(isdigit(k)){s=s*10+(k^48);k=getchar();}
	x = s*f;
}
void file(void){
	#ifdef ONLINE_JUDGE
	freopen("P1333.in","r",stdin);
	freopen("P1333.out","w",stdout);
	#endif
}

