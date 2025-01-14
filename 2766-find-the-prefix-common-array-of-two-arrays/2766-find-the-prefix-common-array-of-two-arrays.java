class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        Map<Integer, Pair<Boolean, Boolean>> M = new HashMap<>();
        int[] ans = new int[A.length];
        int c = 0;
        for (int i = 0; i < A.length; i++) {
            if (!M.containsKey(A[i])) {
                M.put(A[i], new Pair<>(true, false));
            } else {
                Pair<Boolean, Boolean> current = M.get(A[i]);
                if (!current.getKey() && current.getValue()) {
                    c++;
                    M.put(A[i], new Pair<>(true, current.getValue()));
                }
            }
            if (!M.containsKey(B[i])) {
                M.put(B[i], new Pair<>(false, true));
            } else {
                Pair<Boolean, Boolean> current = M.get(B[i]);
                if (!current.getValue() && current.getKey()) {
                    c++;
                    M.put(B[i], new Pair<>(current.getKey(), true));
                }
            }
            ans[i] = c;
        }
        return ans;
    }
    private static class Pair<K, V> {
        private final K key;
        private final V value;
        public Pair(K key, V value) {
            this.key = key;
            this.value = value;
        }
        public K getKey() {
            return key;
        }
        public V getValue() {
            return value;
        }
    }
}