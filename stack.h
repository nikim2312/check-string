#pragma once

#include <iostream>

using namespace std;
class Element {
public:
    int data;
    Element* next;
};
class Stack
{
public:

    Element* head = nullptr;


    void Push(int a);
    void Print();
    int Pop();
    int Back_el();
    Element* Find(int num);
    void Back();
    void sort(bool order);
    int Count();
    int* ToArray();
    bool IsEmpty();
};
