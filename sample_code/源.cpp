#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cmath>
#include<queue>
#include<Windows.h>
#include<algorithm>
 
namespace io {
	inline char gc() {
		static char buf[1 << 17], * p1 = buf, * p2 = buf;
		return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 17, stdin), p1 == p2) ? EOF : *p1++;
	}
	template <class T>
	inline void read(T& n, char ch = gc(), int sign = 1) {
		for (n = 0; ch < '0' || ch > '9' && ch != '-'; ch = gc());
		for (ch == '-' ? ch = gc(), sign = -1 : 0; ch >= '0' && ch <= '9'; ch = gc)
			n = (n << 1) + (n << 3) + ch - '0';
		n = n * sign;
	}
	inline void pc(char ch, bool op = 0) {
		static char buf[1 << 17], * p1 = buf, * p2 = buf + (1 << 17);
		if (op) fwrite(buf, 1, p1 - buf, stdout);
		else (*p1++) = ch, * p1 == *p2 ? fwrite(buf, 1, p1 - buf, stdout), p1 = buf: 0;
	}
	template<class T>
	inline void write(T n, int num = 0) {
		char ch[24];
		if (n < 0) pc('-'), n = -n;
		if (n == 0) pc('0');
		while (n) ch[++num] = n % 10 + '0', num /= 10;
		while (num) pc(ch[num--]);
	}
	inline void endl() {
		pc('\n');
	}
}

namespace mus {
	const double C[10] = { 16.352, 32.703, 65.406, 130.81, 261.63, 523.25, 1046.5, 2093.0, 4186.0, 8372.0 };
	const double Cs[10] = { 17.324, 34.648, 69.296, 138.59, 277.18, 544.37, 1108.7, 2217.5, 4434.9, 8869.8 };
	const double Db[10] = { 17.324, 34.648, 69.296, 138.59, 277.18, 544.37, 1108.7, 2217.5, 4434.9, 8869.8 };
	const double D[10] = { 18.354, 36.708, 73.416, 146.83, 293.66, 587.33, 1174.7, 2349.3, 4698.6, 9397.3 };
	const double Ds[10] = { 19.445, 38.891, 77.782, 155.56, 311.13, 622.25, 1244.5, 2489.0, 4978.0, 9956.1 };
	const double Eb[10] = { 19.445, 38.891, 77.782, 155.56, 311.13, 622.25, 1244.5, 2489.0, 4978.0, 9956.1 };
	const double E[10] = { 20.602, 41.203, 82.407, 164.81, 329.63, 659.26, 1318.5, 2637.0, 5274.0, 10548 };
	const double F[10] = { 21.827, 43.654, 87.307, 174.61, 349.23, 698.46, 1396.9, 2793.8, 5587.7, 11175 };
	const double Fs[10] = { 23.125, 46.249, 92.499, 185.00, 369.99, 739.99, 1480.0, 2960.0, 5919.9, 11840 };
	const double Gb[10] = { 23.125, 46.249, 92.499, 185.00, 369.99, 739.99, 1480.0, 2960.0, 5919.9, 11840 };
	const double G[10] = { 24.500, 48.999, 97.999, 196.0, 392.00, 783.99, 1568.0, 3136.0, 6271.9, 12544 };
	const double Gs[10] = { 25.957, 51.913, 103.83, 207.65, 415.30, 830.61, 1661.2, 3322.4, 6644.9, 13290 };
	const double Ab[10] = { 25.957, 51.913, 103.83, 207.65, 415.30, 830.61, 1661.2, 3322.4, 6644.9, 13290 };
	const double A[10] = { 27.500, 55.000, 110.00, 220.00, 440.00, 880.00, 1760.0, 3520.0, 7040.0, 14080 };
	const double As[10] = { 29.135, 58.270, 116.54, 233.08, 466.16, 932.33, 1864.7, 3729.3, 7458.6, 14917 };
	const double Bb[10] = { 29.135, 58.270, 116.54, 233.08, 466.16, 932.33, 1864.7, 3729.3, 7458.6, 14917 };
	const double B[10] = { 30.868, 61.735, 123.47, 246.94, 493.88, 987.77, 1975.5, 3951.1, 7902.1, 15804 };
};

