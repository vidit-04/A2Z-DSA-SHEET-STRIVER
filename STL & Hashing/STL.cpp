#include<bits/stdc++.h>
using namespace std;

void explainPairs(){
    pair<int,int> p={1,3};

    cout<<p.first<<" "<<p.second;

    pair<int,pair<int,int>> pe={1,{2,3}};
    cout<<pe.first<<" "<<pe.second.first<<" "<<pe.second.second;  //Output:1 2 3

    pair<int,int> arr[]={{1,2},{3,4},{5,6}};   //Array of Pairs

    cout<<arr[1].second;   //Output: 4
}

void explainVector(){
    vector<int>v;
    v.push_back(1);
    v.emplace_back(2);  //faster than push_back

    vector<pair<int,int>>v1;
    v1.push_back({1,2});
    v1.emplace_back(3,4);  //We don't need to create {}

    vector<int>v2(5,200); // Output:{200,200,200,200,200}
    vector<int>v3(5);  //Output: All values are garbage value

    vector<int>v4(v2);  //Copies v2 to v4

    vector<int>::iterator it=v.begin();  //Points to the first element's address of the vector
    it++;  //now it points to second element of the array
    cout<<*(it)<<" ";

    it+=2; //it now points to 4th element of the array
    cout<<*(it)<<" ";

    vector<int>::iterator it2=v.end();  //Points to the last element's address of the vector +1 address. That's why whenever we try to use this it creates problem. Solution is to use it2--; by using this we can comeback to last address of the vector

    // vector<int>::iterator it3=v.rbegin();
    // vector<int>::iterator it4=v.rend();
    //here the it++ and it-- works in reverse order
    
    cout<<v[0]<<" "<<v.at(0);
    cout<<v.back()<<" "<<v.front();
    cout<<v.size()<<" "<<v.capacity();

    for(vector<int>::iterator it5=v.begin();it5!=v.end();it++){
        cout<<*(it5)<<" ";
    }
    for(auto it5=v.begin();it5!=v.end();it++){
        cout<<*(it5)<<" ";
    }
    for(auto it:v){
        cout<<it<<" ";
    }

    //{10,12,30,40}
    v.erase(v.begin()+1);
    //{10,12,30,40}
    v.erase(v.begin()+1,v.begin()+3);  //v.erase(str,end); it is [ )

    vector<int>v5(2,100);
    v5.insert(v5.begin()+1,200);
    //Output: {100,200,100}
    
    v5.insert(v5.begin()+2,2,600);//Insert 2 values of 600 at location 3
    //Output: {100,200,600,600,100}

    v5.insert(v5.begin(),v.begin(),v.end());// insert vector to another vector

    v.pop_back(); //Removes last element
    v5.swap(v);

    v.clear(); //returns empty array
    
    cout<<v.empty()<<" ";

}

void explainList(){
    //begin, end,rbegi,rend,clear, insert,size,swap are same as vector

    list<int>l; // Declare a list of integers named 'l'
    l.push_back(1); // Add '1' to the end of the list
    l.push_back(2); // Add '2' to the end of the list
    l.push_back(3); // Add '3' to the end of the list
    l.push_front(4); // Add '4' to the beginning of the list
    l.emplace_back(5); // Construct and add '5' to the end of the list
    l.emplace_front(6); // Construct and add '6' to the beginning of the list

    list<int>::iterator it=l.begin(); // Declare an iterator 'it' and set it to the beginning of the list
    it++; // Move the iterator to the next element
    l.insert(it,100); // Insert '100' at the position pointed by the iterator
    //Output: {6,100,4,1,2,3,5}
}

void explainDeque(){
    //begin, end,rbegi,rend,clear, insert,size,swap are same as vector
    deque<int>dq; // Declare a deque of integers named 'dq'
    dq.push_back(1); // Add '1' to the end of the deque
    dq.push_front(2); // Add '2' to the beginning of the deque
    dq.emplace_back(3); // Construct and add '3' to the end of the deque
    dq.emplace_front(4); // Construct and add '4' to the beginning of the deque

    cout<<dq[0]<<" "<<dq.at(0); // Output the first element of the deque using two different methods
    cout<<dq.back()<<" "<<dq.front(); // Output the last and first elements of the deque
    cout<<dq.size(); // Output the number of elements in the deque

    dq.pop_back(); // Remove the last element of the deque
    dq.pop_front(); // Remove the first element of the deque

    dq.erase(dq.begin()+1); // Remove the second element of the deque
    dq.erase(dq.begin()+1,dq.begin()+3); // Remove the second and third elements of the deque

    dq.insert(dq.begin()+1,200); // Insert '200' at the second position of the deque
    dq.insert(dq.begin()+2,2,600); // Insert two '600's at the third position of the deque
    dq.insert(dq.begin(),dq.begin(),dq.end()); // Insert a copy of the entire deque at the beginning of the deque

    dq.clear(); // Remove all elements from the deque
    cout<<dq.empty()<<" "; // Output whether the deque is empty (1) or not (0)
}

