#include <iostream>
#include <cstdlib>

using namespace std;

int Maxmium(int divisor, int bound);

int main() {
	int n, m;
	cin >> n >> m;
	cout << Maxmium(n, m);
	return 0;
}

int Maxmium(int divisor, int bound)
{
	for (int i = bound; i >= divisor; --i) {
		if (i % divisor == 0)
			return i;
	}
	return divisor;
}

/*best:
int maxMultiple(int divisor, int bound) {
	return bound - bound % divisor;
}
*/