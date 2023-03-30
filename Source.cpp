#include <vector>
#include <iostream>
#include <ctime>
#include <math.h>
using namespace std;

double Frequency_bitwise_test(const vector<int>& bits)
{
	double frequency = 1.0 / 128;
	double Sn = 0, P = 0;

	for (int i = 0; i < 128; i++)
	{
		if (bits[i] == 1)
		{
			Sn += 1;
		}
		if (bits[i] == -1)
		{
			Sn -= 1;
		}
	}
	Sn = frequency * Sn;
	P = erfc(Sn / sqrt(2));
	return P;
}

double Test_for_identical_consecutive_bits(const vector<int>& bits)
{
	double N = 128;
	double frequency = 1 / N;
	double fraction = 0, sum = 0, P = 0;
	double Vn = 0;

	for (size_t i = 0; i < 128; ++i)
	{
		sum += bits[i];
	}
	fraction = frequency * sum;

	if (abs(fraction - 1) > 2 / (sqrt(frequency)))
	{
		return P = 0;
	}

	for (size_t i = 0; i < 127; ++i)
	{
		if (bits[i] != bits[i + 1])
		{
			Vn += 1;
		}
	}
	P = erfc(abs(Vn - 2 * N * fraction * (1 - fraction)) / (2 * sqrt(2 * N) * fraction * (1 - fraction)));
}
double Test_for_longest_sequence_of_units_in_a_block(vector<int>& bits)
{
	vector<int>number_of_units;
	int index = 0;
	while (true)
	{
		if (index == 128)
		{
			break;
		}
		vector<int> tmp;
		for (int i = index; i < index + 8; ++i)
		{
			tmp.push_back(bits[i]);
		}
		int max_sum_of_one = 0, current = 0;
		for (auto i : tmp)
		{
			if (i == 1)
			{
				++current;
			}
			else
			{
				if (current > max_sum_of_one)
				{
					max_sum_of_one = current;
				}
				current = 0;
			}
		}
		number_of_units.push_back(max_sum_of_one);
		index += 8;
	}
	int v1 = 0, v2 = 0, v3 = 0, v4 = 0;
	for (auto i : number_of_units)
	{
		if (i <= 1) { ++v1; }
		if (i == 2) { ++v2; }
		if (i == 3) { ++v3; }
		if (i >= 4) { ++v4; }
	}
	vector<int> v_array = { v1,v2,v3,v4 };
	vector<double> pi_array = { 0.2148, 0.3672, 0.2305, 0.1875 };
	double X = 0;
	for (int i = 0; i < 4; ++i)
	{
		X += (pow(v_array[i] - 16 * pi_array[i], 2)) / (16 * pi_array[i]);
	}

	return X;
}
int main()
{
	srand(time(NULL));
	vector<int> sequence_of_bits;

	for (size_t i = 0; i < 128; ++i)
	{
		sequence_of_bits.push_back(rand() % 2);
		cout << sequence_of_bits[i];
	}
	cout << endl;

	double test_bit = Frequency_bitwise_test(sequence_of_bits);
	cout << test_bit;

	cout << endl;

	double test_consistency = Test_for_identical_consecutive_bits(sequence_of_bits);
	cout << test_consistency;

	cout << endl;

	double test_for_longest = Test_for_longest_sequence_of_units_in_a_block(sequence_of_bits);
	cout << test_for_longest;

	cout << endl;

}


