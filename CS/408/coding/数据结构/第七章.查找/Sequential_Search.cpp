// ## Sequence Search
typedef struct{
    ElemType *elem;
    int TbaleLen;
}SSTable;
int Search_Seq(SSTable ST, ElemType key)
{
    // Method 1
    ST.elem[0] = key; // A guard at ST.elem[0];
    for(i=ST.TableLen; ST.elem[i]!=key; --i);
    return i;
    // Method 2:
    /*  for (i=0; i<ST.TableLen && ST.elem[i]!=key; i++);
        return i == ST.TableLen? -1:i;
}