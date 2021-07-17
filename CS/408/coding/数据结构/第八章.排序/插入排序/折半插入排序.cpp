void InsertSort(int A[], int n)
{
    int i, j, low, high, mid;
    for(i=2; i<=n; i++){
        A[0]= A[i];
        low = 1;
        high = i-1;
        while(low<=high){
            mid = (low+high)/2;
            if(A[0] < A[mid]) {
                high = mid - 1; // Search the left side of the sorted array
            }
            else low = mid + 1; // Search the right side, meanwhile ensure inserted behind if hold the same key
        }
        for(j=i-1; j>=high+1; --j){
            Aa[j+1] = A[j];
        }
        A[high+1] = A[0]; // Insert
    }
}