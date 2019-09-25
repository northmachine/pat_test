#include <cstdio>
#include <cstdlib>
int main(){
	int *a = (int*)malloc(3*sizeof(int));
	for(int i=0;i<3;i++) printf("%d\n",a[i]) ;
	return 0;
}
