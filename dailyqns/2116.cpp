class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if(n % 2 != 0)return false;
        for(int i = 0;i < n;i++) {
            if(locked[i] == '0')s[i] = '*';
        }
        int max = 0,min = 0;
        for(int i = 0;i < n;i++){
            if(s[i] == '('){
                max++,min++;
            }
            else if(s[i] == ')')max--,min--;
            else{
                max++,min--;
            }
            if(max < 0)return false;
            if(min < 0)min = 1;
        }
        if(max >= 0 && min <= 0)return true;
        return false;



    }
};