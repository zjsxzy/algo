import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.StreamTokenizer;

public class Main{
    int maxn = 50010;

    class SegTree {
        class SegNode {
            int sum, val;
            boolean flag;
            int left, right;
            SegNode(int l, int r) {
                left = l;
                right = r;
            }
            int mid() {
                return (left + right) >> 1;
            }
            int length() {
                return right - left + 1;
            }
        }

        SegNode tree[] = new SegNode[maxn * 4];
        void init(int idx, int left, int right) {
            tree[idx] = new SegNode(left, right);
            if (left == right)
                return;
            int mid = tree[idx].mid();
            init(idx << 1, left, mid);
            init(idx << 1 | 1, mid + 1, right);
            push_up(idx);
        }

        void update(int idx, int left, int right, int v) {
            push_down(idx);
            if (left <= tree[idx].left && right >= tree[idx].right) {
                tree[idx].val = v;
                tree[idx].flag = true;
                return;
            }
            int mid = tree[idx].mid();
            if (left <= mid)
                update(idx << 1, left, right, v);
            if (mid < right)
                update(idx << 1 | 1, left, right, v);
            push_up(idx);
        }

        int query(int idx, int left, int right) {
            push_down(idx);
            if (left == tree[idx].left && right == tree[idx].right) {
                return tree[idx].sum;
            }
            int mid = tree[idx].mid();
            if (right <= mid)
                return query(idx << 1, left, right);
            else if (left > mid)
                return query(idx << 1 | 1, left, right);
            else
                return query(idx << 1, left, mid)
                        + query(idx << 1 | 1, mid + 1, right);
        }

        void push_down(int idx) {
            if (tree[idx].flag) {
                tree[idx].flag = false;
                int k = tree[idx].val;
                tree[idx].sum = k * tree[idx].length();
                tree[idx].val = 0;
                if (tree[idx].left != tree[idx].right) {
                    int t = idx << 1;
                    tree[t].flag = true;
                    tree[t].val = k;
                    t++;
                    tree[t].flag = true;
                    tree[t].val = k;
                }
            }
        }

        void push_up(int idx) {
            if (tree[idx].left == tree[idx].right)
                return;
            push_down(idx << 1);
            push_down(idx << 1 | 1);
            tree[idx].sum = tree[idx << 1].sum + tree[idx << 1 | 1].sum;
        }
    }

    SegTree tree = new SegTree();
    int resL, resR, n;

    boolean bin(int k, int f) {
        if (tree.query(1, k, n) == n - k + 1 || f == 0)
            return false;
        int left = k, right = n;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (tree.query(1, k, mid) < mid - k + 1) {
                resL = mid;
                right = mid - 1;
            } else
                left = mid + 1;
        }
        left = k;
        right = n;
        if (tree.query(1, k, n)+f<=n-k+1) {
            while (left <= right) {
                int mid = (left + right) >> 1;
                if (tree.query(1, k, mid) + f <= mid - k + 1) {
                    resR = mid;
                    right = mid - 1;
                } else
                    left = mid + 1;
            }
        }
        else
        {
            while (left <= right) {
                int mid = (left + right) >> 1;
                if (tree.query(1, mid,n)<n-mid+1) {
                    resR = mid;
                    left = mid + 1;
                } else
                    right=mid-1;
            }
        }
        tree.update(1, resL, resR, 1);
        resL--;
        resR--;
        return true;
    }

    void run() throws Exception {
        int cas = nextInt();
        while (cas-- > 0) {
            n = nextInt();
            int m = nextInt();
            tree.init(1, 1, n);
            while (m-- > 0) {
                if (nextInt() == 1) {
                    int k = nextInt() + 1;
                    int f = nextInt();
                    if (bin(k, f))
                        out.write(resL + " " + resR + "\n");
                    else
                        out.write("Can not put any one.\n");
                } else {
                    int a = nextInt() + 1;
                    int b = nextInt() + 1;
                    out.write(tree.query(1, a, b) + "\n");
                    tree.update(1, a, b, 0);
                }
            }
            out.write("\n");
        }
        out.close();
    }

    StreamTokenizer in = new StreamTokenizer(new BufferedReader(
            new InputStreamReader(System.in)));
    BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));

    int nextInt() throws IOException {
        in.nextToken();
        return (int) in.nval;
    }

    public static void main(String[] args) throws Exception {
        try{
        new Main().run();
        }
        catch(Exception e)
        {
            while(true);
        }
    }

}