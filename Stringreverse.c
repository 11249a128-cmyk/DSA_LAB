🕧Aim:
      // To perform string reverse using stack operation //

🕑Algorithm:
            Step 1: Start the program.
            Step 2: Initialize TOP = -1 and get the size of the string.
            Step 3: Input the string from the user.
            Step 4: For each character in the string, perform PUSH to insert it into the stack.
            Step 5: Once all characters are pushed, start POP operations to remove and print each character.
            Step 6: Continue popping until the stack is empty.
            Step 7: Display the reversed string.
            Step 8: Stop the program.        

Programe :
          #include <stdio.h>
          #include <stdlib.h>
          
          int top = -1;
          int size;
          char *STACK; // Dynamic Array
          
          void push(char item)
          {
              if (top == (size - 1))
              {
                  printf("Stack is already full, no additional push allowed - Overflow");
              }
              else
              {
                  top = top + 1;
                  STACK[top] = item;
              }
          }
          
          char pop()
          {
              char temp = STACK[top];
              top = top - 1;
              return temp;
          }
          
          int main()
          {
              printf("Enter the size of string to reverse: ");
              scanf("%d", &size);
              char input[size];
              STACK = (char *)malloc(size * sizeof(char));
          
              printf("Enter the string of size %d to reverse: ", size);
              scanf("%s", &input);
          
              for (int i = 0; i <= size - 1; i++)
              {
                  push(input[i]);
              }
          
              printf("Reversed string is - \n");
              for (int i = 0; i <= size - 1; i++)
              {
                  printf("%c", pop());
              }
          }
}
