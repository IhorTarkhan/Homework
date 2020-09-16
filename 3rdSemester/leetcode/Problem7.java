class Solution {
    public int reverse(int x) {
        boolean isPositive = true;
        if (x < 0) {
            isPositive = false;
            if (x == Integer.MIN_VALUE)
                return 0;
        }
        String s = new StringBuilder("" + Math.abs(x)).reverse().toString();
        long i = Long.parseLong(s);
        if (!isPositive){
            i*=-1;
        }
        if (i>=Integer.MAX_VALUE || i<=Integer.MIN_VALUE)
            return 0;
        return (int) i;
    }
}