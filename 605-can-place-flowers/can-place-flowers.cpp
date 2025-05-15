class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n==0) return true;
        int size = flowerbed.size();
        if (size == 1) {
            return flowerbed[0] == 0;
        }

        for(int i = 0; i < size; ++i) {
            if (flowerbed[i] == 0) {
                if (i == 0 && flowerbed[i+1] == 0) {
                    flowerbed[i] = 1;
                    n--;
                } else if (i == size - 1 && flowerbed[i-1] == 0) {
                    flowerbed[i] = 1;
                    n--;
                } else if (i > 0 && i < size && flowerbed[i-1] == 0 && flowerbed[i+1] == 0) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
            if (n==0)
                break;
        }
        return n == 0;
    }
};