void explainStack(){
    // LIFO (Last In First Out) principle is followed in stack
    stack<int>s; // Declare a stack of integers named 's'
    s.push(1); // Push '1' onto the stack
    s.push(2); // Push '2' onto the stack
    s.push(3); // Push '3' onto the stack
    s.push(3); // Push '3' onto the stack
    s.emplace(5); // Construct and push '5' onto the stack

    cout<<s.top()<<" "; // Output the top element of the stack. Expected output: 5
    s.pop(); // Remove the top element from the stack
    cout<<s.top()<<" "; // Output the top element of the stack. Expected output: 3
    cout<<s.size()<<" "; // Output the number of elements in the stack. Expected output: 4
    cout<<s.empty()<<" "; // Output whether the stack is empty (1) or not (0). Expected output: 0


    // All work is done in T.C. O(1) i.e. constant
}

void explainQueue(){
    queue<int>q; // Declare a queue of integers named 'q'
    q.push(1); // Add '1' to the end of the queue
    q.push(2); // Add '2' to the end of the queue
    q.push(3); // Add '3' to the end of the queue
    q.emplace(4); // Construct and add '4' to the end of the queue

    cout<<q.front()<<" "; // Output the first element of the queue. Expected output: 1
    cout<<q.back()<<" "; // Output the last element of the queue. Expected output: 4
    cout<<q.size()<<" "; // Output the number of elements in the queue. Expected output: 4
    cout<<q.empty()<<" "; // Output whether the queue is empty (1) or not (0). Expected output: 0

    q.pop(); // Remove the first element from the queue
    cout<<q.front()<<" "; // Output the first element of the queue. Expected output: 2
}

void expalinPQ(){
    //Not a linear way to store. It actually makes a tree and stores data in tree form
    //Also known as MAX HEAP-> stores in descending order
    priority_queue<int>pq; // Declare a priority queue of integers named 'pq'
    pq.push(1); // Add '1' to the priority queue
    pq.push(2); // Add '2' to the priority queue
    pq.push(3); // Add '3' to the priority queue
    pq.emplace(4); // Construct and add '4' to the priority queue

    cout<<pq.top()<<" "; // Output the top element of the priority queue. Expected output: 4
    cout<<pq.size()<<" "; // Output the number of elements in the priority queue. Expected output: 4
    cout<<pq.empty()<<" "; // Output whether the priority queue is empty (1) or not (0). Expected output: 0

    pq.pop(); // Remove the top element from the priority queue
    cout<<pq.top()<<" "; // Output the top element of the priority queue. Expected output: 3

    //Also known as MIN HEAP->stores in ascending order
    priority_queue<int,vector<int>,greater<int>>pq1;
    pq1.push(5);
    pq1.push(2);
    pq1.push(8);
    pq1.emplace(10);
    cout<<pq1.top();
    
    // T.C.
    // PUSH,POP -> logn
    // top->O(1)
}

void explainSet(){
    //Stores in SORTED AND UNIQue manner.
    set < int > s;
  for (int i = 1; i <= 10; i++) {
    s.insert(i);
  }

  cout << "Elements present in the set: ";
  for (auto it = s.begin(); it != s.end(); it++) {
    cout << * it << " ";
  }
  cout << endl;
  int n = 2;
  if (s.find(n) != s.end())
    cout << n << " is present in set" << endl;
//s.find(2) returns the address of the element in set otherwise it gives s.end() as output
   int cnt=s.count(1) ; //Returns occurences of 1 in s

  s.erase(s.begin());
  s.erase(5); //takes logarthimtic time
  cout << "Elements after deleting the first element: ";
  for (auto it = s.begin(); it != s.end(); it++) {
    cout << * it << " ";
  }
  cout << endl;

  cout << "The size of the set is: " << s.size() << endl;

  if (s.empty() == false)
    cout << "The set is not empty " << endl;
  else
    cout << "The set is empty" << endl;
  s.clear();
  cout << "Size of the set after clearing all the elements: " << s.size();

//   T.C. - Everything takes O(log n) time
}

