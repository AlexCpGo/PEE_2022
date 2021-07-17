void swap(int &a, int &b)
{
    int temp = b;
    b = a;
    a = temp;
}

void BubbleSort(ElemType A[], int n){
    for(i=0; i<n-1; i++){
        flag = false;
        for(j=n-1; j>i; j--){
            if(A[j-1] > A[j]){
                swap(A[j-1], A[j]);
                flag = true;
            }
        }
        if(!flag){
            return; //No swap in the list, the list has already been sorted
        }
    }
}
