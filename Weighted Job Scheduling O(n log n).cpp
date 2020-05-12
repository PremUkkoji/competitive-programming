#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Job{
    public:
        int start_time, finish_time, value;
};

bool sortByFinishTime(Job job1, Job job2){
    return job1.finish_time < job2.finish_time;
}

int findNextNode(vector<Job> arr, int index){
    int start = 0, finish = index-1, mid;
    while(start <= finish){
        mid = (start+finish)/2;
        if(arr[mid].finish_time <= arr[index].start_time){
            if(arr[mid+1].finish_time <= arr[index].start_time){
                start = mid + 1;
            }else{
                return mid;
            }
        }else{
            finish = mid - 1;
        }
    }
    return -1;
}

int findMaximumProfit(vector<Job> arr, int n){
    sort(arr.begin(), arr.end(), sortByFinishTime);
    int *table = new int[n];
    table[0] = arr[0].value;
    
    for(int i=1;i<n;i++){
        int include = arr[i].value;
        int nextNodeIndex = findNextNode(arr, i);
        if(nextNodeIndex != -1)
            include += table[nextNodeIndex];
        
        table[i] = max(include, table[n-1]);
    }
    int result = table[n-1];
    delete[] table;
    return result;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;
    Job temp;
    vector<Job> jobs;
    for(int i=0;i<n;i++){
        cin>>temp.start_time;
        cin>>temp.finish_time;
        cin>>temp.value;
        jobs.push_back(temp);
    }
    
    cout<<findMaximumProfit(jobs, jobs.size());
    
    return 0;
}
