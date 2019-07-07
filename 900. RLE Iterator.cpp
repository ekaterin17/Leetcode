class RLEIterator {
  int idx_ = 0; 
  int used_ = 0;
  vector<int>& theA_;
public:
  RLEIterator(vector<int>& A): theA_(A) { }

  int next(int n) {
    for(; idx_<theA_.size(); idx_ += 2) {
      if(theA_[idx_] - used_ > n) {
        used_ += n;
        return theA_[idx_+1];
      }
      else if (theA_[idx_] - used_ == n) {
        used_ = 0;
        idx_ += 2;
        return theA_[idx_-1];
      }
      else {
        n -= theA_[idx_] - used_;
        used_ = 0;
      }
    }
    
    return -1;
  }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */
