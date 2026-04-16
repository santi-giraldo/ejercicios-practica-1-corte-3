#include <vector>

using namespace std;

class ATM {
private:
    vector<long long> bank;
    vector<int> denominations;

public:
    ATM() {
        bank = vector<long long>(5, 0);
        denominations = {20, 50, 100, 200, 500};
    }
    
    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; ++i) {
            bank[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> result(5, 0);
        
        for (int i = 4; i >= 0; --i) {
            if (amount >= denominations[i] && bank[i] > 0) {
                long long needed = amount / denominations[i];
                long long used = min(needed, bank[i]);
                result[i] = used;
                amount -= used * denominations[i];
            }
        }
        
        if (amount != 0) {
            return {-1};
        }
        
        for (int i = 0; i < 5; ++i) {
            bank[i] -= result[i];
        }
        
        return result;
    }
};
