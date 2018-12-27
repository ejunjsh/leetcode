class Solution{
    public:
        string multiply(string num1,string num2){
            int m=num1.size(),n=num2.size();
            string result(m+n,'0');
            for(int i=m-1;i>=0;i--){
                for(int j=n-1;j>=0;j--){
                    int sum=(num1[i]-'0')*(num2[j]-'0')+(result[i+j+1]-'0');
                    result[i+j+1]=sum%10+'0';
                    result[i+j]+=sum/10;
                }
            }

            for(int i=0;i<m+n;i++){
                if(result[i]!='0'){
                    return result.substr(i);
                }
            }

            return "0";
        }
};