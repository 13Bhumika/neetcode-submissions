class Car{
public:
    int speed;
    int position;
    double time;

    Car(int speed, int position, int target){
        this->speed= speed;
        this-> position= position;
        time= (target-position)/(double) speed;
    }
};
bool comp(Car c1, Car c2){
    return c1.position< c2.position;
}
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> cars;
        stack<Car> st;

        for(int i=0; i<position.size(); i++){
            cars.push_back(Car(speed[i], position[i],target));
        }

        sort(cars.begin(), cars.end(), comp);

        for(int i=0; i<cars.size(); i++){
            Car car= cars[i];
            if(st.empty() || st.top().time > car.time ) st.push(car);
            else{
                while(!st.empty() && st.top().time<= car.time){
                    Car st_top= st.top();
                    st.pop();
                    car= Car(min(st_top.speed, car.speed), car.position,target);
                }
                st.push(car);
            }
        }
        return st.size();
    }
};