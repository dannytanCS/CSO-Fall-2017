
/*
 * IMPORTANT: WRITE YOUR NAME AND NetID BELOW.
 * 
 * Last Name: Tan 
 * First Name:  Danny
 * Netid: dt1462
 * 
 * You will do your project in this file only.
 * Do not change function delarations. However, feel free to add new functions if you want.
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/* Function declarations: do not change that, but you may add your own functions */
void arrange(int *, int);
void find_fibonacci(int, int);
void flipping(unsigned int);
void file_histogram(char *);
void file2upper(char *);
void file_encrypt(char *);


/* Add here function declarations of your own, if any. */
void parition( int* array, int low, int high);
void quickSort(int* array, int low, int high);

/*********************************************************************************/

/* 
 * Do  NOT change anything in main function 
 */
int main(int argc, char * argv[])
{
  int option = 0;
  int i, j;
  int * list;
  
  if(argc < 2 )
  {
     fprintf(stderr,"Usage: lab1 num [input]\n");
     fprintf(stderr,"num: 1, 2, 3, 4, 5, or 6\n");
     exit(1);
  }
  
  option = atoi(argv[1]);
  
  switch(option)
  {
    case 1: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 1 num\n");
	      fprintf(stderr,"num: number of elements of the array to be arranged\n");
	      exit(1);
	    }
	    j = atoi(argv[2]);
	    list = (int *)malloc(j*sizeof(int));
	    if(!list)
	    {
	      fprintf(stderr,"Cannot allocate list in option 1\n");
	      exit(1);
	    }
	    
	    /* Gnerate random numbers in the range [0, 100) */
	    for(i = 0; i < j; i++)
	      list[i] = rand()% 100;
	    
	    /* Print the unsorted array */
	    printf("The original array:\n");
	    for(i = 0; i < j; i++) 
	      printf("%d ", list[i]);
	    printf("\n");
	    
	    printf("The arranged array:\n");
	    arrange(list, j);
	    
	    break;
	    
	    
    case 2: if(argc != 4)
	    {
	      fprintf(stderr,"Usage: lab1 2 x y\n");
	      fprintf(stderr,"x and y: positive integers and x < y and y < 1 million\n");
	      exit(1);
	    }
	    i = atoi(argv[2]);
	    j = atoi(argv[3]);
	    
	    find_fibonacci(i, j);
	    
	    break;

	    
    case 3: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 3 num\n");
	      fprintf(stderr,"num: unsigned intger number\n");
	      exit(1);
	    }
	    
	    flipping( atof(argv[2]));
	    
	    break; 
	    
	    
    case 4: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 4 filename\n");
	      exit(1);
	    }
	    
	    file_histogram(argv[2]);
	    
	    break;

	    
    case 5: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 5 filename\n");
	      exit(1);
	    } 
	    
	    file2upper(argv[2]);
	    
	    break;

	    
    case 6: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 46filename\n");
	      exit(1);
	    }
	    
	    file_encrypt(argv[2]);
	    
	    break;	      
	    
    default: fprintf(stderr, "You entered an invalid option!\n");
	     exit(1);
  }
  
  return 0;
}

/******* Start filling the blanks from here and add any extra functions you want, if any *****/

//quicksort the array in O(n log n)

