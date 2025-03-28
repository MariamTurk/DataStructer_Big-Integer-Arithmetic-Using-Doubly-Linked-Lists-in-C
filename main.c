//mariam turk , 1211115 . sec :1

#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int DATA;
    struct NODE * NEXT;
    struct NODE * PREV;
};


struct LINKEDLIST{
    struct NODE * HEAD;
    struct NODE * TAIL;
};


// function to add the numbers in the linked list
struct LINKEDLIST ADDITION (struct LINKEDLIST* L1 , struct LINKEDLIST *L2){ // toe list
    struct LINKEDLIST RES; // to save the result of addition
    RES . HEAD = NULL; // make the list empty
    RES . TAIL = NULL;
    int carry = 0; // to the carry of addition
    int value = 0 ; //value of add tow nodes
    struct NODE * N1 = L1 -> TAIL; // to start add from the end of the list
    struct NODE * N2 = L2 -> TAIL;
    while(N1 != NULL || N2 != NULL || carry !=0){
        int SUM = carry;
        if (N1 != NULL){
            SUM += N1 ->DATA;
            N1=N1 ->PREV;
        }
        if (N2 != NULL){
            SUM +=N2 -> DATA;
            N2=N2 ->PREV;
        }
        carry = SUM /10; // 7+3= 10 // 10 / 10 = 1 , carry =1
        value = SUM % 10 ; //10 % 10 = 0 , value of add 7 and 3 = 0
        InsertBEGINNING(&RES,value); // insert the value in the list res
    }
    return RES;
};



//function to subtraction tow number in the linked list
struct LINKEDLIST  SUBTRACTION (struct LINKEDLIST *L1 , struct LINKEDLIST *L2){
    struct LINKEDLIST RES ;
    struct NODE * N1 = L1 -> TAIL;
    struct NODE * N2 = L2 -> TAIL;
    int BORROW = 0 ;
    int NUM =0;
    while (N1 != NULL || N2 != NULL){
        int NUM1=0 ,NUM2 =0 ;
        if(N1 != NULL){
            NUM1 = N1 -> DATA;
            N1 = N1 ->PREV;
        }
        if (N2 != NULL){
            NUM2 = N2 ->DATA;
            N2 = N2 ->PREV;
        }
        NUM = NUM1 - NUM2 - BORROW;
        if (NUM<0){
            NUM +=10;
            BORROW = 1;
        }
        else {
            BORROW = 0;
        }
        InsertBEGINNING(&RES,NUM);
    }
    return RES;
};


// function for mult to numbers in list
struct LINKEDLIST multiply(struct LINKEDLIST* list1, struct LINKEDLIST* list2) {
    struct LINKEDLIST result;
    result.HEAD = NULL;
    result.TAIL = NULL;
    int carry = 0;

    // Multiply each node of the second list by each node of the first list
    struct NODE* node2 = list2->TAIL;
    while (node2 != NULL) {
        int multiplier = node2->DATA;
        struct NODE *current1 = list1->TAIL;
        struct LINKEDLIST temp_result;
        temp_result.HEAD = NULL;
        temp_result.TAIL = NULL;
        int temp_carry = 0;

        // Multiply the current node of the second list by each node of the first list
        while (current1 != NULL) {
            int product = multiplier * current1->DATA + temp_carry;
            temp_carry = product / 10;
            product %= 10;

            InsertBEGINNING(&temp_result, product);
            current1 = current1->PREV;
        }

        // Add any remaining carry to the result list
        if (temp_carry > 0) {
            InsertBEGINNING(&temp_result, temp_carry);
        }

        // Add the temp result to the final result
        for (int i = 0; i < carry; i++) {
            InsertEND (&temp_result, 0);
        }
        result = ADDITION(&result, &temp_result);
        carry++;
        node2 = node2->PREV;
    }
    return result;
}


struct LINKEDLIST divide(struct LINKEDLIST *list,struct LINKEDLIST* list2) {

}
// to divide to number in the list




void InsertEND(struct LINKEDLIST *LIST , int D);
void InsertBEGINNING (struct LINKEDLIST* LIST , int D);
int DeletEND (struct LINKEDLIST *LIST);
int DeleteFirst(struct LINKEDLIST * LIST);
void READ_F_F(char* filename, struct LINKEDLIST* N1, struct LINKEDLIST* N2);
void WRITE_F_F(char* filename, struct LINKEDLIST RES);
void PRINT_MENU();


