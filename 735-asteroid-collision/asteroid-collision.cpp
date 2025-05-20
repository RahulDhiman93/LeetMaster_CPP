class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> chamber;

        for(int ast: asteroids) {
            bool put = true;
            while(!chamber.empty() && (chamber.top() > 0 && ast < 0)) {

                if (abs(chamber.top()) < abs(ast)) {
                    chamber.pop();
                    continue;
                } else if (abs(chamber.top()) == abs(ast)) {
                    chamber.pop();
                }

                put = false;
                break;
            }
            
            if (put) {
                cout<<"PUSHING: "<<ast<<endl;
                chamber.push(ast);
            }
        }

        vector<int> res (chamber.size());
        for(int i = chamber.size() - 1; i >= 0; --i) {
            res[i] = chamber.top(); 
            chamber.pop();
        }

        return res;
    }
};