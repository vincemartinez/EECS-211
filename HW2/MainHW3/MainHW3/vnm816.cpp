#include <iostream>
using namespace std;

#define MAX_NUMBER_OF_PRIMES 20

/**
*  Checks to see if a number is prime.
*
*  @param pr   an array of known prime numbers in ascending order
*  @param nump the number of primes stored in the pr array
*  @param x    the number we are checking
*
*  @return returns 0 if x is not prime. returns 1 if x is prime. returns -1 if
*          we don't have enough primes in our array to determine if x is prime
*/
int isPrime(int pr[], int nump, int x) {
	//write your code here
	int i = 0;
	
	if (x <= 0){
		return(0);
	}

	for (i = 0; i < nump; i++) {

		if (x%pr[i]==0) {
			return(0);
		}

		else if (pr[i] * pr[i] > x) {
			return(1);
		}

		else continue;
	}

	return -1;
}

/**
*  Generates and populates the prime number array, stopping once we reach
*  MAX_NUMBER_OF_PRIMES primes.
*
*  @param pr the initial prime number array
*  @param nump the number of primes stored in the pr array
*/
void genPrimes(int pr[], int nump) {
	//write your code here
	int j = 8;

	while (nump < MAX_NUMBER_OF_PRIMES) {

		if (isPrime(pr, nump, j) == 1) {
			//get factors
			pr[nump] = j;
			nump++;
			j++;
		}

		else if (isPrime(pr, nump, j) == 0) {
			j++;
		}

		else if (isPrime(pr, nump, j) == -1){
			cout << "Couldn't determine the primality of " << j << endl;
		}

	}

	cout << "Primes generated." << endl;

	return;
}

/**
*  Computes the prime factors for the fourth input, x.
*
*  @param pr an array of prime numbers
*  @param pf an array where we'll store the prime factors of x
*  @param nump the number of primes stored in the pr array
*  @param x  the number we want to factor
*/
void genPrimeFactors(int pr[], int pf[], int nump, int x) {
	//write your code here

	int k;
	int count;
	int div;
	int div_count;


	for (k = nump - 1; k >= 0; k--) {

		div=0;
		div_count=0;

		if (x%pr[k] == 0) {

				div = x / pr[k];
				div_count = 1;

				while (div%pr[k] == 0) {
					div = div / pr[k];
					div_count++;
				}

				count = pow(pr[k], div_count);
				pf[k] = div_count;
				x = x / count;

		}

		else pf[k] = 0;

		cout << pf[k];
	}

	return;
}

/**
*  Displays the prime factors of x, previously calculated.
*
*  @param pr the array of prime numbers
*  @param pf the array representing the prime factors of x
*  @param nump the number of primes stored in the pr array
*  @param x  the number that we factored
*/
void displayPrimeFactors(int pr[], int pf[], int nump, int x) {
	//write your code here
	return;
}

int main() {
	//the provided main function shows how to test your functions
	//you should not change any code inside the main function

	int primes[MAX_NUMBER_OF_PRIMES] = {}; //create an array for primes and allocate
	//enough space for MAX_NUMBER_OF_PRIMES
	int primeFactors[MAX_NUMBER_OF_PRIMES] = {}; //an array to store the prime
	//    factors of a number once necessary
	int numberOfPrimes; //stores the number of primes currently held in the
	//    primes array

	// Set the first four primes and numberOfPrimes
	primes[0] = 2;
	primes[1] = 3;
	primes[2] = 5;
	primes[3] = 7;
	numberOfPrimes = 4;

	// Quick test of isPrime function - one test for each type of answer
	//13 is prime, so should print "13 is prime"
	int test = isPrime(primes, numberOfPrimes, 13);
	if (test == 1)      cout << "13 is prime.\n\n";
	else if (test == 0) cout << "13 is not prime.\n\n";
	else             cout << "Can't tell if 13 is prime or not.\n\n";

	//47 is prime, so should print "47 is prime"
	test = isPrime(primes, numberOfPrimes, 47);
	if (test == 1)      cout << "47 is prime.\n\n";
	else if (test == 0) cout << "47 is not prime.\n\n";
	else             cout << "Can't tell if 47 is prime or not.\n\n";

	//49 is not prime, so should print "49 is not prime"
	test = isPrime(primes, numberOfPrimes, 49);
	if (test == 1)      cout << "49 is prime.\n\n";
	else if (test == 0) cout << "49 is not prime.\n\n";
	else             cout << "Can't tell if 49 is prime or not.\n\n";

	//we can't tell if 169 is prime because 169 > 7*7
	test = isPrime(primes, numberOfPrimes, 169);
	if (test == 1)      cout << "169 is prime.\n\n";
	else if (test == 0) cout << "169 is not prime.\n\n";
	else             cout << "Can't tell if 169 is prime or not.\n\n";

	// Generate the rest of the primes and display
	genPrimes(primes, numberOfPrimes);
	numberOfPrimes = MAX_NUMBER_OF_PRIMES;
	for (int j = 0; j<MAX_NUMBER_OF_PRIMES; j++)
		cout << "The " << j << "th prime is " << primes[j] << "\n";
	cout << "\n\n";

	//  Test genPrimeFactors and displayPrimeFactors
	//genPrimeFactors(primes, primeFactors, numberOfPrimes, 98);
	//displayPrimeFactors(primes, primeFactors, numberOfPrimes, 98);
	//genPrimeFactors(primes, primeFactors, numberOfPrimes, 5043);
	//displayPrimeFactors(primes, primeFactors, numberOfPrimes, 5043);
	//genPrimeFactors(primes, primeFactors, numberOfPrimes, 256);
	//displayPrimeFactors(primes, primeFactors, numberOfPrimes, 256);
	//genPrimeFactors(primes, primeFactors, numberOfPrimes, 98765);
	//displayPrimeFactors(primes, primeFactors, numberOfPrimes, 98765);
	
	return 0;
}

