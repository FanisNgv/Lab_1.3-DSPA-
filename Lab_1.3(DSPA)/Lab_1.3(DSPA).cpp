#include <iostream>
#include <windows.h>
#include <ctime>

struct Node
{
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

bool isempty()
{
    if (front == NULL && rear == NULL)
        return true;
    else
        return false;
}

void enqueue(char value)
{
    Node* ptr = new Node();

    ptr->data = value;
    ptr->next = NULL;

    if (front == NULL)
    {
        front = ptr;
        rear = ptr;
    }
    else
    {
        rear->next = ptr;
        rear = ptr;
    }
}

void dequeue()
{
    if (isempty())
    {
        std::cout << "Очередь пуста" << std::endl;
        return;
    }
    if (front == rear)
    {        
        delete(front);           
        front = rear = NULL;       
    }
    else
    {
        Node* ptr = front;
        front = front->next;
        delete(ptr);
    }    
}

void showQueue()
{
    if (isempty())
    {
        std::cout << "Очередь пуста" << std::endl;
    }
    else
    {
        Node* ptr = front; // создаем копию, чтобы не портить текущую вершину
        do
        {
            std::cout << (char)ptr->data << " ";
            ptr = ptr->next;
        } while (ptr != NULL);
        std::cout << std::endl;
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(0));

    int choice;
    int value;
    int how_many;

    while (true)
    {
        choice = rand() % 2;
        how_many = rand() % 3 + 1;

        if (choice)
        {
            for (int i = 0; i < how_many; i++)
            {
                enqueue(rand() % 26 + 65);
            }                        
        }
        else
        {
            for (int i = 0; i < how_many; i++)
            {
                dequeue();
            }
        }            

        std::cout << "Состояние очереди:" << std::endl;

        showQueue();
        Sleep(2500);
    }    
    
}
