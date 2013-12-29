import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: zhangyang
 * Date: 12/29/13
 */
public class Main {
    static final int tbl[][] = {
            {},
            {2, 1, 1},
            {6, 1, 3, 2},
            {4, 0, 1, 2, 1},
            {30, -1, 10, 15, 6},
            {12, 0, -1, 0, 5, 6, 2},
            {42, 1, 0, -7, 0, 21, 21, 6},
            {24, 0, 2, 0, -7, 0, 14, 12, 3},
            {90, -3, 0, 20, 0, -42, 0, 60, 45, 10},
            {20, 0, -3, 0, 10, 0, -14, 0, 15, 10, 2},
            {66, 5, 0, -33, 0, 66, 0, -66, 0, 55, 33, 6}
    };

    static long n, p[];
    static int k, pn;
    static long mod;
    static BigInteger mdb;


    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextLong();
        k = in.nextInt();
        mod = in.nextLong();
        mdb = BigInteger.valueOf(mod);

        factor(n);
        long ret = 0, cur;
        int cnt;
        for (int i = 0; i >> pn == 0; i++) {
            cur = 1; cnt = 0;
            for (int j = 0; j < pn; j++) {
                if (((i >> j) & 1) == 1) {
                    cnt ^= 1;
                    cur *= p[j + 1];
                }
            }
            if (cnt == 1) {
                ret = (ret - calc(n / cur, cur)) % mod;
            } else {
                ret = (ret + calc(n / cur, cur)) % mod;
            }
        }
        ret = (ret + mod) % mod;
        System.out.println(ret);
    }

    // (1^k + 2^k + ... + n^k) * t^k
    private static long calc(long n, long t) {
        BigInteger todiv = BigInteger.valueOf(tbl[k][0]), M = mdb.multiply(todiv);
        BigInteger N = BigInteger.valueOf(n), a = BigInteger.ONE, res = BigInteger.valueOf(0);
        for (int i = 1; i <= k + 1; i++) {
            a = a.multiply(N).mod(M);
            res = res.add(a.multiply(BigInteger.valueOf(tbl[k][i]))).mod(M);
        }
        res = res.divide(BigInteger.valueOf(tbl[k][0])).mod(mdb);
        res = res.multiply(BigInteger.valueOf(t).pow(k).mod(mdb)).mod(mdb);
        return res.longValue();
    }

    private static void factor(long n) {
        pn = 0;
        p = new long[20];
        for (long i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                p[++pn] = i;
                for (; n % i == 0; n /= i);
            }
        }
        if (n > 1) p[++pn] = n;
    }
}
