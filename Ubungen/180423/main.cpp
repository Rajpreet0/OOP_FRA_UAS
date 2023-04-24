#include <iostream>
#include <cstdlib>

// [x] Count number of elemetens in list
// [x] Find Node on Position x
// [x] Get data from specific position
// [x] New Element at the end
// [x] Add List at the end
// [x] Deleting Element at Position x
// [x] Delete the whole list
// [x] Insert new Element at Position x
// [x] Sort the list by position ascending order
// [x] Output the List with Kommas and an Dot at the end


// Basic Structure of Singly Linked List
struct Node {
    struct Node* next;
    int data;
};

// Function for the Output of that List on the Console
void output_node(struct Node* list){
    struct Node* current = list;
    if(current == NULL){
        std::cout << "The List is empty!" << std::endl;
    }
    while(current != NULL){
        std::cout << current->data << std::endl;
        current = current->next;
    }
}

// Function to Output the List with Commas and an Dot at the end
void prettier_output(struct Node* list){
    struct Node* current = list; 

    while(current != NULL){
        if(current->next == NULL){
            std::cout << current->data << ".";
        }else{
            std::cout << current->data << " ,";
        }
        current = current->next;
    }
}

// Function of counting the number of elements in the list
int countElements(struct Node* list){
    int count = 0;
    struct Node* current = list;

    while(current != NULL){
        count++;
        current = current->next;
    }

    return count;
}

// Function to output a specific node (User decides which index)
int outputSpecificNode(struct Node* list){
    struct Node* current = list;
    int number = 0;
    int count = 0;

    std::cout << "Bitte geben Sie eine Position an" << std::endl;
    std::cin >> count;

    while(current != NULL && number < count){
        current = current->next;
        number++;
    }

    if(current == NULL){
        std::cout << "Position nicht gefunden" << std::endl;
    }

    return current->data;
}

// Function to add Data to the Node at the start of the list
struct Node* add_start(struct Node* list, int input){
    // Andere Syntax bei malloc -> es muss ein Pointer sein und vor Malloc mus nochmals definiert werden was eingefügt werden soll
    // struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
    struct Node* new_node = new Node; 
    new_node->data = input;

    if(list != NULL){
        new_node->next = list;    
    }else{
        new_node->next = NULL;
    }

    return new_node;
}

// Function to add Data to the Node at the end of the list
struct Node* add_end(struct Node* list, int input){
    struct Node* new_node = new Node;
    struct Node* counter = list;

    new_node->data = input;
    new_node->next = NULL;

    if(counter ==  NULL){
        return new_node;
    }

    while(counter->next != NULL){
        counter = counter->next;
    }
    
    counter->next = new_node;

    return list;
}

// Function to merge two Singly Linked Lists together
struct Node* merge_end(struct Node* list, struct Node* another_list){
    struct Node* current = list;

    // Checking if one of the lists are NULL
    if(list == NULL){
        return another_list;
    }else if(another_list == NULL){
        return list;
    }

    while(current->next != NULL){
        current = current->next;
    }

    current->next = another_list;
    return list;
    
}

// Function to delete a node from the list (User decides which index)
struct Node* deleteSpecificNode(struct Node* list){
    struct Node* current = list; 
    struct Node* prev = list;   
    struct Node* next = list;
    int number = 0;
    int count = 0;

    std::cout << "Bitte geben Sie eine Position an" << std::endl;
    std::cin >> count;

    while(current != NULL && number < count){
        prev = current;
        current = current->next;
        next = current->next;
        number++;
    }

    // If the Index is 0 start with the next node in the list
    // Das gibt ein Fehler aus aber kb das jz herauszufinden also es ist wegen der Bedinung
    /*if(number == count){
        struct Node* new_start = list->next;
        return new_start;
    }*/
  
    prev->next = next;


    return list;
    
}

// Function to add a node to the list (User decides which index)
struct Node* insertSpecificNode(struct Node* list, int data){
    struct Node* new_node = new Node;
    struct Node* current = list;
    struct Node* next = list->next;
    new_node->data = data;

    int number = 0;
    int count = 0;

    std::cout << "Bitte geben Sie eine Position an" << std::endl;
    std::cin >> count;

    while(current->next != NULL && number < count){
        current = current->next;
        next = current->next;
        number++;
    }

    current->next = new_node;
    new_node->next = next;


    return list;

}

// Function to delete the whole list
void delete_list(struct Node* list){
    struct Node* current = list; 
    struct Node* next = NULL;

   
   while (current != NULL) {
      next = current->next;
      free(current);
      current = next;
   }
   
   list = NULL;

}

//Function to sort the list in ascending order -> Bubble Sort
void bubble_sort(struct Node* list){
    int swapped = 0;
    struct Node* current;
    struct Node* temp = NULL;

    // Do this till swapped is false (0)
    do{
        swapped = 0;
        current = list;

        // Do this until the next element from the last element in the list is NULL
        while(current->next != temp){
            // If the data from the current element is larger than the data from the next element
            if(current->data > current->next->data){
                // Then Swap the data of these two elements
                std::swap(current->data, current->next->data);
                // Set the Swapped two true (1)
                swapped = 1;
            }
            // Go to the nex element
            current = current->next;
        }
        // The sorted list should now be in the place of the older list
        temp = current;

    }while(swapped);

}


int main(){

    // Basic creation of the list
    struct Node* start = NULL;
    struct Node* second_list = NULL;

    // Adding Data to the list at the beginning
    start = add_start(start, 5);
    start = add_start(start, 10);

    // Adding Data to the list at the end
    start = add_end(start, 20);

    // Adding Data to an other list
    second_list = add_start(second_list, 4);
    second_list = add_start(second_list, 3);
    second_list = add_start(second_list, 2);
    second_list = add_start(second_list, 1);

    // Outputtting an List
    output_node(start);


    // Outputting an other List
    std::cout << "The Second List is" << std::endl;
    output_node(second_list);


    // Mergeing to List together
    start = merge_end(start,second_list);
    std::cout << "Both List merged together: " << std::endl;
    output_node(start);
    
    // Count Elements in th List 
    int count = 0;
    count = countElements(start);
    std::cout << "The Number of Elements in the List are: " << count << std::endl;

    // The sorted List using a Sorting Algorithm -> Bubble Sort
    std::cout << "Sorted List (Ascending Order): " << std::endl;
    bubble_sort(start);
    output_node(start);


    // Get data from the List at a specific index
    int data = 0;
    data = outputSpecificNode(start);
    std::cout << "The Output Data on this spefic node is: " << data << std::endl;


    // Delete Node from the List at a specific index
    start = deleteSpecificNode(start);
    std::cout << "This is the new List after a node has been deleted." << std::endl;
    output_node(start);


    // Insert Node into the List at a specific index
    start = insertSpecificNode(start, 9);
    std::cout << "This is the new List after a node has added." << std::endl;
    output_node(start);


    // Prettier Output for the List
    prettier_output(start);

    // Delete the whole list
    delete_list(start);

    return 0;
}