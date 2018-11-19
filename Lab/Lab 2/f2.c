long f2(int x)
{
     long y = 17;
     int z = x;
	z<<= 3;
	z -= x;
	
	for (int i = 0;  i < z; i ++ ) {
		y += i; 
	}
	return y;
}