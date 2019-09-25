#include <cstdio>
#include <cstring>
struct bign{
	int d[1000];
	int len;
	bign(){
		memset(d,0,sizeof(d));
		len = 0;
	}
};
bign change(char str[]){
	bign a;
	a.len = strlen(str);
	for(int i =0;i<a.len;i++)
		a.d[i] = str[a.len-1-i] - '0';
	return a;
}
bign add(bign a,bign b){
	bign c;
	int carry = 0;
	for(int i = 0;i<a.len||i<b.len;i++){
		int t = a.d[i]+b.d[i]+carry;
		c.d[i] = t%10;
		++c.len;
		carry = t/10;
	}
	if(carry!=0) c.d[c.len++] = carry;
	return c; 
}
bign sub(bign a,bign b){
	bign c;
	for(int i =0;i<a.len||i<b.len;i++){
		if(a.d[i]>=b.d[i]){
			c.d[c.len++] = a.d[i]-b.d[i]; 
		}
		else{
			a.d[i+1]--;
			c.d[c.len++] = 10 + a.d[i] -b.d[i];
		}
	}
	if(c.d[c.len-1]==0) --c.len;
	return c;
}
bign multi(bign a,int b){
	bign c;
	int carry=0,t=0;
	for(int i =0;i<a.len;i++){
		t = a.d[i]*b + carry;
		c.d[c.len++] = t%10;
		carry = t/10;
	}
	while(carry!=0){
		c.d[c.len++] = carry%10;
		carry/=10;
	}
	return c;
}
bign divide(bign a,int b){
	bign c;
	int t = 0;
	c.len = a.len;
	for(int i =a.len-1;i>=0;i--){
		t  = t*10 +a.d[i];
		if(t>=b){
			c.d[i] = t/b;
			t = t%b;
		}
		else c.d[i]=0;
	}
	while(c.d[c.len-1]==0&&c.len>1) --c.len;
	return c;
}
void print(bign a){
	for(int i = a.len-1;i>=0;i--)
		printf("%d",a.d[i]);
}
int main(){
	char a[1000];
	char b[1000];
	scanf("%s%s",a,b);
	bign aa=change(a);
	bign bb = change(b);
	bign cc = multi(aa,35);
	print(aa);
	printf("*");
	printf("35");
	printf("=");
	print(cc);
	return 0;
}
