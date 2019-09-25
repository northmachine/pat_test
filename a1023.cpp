#include <cstdio>
int a[30];
int b[30];
int n;
int tmp[11]={0};
int main(){
	char cc;
	while(true){
		cc = getchar();
		if(cc!='\n'){
			a[n++] = cc-'0';
			tmp[cc-'0']++;
		}
		else break;
	}
	int c=0;
	for(int i =n-1;i>=0;i--){
		b[i] = (a[i]*2+c)%10;
		c = (a[i]*2+c)/10;
	}
	if(c!=0){
		printf("No\n");
		printf("%d",c);
		for(int i =0;i<n;i++) printf("%d",b[i]); 
	}
	else{
		for(int i =0;i<n;i++)tmp[b[i]]--;
		for(int i =0;i<10;i++){
			if(tmp[i]!=0){
				printf("No\n");
				break;
			}
			if(i==9){
				printf("Yes\n");
			}
		}
		for(int i =0;i<n;i++) printf("%d",b[i]); 
	}
	return 0;
} 
