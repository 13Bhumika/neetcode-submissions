class Solution {
private:
    char isLower(char ch){
        if(ch>='A' && ch<='Z') return ch+32;
        if(ch>='a' && ch<='z') return ch;
    }

    bool isAlphanumeric(char ch){        
        if(ch>='A' && ch<='Z') return true;
        if(ch>='a' && ch<='z') return true;
        if(ch>='0' && ch<='9') return true;
        return false;
    }
    string isValid(string s){
        string correct= "";
        for(int i=0; i<s.size(); i++){
            if(!isAlphanumeric(s[i])) continue;
            correct+= isLower(s[i]);
        }
        return correct;
    }
public:
    bool isPalindrome(string s) {
        s= isValid(s);

        int i=0;
        int j=s.size()-1;

        while(i<j){
            if(s[i]!= s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
