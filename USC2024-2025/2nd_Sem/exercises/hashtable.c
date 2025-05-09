#include <stdio.h>
#include <windows.h>
 #define SIZE 10

typedef struct Node{
    //int *key;
    int value;
    struct Node* next;
}Node;

//structure for the hashTable
typedef struct hashTable{
    struct Node*array[SIZE];
}hashTable;

//creating a hash table 
hashTable* hashTable_Create(){
    //malloc shit
    hashTable *new_Hashtable = (hashTable* ) malloc(sizeof(hashTable));
    //making every index in the array NULL
    for(int i = 0; i < SIZE; i++){
            new_Hashtable->array[i] = NULL;
    }
    //return the hashtable
    return;
}

//creating newNode 
Node* newNode(int value){
    //more malloc shit
    Node* newNode = (Node*)malloc(sizeof(Node));

    //making the value asked the value inside of the new node
    newNode->value = value;
    newNode->next = NULL;

    return newNode;
}

//fuction to create the hash key aka to know where to put it aka the index to put it in aka the linklist shit 
int hash(int Value){
    int key = Value % SIZE;
    return key; 
}

//inserting in the hash table
void insert(hashTable** hashTable ,int index,int value) { // double pointer storing two adresses one of the table and another of the pointer
    
    //base case checking if the index is still NULL if so then create new node and make it that
    if ((*hashTable)->array[index] == NULL){
        (*hashTable)->array[index] = newNode(value); 
        return;
    }
    
    
    
    //assuming that the node already has an index
    Node * temp = (*hashTable)->array[index];

    //check if temp-next is NULL if it isnt then move temp to the pointer_next of the NODE
    while(temp->next != NULL){
        temp = temp->next; //keep checking until its NULL rahhh
    }

    //then once its already pointing to NULL then make the pointer_next be the newNode you just created yippe
    temp->next = newNode(value);

       // temp->next = newNode(value);

}

void display(hashTable *hashTable){
    //*: .｡. o(≧▽≦)o .｡.:*☆
    
    //make a for loop to sift thru the array 
    for(int i = 0; i < SIZE; i++){
        //just making a temp assuming that the table has stuff inside of it
        Node * temp = hashTable->array[i];

        //making it look clean display what index were in right now 
        printf("ARRAY AT [%d] : ",i);    

        // if temp does not equal to NULL then print the value inside the node then move to the next one 
        while(temp != NULL){
            printf("[%d]->",temp->value);
            temp = temp->next; //move to the next one so that you can check again if its still not pointing to null
        }
        //make the last thing NULL always just to make it more understandable
        printf("[NULL]\n");
    }
}


void search(hashTable* hashTable,int value){
    //get hash key index shit 
    int index = hash(value);
    
    //use temp to make life easier
    Node * temp = hashTable->array[index];
    
    //while temp is not equals to NULL then check if value is equals to the value inside of the node 
    while(temp != NULL){
        if(temp->value == value){
            //if its the values match then it will say its been found
            printf("\n[%d] IS FOUND\n",value);
            return;    
        }
        //if not then the while loop continues until it reaches NULL or its found
        temp = temp->next;
    }
    //yea if its not found yk 
    printf("\n[%d] NOT FOUND\n",value);
}

//double pointer again because were chainging the values inside of the hashTable
void delete(hashTable** hashTable,int value){
    //find the hash index key shit again 😤😞😭
    int index = hash(value);

    //make a temp to make my life easier 
    Node * temp = (*hashTable)->array[index];
    //make a duplicate of temp for making it the prev
    Node * prev = temp; 
    
    //if the index is still NULL then well yea its WRONG 
    if((*hashTable)->array[index] == NULL){
        printf("NOTHING TO BE SEEN HERE (⓿_⓿)\n");
        return;
    }
    
    //if first node happens to be the value then
    if(temp->value == value ){
        (*hashTable)->array[index] = temp->next; //we make the index point to the next node 
        free(temp); //then free
        return;
    }
    
    //if inbetween or last
    while(temp != NULL){ //while its not null were gonna sift thru the linked list
        if(temp->value == value){ // check if the values match 
            prev->next = temp->next;  //if it does then make the pointer -> next go to the node after the one we just deleted
            //think of it as if it skiped it like its pointing infornt of it now so the one we just deleted is lonely and nobody loves him
            //since nobody is pointing at him
            free(temp);
            return;
        }
        //make prev equls to current temp
        prev = temp;
        //now make temp move up in the world aka to the next node hahha 🫠
        temp = temp->next;
    }

}
int main(){
    hashTable *THE_ONLY_hashTable = hashTable_Create();
    
    int a = 10;
    int b = 20;
    int c = 30;
    int d = 25;

    
    //inserting the values into the array  
    insert(&THE_ONLY_hashTable,hash(a),a);
    printf("\nSTART\n");
    display(THE_ONLY_hashTable);
    insert(&THE_ONLY_hashTable,hash(b),b);
    printf("\n PRINTING AFTER\n");
    display(THE_ONLY_hashTable);
    insert(&THE_ONLY_hashTable,hash(c),c);
    printf("\n PRINTING AFTER\n");
    display(THE_ONLY_hashTable);
    insert(&THE_ONLY_hashTable,hash(d),d);
    printf("\n PRINTING AFTER\n");
    display(THE_ONLY_hashTable);

    //searching for the values
    search(THE_ONLY_hashTable,15);
    search(THE_ONLY_hashTable,100);

    //deletion
    delete(&THE_ONLY_hashTable,b);
    printf("\nafter deleting\n");
    display(THE_ONLY_hashTable);
}