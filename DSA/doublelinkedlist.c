🕧Aim:
       // To write a C program to perform all operations on a Doubly Linked List, including insertion (beginning, position, end), deletion (beginning, position, end, by value), searching, and is playing the list in forward and backward directions //

🕑Algorithm:
          1. Create a structure Node with:
              data
              prev pointer
              next pointer
          2. CreateNode(data)
              Allocate memory
              Initialize data, prev = NULL, next = NULL
              Return node
          3. InsertAtBeginning(head, data)
              Create new node
              If list not empty:
              newNode → next = head
              head → prev = newNode
              head = newNode
          4. InsertAtEnd(head, data)
              Create new node
              If head is NULL:
              head = newNode
              Else:
              Traverse to last node
              last → next = newNode
              newNode → prev = last
           5. InsertAtPosition(head, data, pos)
              If pos = 1 → InsertAtBeginning
              Else traverse to position-1
              If position invalid → print error
              Insert node by adjusting 4 links
           6. DeleteNode(head, value)
              If list empty → print error
              Traverse until node with value is found
              Adjust pointers depending on:
              deleting head
              deleting last
              deleting middle
              Free the node
            7. DisplayList(head)
              Traverse forward
              Print prev/data/next for each node
            8. DisplayReverse(head)
              Traverse to last node
              Then traverse backward
              Print prev/data/next
            9.End
       
🕧Programe :
            #include <stdio.h>
            #include <stdlib.h>
            
            struct Node {
                int data;
                struct Node* next;
                struct Node* prev;
            };
            
            struct Node* head = NULL;
            
            struct Node* CreateNode(int value) {
                struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->data = value;
                newNode->next = NULL;
                newNode->prev = NULL;
                return newNode;
            }
            
            void InsertAtBeginning(int value) {
                struct Node* newNode = CreateNode(value);
                if (head == NULL) {
                    head = newNode;
                } else {
                    newNode->next = head;
                    head->prev = newNode;
                    head = newNode;
                }
                printf("%d inserted at beginning.\n", value);
            }
            
            void InsertAtEnd(int value) {
                struct Node* newNode = CreateNode(value);
                if (head == NULL) {
                    head = newNode;
                    return;
                }
                struct Node* temp = head;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = newNode;
                newNode->prev = temp;
                printf("%d inserted at end.\n", value);
            }
            
            void InsertAtPosition(int value, int pos) {
                if (pos == 1) {
                    InsertAtBeginning(value);
                    return;
                }
                struct Node* temp = head;
                int k = 1;
                while (temp != NULL && k < pos - 1) {
                    temp = temp->next;
                    k++;
                }
                if (temp == NULL) {
                    printf("Position out of range.\n");
                    return;
                }
                struct Node* newNode = CreateNode(value);
                newNode->next = temp->next;
                newNode->prev = temp;
                if (temp->next != NULL)
                    temp->next->prev = newNode;
                temp->next = newNode;
                printf("%d inserted at position %d.\n", value, pos);
            }
            
            void DeleteAtBeginning() {
                if (head == NULL) {
                    printf("List is empty.\n");
                    return;
                }
                struct Node* temp = head;
                head = head->next;
                if (head != NULL)
                    head->prev = NULL;
                printf("%d deleted from beginning.\n", temp->data);
                free(temp);
            }
            
            void DeleteAtEnd() {
                if (head == NULL) {
                    printf("List is empty.\n");
                    return;
                }
                struct Node* temp = head;
                while (temp->next != NULL)
                    temp = temp->next;
                if (temp->prev != NULL)
                    temp->prev->next = NULL;
                else
                    head = NULL;
                printf("%d deleted from end.\n", temp->data);
                free(temp);
            }
            
            void DeleteByValue(int value) {
                if (head == NULL) {
                    printf("List is empty.\n");
                    return;
                }
                struct Node* temp = head;
                while (temp != NULL && temp->data != value)
                    temp = temp->next;
                if (temp == NULL) {
                    printf("%d not found.\n", value);
                    return;
                }
                if (temp->prev != NULL)
                    temp->prev->next = temp->next;
                else
                    head = temp->next;
                if (temp->next != NULL)
                    temp->next->prev = temp->prev;
                printf("%d deleted.\n", value);
                free(temp);
            }
            
            void DeleteAtPosition(int pos) {
                if (head == NULL) {
                    printf("List is empty.\n");
                    return;
                }
                struct Node* temp = head;
                int k = 1;
                while (temp != NULL && k < pos) {
                    temp = temp->next;
                    k++;
                }
                if (temp == NULL) {
                    printf("Position out of range.\n");
                    return;
                }
                if (temp->prev != NULL)
                    temp->prev->next = temp->next;
                else
                    head = temp->next;
                if (temp->next != NULL)
                    temp->next->prev = temp->prev;
                printf("Node at position %d deleted.\n", pos);
                free(temp);
            }
            
            void Search(int value) {
                struct Node* temp = head;
                int pos = 1;
                while (temp != NULL) {
                    if (temp->data == value) {
                        printf("%d found at position %d.\n", value, pos);
                        return;
                    }
                    temp = temp->next;
                    pos++;
                }
                printf("%d not found in list.\n", value);
            }
            
            void Display() {
                if (head == NULL) {
                    printf("List is empty.\n");
                    return;
                }
                struct Node* temp = head;
                printf("Forward: ");
                while (temp->next != NULL) {
                    printf("%d ", temp->data);
                    temp = temp->next;
                }
                printf("%d\n", temp->data);
                printf("Backward: ");
                while (temp != NULL) {
                    printf("%d ", temp->data);
                    temp = temp->prev;
                }
                printf("\n");
            }
            
            int main() {
                int ch, val, pos;
                while (1) {
                    printf("\n--- DOUBLY LINKED LIST MENU ---\n");
                    printf("1. Insert at Beginning\n2. Insert at Position\n3. Insert at End\n");
                    printf("4. Delete at Beginning\n5. Delete by Value\n6. Delete at Position\n");
                    printf("7. Delete at End\n8. Search\n9. Display\n10. Exit\n");
                    printf("Enter choice: ");
                    scanf("%d", &ch);
            
                    switch (ch) {
                        case 1:
                            scanf("%d", &val);
                            InsertAtBeginning(val);
                            break;
                        case 2:
                            scanf("%d", &val);
                            scanf("%d", &pos);
                            InsertAtPosition(val, pos);
                            break;
                        case 3:
                            scanf("%d", &val);
                            InsertAtEnd(val);
                            break;
                        case 4:
                            DeleteAtBeginning();
                            break;
                        case 5:
                            scanf("%d", &val);
                            DeleteByValue(val);
                            break;
                        case 6:
                            scanf("%d", &pos);
                            DeleteAtPosition(pos);
                            break;
                        case 7:
                            DeleteAtEnd();
                            break;
                        case 8:
                            scanf("%d", &val);
                            Search(val);
                            break;
                        case 9:
                            Display();
                            break;
                        case 10:
                            exit(0);
                        default:
                            printf("Invalid choice\n");
                    }
                }
            }
