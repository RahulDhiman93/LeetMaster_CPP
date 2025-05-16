class StockPrice {
private:
    pair<int, int> maxPair;
    pair<int, int> minPair;
    pair<int, int> latest;
    unordered_map<int, int> tpMap;

public:
    StockPrice() {
        maxPair = {0, INT_MIN};
        minPair = {0, INT_MAX};
        latest = {0, 0};
        tpMap = {};
    }

    void update(int timestamp, int price) {
        tpMap[timestamp] = price;

        if (timestamp >= latest.first) {
            latest.first = timestamp;
            latest.second = price;
        }

        if (timestamp == maxPair.first) {
            maxPair = {0, INT_MIN};
            for (auto itr = tpMap.begin(); itr != tpMap.end(); itr++) {
                if (itr->second > maxPair.second) {
                    maxPair.first = itr->first;
                    maxPair.second = itr->second;
                }
            }
        } else if (price > maxPair.second) {
            maxPair.first = timestamp;
            maxPair.second = price;
        }

        if (timestamp == minPair.first) {
            minPair = {0, INT_MAX};
            for (auto itr = tpMap.begin(); itr != tpMap.end(); itr++) {
                if (itr->second < minPair.second) {
                    minPair.first = itr->first;
                    minPair.second = itr->second;
                }
            }
        } else if (price < minPair.second) {
            minPair.first = timestamp;
            minPair.second = price;
        }
    }

    int current() { return latest.second; }

    int maximum() { return maxPair.second; }

    int minimum() { return minPair.second; }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */