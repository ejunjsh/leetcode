class Solution {
public:
    int maxProduct(vector<string>& words) {
        if (words.size() == 0)
            return 0;
        int len = words.size();
        vector<int> value(len,0);
        for (int i = 0; i < len; i++) {
            string tmp = words[i];
            value[i] = 0;
            for (int j = 0; j < tmp.size(); j++) {
                value[i] |= 1 << (tmp[j] - 'a');
            }
        }
        int maxProduct = 0;
        for (int i = 0; i < len; i++)
            for (int j = i + 1; j < len; j++) {
                if ((value[i] & value[j]) == 0){
                     int product=words[i].size() * words[j].size();
                    maxProduct = max(maxProduct,product);
                }
                   
            }
        return maxProduct;
        }
};