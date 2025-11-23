🕧Aim:
      // To implement a Circular Queue using Linked List  with enqueue, dequeue, and display operations //

🕑Algorithm:
            1. Start
            2. Initialize
                  Set front = NULL
                  Set rear = NULL
            3. Repeat the following steps until the user chooses to Exit:
                  Display Menu
                  Enqueue
                  Dequeue
                  Peek
                  Display
                  Exit
                  Read user choice
            4. Perform operation based on the choice
              Case 1: Enqueue
                  Read the value data to insert.
                  Create a new node with given data.
                  If queue is empty (rear == NULL)
                  Set front = newnode
                  Set rear = newnode
                  Else
                  Set rear->next = newnode
                  Update rear = newnode
                  Display “Enqueued successfully”.
             Case 2: Dequeue
                  If queue is empty (front == NULL)
                  Display “Queue is empty. Dequeue not possible.”
                  Go back to main loop.
                  Else
                  Store the node pointed by front in temporary variable temp
                  Print the value to be remove
                  Update front = front->next
                  If front becomes NULL, set rear = NULL
                  Free the memory of temp
             Case 3: Peek
                  If queue is empty (front == NULL)
                  Print “Queue is empty”
                  Else
                  Print the value at front->data
             Case 4: Display Queue
                  If queue is empty
                  Print “Queue is empty”
                  Else
                  Traverse from front to rear, printing each element
             Case 5: Exit
                  Print “Exiting…”
                  Terminate the program
                  Default Case
                  Print “Invalid choice! Try again”
            5. Stop

🕧Programe :
            #include <stdlib.h>
            #include <stdio.h>
            struct node {
                int data;
                struct node *next;
            };
            struct node* create_node(int data) {
                struct node *newnode = (struct node*)malloc(sizeof(struct node));
                if (!newnode) {
                    printf("Memory allocation failed\n");
                    return NULL;
                }
                newnode->data = data;
                newnode->next = NULL;
                return newnode;
            }
            void enqueue(struct node **front, struct node **rear, int data) {
                struct node *newnode = create_node(data);
                if (*rear == NULL) {
                    *front = *rear = newnode;
                } else {
                    (*rear)->next = newnode;
                    *rear = newnode;
                }
                printf("Enqueued %d successfully\n", data);
            }
            void dequeue(struct node **front, struct node **rear) {
                if (*front == NULL) {
                    printf("Queue is empty! Dequeue not possible\n");
                    return;
                }
                struct node *temp = *front;
                printf("Dequeued %d\n", temp->data);
                *front = (*front)->next;
                if (*front == NULL)
                    *rear = NULL;
                free(temp);
            }
            void peek(struct node *front) {
                if (front == NULL) {
                    printf("Queue is empty\n");
                } else {
                    printf("Front element: %d\n", front->data);
                }
            }
            void display(struct node *front) {
                if (front == NULL) {
                    printf("Queue is empty\n");
                    return;
                }
                struct node *temp = front;
                printf("\nQueue (front to rear): ");
            
                while (temp != NULL) {
                    printf("%d -> ", temp->data);
                    temp = temp->next;
                }
                printf("NULL\n");
            }
            int main() {
                struct node *front = NULL;
                struct node *rear = NULL;
                int choice, data;
                while (1) {
                    printf("\n---- Queue using Singly Linked List ----\n");
                    printf("1. Enqueue\n");
                    printf("2. Dequeue\n");
                    printf("3. Peek (Front Element)\n");
                    printf("4. Display Queue\n");
                    printf("5. Exit\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);
                    switch (choice) {
                        case 1:
                            printf("Enter value to enqueue: ");
                            scanf("%d", &data);
                            enqueue(&front, &rear, data);
                            break;
            
                        case 2:
                            dequeue(&front, &rear);
                            break;
            
                        case 3:
                            peek(front);
                            break;
            
                        case 4:
                            display(front);
                            break;
            
                        case 5:
                            printf("Exiting...\n");
                            exit(0);
            
                        default:
                            printf("Invalid choice! Try again\n");
                    }
                }
            
                return 0;
            }
