/*  Exercise 14

  14a.

    Each variable in a struct is known as a member. 
    For example and int and a char inside a struct are members of said struct

  14b.
    1. For accessing the value of a member of the struct.
    2. The same as 1.
    3. This would result in an error. If you tried to write data, 
       it would write the data to a wrong memory location.
    4. This is for accessing a member when you have a pointer to the structure.


*/

//14c.
struct Animal {
  char *family;
  float weight;
  int ID;
  bool alive;
  char *placeOfCapture;
};

void setup() {

  // 14d.
  struct Animal tiger;
  tiger.family = "cat";
  tiger.weight = 100.0;
  tiger.ID = 1;
  tiger.alive = false;
  tiger.placeOfCapture = "Africa";

  struct Animal crow;
  crow.family = "bird";
  crow.weight = 0.6;
  crow.ID = 2;
  crow.alive = true;
  crow.placeOfCapture = "Denmark";

  //Initialize serial
  Serial.begin(9600);

  printAnimal(tiger);
  printAnimal(crow);

  swapWeight(&tiger, &crow);

}

void loop() {
  // put your main code here, to run repeatedly:

}

//14e.
//Print the information of a specific Animal struct.
void printAnimal (struct Animal a){
  Serial.print("ID: ");
  Serial.println(a.ID);
  
  Serial.print("Family: ");
  Serial.println(a.family);
  
  Serial.print("Weight: ");
  Serial.println(a.weight);
  
  Serial.print("Alive: ");
  if(a.alive)
    Serial.println("Yes");
  else
    Serial.println("No");
  
  Serial.print("Place of capture: ");
  Serial.println(a.placeOfCapture);
}

//14f.
//Swaps the weight of two Animal structs
void swapWeight (struct Animal *a, struct Animal *b){
  Animal temp = *a;
  a->weight = b->weight;
  b->weight = temp.weight;

  Serial.print("a weight: ");
  Serial.println(a->weight);
  Serial.print("b weight: ");
  Serial.println(b->weight);
}