int main() {
  segtree<sum_t> st;
  ll inp[n];

  for (ll i = 0; i < n; i++) {
      cin >> inp[i];
  }
  st.init(n, inp);

  // 0-index and inclusive, update
  st.update(--a, --b, u);

  // 0-index and inclusive get the range of a value
  st.query(a - 1, a - 1).val;
}