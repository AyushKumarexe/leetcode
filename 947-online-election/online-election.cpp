class TopVotedCandidate {
    vector<int>arr;
    vector<int>times;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
    unordered_map<int,int>mp; 
    this->times = times; 
     int max = 1;
     int lead =  persons[0];
     mp[persons[0]]++;
     arr.push_back(persons[0]);
     for(int i =1;i<times.size();i++)
     {
     int curr = ++mp[persons[i]];
     if(curr>=max)
     {
     max = curr;
     lead = persons[i];
     }  
     arr.push_back(lead); 
     }
    }
    int q(int t) {
      int i = upper_bound(times.begin(), times.end(), t)
                - times.begin() - 1;

        return arr[i];
    
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */