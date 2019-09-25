#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 1010;
const int INF = 0x3fffffff;
queue<int> Q[21];
int process_time[maxn],leave_time[maxn],que_time[21];
int n,m,k,q;
int main(){
	scanf("%d %d %d %d",&n,&m,&k,&q);
	for(int  i=1;i<=k;i++){
		scanf("%d",&process_time[i]);
	}
	int i;
	for(i=0;i<n*m&&i<k;i++){
		Q[i%n].push(i+1);
		leave_time[i+1] = que_time[i%n]+process_time[i+1];
		que_time[i%n] = leave_time[i+1];
	}
	
	for(;i<k;i++){
		int index = 0;
		int min = INF;
		for(int j=0;j<n;j++){
			int temp = Q[j].front();
			if(leave_time[temp]<min){
				index = j;
				min = leave_time[temp];
			}
		}
		Q[index].pop();
		Q[index].push(i+1);
		leave_time[i+1] = que_time[index] + process_time[i+1];
		que_time[index] = leave_time[i+1];
	} 
	for (i = 0;i < q;++i) {
		int j;
        scanf("%d", &j);
        if (leave_time[j] - process_time[j] >= 540)
            printf("Sorry\n");
        else {
            printf("%02d:%02d\n", leave_time[j] / 60 + 8, leave_time[j] % 60);
        }
    }
    return 0;
}
