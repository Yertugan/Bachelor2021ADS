#include <bits/stdc++.h> 

using namespace std;

 int maxProduct(vector<int>& nums) {
       priority_queue<int>q;
        for(auto x:nums)
        {
            q.push(x);
        }
        int p1=q.top();
        q.pop();
        int p2=q.top();
        q.pop();
        
        p1=p1-1;
        p2=p2-1;
        return p1*p2; 
    }

     vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq;
        vector<string> ans(score.size());
        int count = 1;
        for(int i = 0;i <score.size(); i++)
            pq.push(make_pair(score[i], i));
        
        while(pq.empty() ==false)
        {
            if(count == 1)
            {
                ans[pq.top().second] = "Gold Medal";
            }
            
            else if(count == 2)
            {
                ans[pq.top().second] = "Silver Medal";
            }
            else if(count == 3)
            {
                ans[pq.top().second] = "Bronze Medal";
            }
            
            else 
            {
                ans[pq.top().second] = to_string(count);
            }
            
            count++;
            pq.pop();
        }
        
        return ans;
    }

    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto x:stones){
            pq.push(x);
        }
        while(pq.size() !=1){
            int st1 = pq.top();
            pq.pop();
            int st2 = pq.top();
            pq.pop();
            pq.push(st1 - st2);
        }
        return pq.top();
    }
int main(){
	vector<int> v = {2,7,4,1,8,1};
	cout << maxProduct(v);

    cout << endl << lastStoneWeight(v);
}