//遵循让权等待原则
//#整形信号量
int S = 1;
// P操作
void wait(int S)
{
    while(S <= 0); //会发生忙等原则；
    S = S - 1;
}

// V操作
void signal(int S)
{
    S = S + 1;
}

// Example
/* 
进程P0
...
wait(S);
使用打印机资源...
signal(S);
...
*/

/* 进程P1
...
wait(S);
使用打印机资源...
signal(S);
...
*/

//#记录型信号量
typedef struct{
    int value;
    struct process *L;
}semaphore;

void wait(semaphore S)
{
    S.value--;
    if(S.value<){
        // add this process to S.L;
        block(S.L);
    }
}

void signal(semaphore S)
{
    S.value++;
    if(S.value<=0){
        // remove a process P from S.L;
        wakeup(P);
    }
}


// ######利用信号量实现同步与互斥
// ##互斥
semaphore mutex = 1;
P1(){
    ...
    P(mutex); // Block here
    进程P1的临界区;
    V(mutex);
    ...
}

P2(){
    ...
    P(mutex);
    进程P2的临界区;
    V(mutex);
    ...
}

// ##同步
semaphore S = 0;
P1(){
    block 1;
    block 2;
    V(S);
    block 3;
}

P1(){
    block 4;
    block 5;
    P(S); // To check whether Codes in block 1 and 2 have been run 
    block 6;
}

// ##实现前驱关系
// S1->S2, S1->S3, S2->S4, S2->S5, S3->S6, S4->S6, S5->S6
semaphore s12, s13, s24, s25, s36, s46, s56
S1(){
    ...;
    V(s12);
    V(s13);
}

S2(){
    P(s12);
    ...;
    V(s24);
    V(s25);
}

S3(){
    P(s13);
    ...;
    V(s36);
}

S4(){
    P(s24);
    ...;
    V(s46);
} 
S5(){
    P(s25);
    ...;
    V(s56);
}
S6(){
    P(s36);
    P(s46);
    P(s56);
    ...;
}