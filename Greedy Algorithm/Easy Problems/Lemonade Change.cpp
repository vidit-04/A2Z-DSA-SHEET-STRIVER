#include<bits/stdc++.h>
using namespace std;

bool LemonadeChange(vector<int>a){
    int five=0,ten=0;
    for(int i=0;i<a.size();i++){
        if(a[i]==5) five++;
        else if(a[i]==10){
            if(five){
                five--;
                ten++;
            }
            else return false;
        }
        else if(a[i]==20){
            if(ten && five){
                ten--;
                five--;
            }
            else if(five>=3){
                five-=3;
            }
            else return false;
        }
    }
    return true;    
}

int main(){
    vector<int> a={5,5,5,10,20};
    cout<<LemonadeChange(a);

    //About question -Lemonade Change
    //At a lemonade stand, each lemonade costs $5.
    //Customers are standing in a queue to buy from you, and order one at a time (in the order specified by bills).
    //Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill.
    //You must provide the correct change to each customer, so that the net transaction is that the customer pays $5.
    //Note that you don't have any change in hand at first.
    //Return true if and only if you can provide every customer with correct change.
    //Example 1:
    //Input: [5,5,5,10,20]
    //Output: true
    //Explanation:
    //From the first 3 customers, we collect three $5 bills in order.
    //From the fourth customer, we collect a $10 bill and give back a $5.
    //From the fifth customer, we give a $10 bill and a $5 bill.
    //Since all customers got correct change, we output true.
    //Example 2:
    //Input: [5,5,10]
    //Output: true
        
    return 0;
}