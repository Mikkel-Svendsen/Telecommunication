
// note that we use an arduino mega

/*
Exercise 13
Questions:

 * 13a:
   One would get the memory address for the variable the pointer points to.

 * 13b:
   It changes to something random, because the array is only 5 ints long. Each of the ints has its own memory address and spot in the
   memory. The address the pointer points to is incremented each pass in the loop, which means, that after 5 times, the pointer points
   to an address in the memory, which the array does not inhabit, and therefore we do not know what is in that memory address.
   Random values are stored there.

 * 13c:
   See code.
   

 * 13d:
   See answer 13b.

 * 13e:
   See code.

*/

int a[5] = { 9, 2, 42, 5, 8 };
int b = 24;
int *pointer = &a[0];
int *pointerB = &b;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  *pointerB = 45;
  Serial.print("The value of integer b: ");
  Serial.println(b);

  swap(pointer, pointerB);
  Serial.print("Pointer value: ");
  Serial.println(*pointer);
  Serial.print("PointerB value: ");
  Serial.println(*pointerB);

}

void loop() {
  // loop code here
  Serial.print("Address of pointer is ");
  Serial.print((unsigned int)pointer, HEX);
  Serial.println();
  Serial.print("Value of pointer is ");
  Serial.print(*pointer);
  Serial.println();
  pointer++;
  delay(3000);
}



void swap (int *pointer_a, int *pointer_b) {
  // This function swaps two values of pointers with each other.
  int tempA = *pointer_a;
  int tempB = *pointer_b;

  *pointer_a = tempB;
  *pointer_b = tempA;
}
