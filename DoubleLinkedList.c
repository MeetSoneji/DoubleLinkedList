#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL)
    {
        (*head)->prev = newNode;
    }
    *head = newNode;
    printf("%d inserted at the beginning of the list.\n", data);
}
void insertAfter(struct Node *prevNode, int data)
{
    if (prevNode == NULL)
    {
        printf("The previous node cannot be NULL!\n");
        return;
    }
    struct Node *newNode = createNode(data);
    newNode->prev = prevNode;
    newNode->next = prevNode->next;
    if (prevNode->next != NULL)
    {
        prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
    printf("%d inserted after the given node.\n", data);
}
void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        printf("%d inserted at the end of the list.\n", data);
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    printf("%d inserted at the end of the list.\n", data);
}
void deleteNode(struct Node **head, int key)
{
    struct Node *temp = *head;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            if (temp->prev != NULL)
            {
                temp->prev->next = temp->next;
            }
            else
            {
                *head = temp->next;
            }
            if (temp->next != NULL)
            {
                temp->next->prev = temp->prev;
            }
            free(temp);
            printf("Node with key %d deleted.\n", key);
            return;
        }
        temp = temp->next;
    }

    printf("Node not found!\n");
}
void displayForward(struct Node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty!\n");
        return;
    }
    struct Node *temp = head;
    printf("Linked list elements in forward direction:\n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void displayReverse(struct Node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty!\n");
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("Linked list elements in reverse direction:\n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
int main()
{
    struct Node *head = NULL;
    int choice, data, key;

    while (1)
    {
        printf("\nDouble Linked List Operations:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert after a given node\n");
        printf("3. Insert at the end\n");
        printf("4. Delete a node\n");
        printf("5. Display the linked list in forward direction\n");
        printf("6. Display the linked list in reverse direction\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data to insert at the beginning: ");
            scanf("%d", &data);
            insertAtBeginning(&head, data);
            break;
        case 2:
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            printf("Enter the key after which to insert: ");
            scanf("%d", &key);
            insertAfter(head, data);
            break;
        case 3:
            printf("Enter the data to insert at the end: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;
        case 4:
            printf("Enter the key of the node to delete: ");
            scanf("%d", &key);
            deleteNode(&head, key);
            break;
        case 5:
            displayForward(head);
            break;
        case 6:
            displayReverse(head);
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice! Please enter a valid option.\n");
            break;
        }
    }
    return 0;
}
