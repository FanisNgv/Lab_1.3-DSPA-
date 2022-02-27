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
    //int how_many_for_del;
    //int how_many_for_add;

    while (true)
    {
        choice = rand() % 2;
        how_many = rand() % 3 + 1;
        //how_many_for_del = rand() % 3 + 1;
        //how_many_for_add = rand() % 4 + 1;

        if (choice)
        {
            std::cout << "Добавляем в количестве " << how_many << " элементов" << std::endl;
            for (int i = 0; i < how_many; i++)
            {
                enqueue(rand() % 26 + 65);
            }
            std::cout << std::endl;
        }
        else
        {
            std::cout << "Удаляем в количестве " << how_many << " элементов" << std::endl;
            for (int i = 0; i < how_many; i++)
            {
                if (isempty())
                {
                    std::cout << "Очередь пуста!" << std::endl;
                    break;
                }
                dequeue();
            }
            std::cout << std::endl;
        }            

        std::cout << "Состояние очереди:" << std::endl << std::endl;

        showQueue();
        std::cout << std::endl;
        Sleep(3500);
    }    
    
}
