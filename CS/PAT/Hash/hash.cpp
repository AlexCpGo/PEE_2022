// chars followd by number -> get the hash id
int hashFunc(char S[], int len)
{
    int id=0;
    for(int i=0; i<len-1; i++){
        id = id * 26 + (S[i]-"A");
    }

    id = id*10 + (S[len-1]-"0");
    return id;
}