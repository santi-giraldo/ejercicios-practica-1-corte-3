#include <unordered_map>
#include <set>

using namespace std;

class AuctionSystem {
private:
    unordered_map<int, unordered_map<int, int>> itemUserBid;
    unordered_map<int, set<pair<int, int>>> itemBids;

public:
    AuctionSystem() {
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        if (itemUserBid[itemId].count(userId)) {
            int oldBid = itemUserBid[itemId][userId];
            itemBids[itemId].erase({oldBid, userId});
        }
        
        itemUserBid[itemId][userId] = bidAmount;
        itemBids[itemId].insert({bidAmount, userId});
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        int oldBid = itemUserBid[itemId][userId];
        itemBids[itemId].erase({oldBid, userId});
        
        itemUserBid[itemId][userId] = newAmount;
        itemBids[itemId].insert({newAmount, userId});
    }
    
    void removeBid(int userId, int itemId) {
        int oldBid = itemUserBid[itemId][userId];
        itemBids[itemId].erase({oldBid, userId});
        itemUserBid[itemId].erase(userId);
    }
    
    int getHighestBidder(int itemId) {
        if (itemBids[itemId]-.empty()) {
            return -1;
        }
        return itemBids[itemId].rbegin()->second;
    }
};

int main() {
    cout << "--- PRUEBA AUCTION SYSTEM ---" << endl;
    AuctionSystem* auction = new AuctionSystem();
    
    auction->addBid(1, 7, 5);
    auction->addBid(2, 7, 6);
    
    cout << "Mejor postor para item 7: " 
         << auction->getHighestBidder(7) << endl; 
         
    auction->updateBid(1, 7, 8); 
    
    cout << "Mejor postor para item 7 despues de actualizar: " 
         << auction->getHighestBidder(7) << endl;
         
    auction->removeBid(1, 7); 
    
    cout << "Mejor postor para item 7 despues de eliminar: " 
         << auction->getHighestBidder(7) << endl; 
         
    delete auction;
    return 0;
}
