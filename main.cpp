#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    struct compare{
        bool operator()(pair<int,int> a, pair<int,int> b){
            if(a.first==b.first){
                return a.second > b.second;
            }
            return a.first > b.first;
        }
    };

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
        for(int i=0; i<nums.size(); i++){
            pq.push({nums[i], i}); //valor con el indice
        }

        while(k--){ //de un plumazo modifica todo el queue
            auto y=pq.top();
            pq.pop();
            pq.push({y.first*multiplier, y.second});
        }

        while(!pq.empty()){
            auto to=pq.top();
            pq.pop();
            nums[to.second]=to.first; //usa queue para modificar nums
        }
        return nums;
    }
};

int main(){
    return 0;
}