#include <iostream>

using namespace std;

struct Node{

    int id; 
    Node *next;
    Node *prev;

}; 

class List 
{    
private:
    
    Node *begin = nullptr;
    int Size = 0;
    
public:

    int GetSize(){
        return Size;
    }

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
        Size++;

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
    
    }

    void DeleteFront(){

        Node *current = begin;

        if (current == nullptr){

            return;

        }

        else {

            begin = current->next;
            delete current;
            Size --;
        }

    }

    void DeleteBack() {

        Node *current = begin;
        Node *current2;
        
        if (current == nullptr){
            return;
        }

        if (current->next == nullptr){
            
            DeleteFront();
            return;
        }

        else{

            while (current->next != nullptr){

                current2 = current;
                current = current->next;
            }
            delete current;
            current2->next = nullptr;
            Size--;
        }
        
    }
    
};


void menu(){

    cout << "\nWhat do your prefer? " << endl << endl;
    cout << " 0 - to left menu " << endl;
    cout << " 1 - to display a list  " << endl;
    cout << " 2 - to put new element front " << endl;
    cout << " 3 - to put new element back " << endl;
    cout << " 4 - to delete front element " << endl;
    cout << " 5 - to delete back element" << endl;
    cout << " 6 - to display size of your list " << endl << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian"); 
    
    List *Newitem = new List;
    
    char c;

    do {

        cout <<'\n';
        menu();
        cin >> c;

        switch(c){

            case '0':
                break;

            case '1':
                cout << " your list: " << endl;
                Newitem->Print();
                break;

            case '2':
                cout << " input element: ";
                int k;
                cin >> k;
                Newitem->PushFront(k);
                break;

            case '3':
                cout << " input element: ";
                int m;
                cin >> m;
                Newitem->PushBack(m);
                break;

            case '4':
                Newitem->DeleteFront();
                cout << " element is deleted " << endl;
                break;

            case '5':
                Newitem->DeleteBack();
                cout << " element is deleted " << endl;
                break;

            case '6':
                cout << " size of your list: " << Newitem->GetSize() << endl;
                break;
                
            default:
                cout << " incorrect number " << endl;
                break;
        }
    }

    while (c != '0');
    
    delete Newitem;

    return 0;

}