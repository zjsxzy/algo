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
            int dir = 0, head = 0, tail = n - 1;
            BigInteger add = BigInteger.ZERO, mul = BigInteger.ONE;
            for (int i = 0; i < n; i++) {
                char ch = str.charAt(i);
                if (ch == 'R') {
                    dir ^= 1;
                } else if (ch == 'A') {
                    add = add.add(A).mod(C);
                } else {
                    add = add.multiply(B).mod(C);
                    mul = mul.multiply(B).mod(C);
                }
                BigInteger cur;
                if (dir == 0) {
                    cur = L[head++];
                } else {
                    cur = L[tail--];
                }
                System.out.print(cur.multiply(mul).mod(C).add(add).mod(C));
                if (i == n - 1) System.out.println();
                else System.out.print(" ");
            }
        }
    }
}
