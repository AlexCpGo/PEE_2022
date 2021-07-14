// #1. Problem of Producer & Consumer
semaphore mutex = 1;
semaphore empty = n;
semaphore full = 0;

producer()
{
    while(1){
        produce an item  in nextp;
        P(empty);
        P(mutex);
        add nextp to buffer;
        V(mutex);
        V(full);
    }
}

consumer()
{
    while(1){
        P(full);
        P(mutex);
        remove an item from buffer;
        V(mutex);/
        V(empty);
        //Sperate this block from the critical section to decrease the running time and work load of the critical section
        consume the item; 
    }
}

// 复杂的生产者-消费者问题
semaphore plate = 1, apple = 0, orange = 0;
dad(){
    while(1){
        prepare an apple;
        P(plate);
        put the apple on the plate;
        V(apple);
    }
}

mom(){
    while(1){
        prepare an orange;
        P(plate);
        put the orange on the plate;
        V(orange);
    }
}

son(){
    while(1){
        P(orange);
        take an orange from the plate;
        V(plate);
        eat the orange;
    }
}
 daughter(){
     while(1){
        P(apple);
        take an apple from the plate;
        V(plate);
        eat the apple;
     }
 }

// #2. Problem of Reader & Writer
int count = 0;
semaphore mutex = 1;
semaphore rw = 1;
// To avoid the hunger of writing
writer(){
    while(1){
        // P(w);
        P(rw);
        writing;
        V(rw);
        // V(w);
    }
}

Reader(){
    while(1){
        // P(w);
        P(mutex);
        if(count == 0){
            P(rw);
        }
        count++;
        V(mutex);
        //V(w);

        reading;
        P(mutex);
        count--;
        if(count==0){
            V(rw);
        }
        V(mutex);
    }
}

// #3. Dining Philosophers Problem
semaphore chopstick[5] = {1, 1, 1, 1, 1};
// Method 3.1, which will lead to deadlock;
Pi(){
    do {
        P(chopstick[i]);
        P(chopstick[(i+1)%5]);
        eat;
        V(chopstick[i]);
        V(chopstick[(i+1)%5]);
        think;
    }while (1);
}

// Method 3.2
semaphore mutex = 1;
Pi(){
    do{
        // Ensure one pi can get a pair of chopsticks
        P(mutex);
        P(chopstick[i]);
        P(chopstick[(i+1)%5]);
        V(mutex);

        eat;
        V(chopstick[i]);
        V(chopstick[(i+1)%5]);
        think;
    } while(1);
}

// Smoker Problem
int num = 0;
semaphore offer1 = 0;
semaphore offer2 = 0;
semaphore offer3 = 0;
semaphore finish = 0;
Process P1(){
    while(1){
        num++;
        num = num % 3;
        if(num == 0){
            V(offer1);
        }
        else if(num == 1){
            V(offer2);
        }
        else{
            V(offer3);
        }
    }
}

Process P2(){
    while(1){
        P(offer1);
        take offer 1 and use it;
        V(offer1);
    }
}

Process P3(){
    while(1){
        P(offer2);
        take offer 2 and use it;
        V(offer2);
    }
}


Process P4(){
    while(1){
        P(offer3);
        take offer 3 and use it;
        V(offer3);
    }
}