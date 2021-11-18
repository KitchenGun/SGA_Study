#include "DoubleLinkedList.h"

Node* DLL::Create(int data)
{
    Node* node = new Node();
    node->Data = data;
    node->Prev = node->Next = nullptr;
    return node;
}

void DLL::Destroy(Node* node)
{
    delete node;
    node = nullptr;
}

void DLL::Push(Node* node)
{
    if (Head == nullptr)
    {
        Head = new Node();
        //Head = node;
    }
    else
    {
        Node* tail = Head;
        while (tail->Next!=nullptr)
        {
            tail = tail->Next;
        }
        tail->Next = node;
        node->Prev = tail;

    }
}

void DLL::Insert(Node* Current, Node* node)
{
    node->Next=Current->Next;
    node->Prev = Current;

    if (Current->Next != nullptr)
    {
        Current->Next->Prev = node;
    }
    Current->Next = node;

}

void DLL::HeadInsert(Node* node)
{
    if (Head == nullptr)
    {
        Head = node;
    }
    else
    {
        node->Next = Head;
        Head = node;

    }
}

void DLL::Remove(Node* node)
{
    if (Head == node)
    {
        Head = node->Next;

        if (Head != nullptr)
        {
            Head->Prev = nullptr;
        }
        node->Prev = nullptr;
        node->Next = nullptr;
    }
    else
    {
        Node* current = node;
        node->Prev->Next = current->Next;
        
        if (node->Next != nullptr)
            node->Next->Prev = current->Prev;

        node->Prev = nullptr;
        node->Next = nullptr;
    }
}

Node* DLL::GetNode(int location)
{
    Node* current = Head;
    while (current!=nullptr&&--location>=0)
    {
        current = current->Next;
    }
    return current;
}

int DLL::GetNodeCount()
{
    Node* current = Head;
    int count = 0;
    while (current != nullptr)
    {
        count++;
        current = current->Next;
    }
    return count;
}
