int f3(unsigned int i)
{
    int x = 0;
	while ( i != 0) {
		int y = i & 1;
		if ( y &y  != 0) {
			x += 1;	
		}
		i >>= 1;
	}
	x = -x;
	return x;	
}
