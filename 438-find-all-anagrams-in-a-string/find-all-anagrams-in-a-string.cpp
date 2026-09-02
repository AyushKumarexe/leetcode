class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) return {};
        vector<int> arr1(26, 0);
        vector<int> arr2(26, 0);
        int num = 0;
        vector<int> ans;
        for (int i = 0; i < p.size(); i++) {
            arr1[p[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (arr1[i] == arr2[i])
                num++;
        }
        for (int i = 0; i < p.size(); i++) {
               if (arr1[s[i] - 'a'] == arr2[s[i] - 'a'])
        num--;
            arr2[s[i] - 'a']++;
            if (arr1[s[i] - 'a'] == arr2[s[i] - 'a'])
                num++;
        }
        if (num == 26)
            ans.push_back(0);
        int j = 0;
        for (int i = p.size(); i < s.size(); i++) {
            if(arr1[s[i] - 'a'] == arr2[s[i] - 'a'])num--;
            if(arr1[s[j] - 'a'] == arr2[s[j] - 'a'])num--;
            arr2[s[i] - 'a']++;
            arr2[s[j] - 'a']--;
        if(arr1[s[i] - 'a'] == arr2[s[i] - 'a'])num++;
         if(arr1[s[j] - 'a'] == arr2[s[j] - 'a'])num++;
            j++;
            if (num == 26)
                ans.push_back(j);
        }
        return ans;
    }
};