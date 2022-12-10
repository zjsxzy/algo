/*
ID: frankzh1
TASK: buylow
LANG: JAVA
 */
import java.io.*;
import java.math.BigInteger;
import java.util.Scanner;

public class buylow {
    int n;
    int[] a = new int[5005];
    int[] f = new int[5005];
    BigInteger[] g = new BigInteger[5005];

    void solve() throws IOException {
        Scanner sc = new Scanner(new FileReader("buylow.in"));
        n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            f[i] = 1;
            g[i] = BigInteger.valueOf(1);
        }
        sc.close();

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (a[j] > a[i]) {
                    if (f[j] + 1 == f[i]) {
                        g[i] = g[i].add(g[j]);
                    } else if (f[j] + 1 > f[i]) {
                        f[i] = f[j] + 1;
                        g[i] = g[j];
                    }
                } else if (a[i] == a[j]) {
                    g[j] = BigInteger.valueOf(0);
                }
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (f[i] > res) res = f[i];
        }
        BigInteger sum = BigInteger.valueOf(0);
        for (int i = 0; i < n; i++) {
            if (f[i] == res) {
                sum = sum.add(g[i]);
            }
        }

        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("buylow.out")));
        out.println(res + " " + sum);
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new buylow().solve();
    }
}
