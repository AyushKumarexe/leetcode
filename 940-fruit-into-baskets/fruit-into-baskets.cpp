class Solution {
public:
 int totalFruit(vector<int>& fruits) {
    unordered_map<int,int> mp;
    int i = 0, ans = 0;
    for (int j = 0; j < fruits.size(); j++) {
        mp[fruits[j]]++;                // add exactly ONE element
        while (mp.size() > 2) {         // shrink if needed
            mp[fruits[i]]--;
            if (mp[fruits[i]] == 0) mp.erase(fruits[i]);
            i++;
        }
        ans = max(ans, j - i + 1);      // check ans after EVERY single addition
    }
    return ans;
}
};