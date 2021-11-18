//////////////////////////////////////////////////////
/////                 Rohan Manikrao Magar
////                  Date 18 Nov 2021
//                    Generic Datastructure Template Library
//////////////////////////////////////////////////////

#include <iostream>
using namespace std;
/////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

//----------------------------------------------------------------------------------------------------------------

template <typename T>
struct node
{
    T data;
    struct node *next;
};
///////////////////////////////////////////////////////////////////////////////
///                             Singly Linear Linked List
////////////////////////////////////////////////////////////////////////////////
template <class T>
class SinglyLL
{
private:
    struct node <T>* first;
    T size;

public:
    SinglyLL();
    void InsertFirst(T);
    void InsertLast(T);

    void InsertAtPos(T, int);
    void DeleteAtPos(T);
    void DeleteFirst();
    void DeleteLast();
    int Count();
    void Display();
};
////////////////////////////////////////////////////////////////////
  //  SinglyLL Constructor
////////////////////////////////////////////////////////////////////
template <class T>
SinglyLL<T> ::SinglyLL()
{
    first = NULL;
    size = 0;
}

////////////////////////////////////////////////////////////////////
//  Inserting node at first position in SLL
////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T> ::InsertFirst(T no)
{
   node <T>* newn = new node <T> ; // newn = (struct node *)malloc(sizeof(struct node ))

    newn->data = no;
    newn->next = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    size++;
}


////////////////////////////////////////////////////////////////////
//  Inserting node at last position
////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>::InsertLast(T no)
{
      node <T> * newn = new  node<T> ; // newn = (struct node *)malloc(sizeof(struct node ))

    newn->data = no;
    newn->next = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
         node <T>* temp = first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    size++;
}

////////////////////////////////////////////////////////////////////
///               Inserting node at desired position
////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL <T>::InsertAtPos(T no, int pos)
{

            if((pos<0 ) || (pos>size+1))
            {
                cout<<"Invalide position\n";
                return;
            }
            node <T>* newn = new node<T>;
            node <T>* temp = first;
            int i=0;
                if(first == NULL)
                {
                    InsertFirst(no);
                    size++;
                }
                else if(pos ==size+1)
                {
                    InsertLast(no);
                    size++;
                }
                else
                {
                    for(i=1;i<pos-1;i++)
                    {
                        temp = temp->next;
                    }
                    newn->next=temp->next;
                    temp->next = newn;
                    newn->data = no;
                    size++;

                }
}

////////////////////////////////////////////////////////////////////
 //                   Deleting node at first position 
////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T> ::DeleteFirst()
{
      node <T>* temp = first;

    if (first != NULL)
    {
        first = first->next;
        delete temp;

        size--;
    }
}

//////////////////////////////////////////////////////////////////////////////
//                  Deleteling node at last position
////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T> ::DeleteLast()
{
      node <T> * temp = first;

    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
        size--;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
        size--;
    }
}
////////////////////////////////////////////////////////////////////
    //  Deleteling node at desired position
////////////////////////////////////////////////////////////////////
template <class T>

void SinglyLL<T>::DeleteAtPos(T pos)
{
         node <T>* temp = first;
         node <T>* tempRes= NULL;
            int i=0;
                if( (pos<0) || (pos>size+1))
                {
                    printf("!!!!!!! Invalide Position   !!!!!!!!!!!!!!\n");
                    return;
                }
                if(first->next == NULL )
                {
                    DeleteFirst();
                    size--;
                }
                else if(pos == size)
                {
                    DeleteLast();
                    size--;
                }
                else
                {
                    for(i=1;i<pos-1;i++)
                    {
                       temp = temp->next;

                    }
                    tempRes = temp->next;
                    temp->next = temp->next->next;
                    delete tempRes;
                    size--;
                }
}

////////////////////////////////////////////////////////////////////
/// Displaying Singly Linear Linked List
////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T> ::Display()
{
      node <T>* temp = first;

    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << "\n";
}

/////////////////////////////////////////////////////////////////////////////////////
///                             Counting number of nodes in linked list
////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyLL<T> ::Count()
{
    return size;
}


//----------------------------------------------------------------------------------------------------------------


//////////////////////////////////////////////////////////////////////////////////////////////////
////////            Entry Point Function(Main Fuction)
//////////////////////////////////////////////////////////////////////////////////////////////////



int main()
{

    int iret = 0;
    SinglyLL <char>obj;
    SinglyLL <int>cobj;

    obj.InsertFirst('A');
    obj.InsertFirst('B');
    obj.InsertFirst('C');

    obj.InsertLast('D');
    obj.InsertLast('Z');

    obj.Display();

    iret = obj.Count();
    cout << "Number of elemensts are : " << iret << "\n";
    /////////////////////////////////////////////////////////////////
    cobj.InsertFirst(10);
    cobj.InsertFirst(20);
    cobj.InsertFirst(30);
    cobj.Display();

    cobj.DeleteAtPos(2);
    cobj.InsertAtPos(880,2);

    cobj.InsertLast(40);
    cobj.InsertLast(60);

    cobj.Display();

    iret = cobj.Count();
    cout << "Number of elemensts are : " << iret << "\n";


    return 0;
}
