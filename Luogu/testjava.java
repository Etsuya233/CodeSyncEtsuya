import java.util.Scanner;

public class testjava {
    static final long MODA = 1000000007;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[10002];
        boolean[][] va = new boolean[10002][10002];
        long[] dp = new long[10002];

        for (int i = 1; i <= n; i++) {
            arr[i] = scanner.nextInt();
        }

        // init
        for (int i = 1; i <= n; i++) {
            va[i][i] = true;
            int minn = arr[i], maxn = arr[i];
            for (int j = i + 1; j <= n; j++) {
                minn = Math.min(minn, arr[j]);
                maxn = Math.max(maxn, arr[j]);
                if (maxn - minn != j - i) va[i][j] = false;
                else va[i][j] = true;
            }
        }

        // dp
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                if (va[j][i]) dp[i] = (dp[j - 1] + dp[i]) % MODA;
            }
        }

        System.out.println(dp[n] % MODA);
        scanner.close();
    }
}