int partition (int* array, int low, int high) {
	int pivot = array[high];    
	int i = (low - 1); 
	
	for (int j = low; j <= high - 1; j++) {
	// compare the number to the pivot to place it before or after the pivot
		if (array[j] <= pivot){
			i++;   
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	int temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	
	return (i + 1);
}
	
//function for quick sort
void quickSort(int* array, int low, int high) {
	if (low < high) {
		//the current index or the pivot is correctly placed
		int index = partition(array, low, high);
		quickSort(array, low, index - 1);
		quickSort(array, index + 1, high);
	}
}

/*
 * Part 1:
 * In this function, you are given two inputs:
 * inputs: 
 * 	an array of int list[] 
 * 	The number of elements in that array: num
 * You need to put the even numbers first (if any), sorted in ascending order, followed
 * by the odd numbers (if any) sorted in ascending order too.
 * Example: a list of 5 elements: 5 4 3 2 1 
 * The output will be: 2 4 1 3 5 
 * Finally, print the array on the screen.
 * */
void arrange(int *list, int num)
{	
	//sort the array
	quickSort(&list[0], 0, num -1);

	//print out the even  numbers first
	for (int i = 0; i < num; i ++) {
		if ((list[i] & 1) == 0 ) {
			printf("%d ", list[i]);
		}
	}

	//then print out the odd numbers
	for (int i = 0; i < num; i++ ) {
		if ((list[i] & 1) == 1) {
			printf("%d ", list[i]); 
		}
	}
	printf("\n");
}


/*********************************************************************************/

/* 
 * Part 2:
 * In this part, you are given two positive integer, x and y, larger than 0.
 * You need to print all the Fibonacci numbers between x and y (NOT including x and y themselves), if any.
 */
void find_fibonacci(int x, int y)
{
	int a = 0, b = 1, sum;
	//loop through until it is bigger than y
	while ( b < y) {
		//if it is bigger than x, then print the fib
		if (b > x) {
			printf("%d ", b); 
		}
		//next fibonacci
		sum = a+b;
		//switch the first to the second
		a = b;
		b = sum;
	}
	printf("\n");
}


/*********************************************************************************/

/*
 * Part 3:
 * Given an unsigned integer (so has values of 0 and up), print on the screen 
 * the flipping of that number.
 * That is, if the number given is: 1234  then you print: 4321
 */

//flipping recursively
void flipping(unsigned int num)
{	
	//base case: if less than 10, just print the number
	if (num < 10) {
		printf ("%d \n", num);
		return;	
	}
 	int remainder;
	remainder = num % 10;
	//we print first, since we want to truncate from the back
	printf ("%d", remainder);
	flipping(num / 10);
}

/*********************************************************************************/

/*
 * Part 4
 * The input is a filename.
 * The filename contains a string of characters (can be upper case letters, lower case letters, numbers, ...).
 * The output is a histogram of the file printed on the screen ONLY for lower case letters.
 * Example: 
 * The input file in.txt contains:  a1aaAbBBb709bbc
 * The output will be:
 * a: 3
 * b: 4
 * c: 1
 * .... and so one
 * The file can contain any characters, not necessarily only lower case characters.
 */
void file_histogram(char *filename)
{
	//structure of a character with its count
	typedef struct character {
		char letter;
		int count;
	} Character;
	
	char chara;
	//store 26 characters;
	Character* charList = (Character*) malloc (26 * sizeof(Character));

  	FILE* filePtr = fopen(filename, "r");
  	if (filePtr == NULL) {
		printf ("File is not found. \n");
		return;
	}

	//put the default values in the list
	for (int i =0; i < 26; i++) {
		char c = 'a' + i;
		charList[i].letter = c;
		charList[i].count = 0;
	}

	//loop through the file
	while (fscanf( filePtr, "%c", &chara) == 1) {
		//check if the character is between a and z
		if ( chara >= 'a' && chara <= 'z') {
			//increase the count of the character by 1 if found
			charList[chara - 'a'].count += 1;
 		} 
	}

	//print out the letter with its count
	for (int i = 0; i < 26; i ++) {
		printf("%c: %d \n", charList[i].letter, charList[i].count);
	}

	//free memory and close file
	free(charList);
	fclose(filePtr);
}

/*********************************************************************************/

/* 
 * Part 5:
 * Input: filename
 * Output:filenameCAPITAL
 * The output files contains the same characters as the input file but in upper case.
 * The input file will ONLY contain lower case letters and no spaces.
 * If the input filename is: mmmm 
 * The output filename is: mmmmCAPITAL
 */
void file2upper(char *filename)
{
	char chara;

	FILE* filePtr = fopen(filename, "r");
  	if (filePtr == NULL) {
		printf ("File is not found. \n");
		return;
	}

	//find the length of the filename
	int length = sizeof(filename)/ sizeof(filename[0]);

	//allocate the memory for length of the filename with "CAPITAL" in it
	char* outputFile = (char*) malloc(length +7);

	//store the filename without ".txt\o"
	for (int i = 0; i < length - 6; i++ ) {
		outputFile[i] = filename[i];
	}

	char* cap = "CAPITAL.txt";
	
	//adds "CAPITAL.txt" to the end of the filename
	for (int i = 0; i < 12; i ++ ) {
		outputFile[length - 6 + i] = cap[i];
	}

	//write to the output file
 	FILE* file2Ptr =  fopen( outputFile, "w");

	//loop through input file
	while (fscanf( filePtr, "%c", &chara) == 1) {
		//if it is lowercase, change it to upper case
		if ( chara >= 'a' && chara <= 'z') {
			chara = chara - ("a" - "A");
 		} 	
		//write it to the output file
		fprintf(file2Ptr, "%c", chara);
	}
	
	//close both files
	fclose(filePtr);
	fclose(file2Ptr);
	free(outputFile);
}

/*********************************************************************************/

/*
 * Part 6:
 * In that last part, you will learn to implement a very simple encryption.
 * Given a file that contains a series of lower case charaters (may be separated by white space),
 * replace all non-white space with the lower case letter that exists 3 letters before, in a circular way.
 * For example: 
 * e will be replaced with b
 * d will be replaced with a 
 * c will be replaced with z  <--- circular
 * b will be replaced with y  <--- circular
 * and white spaces will be left unchanged.
 * Print the output on the screen.
 */
void file_encrypt(char * filename)
{
	char chara;
	
	FILE* filePtr = fopen(filename, "r");
  	if (filePtr == NULL) {
		printf ("File is not found. \n");
		return;
	}

	//loop through the file
	while (fscanf( filePtr, "%c", &chara) == 1) {
		//check whether it is lowercase
		if ( chara >= 'a' && chara <= 'z') {
			//if it is less than c, loops back
			if (chara <= 'c') {
				chara += 23;
			}
			//print 3 letters before
			else {
				chara -= 3;
			}
		}
		//if it is not lowercase print as is
		printf("%c", chara);
	}
	printf("\n");

	//close file
	fclose(filePtr);
}