#include "stdafx.h"
#include "EuclideanAlgorithm.h"


EuclideanAlgorithm::EuclideanAlgorithm()
{
}

template <typename T>
void Swap(T & value1, T & value2)
{
	T temp = value1 ;
	value1 = value2;
	value2 = temp;
}

int EuclideanAlgorithm::start(int argc, char * argv[])
{
	using namespace std;

	cout << "Please Euclidean algorithm Two Number\n";
	long long m, n, r =1 ;
	cin >> m >> n;

	while (true)
	{
		if (m < n)
		{
			Swap(m, n);
		}

		r = m % n;
		if (r == 0)
		{
			break;
		}
		m = n;
		n = r;

	}

	cout << "result : " << n;
	return 0;
}


EuclideanAlgorithm::~EuclideanAlgorithm()
{
}
