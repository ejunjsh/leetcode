class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        // define a string to int map to save the frequency of each string
        unordered_map<string, int> mp;
        for (const auto& str : strs)
            mp[str]++;
        
        // define a vector of map element pair and sort it in descending order of string size
        vector<pair<string, int>> vec;
        for (const auto& m : mp)
            vec.push_back(m);
        sort(vec.begin(), vec.end(), cmp);
        
        // For each string in the sorted vector, if all the other string coming before it is
        // NOT super string of it then we use its size as LUS. If each pair of string have 
        // sub string relation then the longest uncommon subsequence doesn't exist
        for (int i = 0; i < vec.size(); i++) {
            if (1 == vec[i].second) {
                int j = 0;
                for (; j < i; j++)
                    if (isSubStringOf(vec[i].first, vec[j].first))
                        break;
                if (j == i)
                    return vec[i].first.size();        
            }
        }
        
        return -1;
    }
    
    //desending order of string size
    static bool cmp(pair<string,int> &a, pair<string,int> &b) {
        return a.first.size() > b.first.size();
    }

    // Return true for s1 = abc, s2 = aebece
    bool isSubStringOf(string &s1, string &s2){
        int i = 0, j = 0;
        while (i < s1.size()) {
            while (j < s2.size() && s1[i] != s2[j])
                j++;
            if (j == s2.size())
                return false;
            i++;
            j++;
        }
        return true;
    }
};