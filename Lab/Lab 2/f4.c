char f4(unsigned int i)
{
	char  x = i;
    if ( i <= 10) {
		x += 64;
	}
	else if ( 10 < i <= 15 ) {
		x += 96;
	}
	else {
		 x = 65;	
	}
  	return x;
}
