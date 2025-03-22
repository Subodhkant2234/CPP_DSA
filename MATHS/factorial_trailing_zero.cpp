int trailingZeroesInFactorial(int n) {
	int count = 0; // Initialize count of trailing zeroes in factorial
    // Loop to divide n by powers of 5 and add to the count
	while (n > 0) {
		n /= 5;// Factor out the 5's, as 10 is the product of 2 and 5,
		// and there are always more 2's than 5's in factorial.
        count += n;  // Accumulate the number of 5's in all factors of n
	}
	return count;
}
