#include <iostream>
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

int main() {
    cout << "--- PRUEBA ATM MACHINE ---" << endl;
    ATM atm;
    
    atm.deposit({0, 0, 1, 2, 1}); 
    cout << "Deposito realizado: 1 de $100, 2 de $200, 1 de $500" << endl;

    vector<int> result = atm.withdraw(600); 
    cout << "Intento de retiro de 600: ";
    
    if (result.size() == 1 && result[0] == -1) {
        cout << "Rechazado (-1)" << endl;
    } else {
        for (int n : result) cout << n << " ";
        cout << endl; 
    }
    
    return 0;
}
