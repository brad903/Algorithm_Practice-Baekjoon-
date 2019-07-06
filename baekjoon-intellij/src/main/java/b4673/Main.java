package b4673;

public class Main {
    public static final int MAX_NUM = 10000;
    private static boolean[] memo = new boolean[MAX_NUM + 1];

    public static void main(String[] args) {
        for (int i = 1; isInRange(i); i++) {
            if (!memo[i]) System.out.println(i);
            markSelfNum(i);
        }
    }

    private static void markSelfNum(int num) {
        if (!isInRange(num) || memo[num]) return;
        int next = num + getSumOfDigits(num);
        markSelfNum(next);
        if (isInRange(next)) memo[next] = true;
    }

    private static boolean isInRange(int next) {
        return next <= MAX_NUM;
    }

    static int getSumOfDigits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
}
