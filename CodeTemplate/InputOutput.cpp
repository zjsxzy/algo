template <typename T>
inline T read() {
    T a = 0; char c = getchar(), f = 1;
    for(; c < '0' || c > '9'; c = getchar())
        if(c == '-') f = -f;
        else if(c == -1) return -1;
    for(; c >= '0' && c <= '9'; c = getchar()) a = (a << 1) + (a << 3) + (c ^ 48);
    return a * f;
}

a = read<int>();
