#include <cstdio>
int a[100000];
int tmp[100000];
int n,k;
int main(){
	char c;
	while(1){
		c = getchar();
		if(c!=' ')a[n++] = c-'0';
		else break;
	}
	for(int i =0;i<n;i++) tmp[i] = a[i];
	for(int i =0;i<n;i++)a[n-1-i] = tmp[i];
	scanf("%d",&k);
	bool f = true;
	for(int j =0;j<n;j++){
		if(a[j]!=a[n-1-j]) f = false;
	}
	if(f){
		for(int j =0;j<n;j++) printf("%d",a[n-1-j]);
		printf("\n0");
	}else{
		for(int i =0;i<k;i++){
			for(int i =0;i<n;i++) tmp[i] = a[i];
			int c=0;
			for(int j =0;j<n;j++){
				a[j] = (c+tmp[j]+tmp[n-1-j])%10;
				c = (c+tmp[j]+tmp[n-1-j])/10;
			}
			if(c!=0) a[n++] = c;
			f = true;
			for(int j =0;j<n;j++){
				if(a[j]!=a[n-1-j]) f = false;
			}
			if(f){
				for(int j =0;j<n;j++) printf("%d",a[n-1-j]);
				printf("\n%d",i+1);
				break;
			}
		}
		if(!f){
			for(int i =0;i<n;i++) printf("%d",a[n-1-i]);
			printf("\n%d",k);
		}
	}	
	return 0;
}
