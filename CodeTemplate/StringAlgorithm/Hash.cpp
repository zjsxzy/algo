int ELFhash(string& s) {
    int h = 0, x = 0;
    for (int i = 0; i < s.size(); i++) {
        h = (h << 4) + s[i];
        if ((x = h & 0xF0000000L) != 0) {
            h ^= (x >> 24);
        }
        h &= ~x;
    }
    return h;
}