void explainMultiSet(){
    //Stores in sorted manner but allows duplicates.
    multiset < int > ms;
    for (int i = 1; i <= 10; i++) {
        ms.insert(i);
    }   
    ms.insert(5);
    cout << "Elements present in the multiset: ";
    for (auto it = ms.begin(); it != ms.end(); it++) {
        cout << * it << " ";
    }
    cout << endl;
    int n = 2;
    if (ms.find(n) != ms.end())
        cout << n << " is present in multiset" << endl;
    int cnt = ms.count(1); //Returns occurences of 1 in s       
    ms.erase(ms.begin());
    ms.erase(5); //takes logarthimtic time
    cout << "Elements after deleting the first element: ";
}

void explainUSet(){
    //It stores unique values
    // All operations are in O(1). Lowerbound and upper_bound funcitons do not work here
    unordered_set < int > us;
    for (int i = 1; i <= 10; i++) {
        us.insert(i);
    }
    us.insert(5);
    cout << "Elements present in the unordered set: ";
    for (auto it = us.begin(); it != us.end(); it++) {
        cout << * it << " ";
    }
    cout << endl;
    int n = 2;
    if (us.find(n) != us.end())
        cout << n << " is present in unordered set" << endl;
    int cnt = us.count(1); //Returns occurences of 1 in s
    us.erase(us.begin());
    us.erase(5); //takes O(1) time
    cout << "Elements after deleting the first element: ";
    for (auto it = us.begin(); it != us.end(); it++) {
        cout << * it << " ";
    }
    cout << endl;
    cout << "The size of the unordered set is: " << us.size() << endl;
    if (us.empty() == false)
        cout << "The unordered set is not empty " << endl;
    else
        cout << "The unordered set is empty" << endl;
    us.clear();
    cout << "Size of the unordered set after clearing all the elements: " << us.size();
    
}
void explainMap(){
    //Map stores unique keys in sorted order
    map<int,int>mpp;
    // map<int,pair<int,int>>mpp;
    // map<pair<int,int>,int>mpp;

    mpp[1]=100;
    // mpp.emplace({3,1});
    mpp.insert({3,1});
    // mpp[{2,3}]=20;

    for(auto it:mpp){
        cout<<it.first<<" "<<it.second;
    }
    cout<<mpp[1];
    cout<<mpp.at(1);

    auto it=mpp.find(3);  //If welement not found then it returns mpp.end()
    // cout<<*(it).second;

    auto it= mpp.upper_bound(2);
    auto it= mpp.lower_bound(2);
    // All functions like erase,swap,size,empty, are same as above

}

bool comp(pair<int,int>p1,pair<int,int>p2){
    if(p1.second<p2.second) return true;
    if(p1.second>p2.second) return false;

    //if they are same

    if(p1.first>p2.first) return true;
    return false;    
}

 void sortingAlgos(int a, int n){
    sort(a,a+n);
    // sort(v.begin(),v.end());
    sort(a+2,a+4);
    // sort(a,a+n,greater<int>);
    // sort(v.begin(),v.end(),greater<int>);

    pair<int,int>a[]={{1,2},{2,1},{4,1}};
    // Sort it according to second element and if second element is same then sort it according to first element in decreasing order

    sort(a,a+n,comp);


    int n=7;
    int cnt=__builtin_popcount(n); //Tells numbers of 1's in binary of n. For ex-7 cnt=3;

    long long num=123456789987;
    int sum=__builtin_popcountll(num); //Tells numbers of 1's in binary of num. For ex-7 cnt=3;
    string s="123";
    sort(s.begin(),s.end());

    do{
        cout<<s<<endl;
    }while(next_permutation(s.begin(),s.end()));
    //It is important to sort in order to get all permutation of that string

    int maxi=max_element(a,a+n);
    int mini=min_element(a,a+n);

 }  

 void algos(int arr[], int n){
    bool isElement=binary_search(arr,arr+n,3);
    //Returns true if element is present in array otherwise false

    int ind=lower_bound(arr,arr+n,7) - arr;
    //Returns the index of the element which is greater than or equal to 7
    //Useful in  finding the first occurence of an element

    int ind=upper_bound(arr,arr+n,7) - arr;
    //Returns the index of the element which is greater than 7
    //Useful in  finding the last occurence of an element

    //T.C. of lower and upper_bound is logn
        
 }

int main(){
    // cout<<"Hlo";
    explainPairs();
    explainVector();
    explainList();
    explainDeque();
    explainStack();
    explainQueue();
    expalinPQ();
    explainSet();
    explainMultiSet();
    explainUSet();
    explainMap();
    sortingAlgos(2,3);
    algos({},5);
    return 0;
}