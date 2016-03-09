class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		size_t map[128] = { 0 }, length = 0;
		size_t p1 = 0, p2 = 0;
		while (p2 < s.length()) {
			if (map[s[p2]] != 0)
			{
				if (p2 - p1 > length)
					length = p2 - p1;
				p1 = map[s[p2]];
				for (int i = 0; i < 128; i++) {
					if (map[i] < p1)
						map[i] = 0;
				}
			}
			map[s[p2]] = p2 + 1;
			p2++;
		}
		return length > p2 - p1 ? length : p2 - p1;
	}
};