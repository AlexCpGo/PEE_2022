#include <iostream>
using namespace std;
typedef struct PolyNode *polynomial;
struct PolyNode{
    int expon;
    double coef;
    polynomial NextTerm;
};

void Attach(double c, int e, polynomial *rear){
    polynomial NewNode;
    NewNode = new PolyNode;
    
    NewNode->coef = c;
    NewNode->expon = e;
    NewNode->NextTerm = NULL;
    (*rear)->NextTerm = NewNode;
    *rear = NewNode;
}

polynomial CreatePoly(int k){
    double c;
    int e;
    polynomial head, rear, temp;
    head = new PolyNode;
    head->NextTerm = NULL;
    
    rear = head;
    int i = k;
    while (i--){
        cin >> e >> c;
        Attach(c,e,&rear);
    }
    // Free the head pointer
    temp = head;
    head = head->NextTerm;
    delete(temp);
    return head;
}

void PrintPoly(polynomial p){
    /* Print the number of terms of the polynomial */
    int k = 0;
    polynomial t = new PolyNode;
    t = p;
    while (t){
        k++;
        t = t->NextTerm;
    }
    cout << k;
    if (k!=0){
    	count << " ";
	}
    delete(t);
    
    int flag = 0;
    /*if (p==NULL){
        cout << "0 0 0.0";
        return;
    }*/
    
    /* Print the polynomial*/
    while(p){
        if (!flag){
            flag = 1;
        }
        else {
            cout << " ";
        }
        cout << p->expon << " ";
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(1);
        cout << p->coef;
        p = p->NextTerm;
    }
    cout << "\n";
}

polynomial AddPoly(polynomial p1, polynomial p2){
    polynomial t1,t2,head,rear,temp;
    t1 = p1;
    t2 = p2;
    head = new PolyNode;
    head->NextTerm = NULL;
    rear = head;
    while (t1 && t2){
        if (t1->expon == t2->expon){
            if (t1->coef + t2->coef != 0){
                Attach(t1->coef + t2->coef, t1->expon, &rear);
            }
            t1 = t1->NextTerm;
            t2 = t2->NextTerm;
        }
        else if (t1->expon > t2->expon){
            if (t1->coef != 0){
                Attach(t1->coef, t1->expon, &rear);
                t1 = t1->NextTerm;
            }
        }
        else if (t1->expon < t2->expon){
            if (t2->coef != 0){
                Attach(t2->coef, t2->expon, &rear);
                t2 = t2->NextTerm;
            }
        }
    }
    while (t1){
        Attach(t1->coef, t1->expon, &rear);
        t1 = t1->NextTerm;
    }

    while (t2){
        Attach(t2->coef, t2->expon, &rear);
        t2 = t2->NextTerm;
    }
    temp = head;
    head = head->NextTerm;
    delete(temp);
    
    return head;
}


int main(){
    int k1,k2;
    // k1 is the number of nonzero terms of the first polynomial
    cin >> k1;
    polynomial p1 = CreatePoly(k1);
    // k2 is the number of nonzero terms of the second polynomial
    cin >> k2;
    polynomial p2 = CreatePoly(k2);
    polynomial Psum = AddPoly(p1, p2);
    PrintPoly(Psum);
    /*
    cout << k1 << " ";
    PrintPoly(p1);
    cout << k2 << " ";
    PrintPoly(p2);
    */
}
