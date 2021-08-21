#include <iostream>
#include <math.h>
using namespace::std;
int main(){
    int a,b,sum,i;
    int digit[7];
    cin>>a;
    cin>>b;
    sum = a + b;
    if (sum<0){
        cout << "-";
    }
    
    /* Store the digits in an array */
    int abs_sum = abs(sum);
    i = 0; // i implies the number of dight of the sum
    while (abs_sum > 0){
        digit[i] = abs_sum % 10; 
        abs_sum = abs_sum / 10;
        //cout << "The stored digit is " << digit[i] << endl;
		i = i + 1;
        
    }
    
    /* Print out digits directly if the number of digit <= 3 */
    if (i<=3){
        int k = i - 1;
        for (; k >= 0; k--){
            cout << digit[k];
        }
    }
    
    /* Print out 3 digits for a loop if the number of digit > 3 */
    else if (i>3){
        int head = i % 3;
        // The situation when head contains 3 digits
        if (head == 0){
        	head = 3;
		} 
        int j = i - 1;
        //cout << "head is" << head << endl;
        for (; head>0; head--){
            cout << digit[j];
            j--;
        }
        
        while (j > 0){
            cout << ","; 
            for (int n = 0; n < 3; n++){
                cout << digit[j];
                j = j - 1;
            }
           
        }
    }
}   
