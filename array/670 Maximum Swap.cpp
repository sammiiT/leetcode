class Solution {
public:
	int maximumSwap(int num) {

		string str = to_string(num);
		int res = num;//????

		for (int i = 0; i < str.size() - 1; ++i) {
			for (int j = i + 1; j < str.size(); ++j) {
				swap(str[i], str[j]);
				res = max(res, stoi(str));
				swap(str[i], str[j]);

			}
		}
		return res;
	}

};