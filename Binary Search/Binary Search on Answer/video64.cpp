#include<bits/stdc++.h>
using namespace std;

long double minimiseMaxDistance(vector<int> &arr, int k) {
    //BRUTE FORCE
    int n = arr.size(); //size of array.
    vector<int> howMany(n - 1, 0);

    //Pick and place k gas stations:
    for (int gasStations = 1; gasStations <= k; gasStations++) {
        //Find the maximum section
        //and insert the gas station:
        long double maxSection = -1;
        int maxInd = -1;
        for (int i = 0; i < n - 1; i++) {
            long double diff = arr[i + 1] - arr[i];
            long double sectionLength =
                diff / (long double)(howMany[i] + 1);
            if (sectionLength > maxSection) {
                maxSection = sectionLength;
                maxInd = i;
            }
        }
        //insert the current gas station:
        howMany[maxInd]++;
    }

    //Find the maximum distance i.e. the answer:
    long double maxAns = -1;
    for (int i = 0; i < n - 1; i++) {
        long double diff = arr[i + 1] - arr[i];
        long double sectionLength = diff / (long double)(howMany[i] + 1);
        maxAns = max(maxAns, sectionLength);
    }
    return maxAns;
}

long double MinimiseMaximumDistanceBetweenGasStationApproach1(vector<int>a,int k){
    // USING priority_queue
    //BETTER APPROACH
    int n=a.size();
    priority_queue<pair<long double,int>>pq;
    vector<int>howMany(n-1,0);
    for(int i=0;i<n-1;i++){
        pq.push({a[i+1]-a[i],i});
    }

    for (int gasStation = 0; gasStation < k; gasStation++){
        auto tp=pq.top(); pq.pop();
        int secInd=tp.second;
        howMany[secInd]++;
        long double iniDiff=a[secInd+1]-a[secInd];
        long double newSecLen= (long double) iniDiff/(long double) (howMany[secInd]+1);
        pq.push({newSecLen,secInd});
    }
    return pq.top().first;
    //T.C.-O(nlogn)+O(klogn)
    //S.C.-O(n-1)
}

int numberofGasStationRequired(vector<int>a,long double dist){
    int cnt=0;
    for(int i=1;i<a.size()-1;i++){
        // cnt+=ceil((a[i+1]-a[i])/mid)-1;
        int NumberOfStations=((a[i]-a[i-1])/dist);
        if((a[i]-a[i-1])==(NumberOfStations*dist)){
            NumberOfStations--;
        }
        cnt+=NumberOfStations;
    }
    return cnt;
}

long double MinimiseMaximumDistanceBetweenGasStationApproach2(vector<int>a,int k){
    //USING BINARY SEARCH
    int n=a.size();
    long double low=0;
    long double high=0;
    for(int i=0;i<n-1;i++){
        high=max((long double)(a[i+1]-a[i]),high);
    }

    while(high-low>1e-6){
        long double mid=(low+high)/2.0;
        int cnt=numberofGasStationRequired(a,mid);
        if(cnt>k){
            low=mid;
        }
        else{
            high=mid;
        }
    }   
    return high;

}

int main(){
    // Minimise Maximum Distance Between Gas Station
    // Approach 1 is the most used one and accepted by interviewer
    // vector<int>a={1,13,17,23};
    // int k=5;
    vector<int>a={1,2,3,4,5};
    int k=4;
    cout<<MinimiseMaximumDistanceBetweenGasStationApproach2(a,k);
    return 0;
}