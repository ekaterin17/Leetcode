class StockSpanner {
private:
    stack<pair<int,int> > s;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int days = 1;
        while (!s.empty() && s.top().first <= price) {
            days += s.top().second;
            s.pop();
        }
        s.push(make_pair(price, days));
        return days;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
