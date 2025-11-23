🕧AIM : 
       // To find the required element in Binary Search //

🕑Algorithm:
              • Divide the search space into two halves by finding the middle index "mid".
              • Compare the middle element of the search space with the key.
              • If the key is found at middle element, the process is terminated.
              • If the key is not found at middle element, choose which half will be used as the next
                search space.
                – If the key is smaller than the middle element, then the left side is used for next
                search.
                – If the key is larger than the middle element, then the right side is used for next
                search.
              • This process is continued until the key is found or the total search space is exhausted.   


🕧PROGRAM :
            #include <stdio.h>
            int main()
            {
                int i, n, low, high, mid, a[10], key;
                //user to enter the number of elements in the array
                printf("Enter the number of elements:\n");
                scanf("%d", &n);
                // user to enter the elements in sorted order
                printf("Enter the elements in sorted order:\n");
                for (i = 0; i < n; i++)
                {
                    scanf("%d", &a[i]);
                }
                
                printf("Enter the element to be searched:\n");
                scanf("%d", &key);
                
                low = 0; //lower bound of the search range
                high = n - 1;// upper bound of the search range
                
                while (low <= high)
                {
                    mid = (low + high) / 2;
                    
                    if (key == a[mid])
                    {
                        printf("Successful search: element found at position %d\n", mid + 1);
                        return 0;
                    }
                    else if (key < a[mid])
                    {
                        high = mid - 1;
                    }
                    else
                    {
                    low = mid + 1;//the key is larger, adjust the low bound to search the right half?
                    }
                }
                printf("Element not found\n");//loop ends without finding the element, print a failure message
                return 0;
            }
