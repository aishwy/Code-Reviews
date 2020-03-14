#include<iostream>
using namespace std;

int main()
{
	int cases; // number of test cases
	cin >> cases; 
	int answers[cases-1]; // array for storing answer of each test case

	/// You don't need to store answer for each case, 
	/// print each answer as soon as calculated and then forget about it because all test cases are unrelated, 
	/// it will save extra memory usage
	/// try: while(cases--)
	for (int i = 0; i < cases; ++i)
	{
		int n, m; // number of baskets, types of fruits
		cin >> n >> m;
		int types[n-1], prices[n-1]; // arrays for types of fruits, prices of baskets
		int totalPrice[m-1];  // array for storing final cost of each type of fruit

		for (int j = 0; j < n; ++j) // input types of fruit in each basket
			cin >> types[j];
		
		for (int j = 0; j < n; ++j) // input price of each basket
			cin >> prices[j];
		
		for (int j = 0; j < m; ++j) // initializing array to 0
			totalPrice[j] = 0;
		/// you should not initialize totalPrice for every type to be 0
		/// because even though there are m types of fruit 
		/// you will not get to know the prices of the type of fruit which is not in any of the baskets 
		/// and for those type of fruits, total price will remain zero as it will not be updated 
		/// and the min price will come out to zero which would be wrong answer

		for (int j = 0; j < n; ++j) // calculating final price for each type of fruit
			totalPrice[types[j] - 1] += prices[j];
		
		int min = totalPrice[0]; // for minimum price

		for (int j = 1; j < m; ++j)  /// smart move
		{
			if(totalPrice[j] < min && totalPrice[j] != 0) // finding minimum priced fruit
				/// you are checking here that totalPrice of type j should not be zero
				/// it can totally be zero and that case would actually be the best case
				/// since we want the minimum cost
				min = totalPrice[j];
		}
		answers[i] = min; // storing answer of this test case in array
		/// try: cout<<min<<"\n";
	}

	for (int i = 0; i < cases; ++i) // printing final answer
		cout << answers[i] << endl;
	return 0;
}