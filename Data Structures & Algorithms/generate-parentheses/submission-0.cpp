class Solution {
private:
    void generateParentheses(vector<string>& result, int n, int opening_count, int closing_count,
    string s) {
        if (opening_count == n && closing_count == n) {
            result.push_back(s);
            return;
        }
        if (opening_count < n) generateParentheses(result, n, opening_count + 1, closing_count,
        s + "(");
        if (closing_count < opening_count) generateParentheses(result, n, opening_count,
        closing_count + 1, s + ")");
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        int opening_count=0, closing_count=0;
        generateParentheses(result,n, opening_count, closing_count, "");
        return result;
    }
};