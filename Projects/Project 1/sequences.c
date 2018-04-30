/*
*
*  Project Name: Check the Mathematics
*  Description: Computes the first 50 terms of various sequences.
*  File names: sequences.c
*  Date: Project due date   2/2/2018
*  Authors: Kevin Carman and Miguel Gonzalez Fernandez
*
*/

#include <stdio.h>

int main(){

  /*Lazy Caterer's sequence
  * Determines the maximum number of pieces that can be made with n cuts
  * Prints the maximum number of pieces made from 0 to 49 cuts*/

  double i;  //for use with the for loop
  printf("Lazy Caterer's Sequence:\n");

  //loop computes the lazy caterers sequence
  for(i = 0; i < 50; i += 1.0){
    printf("%1.0f ",((i*i+i+2)/2));
  }

  /*PrimeNumber's Sequence
  * Finds intergers that are only divisible by 1 and themselves
  * Prints the first 50 prime numbers starting from 2*/

  int j; //used in for loop as number to be tested if prime or not
  int k; //used in the nested for loop for trial by division
  int counter = 0; //counts the number of primes
  int primeChecker; //acts as a boolean to check if prime or not
  printf("\n\nPrime Numbers:\n");

  //loops check if a number is prime or not using trial by division method
  for(j = 2; counter < 50; j++){
    primeChecker = 1;
    for(k = 2; k < j; k++){
      //breaks if a number is not a prime and sets primesChecker to false
      if((j % k) == 0){
        primeChecker = 0;
        break;
      }
    }
    //prints the number and increases the counter only if it is a prime number
    if(primeChecker){
        counter++;
        printf("%d ", j);
    }
  }

/*Fibonaci sequence
* Each number is the sum of the two previous numbers starting at 1
* Prints the first 50 terms of the sequence*/

counter = 0; //counts the number of terms in the sequence
long long secondPrevious = 0; //the second previous number of the current term
long long previous = 1; //the previous number of the current term
long long sum; // sum of secondPrevious and previous
printf("\n\nFibonacci Sequence:\n1 ");

//loop sums secondPrevious and previous, outputs them, and reassigns them to the next term
while(counter < 49){
  sum = secondPrevious + previous;
  printf("%lld ", sum);
  secondPrevious = previous;
  previous = sum;
  counter++;
}

/*Collatz Stopping Times
* Find the number of operations needed before a number becomes 1
* If a number is even n/2, if a number is odd 3n+1
* Prints the number of operations for numbers 1 through 50*/

int number; //number currently being tested
int operations; //number of operations used
printf("\n\nCollatz Stopping Times:\n");

//loop dtermines the number of operations a number takes to arrive at 1
for(j = 1; j < 51; j++){
  number = j;
  operations = 0;
  while(number != 1){
    //determines if even or odd and performs the appropriate operation
    if((number % 2) == 0){
      number = number / 2;
    }else{
      number = 3 * number + 1;
    }
    operations++;
  }
  printf("%d ", operations);
}

/*Happy Numbers
* Finds if a number is happy or not by taking each of the digits, squaring them,
* them adding them together and repeating the process. A number is happy if it converges to 1.
* Prints out the first 50 happy numbers*/

int sumOfSquares; //stores the sum of the squares of the digits
int happyChecker;  //1 if a number is happy, 0 if not
counter = 0;  //reused int to count number of happy numbers found
printf("\n\nHappy Numbers:\n");

//loop determines if a number is happy or not
for(j = 1; counter < 50; j++){
  number = j;
  sumOfSquares = 0;
  happyChecker = 1;
  while(sumOfSquares != 1){
    sumOfSquares = 0;
    //determines the sum of the squares of each digit for a given number
    while(number){
      sumOfSquares += (number % 10) * (number % 10);
      number /= 10;
    }
    number = sumOfSquares;
    //all unhappy numbers will get stuck in a loop with 4, so this terminates the infinite loop
    if(number == 4){
      happyChecker = 0;
      sumOfSquares = 1;
    }
  }
  //prints happy numbers and increments counter
  if(happyChecker){
    printf("%d ", j);
    counter++;
  }
}

  return 0;
}
