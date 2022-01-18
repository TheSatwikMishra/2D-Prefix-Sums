    ll N, Q;
    cin >> N >> Q;
    vector<string> v;
    for (ll i = 0; i < N; i++) {
        string s;
        cin >> s;
        v.pb(s);
    }
    vector<vector<ll>> sum(N + 5, vector<ll>(N + 5, 0));
    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= N; j++) {
            if (v[i - 1][j - 1] == '*') sum[i][j] = 1;
            sum[i][j] += sum[i][j - 1];
        }
    }
    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= N; j++) {
            sum[i][j] += sum[i - 1][j];
        }
    }
    debug(sum)
    while (Q--) {
        ll i1, i2, j1, j2;
        cin >> i1 >> j1 >> i2 >> j2;
        ll ans = sum[i2][j2] - sum[i1 - 1][j2 ] - sum[i2][j1 - 1] + sum[i1 - 1][j1 - 1];
        cout << ans << "\n";
    }
