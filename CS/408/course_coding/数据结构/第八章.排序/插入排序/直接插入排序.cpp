// Simple InsertSort Algorithm to get an array in ascending order
void InsertSort(ElemType A[], int n)
{
    int i, j, temp;
    //A[0] = NULL or A[0] is a guard
    for(i=2; i<=n; i++){
        if(A[i]<A[i-1]){
            temp = A[i];
            for(j=i-1; A[j]>temp && j>=0;--j){
                A[j+1] = A[j];
            }
            A[j+1] = temp;
        }
    }
}