class RandomizedSet {
private:
    vector<int> vec;
    unordered_map<int, int> idx;
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(idx.find(val) != idx.end()){
            return false;
        }else{
            vec.push_back(val);
            idx[val] = vec.size() - 1;
            return true;
        }
    }
    
    bool remove(int val) {
        if(idx.find(val) != idx.end()){
            int lastVal = vec[vec.size() - 1];
            swap(vec[idx[val]], vec[vec.size() - 1]);
            idx[lastVal] = idx[val];
            vec.pop_back();
            idx.erase(val);
            return true;
        }else{
            return false;
        }
    }
    
    int getRandom() {
        int randomIndex = rand() % vec.size();
        return vec[randomIndex];
    }
};