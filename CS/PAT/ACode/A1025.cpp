#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Student{
    char id[15];
    int score;
    int location_number;
    int local_rank;
    int total_rank;
}stu[30010];

bool cmp_score(Student a, Student b){
    if(a.score!=b.score) return a.score>b.score; // return 1 means a>b
    else return strcmp(a.id, b.id)<0; //return 1 means a<b
}

int main(){
    int n, k, num=0;
    scanf("%d", &n);// location number
    for(int i=1; i<=n; i++){
        scanf("%d", &k); //the testees in some location
        for(int j=0; j<k; j++){
            stu[num].location_number = i;
            scanf("%s %d", stu[num].id, &stu[num].score);
            num++;
        }
        
        sort(stu+num-k, stu+num, cmp_score);
        stu[num-k].local_rank = 1;
        for(int j=num-k+1; j<num; j++){
            if(stu[j].score == stu[j-1].score){
                stu[j].local_rank = stu[j-1].local_rank;
            }
            else{
                stu[j].local_rank = j+1-(num-k);
            }
        }
    }
    
    printf("%d\n",num);
    sort(stu, stu+num, cmp_score);
    int r = 1;
    for(int i = 0; i<num; i++){
        if(i>0 && stu[i].score!=stu[i-1].score){
            r = i+1;
        }
    printf("%s %d %d %d\n",stu[i].id, r, stu[i].location_number, stu[i].local_rank);    
    }
    
    /*
    stu[0].total_rank = 1;
    printf("%s %d %d %d\n",stu[0].id, 1, stu[0].location_number, stu[0].local_rank);
    for(int i=1; i<num; i++){
        if(stu[i].score==stu[i-1].score) stu[i].total_rank = stu[i-1].total_rank;
        else stu[i].total_rank = i+1;
        printf("%s %d %d %d\n",stu[i].id, stu[i].total_rank, stu[i].location_number, stu[i].local_rank);
    }
    */

    return 0;
}
