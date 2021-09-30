#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
struct Student{
    int ID;
    int grade[4]; // grade[0]:A; grade[1]:C; grade[2]:M; grade[3]:E
    //int rank[4]; rank[0]~rank[3]: rank of this student from A to E
}stu[2010];

char course[4] = {'A', 'C', 'M', 'E'};
int Rank[10000000][4] = {0};
int Igrade;

bool cmp_grade(Student a, Student b)
{
    return a.grade[Igrade] > b.grade[Igrade];
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    // get grade of A, C, M, E
    for(int i=0; i<n; i++){
        scanf("%d%d%d%d", &stu[i].ID, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
        stu[i].grade[0] = round(stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3]) / 3.0;
    }
    
    // get rank of A, C, M, E
    for(Igrade=0; Igrade<4; Igrade++){
        sort(stu, stu+n, cmp_grade);
        //stu[0].rank[Igrade] = 1;
        Rank[stu[0].ID][Igrade] = 1;
        for(int k=1; k<n; k++){
            if(stu[k].grade[Igrade]==stu[k-1].grade[Igrade]){
                //stu[k].rank[Igrade] = stu[k-1].rank[Igrade];
                Rank[stu[k].ID][Igrade] = Rank[stu[k-1].ID][Igrade];
            }
            else{
                Rank[stu[k].ID][Igrade] = k + 1;
            }
        }
    }
    
    // Find the student and get its highest rank;
    int query;
    
    for(int q=0; q<m; q++){
        scanf("%d", &query);
        if(Rank[query][0]==0){
            printf("N/A\n");
        }
        else{
            h = 0;
            for(int j=0; j<4; j++){
                if(Rank[query][j] < Rank[query][h]){
                    h = j;
                }
            }
            printf("%d %c\n", Rank[query][h], course[h]);
        }
    }

    return 0;
}
