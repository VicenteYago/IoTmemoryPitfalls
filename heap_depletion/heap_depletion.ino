
// In this example we will consume all the heap space triggering a memory exception code:
// Exception 29: StoreProhibited: A store referenced a page mapped with an attribute that does not permit stores
// This error confirms that the heap has overflowed the stack.
// As no single block of memory is freed, fragmentation is minimal.

# define L 1024
# define MAX 1024
s
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

   arrayChar[r_pos] = (char*) malloc(r_len*sizeof(char));
    
    Serial.print(" > ESP.getFreeHeap()=");
    Serial.print(ESP.getFreeHeap());
    Serial.print(", ");
    Serial.print(" > ESP.getHeapFragmentation()=");
    Serial.print(ESP.getHeapFragmentation());
    Serial.print("%");
    Serial.println(".");
 }
  
