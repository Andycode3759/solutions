#include <cstdio>
// This does what you think it does.
constexpr const int max(const int &a, const int &b)
{
    return a < b ? b : a;
}
// This does what you think it does.
constexpr const int min(const int &a, const int &b)
{
    return a < b ? a : b;
}
// Same as memset in cstring, without return value.
inline void memset(void *s, int c, unsigned int len)
{
    char *p = (char *)s;
    while (len--)
        *p++ = (char)c;
}
// This does what you think it does.
inline const int readInt()
{
    int res = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
        res = res * 10 + c - '0', c = getchar();
    return res;
}
// This does what you think it does.
inline const long long readLL()
{
    long long res = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
        res = res * 10 + c - '0', c = getchar();
    return res;
}
// This does what you think it does.
template <class T>
inline void swap(T &a, T &b)
{
    T t = a;
    a = b, b = t;
}