/*

Hello Shashank ,

You have to write a program to solve the following:

 

UTF-8 is probably the most common unicode encoding scheme in the world. UTF-8 is designed to retain the extremely widespread 7-bit ASCII encoding without any change. This is probably the biggest reason for UTF-8's popularity.

 

Your objective is to write a C program that reads multiple UTF-8 encoded strings from STDIN (1 string per line), count all non-ascii characters (ascii characters are with ordinal decimal 0 to 127) and print the total non-ascii character count to STDOUT (1 number per line).

Note that:

    You cannot use any wchar.h service in your program. This rule will disqualify your program even if you generate the right result.
    The UTF-8 strings supplied to you can have 1 or more whitespaces in them.
    No input string will have a character length greater than 200 (including spaces)
    You will be given multiple lines of input (1 string per line).
    Input will be limited to UTF-8 encoded strings and will not contain any garbage values.

We have attached a sample input file and a sample output file that you can use to test your program. We will test your program by compiling it on Linux and running it as follows.

 

$ gcc your_prog.c -Wall

$ ./a.out < test_cases > generated_output

$ diff -B --strip-trailing-cr generated_output correct_output

 

You can write the program on any platform (windows, linux, osx etc) as long as it is written in a portable fashion.

 

Additional Notes:

    We will ignore all extra lines, blank lines and carriage return/line feed problems, so you dont have to worry about those.
    We will run automated test cases on your program, so your program should comply to rules mentioned in the description.
    It should read each line of input file from STDIN and write each result to STDOUT.
    Do not have any extra print statements - "Enter String", "Output is", etc.
    Please run the commands that would be used to check your program against the attached sample input/output file. 

*/

#include <stdio.h>

int main()
{
    int a, na =0;
	int last_a = 0;
	int conti = 0;

    while((a=getchar())!= EOF){
		//printf("%d ", (int)a);
		// parsing chars that are not new line
		if(a != '\n'){
			// checking chars for every fall in int below 128
			if((last_a >= 128 && (0<a && a<128))|| conti == 3){
					na++;
					conti=0;
			}else if(a>=128){
				conti++;
			}else{
				conti=0;
			}
		}else{
			// if last char was non-ascii
			if(last_a >= 128){
				na++;
				conti=0;			}
			printf("%d\n", (int)na);
			na =0;
		}
		// storing the last char
		last_a=a;
	}
	// if last char before EOF was non-ascii
	if(last_a >= 128){
		na++;
	}
	printf("%d", (int)na);

   
    return 0;
}
