#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
} node;

// tạo mới một node
node *CreateNewNode(int value)
{
    node *newnode = new node;
    newnode->data = value;
    return newnode;
}

// thêm vào đầu
node *InsertHead(node *tail, int value)
{
    node *newnode = CreateNewNode(value);
    if (tail == NULL)
    {
        tail = newnode;
        newnode->next = newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
    }
    return tail;
}

void Display(node * tail) {
    node * current = tail;
    if (tail != NULL) {
        do {
            current = current -> next;
            printf(" %d -> ", current -> data);
        } while (current != tail);
    }
}

// thêm vào cuối
node *InsertTail(node *tail, int value)
{
    return InsertHead(tail, value)->next;
}

// lấy số lượng node
int Length(node *tail)
{
    node *temp = tail;
    int i = 1;
    if (tail == NULL)
        return 0;
    else
    {
        temp = temp->next;
        while (temp != tail)
        {
            i++;
            temp = temp->next;
        }
    }
    return i;
}

// thêm vào vị trí bất kì
node *InsertAtArbitrary(node *tail, int data, int location)
{
    int len = Length(tail), i;
    if (location < 1 || location > len + 1)
    {
        cout << "Vi tri nhap du lieu khong hop le";
    }
    else
    {
        if (tail == NULL)
            return InsertHead(tail, data);
        node *newnode = CreateNewNode(data), *current = tail;
        for (i = 1; i != location; i++)
            current = current->next;
        newnode->next = current->next;
        current->next = newnode;
        if (location == len + 1)
            tail = newnode;
    }
    return tail;
}

node *DeleteByValue(node *tail, int data)
{
    node *current = tail, *previous;
    if (tail == NULL)
        return tail;
    else if (tail == tail->next)
    {
        if (tail->data == data)
        {
            tail = NULL;
            delete(current);
        }
        return tail;
    }
    do
    {
        previous = current;
        current = current->next;
        if (current->data == data)
        {
            previous->next = current->next;
            if (current == tail)
                tail = previous;
            delete(current);
            current = previous->next;
        }
    } while (current != tail);
    return tail;
}

node *DeleteByLocation(node *tail, int location)
{
    node *current, *previous = tail;
    int len = Length(tail), i;
    if (location < 1 || location > len)
    {
        printf("Invalid Location to delete");
    }
    else if (len == 1)
    {
        tail = NULL;
        delete(current);
    }
    else
    {
        current = tail->next;
        for (i = 1; i < location; i++)
        {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        if (current == tail)
            tail = previous;
        delete(current);
    }

    return tail;
}

node *sort(node *tail)
{
    if (Length(tail) < 2)
        return tail;
    node *ptr1 = tail->next, *ptr2, *min;
    int temp;
    // selection sort implementation
    while (ptr1->next != tail->next)
    {
        min = ptr1;
        ptr2 = ptr1->next;
        while (ptr2 != tail->next)
        {
            if (min->data > ptr2->data)
                min = ptr2;
            ptr2 = ptr2->next;
        }
        if (min != ptr1)
        {
            temp = min->data;
            min->data = ptr1->data;
            ptr1->data = temp;
        }
        ptr1 = ptr1->next;
    }
    return tail;
}

int main()
{
    node *cll = NULL;
    int option, data, location;
    while (1)
    {
        Display(cll);
        printf("\nlength = %d\n", Length(cll));
        printf("\n\nMENU OF CHOICE\n1. Insert at head\n2. Insert at end\n3. Insert at arbitrary location\n4. Delete by value\n5. Delete by location\n6. Sort\n7. Exit\n");
        printf("Your choice: ");
        scanf("%d", &option);

        if (option == 1)
        {
            printf("Enter data to be inserted: ");
            scanf("%d", &data);
            cll = InsertHead(cll, data);
        }
        else if (option == 2)
        {
            printf("Enter data to be inserted at end: ");
            scanf("%d", &data);
            cll = InsertTail(cll, data);
        }
        else if (option == 3)
        {
            printf("Enter data to be inserted: ");
            scanf("%d", &data);
            printf("Enter location to be inserted into: ");
            scanf("%d", &location);
            cll = InsertAtArbitrary(cll, data, location);
        }
        else if (option == 4)
        {
            printf("Enter value to be deleted: ");
            scanf("%d", &data);
            cll = DeleteByValue(cll, data);
        }
        else if (option == 5)
        {
            printf("Enter location to be deleted: ");
            scanf("%d", &location);
            cll = DeleteByLocation(cll, location);
        }
        else if (option == 6)
        {
            sort(cll);
        }
        else if (option == 7)
        {
            break;
        }
    }
    return 0;
}