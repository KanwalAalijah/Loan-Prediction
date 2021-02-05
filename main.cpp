#include <math.h>
#include <iostream>
#include <thread>
#include <future>
#include <sys/time.h>
#include "header.h"
#include <pthread.h> 
#include "is_prime.cpp"



int main(int argc, char* argv[])
{
  /* if (argc < 2) {
    fprintf(stderr, "Usage: %s num1 [num2 num3 ...]\n", argv[0]);
    return 1;
  } */ 

  struct timeval t0, t1;
std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< std::endl << std::endl;

  std::cout << "Current number of threads = " << numOfThreads << std::endl << std::endl;
std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< std::endl << std::endl;

  for( int i = 1; i < argc; ++i )
  { 
    long long num = strtoll(argv[i], NULL, 0);
    long long max = (long long) (sqrt( (double)num ) + 1);  //checking for square root of the number
    std::cout << "Sequential isPrime for " << num << std::endl;  
    gettimeofday( &t0, NULL ); 
    bool answer = isPrime( num, 3, max );
    gettimeofday( &t1, NULL ); // finish
    double seqTime = t1.tv_sec - t0.tv_sec +
                    (t1.tv_usec - t0.tv_usec) / 1000000.0;
    std::cout << num << (answer == true ? " is " : " is not ")
              << "prime" << std::endl;
    std::cout << "Time take for sequential is prime " << seqTime << " sec" << std::endl << std::endl;
std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< std::endl << std::endl;

    std::cout << "Async-get parallel isPrime for " << num << std::endl;  ////doing multithreading here
int partitionsize = max/numOfThreads;
std::future<bool> results[numOfThreads - 1];

    bool answers[numOfThreads];

    gettimeofday( &t0, NULL ); // start


    int j;
    for ( j = 0; j < numOfThreads - 1; ++j )
    {
      results[j] = std::async( std::launch::async, isPrime, num,
	  j*partitionsize, (j*partitionsize) + partitionsize );
    }

    
    answers[j] = isPrime(num,((numOfThreads-1)* partitionsize),max);
    for ( j = 0; j < numOfThreads - 1; ++j )
    {
      answers[j] = results[j].get();
    } 

    answer = true;

    for ( j = 0; j < numOfThreads; ++j )
    {
        
		if (!answers[j]){
		    answer = false;
			break;
		}
    }

    gettimeofday( &t1, NULL ); 
double parallelTime = t1.tv_sec - t0.tv_sec + 
                         (t1.tv_usec - t0.tv_usec) / 1000000.0;

    std::cout << num << (answer == true ? " is " : " is not ")
              << "prime" << std::endl;

    std::cout << "Time Taken with multi-threading " << parallelTime 
              << " sec" << std::endl << std::endl;
double speedup=(double) seqTime / parallelTime;
std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< std::endl << std::endl;
    std::cout << "Speed-up: " << speedup 
              << std::endl << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< std::endl << std::endl;
 	if(speedup>1)
{ std::cout<<"Performance of parallel mode is better because speedup is greater then 1"<< std::endl << std::endl;}
	if (speedup == 1)
{ std::cout<<"Performance of both the modes are almost equal because speedup is equal to 1"<< std::endl << std::endl;}

	if(speedup <1)
{ std::cout<<"Performance of sequential mode is better becuase speedup is < 1 "<< std::endl << std::endl;}
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< std::endl << std::endl;
  }

  return 0;
}

