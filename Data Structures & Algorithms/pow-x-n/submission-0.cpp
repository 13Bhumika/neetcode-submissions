class Solution {
private:
    double answer(double x, long long n){
        if(n==0) return 1;
              
        if(n%2==1) return x* myPow(x,n-1);
        return myPow(x*x, n/2);
    }
public:
    double myPow(double x, int n) {
        bool isNegative= false;
        long long power=n;
        double result;
        
        if(n<0){
            isNegative= true;
            power*=(-1);
        }
        result=answer(x, power);
        if(isNegative) return 1/result;
        else return result;
    }
};