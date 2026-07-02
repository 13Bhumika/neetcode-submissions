class Solution {
public:

    char isLower(char ch){
        if(ch>='a' && ch<='z') return ch;
        else if(ch>='A' && ch<='Z') return ch+32;
        else return ch;
    }

    bool alphaNumeric(char ch){
        if(ch>='a' && ch<='z') return true;
        if(ch>='A' && ch<='Z') return true;
        if(ch>='0' && ch<='9') return true;
        else return false;
    }

    string isCorrect(string s){
        string result = "";
        for(int i=0; i<s.size(); i++){
            if(!alphaNumeric(s[i])) continue;
            result += isLower(s[i]);
        }
        return result;
    }

    bool isPalindrome(string s) {
        s = isCorrect(s);
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++,j--;
        }
        return true;
    }
};
