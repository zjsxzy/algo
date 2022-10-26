void compress(vector<int>& as) {
    vector<int> num;
    for (int i = 0; i < (int)as.size(); i++) {
        num.push_back(as[i]);
    }
    sort(num.begin(), num.end());
    num.resize(unique(num.begin(), num.end()) - num.begin());
    for (int i = 0; i < (int)as.size(); i++) {
        as[i] = lower_bound(num.begin(), num.end(), as[i]) - num.begin() + 1;
    }
}
