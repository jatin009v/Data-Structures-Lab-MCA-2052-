// Write a menu-based program in C to traverse/ display an array, insert an item at any location (beginning, middle, end), 
// delete an item from any location (beginning, middle, end), search an item in an array using liner search and sort the array using Bubble sort.

#include <stdio.h>

int main() {
    int arr[100], n = 0;
    int choice, pos, item, i, j, temp;
    int found = 0;

    do {
        printf("\n===== ARRAY MENU =====\n");
        printf("1. Traverse / Display Array\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at Middle\n");
        printf("4. Insert at End\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from Middle\n");
        printf("7. Delete from End\n");
        printf("8. Linear Search\n");
        printf("9. Bubble Sort\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:   // Traverse
            if (n == 0) {
                printf("Array is empty\n");
            } else {
                printf("Array elements: ");
                for (i = 0; i < n; i++)
                    printf("%d ", arr[i]);
            }
            break;

        case 2:   // Insert at Beginning
            printf("Enter element: ");
            scanf("%d", &item);
            for (i = n; i > 0; i--)
                arr[i] = arr[i - 1];
            arr[0] = item;
            n++;
            printf("Inserted at beginning\n");
            break;

        case 3:   // Insert at Middle
            printf("Enter position (0 to %d): ", n);
            scanf("%d", &pos);
            printf("Enter element: ");
            scanf("%d", &item);
            for (i = n; i > pos; i--)
                arr[i] = arr[i - 1];
            arr[pos] = item;
            n++;
            printf("Inserted at middle\n");
            break;

        case 4:   // Insert at End
            printf("Enter element: ");
            scanf("%d", &item);
            arr[n] = item;
            n++;
            printf("Inserted at end\n");
            break;

        case 5:   // Delete from Beginning
            if (n == 0) {
                printf("Array is empty\n");
            } else {
                for (i = 0; i < n - 1; i++)
                    arr[i] = arr[i + 1];
                n--;
                printf("Deleted from beginning\n");
            }
            break;

        case 6:   // Delete from Middle
            if (n == 0) {
                printf("Array is empty\n");
            } else {
                printf("Enter position (0 to %d): ", n - 1);
                scanf("%d", &pos);
                for (i = pos; i < n - 1; i++)
                    arr[i] = arr[i + 1];
                n--;
                printf("Deleted from middle\n");
            }
            break;

        case 7:   // Delete from End
            if (n == 0) {
                printf("Array is empty\n");
            } else {
                n--;
                printf("Deleted from end\n");
            }
            break;

        case 8:   // Linear Search
            printf("Enter element to search: ");
            scanf("%d", &item);
            found = 0;
            for (i = 0; i < n; i++) {
                if (arr[i] == item) {
                    printf("Element found at position %d\n", i);
                    found = 1;
                    break;
                }
            }
            if (!found)
                printf("Element not found\n");
            break;

        case 9:   // Bubble Sort
            for (i = 0; i < n - 1; i++) {
                for (j = 0; j < n - i - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
            printf("Array sorted using Bubble Sort\n");
            break;

        case 0:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice\n");
        }

    } while (choice != 0);

    return 0;
}
