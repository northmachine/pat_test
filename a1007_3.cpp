#include <stdio.h>

//N是数组长度，num是待计算的数组，放在全局区是因为可以开很大的数组
int N, num[134217728];

int main()
{
    //输入数据
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        scanf("%d", &num[i]);
    
    //计算数组前缀和，并在此过程中得到答案
    num[0] = 0;
    int ans = num[1], lmin = 0;
    for(int i = 1; i <= N; i++) {
        num[i] += num[i - 1];
        if(num[i] - lmin > ans)
            ans = num[i] - lmin;
        if(num[i] < lmin)
            lmin = num[i];
    }

    printf("%d\n", ans);

    return 0;
}
