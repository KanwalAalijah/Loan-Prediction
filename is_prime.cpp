
bool isPrime( long long n, long long lo, long long hi )
{
	if (n <= 1){
		return false;
	}
	
	if (n == 2){
		return true;
	}
	
	if (n % 2 == 0){
		return false;
	}
	
        /*The lowest base can be 3*/
	if (lo < 3){
		lo = 3;
	}
	
	if (lo % 2 == 0){
		lo = lo + 1;
	}
	
	int counter;
	for(counter = lo; counter < hi; counter+= 2){
		
		if (n % counter == 0){
			return false;
		}
			
	}
	
    return true; //number is prime if it gets here
}

