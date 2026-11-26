class Solution {
public:
    bool canAliceWin(int n) {
        int turn=1;
        int curr=10;
        while(n>=curr){
            n-=curr;
            curr--;
            turn =1-turn;
        }
        if(turn==1) return false;
        return true;
    }
};