int main()
{
 struct LINKEDLIST N1;
    N1.HEAD = NULL;
    N1.TAIL = NULL;
    struct LINKEDLIST N2;
    N2.HEAD = NULL;
    N2.TAIL = NULL;
    READ_F_F("input.txt", &N1, &N2);
    while (1) {
        PRINT_MENU();
        int choice;
        scanf("%d", &choice);
        struct LINKEDLIST RES;
        switch (choice) {
            case 1:
                RES = ADDITION(&N1, &N2);
                printf("Result: ");
                struct NODE* node = RES.HEAD;
                while (node != NULL) {
                    printf("%d", node->DATA);
                    node = node->NEXT;
                }
                printf("\n");
                break;
            case 2:
                RES = SUBTRACTION(&N1, &N2);
                printf("Result: ");
                node = RES.HEAD;
                while (node != NULL) {
                    printf("%d", node->DATA);
                    node = node->NEXT;
                }
                printf("\n");
                break;
            case 3:
                RES = multiply(&N1, &N2);
                printf("Result: ");
              node = RES.HEAD;
                while (node != NULL) {
                    printf("%d", node->DATA);
                    node = node->NEXT;
                }
                printf("\n");
                break;
            case 4:
                RES = divide(&N1, &N2);
               printf("Result: ");
               node = RES.HEAD;

               while (node != NULL) {
                   printf("%d", node->DATA);
                   node = node->NEXT;
               }
                printf("\n");
                break;
            case 5:
                WRITE_F_F("output.txt", RES);
                printf("Result written to output file\n");
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
//function to insert the data in the ?? of the double linked list
void InsertEND(struct LINKEDLIST *LIST , int D){
    struct NODE * NEW_NODE = (struct NODE*) malloc (sizeof(struct NODE)); // to save space for it in memory (Dynamically Allocated Memory)
    NEW_NODE -> DATA = D; // insert the data in the new node that we want to add it
    NEW_NODE -> NEXT = NULL; // the next is null because it is the last node in the list
    NEW_NODE -> PREV = LIST -> TAIL; //the perv will share to the tail of list which is the pointer share in the last node in the list before add the new node
    if(LIST->TAIL == NULL){ // in case the list is empty , so the tail will be empty then the head will share to the new node
        LIST -> HEAD = NEW_NODE;
    }
    else{ // in case it is not empty
        LIST -> TAIL -> NEXT = NEW_NODE; // ???????????????????????????????
    }
    LIST -> TAIL = NEW_NODE; // make the tail share to the new node which it is the last node in the list
}


//function to insert node in the beginning
void InsertBEGINNING (struct LINKEDLIST* LIST , int D){
    struct NODE * NEW_NODE = (struct NODE*) malloc(sizeof(struct NODE));
    NEW_NODE ->DATA = D;
   NEW_NODE -> NEXT = LIST -> HEAD;
   NEW_NODE -> PREV = NULL;
    if(LIST -> HEAD == NULL){
        LIST -> TAIL = NEW_NODE;
    }
    else{
        LIST->HEAD->PREV = NEW_NODE;
    }
    LIST -> HEAD = NEW_NODE;
}

// function to delete node from the em=nd of the lest
int DeletEND (struct LINKEDLIST *LIST){
    if(LIST -> TAIL == NULL){
        printf("THE LIST IS EMPTY");
        return -1;
    }
    int D = LIST->TAIL->DATA;
    struct NODE * PRE_NODE = LIST -> TAIL -> PREV;
    free(LIST ->TAIL);
    if(PRE_NODE == NULL){
        LIST ->HEAD = NULL;
    }
    else {
        PRE_NODE -> NEXT = NULL;
    }
    return D;
}

// function to delete node from the beginning of the list
int DeleteFirst(struct LINKEDLIST * LIST){
    if(LIST -> HEAD == NULL){
        printf("LIST IS EMPTY");
        return -1;
    }
    int D = LIST -> HEAD -> DATA;
    struct NODE * NEXT_NODE = LIST -> HEAD -> NEXT;
    free(LIST ->HEAD);
    if(NEXT_NODE == NULL){
        LIST -> TAIL = NULL;
    }
    else {
        NEXT_NODE -> PREV = NULL;
    }
    return D;
}

//function to write the value in file
void READ_F_F(char* filename, struct LINKEDLIST* N1, struct LINKEDLIST* N2) {
    FILE* file_IN = fopen(filename, "r");
    char buffer[1024];
    fgets(buffer, 1024, file_IN);
    for (int i = 0; buffer[i] != '\0' && buffer[i] != '\n'; i++) {
        InsertEND(N1, buffer[i] - '0');
    }
    fgets(buffer, 1024, file_IN);
    for (int i = 0; buffer[i] != '\0' && buffer[i] != '\n'; i++) {
        InsertEND(N2, buffer[i] - '0');
    }
    fclose(file_IN);
}

// function to read from the file and print the output in another file
void WRITE_F_F(char* filename, struct LINKEDLIST RES) {
    FILE* file_OUT = fopen(filename, "w");
    struct NODE* node = RES.HEAD;
    while (node != NULL) {
        fprintf(file_OUT, "%d", node->DATA);
        node = node->NEXT;
    }
    fclose(file_OUT);
}

void PRINT_MENU() {
    printf("Select an operation:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Print result to output file\n");
    printf("6. Exit\n");
}