class fracs {
private:
	inline int abs(int x) {
		return x < 0 ? -x : x;
	}
	inline void swap(int& a, int& b) {
		int c = b;
		b = a, a = c;
	}
	inline int gcd(int a, int b) {
		while (b ^= a ^= b ^= a %= b);
		return a;
	}
	inline void simp() {
		if (s == 0) {
			m = 1;
			return;
		}
		int f = gcd(abs(s), abs(m));
		if (f != 1) {
			s /= f;
			m /= f;
		}
		if (m < 0) m = -m, s = -s;
	}//-1045 -775
public:
	int s, m;
	fracs(int ss = 0, int mm = 1) :
	s(ss), m(mm) {
		simp();
	}
	friend fracs operator *(fracs a, fracs b) {
		a.s *= b.s;
		a.m *= b.m;
		a.simp();
		return a;
	}
	void operator *=(fracs b) {
		*this = *this * b;
	}
	friend fracs operator /(fracs a, fracs b) {
		a.swap(b.s, b.m);
		return  a * b;
	}
	void operator /=(fracs b) {
		*this = *this / b;
	}
	friend fracs operator +(fracs a, fracs b) {
		int t = a.gcd(a.m, b.m);
		t = (a.m * b.m) / t;
		int t1 = t / a.m, t2 = t / b.m;
		a.m = t;
		a.s = a.s * t1 + b.s * t2;
		a.simp();
		return a;
	}
	void operator +=(fracs b) {
		*this = *this + b;
	}
	friend fracs operator -(fracs a, fracs b) {
		int t = a.gcd(a.m, b.m);
		t = (a.m * b.m) / t;
		int t1 = t / a.m, t2 = t / b.m;
		a.m = t;
		a.s = a.s * t1 - b.s * t2;
		a.simp();
		return a;
	}
	void operator -=(fracs b) {
		*this = *this - b;
	}
	void operator =(fracs b) {
		this->s = b.s;
		this->m = b.m;
	}
	bool operator ==(fracs b) {
		return (this->s == b.s && this->m == b.m) || (this->s == 0 && b.s == 0);
	}
	bool operator >(fracs b) {
		int t = gcd(this->m, b.m);
		t = (this->m * b.m) / t;
		int t1 = t / this->m, t2 = t / b.m;
		return this->s * t1 > b.s * t1;
	}
	bool operator <(fracs b) {
		int t = gcd(this->m, b.m);
		t = (this->m * b.m) / t;
		int t1 = t / this->m, t2 = t / b.m;
		return this->s * t1 < b.s * t1;
	}
	bool operator >=(fracs b) {
		return *this > b || *this == b;
	}
	bool operator <=(fracs b) {
		return *this < b || *this == b;
	}
	inline void show() {
		if (s == 0) {
			printf("0   ");
		}
		else if (s == m) {
			printf("1   ");
		}
		else if (m == 1) {
			printf("%d   ", s);
		}
		else {
			printf("%d/%d ", this->s, this->m);
		}
	}
};

fracs m[3][3], r[3][3], t[3][3];

inline void ini() {
	m[0][0] = fracs(1, 3);
	m[0][1] = fracs(1, 1);
	m[1][1] = fracs(1, 3);
	m[1][2] = fracs(1, 1);
	m[2][2] = fracs(1, 3);
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			r[i][j] = 0;
	r[0][0] = fracs(1, 3);
	r[0][1] = fracs(1, 1);
	r[1][1] = fracs(1, 3);
	r[1][2] = fracs(1, 1);
	r[2][2] = fracs(1, 3);
}


inline void calc() {

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			t[i][j] = fracs();

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				t[i][j] += (r[i][k] * m[k][j]);
			}
		}
	}
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			r[i][j] = t[i][j];

}

inline bool cmp(int a, int b) {
	return a > b;
}

using namespace std;

//using namespace mus;

const int bt = 400;
inline void read(long long& x) { scanf("%lld", &x); }
inline void read(int& x) { scanf("%d", &x); }
inline void read(double& x) { scanf("%lf", &x); }
const int N = 105;
const double eps = 1e-8;
fracs B[N][N];
inline fracs abs(fracs a) {
	if (a < fracs(0, 1)) a = fracs(0, 1) - a;
	return a;
}

const double inf = 900000000000000.0f;

