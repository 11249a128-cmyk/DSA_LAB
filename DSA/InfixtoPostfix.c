🕧Aim:
     // To convert an infix expression to postfix expression using stack operation //

🕑Algorithm:
           1. INITIALIZE AN EMPTY STACK AND AN EMPTY POSTFIX STRING.
           2. PUSH '(' ONTO THE STACK AND ADD ')' TO THE END OF THE INFIX EXPRESSION
           3. FOR EACH SYMBOL X IN THE INFIX EXPRESSION, DO:
                a. IF X IS AN OPERAND, ADD X TO THE POSTFIX STRING.
                b. IF X IS '(', PUSH IT ONTO THE STACK.
                c. IF X IS AN OPERATOR, THEN:
                     WHILE (STACK IS NOT EMPTY) AND (PRECEDENCE OF TOP OF STACK ≥
                     PRECEDENCE OF X):
                     POP OPERATOR FROM STACK AND ADD IT TO POSTFIX STRING.
                    
                     PUSH X ONTO THE STACK.
                 d. IF X IS ')', THEN:
                WHILE THE TOP OF THE STACK IS NOT '(':
                POP OPERATOR FROM STACK AND ADD IT TO POSTFIX STRING.
                POP '(' FROM THE STACK AND DISCARD IT.
           4. END FOR
           5. THE RESULTING POSTFIX STRING IS THE FINAL OUTPUT.
           6.END

🕧Programe :
            #include <stdio.h>
            #include <stdlib.h>
            #include <ctype.h>
            int top = -1;
            int max;
            char *stack;
            void push(char item)
            {
                if (top == max - 1)
                {
                    printf("Stack overflow!\n");
                }
                else
                {
                    stack[++top] = item;
                }
            }
            char pop()
            {
                if (top == -1)
                {
                    printf("Stack underflow!\n");
                    return '\0';
                }
                else
                {
                    return stack[top--];
                }
            }
            char peek()
            {
                if (top == -1)
                    return '\0';
                else
                    return stack[top];
            }
            int getPrecedence(char op)
            {
                switch (op)
                {
                case '+':
                case '-':
                    return 1;
                case '*':
                case '/':
                    return 2;
                case '^':
                    return 3;
                default:
                    return 0;
                }
            }
            int main()
            {
                printf("Enter maximum size of infix expression: ");
                scanf("%d", &max);
                stack = (char *)malloc(max * sizeof(char));
                char infix[max], postfix[max];
                printf("Enter the infix expression: ");
                scanf("%s", infix);
                int i = 0, j = 0;
                char c, temp;
                while ((c = infix[i++]) != '\0')
                {
                    if (isalnum(c))
                    {
                        postfix[j++] = c;
                    }
                    else if (c == '(')
                    {
                        push(c);
                    }
                    else if (c == ')')
                    {
                        while (peek() != '(' && peek() != '\0')
                        {
                            postfix[j++] = pop();
                        }
                        pop(); 
                    }
                    else 
                    {
                        while (getPrecedence(c) <= getPrecedence(peek()) && peek() != '\0')
                        {
                            postfix[j++] = pop();
                        }
                        push(c);
                    }
                }
                while (peek() != '\0')
                {
                    postfix[j++] = pop();
                }
                postfix[j] = '\0';
                printf("Postfix expression: %s\n", postfix);
                free(stack);
                return 0;
            }
