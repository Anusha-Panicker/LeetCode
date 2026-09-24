int lengthOfLongestSubstring(char* s) {
    int last[256];
    
    // Initialize all characters as not seen
    for (int i = 0; i < 256; i++) {
        last[i] = -1;
    }

    int left = 0;
    int maxLen = 0;

    for (int right = 0; s[right] != '\0'; right++) {

        // If character was already seen inside current window
        if (last[(unsigned char)s[right]] >= left) {
            left = last[(unsigned char)s[right]] + 1;
        }

        // Store latest position of character
        last[(unsigned char)s[right]] = right;

        // Current window length
        int len = right - left + 1;

        if (len > maxLen) {
            maxLen = len;
        }
    }

    return maxLen;
}