

class NestedIterator {
    vector<int> flattened;
    int i;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        i=0;
        for(auto i:nestedList){
            if(i.isInteger())
                flattened.push_back(i.getInteger());
            else
                flattenList(i.getList());
        }
    }

    void flattenList(vector<NestedInteger> &list){
        for(auto i:list){
            if(i.isInteger())
                flattened.push_back(i.getInteger());
            else
                flattenList(i.getList());
        }
    }
    
    int next() {
        return flattened[i++];
    }
    
    bool hasNext() {
        if(i>=flattened.size())
            return false;
        return true;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */