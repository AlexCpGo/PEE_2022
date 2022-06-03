//###2.2线性表的顺序存储

#include<stdio.h>
// 2.2.1
int DeleteSmallest(SqList &L)
{
    if (L.length==0) return NULL;

    int smallest = L.data[0]; //Initially suppose that L.data[0] is the smallest.
    int sIndex = 0; 
    for(int i=1; i<L.length; i++){
        if (L.data[i] < smallest){
            smallest = L.data[i]
            sIndex = i;
        }
    }
    L.data[sIndex] = L.data[L.length-1];
    L.length--;
    return smallest;
}

// 2.2.2
void ReverseSqList(SqList &L)
{
    int temp;
    for (int i=0; i<L.length/2; i++){
        temp = L.data[i];
        L.data[i] = L.data[L.length-1-i];
        L.data[L.length-1-i] = temp;
    }
}

// 2.2.3
void Delete(SqList &L, int x)
{
    int k = 0;
    for (int i=0; i<L.length-1; i++){
        if (L.data[i]=x){
            // elements from i+1 to the last moving forward
            for (int j=i; j<L.length-2; j++){
                L.data[j] = L.data[j+1];
            }
            L.length--;
        }
    }
}

// 2.2.4
int DeleteRBetw(SqList &L, int s, int t)
{
    if (s>=t){
        cout<<"Invalid input s>=t"<<endl;
        return NULL;
    }
    else if(L.length==0){
        cout<<"SqList is empty"<<endl;
        return NULL;
    }

    for (int i=0; i<L.length-1; i++){
        if (L.data[i]>s && L.data[i]<t){
            // elements from i+1 to the last moving forward
            for (int j=i; j<L.length-2; j++){
                L.data[j] = L.data[j+1];
            }
            L.length--;
        }

        if(L.data[i]>t) return 1;
    }

    return 1; // return true;
}

// 2.2.5
int DeleteBetw(SqList &L, int s, int t)
{
    if (s>=t){
        cout<<"Invalid input s>=t"<<endl;
        return NULL;
    }
    else if(L.length==0){
        cout<<"SqList is empty"<<endl;
        return NULL;
    }

    for (int i=0; i<L.length-1; i++){
        if (L.data[i]>=s && L.data[i]<=t){
            // elements from i+1 to the last moving forward
            for (int j=i; j<L.length-2; j++){
                L.data[j] = L.data[j+1];
            }
        L.length--;
        }
    }
    return 1; // return true;
}

// 2.2.6
int DeleteRe(SqList &L){
    for (int i=1; i<L.data[L.length-1]; i++){
        for (int j=i-1; j>0 j--){
            if (L.data[i] == L.data[j]){
                //Delete the repeted Element(the later one)
                for (int k=i;k<L.length-2; k++){
                    L.data[k] = L.data[k+1];
                }
                L.length--;
            }
        }
    }
}

// 2.2.7

// 2.2.8

// 2.2.9

// 2.2.10 序列循环左移p个位置
// 1)算法设计思想: 可视为将数组ab转化为ba
/* 首先，将前p个元素逆置：a (X0, X1, ..., Xp-1) -> a^(-1) (Xp-1, ..., X1, X0)
   接着，将后n-p+1个元素逆置：b (Xp, Xp+1, ..., Xn-1) -> b^(-1) (Xn-1, ..., Xp+1, Xp) 
   最后，将两个逆置数组再整体逆置：a^(-1)b^(-1)(Xp-1, ..., X1, X0, Xn-1, ..., Xp+1, Xp) 
    -> (a^(-1)b^(-1)) = ba (Xp, Xp+1, ..., Xn-1, X0, X1, ..., Xp-1)
*/

// 2)实现
void Reverse(SqList &L, int front, int rear )
{
    int temp;
    for(int i=0; i<(rear-1-front+1)/2; i++){
        temp = L.data[front+i];
        L.data[front+i] = L.data[rear-1-i];
        L.data[rear-1-i] = temp;
    }
}

void SqListMoveL(SqList &L, int n, int p)
{
    Reverse(L, 0, p);
    Reverse(L, p, n);
    Reverse(L, 0, n);
}

// 3) T(n) = O(n), S(n) = O(1)

// 2.2.11
// 1) 算法设计思想
// 将两个升序序列A,B合并成一个升序序列C， 再从C中找其中位数

// 2) 实现
// 假定序列以顺序表的形式存储
void Merge(SqList A, SqList B, SqList &C)
{
    int i = 0; j = 0;
    while(i<A.length-1 && j<B.length-1){
        if(A.data[i]<=B.data[i]){
            C.data[i+j] = A.data[i];
            i++;
        }
        else{
            C.data[i+j] = B.data[j];
            j++;
        }
        C.length++;
    }
}

int FindTLMiddle(SqList A, SqList B)
{
    ListC_Length = A.length + B.length;
    SqList C = (SqList*)malloc(sizeof(SqList)*ListC_length);
    Merge(A, B, &C);
    int middle = C.data[cell(C.length-1)];
    return middle;
}

// 3) T(n) = O(n^2);
//    S(n) = O(p+q); (length of A is p and length of B is q)

// 2.2.12
// 1)算法设计思想
// 先将数组A用快速排序算法排成升序序列，使得可能出现部分重复元素连续分布，进而再遍历整个数组，通过统计确定主元素

// 2）实现
int FindMainElem(Array &A)
{
    low = A[0];
    high = A[A.length-1];
    QuickSort(&A, low, high); // O(n*logn)
    int Main = A[0]; //Initially the first one
    int Max = 0;
    int k = 0;
    for(int i=0; i<A.lenght-2; i++){ // O(n)
        if(A[i+1]=A[i]){
            k++;
            if(k>Max){
                Max = k;
                Main = A[i];
            }
        }
        else{
            k=0;
        }
    }
    
    if (Max>(A.length/2)) return Main;
    else return -1;
}

// 3) T(n) = O(nlogn), S(n) = O(1);








