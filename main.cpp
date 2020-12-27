#include <iostream>

using namespace std;


class List 
{    
private:
    
    struct Node{

    int id; 
    Node *next;
    Node *prev;

    }; 
    Node *begin = nullptr;
    int Size = 0;

public:


    void Print () {

        Node *temp = begin;
        while (temp != nullptr){

            cout << temp->id <<" ";
            temp = temp->next;

        }
    }

    void PushFront (const int &item) {

        Node *newitem = new Node;
        newitem->id = item;
        newitem->prev = nullptr;
        newitem->next = begin;
        begin = newitem; 

        Size++;

    }

    void PushBack (const int &item) {

        Node *current = begin;

        if (current == nullptr){

            Node *newitem = new Node;
            newitem->id = item;
            begin = newitem;
            newitem->next = nullptr;
            newitem->prev = nullptr;
            return;

        }
        else{

            while (current->next != nullptr){

                current = current->next;

            }

            Node *newitem = new Node;
            newitem->id = item;
            newitem->next = nullptr;
            newitem->prev = current;
            current->next = newitem;

        }
        
        Size++;
        

    }
    
};


int main()
{
    setlocale(LC_ALL, "Russian"); 
    
    List *Newitem = new List;
    
    Newitem->PushBack(66);
    Newitem->PushFront(14);
    Newitem->Print();
    
    delete Newitem;
    return 0;

}