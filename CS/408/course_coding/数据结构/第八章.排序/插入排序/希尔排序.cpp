void ShellSort(ElemType A[], int n)
{
    int i, j, dk;
    for(dk = n/2; dk>=1; dk=dk/2){
        for(i=dk+1; i<=n; i++){
            if(A[i]<A[i-dk]){
                A[0] = A[i];
                for(j=i-dk; j>0 && A[0]<A[j]; j-=dk){
                    A[j+dk] = A[j]
                }
                A[j+dk] = A[0];
            }
        }
    }
}