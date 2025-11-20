🕧AIM:
     // To find the required element in linear Search //

🕧Programe :
            #include <stdio.h>
            int main()
            {
                // Declare an array of size 10, a variable for the key, and variables for loop and size
                int a[10], key, i, n;
                //user to enter the size of the array
                printf("Enter the size of array:\n");
                scanf("%d", &n);
                printf("Enter %d elements:\n", n);
                for (i = 0; i < n; i++)//Loop to get array elements
                {
                    scanf("%d", &a[i]);
                }
                printf("Enter the key element:\n");
                scanf("%d", &key);
                for (i = 0; i < n; i++)
                {
                    if (a[i] == key)//if the current element matches the key
                    {
                        //he element is found, print the position (index + 1 to make it 1-based)
                        printf("\nElement is found at position %d\n", i + 1);
                        return 0; 
                    }
                }
                printf("\nElement is not found in the array\n");
                return 0;
            }
