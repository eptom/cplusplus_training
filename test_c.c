#include<stdio.h>
int main()
{
	const int a;   // LINE 4			// w c const nie musi byc zainicjalizowany
	
	int new = 5;  // new is a keyword in C++, but not in C
    printf("%d", new);
    
	int const j = 20;
    /* The below assignment is invalid in C++, results in error
       In C, the compiler *may* throw a warning, but casting is
       implicitly allowed */
    int *ptr = &j;  // A normal pointer points to const	
    printf("*ptr: %d\n", *ptr);
    
   foo(); // foo() is called before its declaration/definition
} 
 
int foo()
{
   printf("Hello");
   return 0; 
}
