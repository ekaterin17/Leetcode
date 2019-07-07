class Solution {
public:
    string intToRoman(int num) {
		int quotient = 0, fix = 0;
		vector<pair<int, char>> intRoman = { {1000,'M'},{500,'D'},{100,'C'},{50,'L'},{10,'X'},{5,'V'},{1,'I'} };
		unordered_map<int,char> intRomanMap = { {100,'C'},{10,'X'},{1,'I'} };

		string result;
		for (size_t i = 0; i < intRoman.size();++i) {
			fix = intRoman[i].first / 10;
			if (fix > 10) { fix = 100; }
			else if (fix > 1) { fix = 10; }
			else fix = 1;
			quotient = num / intRoman[i].first;
			num = num % intRoman[i].first;
			for (int j = 0; j < quotient; ++j) {
				result.push_back(intRoman[i].second);
			}
			if (num != 0 && num >= intRoman[i].first - fix) {
				num -= (intRoman[i].first - fix);
				result.push_back(intRomanMap[fix]);
				result.push_back(intRoman[i].second);
			}
		}
		return result;
	}
};