struct factor{
	int val, tot;
	factor(int a) : val(a), tot(0) {}
	factor(int a, int b) : val(a), tot(b) {}
};

vector<factor> get_fac(int n) {
	vector<factor> res;
	for (int i = 2; i <= n / i; ++i) {
		if (n % i == 0) {
			factor new_factor(i);
			while (n % i == 0) {
				++new_factor.tot;
				n /= i;
			}
			res.push_back(new_factor);
		}
	}
	if (n != 1) {
		res.push_back(factor(n, 1));
	}

	return res;
}

int f(int n, int m) {
	if (n == 1 && m == 1)
		return 1;
	int res = 0;
	if (n > 1) {
		res = res + f(n - 1, m);
	}
	if (m > 1) {
		res = res + f(n, m - 1);
	}
	return res;
}

int main() {
	double x;
	scanf("%lf", &x);
	double res = (cos(sin(x)) - cos(x)) / (sin(x) * sin(x) * sin(x) * sin(x));
	printf("%lf", res);
}

/*int main() {
	freopen("C:\\Users\\XXY\\Desktop\\work\\MATH\\in.txt", "r", stdin);
	int n, m;
	read(n), read(m);
	for (int i = 0; i < n; ++i) {
		int s, mo = 1;
		for (int j = 0; j < m; ++j) scanf("%d", &s), B[i][j] = fracs(s, mo);
	}
	for(int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			if (i == j) B[i][j + n] = fracs(1, 1);
			else B[i][j + n] = fracs(0, 1);
		}
	fracs ans = fracs(1, 1);
	for (int i = 0; i < n; ++i) {
		int tmp = i;
		for (int j = i; j < n; ++j)
			if (abs(B[j][i]) > abs(B[tmp][i]) ) tmp = j;
		for (int j = 0; j < m; ++j) {
			fracs t = B[i][j];
			B[i][j] = B[tmp][j], B[tmp][j] = t;
		}
		if (B[i][i] == fracs(0, 1)) return puts("No Solution") & 0;
		fracs r = B[i][i];
		ans *= r;
		for (int j = i ; j < m; ++j) B[i][j] /= r;
		for (int j = 0; j < n; ++j)
			if (i != j) {
				fracs r = B[j][i];
				for (int k = i; k < m; ++k) B[j][k] -= r * B[i][k];
			}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				B[i][j].show();
			}
			putchar('\n');
		}
		putchar('\n');
	}
	ans.show();
}*/

/*int main() {
	int n;
	while (1) {
		scanf("%d", &n);
		--n;
		ini();
		for (int i = 1; i <= n; ++i) {
			calc();
		}

		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) r[i][j].show();
			putchar('\n');
		}
	}
	Beep(C[5], bt * 2);
	Beep(Eb[4], bt / 2);
	Beep(Ab[4], bt / 2);
	Beep(C[5], bt / 2);
	Beep(Ab[4], bt / 2);
	Beep(Db[5], bt / 2);
	Beep(Ab[4], bt / 2);
	Beep(Ab[5], bt / 2);
	Beep(Bb[4], bt * 3 / 2);
	Beep(Ab[4], bt);
	Beep(Bb[4], bt * 2);
	Beep(Eb[4], bt / 2);
	Beep(Ab[4], bt / 2);
	Beep(Bb[4], bt / 2);
	Beep(Eb[4], bt / 2);
	Beep(Eb[5], bt / 2);
	Beep(Eb[4], bt / 2);
	Beep(G[5], bt / 2);
	Beep(C[5], bt * 3 / 2);
	Beep(Eb[4], bt);
	Beep(Ab[4], bt * 2);
	Beep(Eb[4], bt / 2);
	Beep(Ab[4], bt / 2);
	Beep(Bb[4], bt / 2);
	Beep(Eb[4], bt / 2);
	Beep(Bb[4], bt * 3 / 2);
	Beep(Eb[5], bt * 3 / 2);
	Beep(Bb[4], bt);
	Beep(Gb[4], bt);
	Beep(Eb[4], bt / 2);
	Beep(Gb[4], bt / 2);
	Sleep(bt);
	Beep(Ab[4], bt * 2);
	Beep(Db[5], bt / 2);
	Beep(C[5], bt / 2);
	Beep(Ab[4], bt / 2);
	Beep(Eb[4], bt / 2);

}*/