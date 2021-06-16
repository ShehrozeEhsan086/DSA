#include<iostream>
#include<cstdio>
#include<cstdlib>


using namespace std;
    

struct Node {
    int data;
    Node* next;
}*head, * tail, * current, * previous, * temp,*head1,*tail1;


class SingleLinkList {
public:
    SingleLinkList() {
        head = tail = current = previous = temp = NULL;
    }

public:
    void createList(int value) {
        Node* temp = new Node;
        temp->data = value;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
            tail->next = NULL;
        }
    }
    
public:
    void createList2(int value) {
        Node* temp = new Node;
        temp->data = value;
        temp->next = NULL;
        if (head1 == NULL)
        {
            head1 = temp;
            tail1 = temp;
        }
        else {
            tail1->next = temp;
            tail1 = temp;
            tail1->next = NULL;
        }
    }

public:
    void display() {
        temp = head;
        while (temp != NULL) {
            cout << temp->data;
            cout << "<--->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

public:
    void display1() {
        temp = head1;
        while (temp != NULL) {
            cout << temp->data;
            cout << "<--->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }


public:
    void add(int index, int data) {
        current = head;
        for (int i = 1; i < index; i++) {
            previous = current;
            current = current->next;
        }
        temp = new Node();
        temp->data = data;
        previous->next = temp;
        temp->next = current;
    }


public:
    void insertNodes(SingleLinkList s2) {
        int positionIndex = 2;
        Node* temp = head1;
        while (temp != NULL) {
            add(positionIndex, temp->data);
            temp = temp->next;
            positionIndex = positionIndex + 2;
        }
    }

public:
    void remove(int data) {
        current = head;
        previous = head;
        while (current != NULL) {
            if (current->data == data) {
                if(current == head){
                    head = current->next;
                    delete current;
                    break;
                }
                previous->next = current->next;
                temp = current;
                delete temp;
                break;
            }
            previous = current;
            current = current->next;
        }
    }

public:
    void deleteSmallest() {
        Node* smallestLocation = head;
        current = head;
        while (current != NULL) {
            if (current->data < smallestLocation->data) {
                smallestLocation = current;
            }
            else {
                current = current->next;
            }
        }
        remove(smallestLocation->data);
    }

public:
    void duplicateInner(Node*& current, SingleLinkList& l2) {
        if (current == NULL) {
            return;
        }
        else {
            duplicateInner(current->next, l2);
        }
        l2.createList(current->data);
    }
public:
    SingleLinkList duplicateReverse() {
        Node* temp = head;
        SingleLinkList l2;
        duplicateInner(temp, l2);
        l2.display();
        return l2;
    }


public:
    int size() {
        int size = 0;
        current = head;
        while (current != NULL) {
            size++;
            current = current->next;
        }
        return size;
    }

public:
    void addListAtEnd() {
        int s = size();
        Node* t = head;
        int limit = s * 2;
        while (s<limit) {
            add(s+1, t->data);
            t = t->next;
            s++;
        }
    }

public:
    void printMiddle() {
        int s = size();
        s = s / 2;
        int count = 0;
        Node* temp = head;
        while (count != s) {
            temp = temp->next;
            count++;
        }
        cout << temp->data;
    }
};


int main()
{
    int choice, data, location;
    SingleLinkList s1;
    SingleLinkList s3;

    cout << "THIS CODE CONTAINS QUESTION 2,4,6,8,10,14 AND 16: "<<endl;


    while (1)
    {
        cout << "-------------------------------------------------------------------" << endl;
        cout << "1.Create List  ";
        cout << "2.Add(Q.2)  ";
        cout << "3.Display  ";
        cout << "4.Delete(Q.4)  ";
        cout << "5.Duplicate Reverse(Q.6)  ";
        cout << "6.Delete Smallest(Q.8)  ";
        cout << "7.Print Middle(Q.10) ";
        cout << "8.Insert Alternatively(Q.14)  ";
        cout << "9.Add the list at its end(Q.16)   ";
        cout << "0.Quit" << endl;
        cout << "-------------------------------------------------------------------" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the data: ";
            cin >> data;
            s1.createList(data);
            cout << endl;
            break;

        case 2:
            cout << "Enter the data: ";
            cin >> data;
            cout << "Enter the location you want to add at: ";
            cin >> location;
            s1.add(location, data);
            cout << endl;
            break;

        case 3:
            s1.display();
            cout << endl;
            break;

        case 4:
            if (head == NULL)
            {
                cout << "List empty,nothing to delete" << endl;
                break;
            }
            cout << "Enter the data for deletion: ";
            cin >> data;
            s1.remove(data);
            cout << endl;
            break;
        case 5:
            s1.duplicateReverse();
            cout << endl;
            break;
        case 6:
            s1.deleteSmallest();
            cout << endl;
            break;
        case 7:
            s1.printMiddle();
            cout << endl;
            break;
        case 8:
            cout << endl << "How many elemets you want to insert in list 2: ";
            int number;
            cin >> number;
            for (int i = 0; i < number; i++) {
                cout << "Enter the data: ";
                cin >> data;
                s3.createList2(data);
            }
            cout << endl;
            cout << "Your lists are " << endl;
            cout << "First List: ";
            s1.display();
            cout << endl;
            cout << "Second List: ";
            s3.display1();
            cout << endl;
            s1.insertNodes(s3);
            cout << "Final List after adding list 2 elements alternativly into list 1: ";
            s1.display();
            break;
        case 9:
            s1.addListAtEnd();
            cout << "New List that added the list to itself at the end: ";
            s1.display();
            cout << endl;
            break;
        case 0:
            exit(1);

        default:
            cout << "Wrong choice" << endl;
        }
    }
    return 0;
}