#include<bits/stdc++.h>
using namespace std;

bool ls(vector<int>a, int x){
    for(int i=0;i<a.size();i++){
        if(a[i]==x){
            return true;
        }
    }
    return false;
}

int longestConsecutiveSequence(vector<int>a){
    //Consecutive Sequence of numbers like : 1 2 3 4 
    // BRUTE FORCE
    int count=1;
    int maxCount=1;
    for(int i=0;i<a.size();i++){
        int x=a[i];
        count=1;
        while (ls(a,x+1)==true)
        {
            count++;
            x++;
        }        
        maxCount=max(maxCount,count);
    }
    return maxCount;
    //T.C. - O(n^2)
    // S.C. - O(1)
}

int longestConsecutiveSequenceApproach2(vector<int>a){
    //Consecutive Sequence of numbers like : 1 2 3 4 
    // BETTER SOLUTUION
    //Step 1 : Sorting
    if(a.size()==0) return 0;
    sort(a.begin(),a.end());

    int lastSmaller=INT_MIN;
    int count=0;
    int longest=1;

    //Step 2 : Counting ++ when the last element is just 1 less than current element. If the current element is same then we don't need to do anything. But if the last element is not 1 less then we neeed to initialize current item and counting restart to 1. 
   for(int i=0;i<a.size();i++) {
        if(a[i]-1==lastSmaller){
            count++;
            lastSmaller=a[i];
        }
        else if(a[i]!=lastSmaller){
            count=1;
            lastSmaller=a[i];
        }
        // else if(a[i]==lastSmaller){}
        //Step 3 :: Out of all calculate the max sequence length
        longest=max(longest,count);
    }
    return longest;
}

int longestConsecutiveSequenceApproach3(vector<int>a){
    //Consecutive Sequence of numbers like : 1 2 3 4 
    int n=a.size();
    if(n==0) return 0;
    int longest=1;
    unordered_set<int>s;
    //STEP 1 : Put all the elements in unordered set. So that we can find it consecutive membere in O(1) T.C. WE can use set also but it's sorted property is not need otherwise it will be just same as Better Solution given above.
    for (int i = 0; i < a.size(); i++)
    {
        s.insert(a[i]);
    }
    
    //Count for every consecutive sequence so that at last we can have maximum one with us.
    int count=0;

    //STEP 2 : For every element in set check if the previous element is not present in the set.If it is present we do nothing but  If it is not present then it is the starting element of the sequence. So we will check how many elements are there in the sequence and update the count variable. 

    //It's just like first finding the initial element of the sequence then checking whether it's next element is present or not.
    //Count and longest is always atleast 1 because atleast 1 element is consecutiveto itself
    for (auto it:s){
        if(s.find(it-1)==s.end()){
            count=1;
            while (s.find(it+1)!=s.end()){
                count++;
                it++;
            }
        }
        longest=max(longest,count);
    }
    return longest;
    //T.C. - O(n)+O(2n)
    // S.C. - O(n)
}
//APPROACH 2 and 3 BOTH ARE GOOD AT THERE OWN USE

int main(){
    // vector<int>a ={102,4,100,1,101,3,2,1,1};
    // cout<<longestConsecutiveSequence(a);

    vector<int>b={100,102,100,101,101,4,3,2,3,2,1,1,1,2};
    cout<<longestConsecutiveSequenceApproach3(b);
    return 0;
}