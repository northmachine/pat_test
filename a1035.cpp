#include <cstdio>
#include <cstring>
struct node{
	char name[11];
	char pass[11];
}user[1010];
bool fix[1010];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0 ;i<n;i++){
		scanf("%s %s",user[i].name,user[i].pass);
	}
	int m=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<strlen(user[i].pass);j++){
			if(user[i].pass[j]=='1'||
				user[i].pass[j]=='0'||
				user[i].pass[j]=='l'||
				user[i].pass[j]=='O'){
				if(!fix[i]){
					m++;
					fix[i] = true;
				}
				if(user[i].pass[j]=='1'){
					user[i].pass[j]='@';
				}
				if(user[i].pass[j]=='0'){
					user[i].pass[j]='%';
				}
				if(user[i].pass[j]=='l'){
					user[i].pass[j]='L';
				}
				if(user[i].pass[j]=='O'){
					user[i].pass[j]='o';
				}
			}			
		}
	}
	if(m!=0){
		printf("%d\n",m);
		for(int i =0;i<n;i++){
			if(fix[i]){
				printf("%s %s\n",user[i].name,user[i].pass);
			}	
		}
	}
	else if(n>1){
		printf("There are %d accounts and no account is modified",n);
	}
	else printf("There is %d account and no account is modified",n);
	return 0;
}
