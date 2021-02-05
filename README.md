# Multi-Threading---IS-Prime

Determine whether a large number is prime or not, both in parallel over many threads simultaneously, and sequentially in one. The program will also record and display the execution time of the calculations using both methods, allowing you to see the relative performance of each.


Table of Contents 
---------------------------
main.cpp

	Function prototype: int main( int argc, char *argv[] );
The driver of the program. For each number entered on the command line, main calls
gettimeofday to get the start time, and then calls isPrime to run the calculations sequentially.
Upon return, gettimeofday is called again to get the end time. The time difference is then
calculated and the results of the sequential run are printed to stdout.
Next, we will partition the factor range into N separate pieces, where N = # of threads supported
by the machine (you can use the numOfThreads constant defined in the header file) and create
N - 1 new threads (the Nth thread is just main). An array of bools is then created to store the
results of the calculations for each partition and a thread is launched to work on each part of
the factor range, each calling isPrime with low (inclusive) and high (exclusive) factor arguments
that define the boundaries that each thread is operating on, and each returning its result into
the array of bools. You will have to calculate the partition size and fill in the call to isPrime()
with the appropriate arguments.
Now the results need to be combined. The program should iterate through the array of bools,
checking the values returned by each thread's call to isPrime. If any returned false, set a variable
to indicate that the number is not prime and then break out of the loop. If all parallel calls to
isPrime returned true, then the number is prime and you should set the relevant variable
accordingly. gettimeofday is called before the parallel computations begin and again after they
are completed. The time difference and the speedup are then calculated, and the results of the
parallel run are printed to stdout.
	
preprocessing.py

	Clean data to remove punctuation, numbers, white spaces and convert the text to lower case
	
k_means.py

	Tokenize and Stem Data using NLTK
	Convert words to Vector Space using TFIDF matrix
	Calculate Cosine Similarity and generate the distance matrix
	Generate Clusters using KMeans clustering algorithm
	Dimensionality reduction using MDS
	Visualization of clusters using matplotlib
	
hierarchical.py

	Tokenize and Stem Data using NLTK
	Convert words to Vector Space using TFIDF matrix
	Calculate Cosine Similarity and generate the distance matrix
	Hierarchical clustering using Ward Method
	Visualization of clusters using matplotlib
