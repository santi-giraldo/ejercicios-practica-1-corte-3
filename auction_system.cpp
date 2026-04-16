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
