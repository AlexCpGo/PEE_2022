// Access on Critical Resource
do {
    entry section;
    critical section;
    exit section;
    remainder section;
} while(true);

// #### software method implementation
// Single Notation Method: 违背空闲让进原则
int turn = 0;
// P0进程
while (turn != 0);
critical section;
turn = 1;
remainder section;

// P1进程   
while(turn != 1);
critical section;
turn = 0;
remainder section;

// 双标志先检查法: 违背忙则等待原则, 原因在于检查和上锁间可能存在进程切换（异步性）
bool flag[2];
flag[0] = false;
flag[1] = false;

// P0进程
while(flag[1]);
flag[0] = true;
critical section;
flag[0] = false;
remainder section;


// P1进程
while(flag[0]);
flag[1] = true;
critical section;
flag[1] = false;
remainder section;

// 双标志后检查法: 违背空闲让进和有限等待原则, 原因在于异步性可能使各进程长期无法访问临界资源而产生饥饿现象
bool flag[2];
flag[0] = false;
flag[1] = false;

// P0进程
flag[0] = true;
while(flag[1]);
critical section;
flag[0] = false;
remainder section;


// P1进程
flag[1] = true;
while(flag[0]);
critical section;
flag[1] = false;
remainder section;

// Peterson' s Algorithm: 遵循了空闲让进、忙则等待、有限等待原则，但依然未遵循让权等待原则
// P0进程
flag[0] = true;
turn = 1
while(flag[1] && turn==1);
critical section;
flag[0] = false;
remainder section;


// P1进程
flag[1] = true;
turn = 0
while(flag[0] && turn==0);
critical section;
flag[1] = false;
remainder section;


// #### hardware method implementation
// 1) 中断屏蔽方法： 简单、高效
/*
... 
关中断；
临界区；
开中断；
...
*/

// 2) 硬件指令方法（TestAndSet TS or TestAndSetLock TSL)： 不能实现让权等待 
// 代码仅为对功能实现的描述，实际为硬件逻辑实现，原子操作不被中断
/*
boolean TestAndSet(boolean *lock)
{
    boolean old;
    old = *lock;
    *lock = true;
    return old;
}

while TestAndSet(&lock);
进程的临界区代码段;
lock = false;
进程的其他代码;
*/

// 3) Swap指令: 不能实现让权等待
/*
Swap(boolean *a, boolean *b)
{
    boolean temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

key = true;
while (key != false)
    Swap(&lock, &key);
进程的临界区代码段;
lock = false;
进程的其他代码;


