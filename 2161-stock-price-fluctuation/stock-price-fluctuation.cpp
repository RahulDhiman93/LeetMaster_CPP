class StockPrice {
private:
    int latestTime;
    unordered_map<int, int> tpMap;
    map<int, int> priceMap;

public:
    StockPrice() {
        latestTime = 0;
    }
    
    void update(int timestamp, int price) {
        latestTime = max(latestTime, timestamp);

        if (tpMap.contains(timestamp)) {
            int oldPrice = tpMap[timestamp];
            priceMap[oldPrice]--;

            if (priceMap[oldPrice] == 0) {
                priceMap.erase(oldPrice);
            }
        }

        tpMap[timestamp] = price;
        priceMap[price]++;
    }
    
    int current() {
        return tpMap[latestTime];
    }
    
    int maximum() {
        return priceMap.rbegin()->first;
    }
    
    int minimum() {
        return priceMap.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */