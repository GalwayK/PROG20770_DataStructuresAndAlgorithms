 // Using the continue statement in a for statement.
    #include <stdio.h>
 
    // function main begins program execution
    int main( void )
    {
       unsigned int x; // counter
 
      // loop 10 times
      for ( x = 1; x <= 10; ++x ) {

         // if x is 5, continue with next iteration of loop
         if ( x == 5 ) {
            continue; // skip remaining code in loop body
         } // end if

         printf( "%u ", x ); // display value of x
      } // end for

      puts( "\nUsed continue to skip printing the value 5" );
  } // end function main

