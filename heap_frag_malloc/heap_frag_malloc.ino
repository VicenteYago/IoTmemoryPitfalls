
// In this example we will fragment the heap space triggering a memory exception code:
// "Exception 29: StoreProhibited: A store referenced a page mapped with an attribute that does not permit stores"
// This error confirms that the heap has overflowed the stack.
// But unlike the heap-depletion.ino output, the heap is indeed fragmented.

# define MAX 1024 // string buffer
# define L 100 // maximun size of heap strings


char **arrayChar = (char **) malloc(MAX*sizeof(char*));

void setup() {
  Serial.begin(9600);
  delay(5000);
  Serial.println();
  Serial.println("Welcome to abusing the memory!. Sorry ESP8266 its not personal ;)");
}

void loop() {

  int r_pos  = rand() % MAX;
  int r_len = rand() % MAX + 1;

  if (arrayChar[r_pos] != NULL){
    free(arrayChar[r_pos]);
  } 
   arrayChar[r_pos] = (char*) malloc(r_len*sizeof(char));

  Serial.print(" > ESP.getFreeHeap()=");
  Serial.print(ESP.getFreeHeap());
  Serial.print(", ");
  Serial.print(" > ESP.getHeapFragmentation()=");
  Serial.print(ESP.getHeapFragmentation());
  Serial.print("%");
  Serial.println(".");
 }
