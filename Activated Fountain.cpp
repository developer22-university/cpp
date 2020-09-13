 QUESTIONLINK-https://leetcode.com/discuss/interview-question/363036/twitter-oa-2019-activate-fountain
It seems like using a greedy approach that always add the fountain that (1) covers all uncovered spots to the left, and (b) maximizes the number of spots to the right that are covered, will work. O(n^2) without optimizations, but the array can be preprocessed to store the rightmost index that can be "covered with water" from a given index for O(n).

int numFountains(vector<int> fountains) {
    int n = fountains.size();
    vector<int> extents(n, 0);

    for (int i = 0; i < n; i++) {
        int left = max(i - fountains[i], 0);
        int right = min(i + (fountains[i] + 1), n);
        extents[left] = max(extents[left], right);
    }

    int num_fountains = 1;
    int right = extents[0], next_right = 0;
    for (int i = 0; i < n; i++) {
        next_right = max(next_right, extents[i]);
        if (i == right) {
            num_fountains++;
            right = next_right;
        }
    }

    return num_fountains;
}

