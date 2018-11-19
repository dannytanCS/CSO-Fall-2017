int check(int x) {
	long i = 1;
	while (x != 0) {
		i += x;
		x -= 1;
	}
	return i;
}

int count(int x) {
	int y = 0;
	while ( x != 0) {
		int z = x;
		z &= 1;
		y <<= z;
		x >>= 1;
	}
	return y;
}


unsigned int f5 (unsigned int x) {
	int y = x;
	if ( x > 5) {
		y += y;
		y += x;
	}
	else {
		switch (x) {
			y = x;
			y >>= 2;
			case 1:
				y = x;
				y <<= 2;
				break;
			case 2:
				y = x;
				int z = y;
				break;
			case 3:
				x = y;
				y = 0;
				y = check(x);
				break;
			case 4:
				x = y;
				y = 0;
				y = count(x);
				break;
			case 5:
				y = 7;
				break;
			default:
				break;
		}
	}
	return y;
}

