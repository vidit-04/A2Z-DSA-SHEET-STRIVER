#include<bits/stdc++.h>
using namespace std;

struct Data{
    int start;
    int end;
    int pos;    
};

bool cmp(Data a,Data b){
    return a.end<b.end;
}

vector<int> NMeetinginOneRoom(vector<int>start,vector<int>end){
    vector<Data> a(start.size());
    for(int i=0;i<start.size();i++){
        a[i].start=start[i];
        a[i].end=end[i];
        a[i].pos=i+1;
    }
    sort(a.begin(),a.end(),cmp);
    int count=1;
    int freeTime=a[0].end;
    vector<int>ans;
    ans.push_back(a[0].pos);
    for(int i=1;i<a.size();i++){
        if(a[i].start>freeTime){
            count++;
            freeTime=a[i].end;
            ans.push_back(a[i].pos);
        }
    }
    return ans;
    //T.C.-O(nlogn+2n)
    //S.C.-O(3*n+n)
}

int main(){
    vector<int>start={0,3,1,5,5,8};
    vector<int>end={5,4,2,9,7,9};

    vector<int>ans=NMeetinginOneRoom(start,end);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}

//TUF
// #include <bits/stdc++.h>
// using namespace std;

// struct meeting {
//    int start;
//    int end;
//    int pos;
// };

// class Solution {
//    public:
//       bool static comparator(struct meeting m1, meeting m2) {
//          if (m1.end < m2.end) return true;
//          else if (m1.end > m2.end) return false;
//          else if (m1.pos < m2.pos) return true;
//          return false;
//       }
//    void maxMeetings(int s[], int e[], int n) {
//       struct meeting meet[n];
//       for (int i = 0; i < n; i++) {
//          meet[i].start = s[i], meet[i].end = e[i], meet[i].pos = i + 1;
//       }

//       sort(meet, meet + n, comparator);

//       vector < int > answer;

//       int limit = meet[0].end;
//       answer.push_back(meet[0].pos);

//       for (int i = 1; i < n; i++) {
//          if (meet[i].start > limit) {
//             limit = meet[i].end;
//             answer.push_back(meet[i].pos);
//          }
//       }
//       cout<<"The order in which the meetings will be performed is "<<endl;
//       for (int i = 0; i < answer.size(); i++) {
//          cout << answer[i] << " ";
//       }

//    }

// };
// int main() {
//    Solution obj;
//    int n = 6;
//    int start[] = {1,3,0,5,8,5};
//    int end[] = {2,4,5,7,9,9};
//    obj.maxMeetings(start, end, n);
//    return 0;
// }
