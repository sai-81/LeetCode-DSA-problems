class Solution {
public:
    bool checkString(string s) {
        bool b_check=false;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='b'){
                b_check=true;
                continue;
            }
           if(s[i]=='a'&&b_check) return false;
        }
        return true;
    }
};