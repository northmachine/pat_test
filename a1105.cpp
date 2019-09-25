#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int n;
int a[maxn];
int matrix[150][150];
int main(){
	scanf("%d",&n);
	for(int i =0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	int i;
	for(i =sqrt(n);i>1;i--){
		if(n%i==0)break;
	}	
	int up = 1,down = n/i-1,left = 0,right = i-1;
	int c = n-1,pos1=0,pos2=0,status=1;
	if(i==1) status=2;
	while(c>=0){
		matrix[pos1][pos2] = a[c--];
		switch(status){
			case 1:pos2++;
				if(pos2==right){
					status=2;
					right--;
				}
				break;
			case 2:pos1++;
				if(pos1==down){
					status=3;
					down--;
				}
				break;
			case 3:pos2--;
				if(pos2==left){
					status=4;
					left++;
				}
				break;
			case 4:pos1--;
				if(pos1==up){
					status=1;
					up++;
				}
				break;
			default:
				break; 
		}
	}
	for(int x=0;x<n/i;x++){
		for(int y=0;y<i;y++){
			printf("%d",matrix[x][y]);
			if(y!=i-1)printf(" ");
		}
		if(x!=n/i-1) printf("\n");
	}
	return 0;
} 
