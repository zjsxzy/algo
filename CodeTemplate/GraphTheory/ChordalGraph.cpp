/*
�ж�ͼ�Ƿ�����ͼ

������������������
�����������еĶ���:
v1,v2,...,vn
����vi��vi��{vi,vi+1,...,vn}����vi�����ĵ���յ���ͼ����

��ͼ����������������

����:
���ȶ���ÿ������label[i]=0
ÿ��ѡ��label���ĵ���
���������ڵ�δ��ŵĵ��label++
��i�α�ŵĵ��������е�λ���ǵ�n-i+1λ

���check�õ��������Ƿ���������������
�Ժ���ǰ,����vi�������ڵ�vi1,vi2,...,vik
�ж�vi1��vi2,vi3,...,vik�Ƿ�����
*/
#define MAXN 1005
struct ChordalGraph{
	int n, m;
	int label[MAXN], que[MAXN];
	bool flag[MAXN][MAXN];
	vector<int> adj[MAXN];

	void init(int n, int m) {
		this->n = n; this->m = m;
		memset(label, 0, sizeof(label));
		memset(flag, 0, sizeof(flag));
		for (int i = 0; i <= n; i++)
			adj[i].clear();
	}

	void addEdge(int u, int v) {
		adj[u].PB(v);
		adj[v].PB(u);
		flag[u][v] = flag[v][u] = true;
	}

	void PerfectSequence() {
		for (int i = 0; i < n; i++) {
			int Max = -1;
			for (int j = 1; j <= n; j++)
				if (label[j] >= 0 && (Max == -1 || label[j] > label[Max])) {
					Max = j;
				}
			que[i] = Max;
			label[Max] = -1;
			for (int j = 0; j < adj[Max].size(); j++)
				if (label[adj[Max][j]] >= 0)
					label[adj[Max][j]]++;
		}
	}

	bool isChordalGraph() {
		PerfectSequence();
		bool ret = true;
		for (int i = 1; i < n && ret; i++) {
			int first = -1;
			for (int j = 0; j < i && ret; j++) {
				if (flag[que[i]][que[j]]) {
					if (first == -1) first = que[j];
					else ret &= flag[first][que[j]];
				}
			}
		}
		return ret;
	}
};