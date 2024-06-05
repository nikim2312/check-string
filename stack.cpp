#include "Stack.h"
using namespace std;
void Stack::Push(int a)
{
    Element* new_el = new Element;
    new_el->data = a;
    new_el->next = nullptr;

    if (head == nullptr)
    {
        head = new_el;
    }
    else
    {
        Element* tail;
        tail = head;
        while (tail->next != nullptr)
        {
            tail = tail->next;
        }

        tail->next = new_el;
        tail = new_el;
    }

}
void Stack::Print()
{
    if (head == nullptr)
    {
        return;
    }
    Element* count;
    count = head;
    while (count->next != nullptr)
    {
        cout << count->data << " ";
        count = count->next;
    }
    cout << count->data;

    cout << endl;
}
int Stack::Pop()
{

    if (head == nullptr)
    {
        return 0;
    }
    else if (head->next == nullptr)
    {
        int a = head->data;
        delete head;
        head = nullptr;
        return a;

    }
    else
    {
        Element* tmp = head;
        while (tmp->next->next != nullptr)
        {
            tmp = tmp->next;
        }
        int last = tmp->next->data;
        delete tmp->next;
        tmp->next = nullptr;
        return last;
    }

}
int Stack::Back_el()
{
    if (head == nullptr)
    {
        return 0;
    }
    else if (head->next == nullptr)
    {
        int a = head->data;
        return a;

    }
    Element* tmp = head;
    while (tmp->next->next != nullptr)
    {
        tmp = tmp->next;
    }
    int last = tmp->next->data;
    return last;
}
Element* Stack::Find(int num)
{
    Element* ite;
    ite = head;
    bool stop = false;
    while (ite->next != nullptr)
    {
        if (ite->data != num)
        {
            ite = ite->next;
        }
        else if (ite->data == num)
        {
            stop = true;
            break;
        }
    }
    if (ite->data != num)
    {
        ite = ite->next;
    }
    else if (ite->data == num)
    {
        stop = true;
    }
    if (stop == false)
    {
        ite = nullptr;
        return ite;
    }
    return ite;

}
void Stack::Back()
{
    Element* current = head;
    Element* next = nullptr;
    Element* prev = nullptr;
    while (current->next != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    current->next = prev;
    head = current;
}
void Stack::sort(bool order)
{
    if (order)
    {
        Element* count = head;
        int counter = 1;
        while (count->next != nullptr)
        {
            count = count->next;
            counter++;
        }
        for (int i = 0; i < counter; i++)
        {
            Element* sorting = head->next;
            Element* help = head;
            if (head->data > head->next->data)
            {
                head->next = head->next->next;
                sorting->next = head;
                head = sorting;
                help = head;
                sorting = head->next;
            }

            while (sorting->next->next != nullptr)
            {
                if (sorting->data > sorting->next->data)
                {
                    Element* temp = sorting->next;
                    sorting->next = sorting->next->next;
                    temp->next = sorting;
                    help->next = temp;
                    help = temp;
                    temp = sorting->next;
                }
                else
                {
                    help = sorting;
                    sorting = sorting->next;
                }

            }
            if (sorting->data > sorting->next->data)
            {
                sorting->next->next = sorting;
                sorting->next = nullptr;
            }
        }
    }
    else if (!order)
    {
        Element* count = head;
        int counter = 1;
        while (count->next != nullptr)
        {
            count = count->next;
            counter++;
        }
        for (int i = 0; i < counter; i++)
        {
            Element* sorting = head->next;
            Element* help = head;
            if (head->data < head->next->data)
            {
                head->next = head->next->next;
                sorting->next = head;
                head = sorting;
                help = head;
                sorting = head->next;
            }

            while (sorting->next->next != nullptr)
            {
                if (sorting->data < sorting->next->data)
                {
                    Element* temp = sorting->next;
                    sorting->next = sorting->next->next;
                    temp->next = sorting;
                    help->next = temp;
                    help = temp;
                    temp = sorting->next;
                }
                else
                {
                    help = sorting;
                    sorting = sorting->next;
                }

            }
            if (sorting->data < sorting->next->data)
            {
                sorting->next->next = sorting;
                sorting->next = nullptr;
            }
        }
    }
}
int Stack::Count()
{
    Element* count = head;
    int counter = 1;
    while (count->next != nullptr)
    {
        count = count->next;
        counter++;
    }
    return counter;
}

int* Stack::ToArray() {
    int* arr;
    int size = Count();
    arr = new int[size];
    Element* ite;
    ite = head;
    for (int i = 0; i < size; i++)
    {
        arr[i] = ite->data;
        ite = ite->next;
    }
    return arr;
}
bool Stack::IsEmpty()
{
    if (head == nullptr)
        return true;
    else
        return false;
}
