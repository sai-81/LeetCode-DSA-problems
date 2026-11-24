class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++){
            long long p=1,g=0,l=1;
            for(int j=i;j<n;j++){
                p*=(1LL*nums[j]);
                g=__gcd(g,1LL*nums[j]);
                l=lcm(l,1LL*nums[j]);
                if(p>g*l) break;
                if(p==g*l)
                  res=max(res,j-i+1);
            }
        }
        return res;
    }
};