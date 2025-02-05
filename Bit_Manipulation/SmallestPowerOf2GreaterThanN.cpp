cout << ((n <= 1) ? 2 : (1LL << ((63 - __builtin_clzll(n-1)) + 1)))
