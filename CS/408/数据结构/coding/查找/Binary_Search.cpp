// ## Binary Search
// Data structure: Sequence List
// By default, the binary search algorithm is used in an ascending order array/list.
typedef struct{
    ElemType *elem;
    int TableLen;
}SSTable;x

int Binary_Search(SSTable L, ElemType key)
{
    int low = 0, hig h= L.TableLen-1, mid;
    while(low<=high){
        mid = (low+high)/2;
        if(L.elem[mid]==key){
            return mid;
        }
        else if(L.elem(mid)>key){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}