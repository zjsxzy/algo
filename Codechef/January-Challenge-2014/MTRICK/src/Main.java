import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: zhangyang
 * Date: 1/4/14
 */
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int ts = in.nextInt();
        for (int cas = 1; cas <= ts; cas++) {
            int n = in.nextInt();
            BigInteger L[] = new BigInteger[n];
            for (int i = 0; i < n; i++) {
                L[i] = in.nextBigInteger();
            }
            BigInteger A = in.nextBigInteger();
            BigInteger B = in.nextBigInteger();
            BigInteger C = in.nextBigInteger();
            String str = in.nextLine();
            str = in.nextLine();
            //System.out.println(str);
            for (int i = 0; i < n; i++) {
                char ch = str.charAt(i);
                if (ch == 'R') {
                    for (int j = 0; j < (n - i) / 2; j++) {
                        BigInteger temp = L[i + j];
                        L[i + j] = L[n - j - 1];
                        L[n - j - 1] = temp;
                    }
                } else if (ch == 'A') {
                    for (int j = i; j < n; j++) {
                        L[j] = L[j].add(A).mod(C);
                    }
                } else {
                    for (int j = i; j < n; j++) {
                        L[j] = L[j].multiply(B).mod(C);
                    }
                }
                System.out.print(L[i].toString());
                if (i == n - 1) System.out.println();
                else System.out.print(" ");
            }
        }
    }
}
