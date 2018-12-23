#include <stdio.h>
#include <math.h>
#include <string.h>
/*
Assignment 2
<base2base>

Name: Simon Basescu
Email: sbasescu@middlebury.edu
Date: 9/26/18
Collaborators: Lillie Atkins

To compile: gcc hw2_base2base.c -o hw2_base2base -lm
To run: ./hw2_base2base int_num int_currentbase int_targetbase
        The int_num argument should be the value of a number represented
        in the base given by int_currentbase. The int_targetbase
        will be the base into which the number gets converted to. 
*/
/*
Converts a string representation of a number in its given base to its
base 10 (integer) value. This fuction works by looping through the
given string representation of a number, and for each digit it checks
if it is upper case or a digit, otherwise it prints out an error message.
If the input is valid, it then turns the character into an integer using
the correct ascii values, and multiplies that value by the current base
to the power of its position in the string (distance from the right) which
is kept in the int power variable which gets incremented each time
the loop restarts.
*/
int BasetoInt (char * str, int curbase) {
  int length = strlen(str);
  int power = 0;
  int num = 0;
  for (int i = length - 1; i >= 0; i--) {
    if (65 <= str[i] && str[i] <= 90) { //if char is A - Z, converts to decimal
      int val;
      val = str[i] - 55;
      num += (val * pow(curbase, power));
      power++;
    }
    else if (48 <= str[i] && str[i] <= 57) { //if char is 0 - 9
      int val;
      val = str[i] - 48;
      num += (val * pow(curbase, power));
      power++;
    }
    else {
      printf("Error, please enter only positive integers and upper case letters in your input");
      return 0;
    }
  }
  return num;
}

/*
This function takes the first parameter which is a number in base 10 and converts
it into a representation of the number in the target base given by the second parameter.
It works by first finding how many digits the integer will need to be
represented in the target base. Then it creates a character array of sufficient
size and enters a while loop that continually divides the number by the targetbase
and keeps track of the remainders until the number cannot be divided anymore.
Then the remainders are printed off backwards, giving the integer's representation
in the target base.

*/
void InttoBase (int number, int tarbase) {
  int length = 0;
  int num = number;
  //the following while loop will tell how many characters will be
  //in the output so sufficient size can be allocated in an array
  //which will then be looped through backwards and printed
  while (num > 0) {
    num = num / tarbase;
    length+=1;
  }

  char characters[length + 1]; //includes null character
  int index = 0;

  while (number > 0) {
    int temp = number % tarbase;
    if (temp > 9) { //if remainder is greater than 9 we must print hexadecimal
      characters[index] = temp + 55;
      index++;
    }
    else {//if remainder is less than 9
      characters[index] = temp + 48;
      index++;
    }
    number = number / tarbase;
  }

  for (int i = index; i >= 0; i--) {
    printf("%c", characters[i]);
  }
  printf("\n");
}

int main(int argc, char * argv[]) {


  if (argc == 4) {
    int currentbase = BasetoInt(argv[2], 10); //converts argument to integer
    int decimal = BasetoInt(argv[1], currentbase);
    int targetbase = BasetoInt(argv[3], 10); //converts argument to integer
    //printf("%d ", decimal);
    InttoBase(decimal, targetbase); //prints out string representation of number in desired base
  }

  else {
    printf("Error, please enter three arguments");
  }



//  int num, curbase, tarbase;
//  num = argv[1];
//  curbase = argv[2];
//  tarbase = argv[3];

}
