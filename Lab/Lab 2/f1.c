int f1(int x)
{
  	if ( x <= 15) {
		x >>= 1;
		x += 7;
	}
	else {
		int z = x << 3;
		x <<= 2;
		z += x;
		x +=x;
		x += z;
	}
	return x;
  	
}