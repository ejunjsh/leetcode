class Solution {
public:
    string intToRoman(int num) {
        string temp;
        unordered_map<int,string> map;
        map[1] = "I";
        map[4] = "IV";
        map[5] = "V";
        map[9] = "IX";
        map[10] = "X";
        map[40] = "XL";
        map[50] = "L";
        map[90] = "XC";
        map[100] = "C";
        map[400] ="CD";
        map[500] = "D";
        map[900] = "CM";
        map[1000] = "M";
        vector<int> key;
        for(auto s : map)
        {
            key.push_back(s.first);
        }
        sort(key.begin(),key.end(),[](int a,int b){return a>b;});
        for(int i =0;i<key.size();i++)
        {
            int times = num/key[i];
            for(int j = 0;j<times;j++)
            {
                temp+=map[key[i]];
            }
            num-=(times*key[i]);
        }
        return temp;
    }
};