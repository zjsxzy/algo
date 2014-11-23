void compress() {
	vector<int> num;
	for (int i = 0; i < as.size(); i++) {
		num.PB(as[i]);
	}
	sort(num.begin(), num.end());
    num.resize(unique(num.begin(), num.end()) - num.begin());
	for (int i = 0; i < as.size(); i++) {
		as[i] = lower_bound(num.begin(), num.end(), as[i]) - num.begin() + 1;
	}
}
