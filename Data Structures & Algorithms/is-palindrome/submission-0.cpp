class Solution {
private:
    char toLower(char ch){
        if(ch >= 'a' && ch <= 'z') return ch;
        else if(ch >= 'A' && ch <= 'Z') return ch + 32;
        else return ch;
    }

    bool alphaNumeric(char ch){
        if(ch >= 'a' && ch <= 'z') return true;
        if(ch >= 'A' && ch <= 'Z') return true;
        if(ch >= '0' && ch <= '9') return true;
        else return false;
    }

    string correctString(string s){
        string result = "";

        for(int i = 0; i < s.size(); i++){
            if(!alphaNumeric(s[i])) continue;
            result += toLower(s[i]);
        }
        return result;
    }

public:
    bool isPalindrome(string s) {
        s = correctString(s);

        int i = 0;
        int j = s.size() - 1;

        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
