#include<stdio.h>
int main(){
    int n;
    long long A, B, C;
    scanf("%d", &n);
    for(int i=0; i<=n-1; i++){
        scanf("%lld %lld %lld", &A, &B, &C);
        if(A+B>C){
            printf("Case #%d: true\n",i+1);
        }
        else{
            printf("Case #%d: false\n",i+1);
        }
    }
    return 0;
}
