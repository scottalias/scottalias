#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	int winningDigits[5];
	int player[5];
	int digit, match = 0;

	srand(time(0)); // Initialize random number generator
										

	// Get 5 random digits and store them in array winningDigits
	for (int i = 0; i < 5; i++)
	{
		winningDigits[i] = rand() % 9; // array winningDigits[i] will be 5 random numbers from 0 through 8
	}

	// Ask user to enter 5 digits and store them in array player
	cout << "Enter 5 lottery picks in the range of 0 to 9,\n"
		<< "one number at a time.\n";
	for (int i = 0; i < 5; i++)
	{
		do
		{
			cout << "Number " << (i + 1) << ": ";//i+1 avoids off by one error
			cin >> digit;

			// Input validation:
			if (digit < 0 || digit > 9)
			{
				cout << "Invalid number.\n"
					<< "Pick a number in the range of 0 to 9.\n";
			}
		} while (digit < 0 || digit > 9);

		player[i] = digit;
	}

	// Compare the corresponding elements in the two arrays and
	// count how many digits match.
	for (int i = 0; i < 5; i++)
	{
		if (winningDigits[i] == player[i])
			match++;
	} 

	// Display winning digits
	cout << "Winning digits : ";
	for (int i = 0; i < 5; i++)
	{
		cout << winningDigits[i] << " ";
	}
	cout << endl;

	// Display player's digits
	cout << "player digits  : ";
	for (int i = 0; i < 5; i++)
	{
		cout << player[i] << " ";
	}
	cout << endl;

	// Display number of matching digits
	cout << "Matching digits are: ";
	int count = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int n = 0; n < 5; n++)
		{
			if (winningDigits[i] == player[n])
			{
				count += 1;
				cout << player[n] << " ";
			}
		}

	}
	return 0;
}