#include<stdio.h>
int main()
{
    int col,row;
    char c;
    scanf("%d %c",&col, &c);
    if (col%2==0) row = col/2;
    else row = col/2 + 1;
    
    for(int i=0; i<=row-1; i++){
        if(i==0||i==row-1){
            for(int j=0; j<=col-1; j++){
                printf("%c", c);
            }
        }
        
        else{
            for(int j=0; j<=col-1; j++){
                if(j==0||j==col-1){
                    printf("%c", c);
                }
                else{
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}
