#include <iostream>
using namespace std;

//////////// Structure for Singly Linear and Singly Circular ////////////

template <class T>
struct nodeS
{
    T data;
    struct nodeS *next;
};

//////////// Structure for Doubly Linear and Doubly Circular ////////////

template <class T>
struct nodeD
{
    T data;
    struct nodeD *next;
    struct nodeD *prev;
};

////////////Class of Singly Linear Linked List/////////////

template <class T>
class SinglyLL
{
public:
    struct nodeS<T> *First;

    SinglyLL();

    void InsertFirst(T no);
    void InsertLast(T no);
    void InsertAtPos(T no, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);

    void Display();
    int Count();

    //////////

    void SumAll();
    void OddCount();
    int SearchFirst(int value);
    int SearchLast(int value);
    int Frequency();
    void EvenCount();
};

//--------------> Functions Decleration of Singly Linear Linked List ////

///////////////////////////////////////////////////////////
//
// Function name        : Constructor of Singly Linear Linked List
// Description          : This is the Constructor of Class Singly_Linked_List
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
SinglyLL<T>::SinglyLL()
{
    First = NULL;
}

///////////////////////////////////////////////////////////
//
// Function name        : Insert First
// Parameter            : Number or float or alphabet
// Description          : to insert node on first postion
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::InsertFirst(T iNo)
{
    nodeS<T> *newn = new nodeS<T>;

    newn->data = iNo;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
}

///////////////////////////////////////////////////////////
//
// Function name        : Insert Last
// Parameter            : Number or float or alphabet
// Description          : to insert node on Last postion
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::InsertLast(T iNo)
{
    nodeS<T> *newn = new nodeS<T>;
    newn->data = iNo;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        nodeS<T> *temp = First;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

///////////////////////////////////////////////////////////
//
// Function name        : Insert At postion
// Parameter            : Number or float or alphabet
// Description          : to insert node between in any postion in Linked list
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::InsertAtPos(T iNo, int iPos)
{
    if (iPos > Count() + 1 || iPos < 1)
    {
        cout << "invaid entry";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if (iPos == Count() + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        nodeS<T> *temp = First;
        nodeS<T> *newn = new nodeS<T>;

        newn->data = iNo;
        newn->next = NULL;

        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

///////////////////////////////////////////////////////////
//
// Function name        : Delete First
// Description          : to use Delete First Node
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    if (First == NULL)
    {
        cout << "LL is empty"
             << "\n";
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        nodeS<T> *temp = First;
        First = First->next;
        delete (temp);
    }
}

///////////////////////////////////////////////////////////
//
// Function name        : Delete At Positon
// Parameter            : Postion number
// Description          : to use Delete node from any postion
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == Count())
    {
        DeleteLast();
    }
    else
    {
        nodeS<T> *temp = First;
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        nodeS<T> *temp2 = temp->next->next;
        delete temp->next;
        temp->next = temp2;
    }
}

///////////////////////////////////////////////////////////
//
// Function name        : Delete Last
// Parameter            : NONE
// Description          : to use Delete Last Node of Linked List
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::DeleteLast()
{
    nodeS<T> *temp = First;

    if (First == NULL)
    {
        cout << "LL is emptyy"
             << "\n";
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
}

///////////////////////////////////////////////////////////
//
// Function name        : Display
// Parameter            : NONE
// Description          : use to Display all nodes of Linked List
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::Display()
{
    nodeS<T> *temp = First;
    while (temp != NULL)
    {
        cout << "| " << temp->data << " ";
        temp = temp->next;
    }
    cout << "| NULL";

    cout
        << "\n";
}

///////////////////////////////////////////////////////////
//
// Function name        : Count
// Parameter            : NONE
// Description          : use to Count all nodes of Linked List
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
int SinglyLL<T>::Count()
{
    int iCnt = 0;
    nodeS<T> *temp = First;
    while (temp != NULL)
    {
        temp = temp->next;
        iCnt++;
    }
    return iCnt;
}

/////////////Class of Singly Circular Linked List//////////////

template <class T>
class SinglyCL
{
public:
    struct nodeS<T> *First;
    struct nodeS<T> *Last;

    SinglyCL();

    void InsertFirst(T no);
    void InsertLast(T no);
    void InsertAtPos(T no, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);

    void Display();
    int Count();
};

//-------------> Functions of Singly Circular Linked List

///////////////////////////////////////////////////////////
//
// Function name        : Constructon of Singly Circular Linked list
// Parameter            : NONE
//
///////////////////////////////////////////////////////////

template <class T>
SinglyCL<T>::SinglyCL()
{
    First = NULL;
    Last = NULL;
}

///////////////////////////////////////////////////////////
//
// Function name        : Inser First
// Parameter            : Number or float or alphabet
// Description          : use to Insert Node on First Postion in Linked List
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::InsertFirst(T iNo)
{
    nodeS<T> *newn = new nodeS<T>;

    newn->data = iNo;
    newn->next = NULL;

    if (First == NULL && Last == NULL)
    {
        First = Last = newn;
        Last->next = First;
    }
    else
    {
        newn->next = First;
        First = newn;
        Last->next = First;
    }
}

///////////////////////////////////////////////////////////
//
// Function name        : Display
// Parameter            : NONE
// Description          : use to Display all nodes of Linked List
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::Display()
{
    if (First == NULL && Last == NULL)
    {
        cout << "Displaying No Linked List"
             << "\n";
    }

    do
    {
        cout << First->data << " | ";
        First = First->next;
    } while (Last->next != First);
    cout << "\n";
}

///////////////////////////////////////////////////////////
//
// Function name        : Inser At Postion
// Parameter            : Number which insert, and Postion on insert
// Description          : use to Insert Node any where in to the Linked List
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::InsertAtPos(T iNo, int iPos)
{
    nodeS<T> *newn = new nodeS<T>;
    newn->data = iNo;
    newn->next = NULL;

    if (iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if (iPos == Count() + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        nodeS<T> *temp = First;
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

///////////////////////////////////////////////////////////
//
// Function name        : Inser Last
// Parameter            : Number or float or alphabet
// Description          : use to Insert Node on Last Postion in Linked List
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::InsertLast(T iNo)
{

    nodeS<T> *newn = new nodeS<T>;

    newn->data = iNo;
    newn->next = NULL;

    if (First == NULL && Last == NULL)
    {
        First = Last = newn;
        Last->next = First;
    }
    else
    {
        Last->next = newn;
        Last = newn;
        Last->next = First;
    }
}

///////////////////////////////////////////////////////////
//
// Function name        : Delete First
// Parameter            : NONE
// Description          : use to Delete Node on First Postion in Linked List
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if (First == NULL & Last == NULL)
    {
        cout << "LL is empty"
             << "\n";
        return;
    }
    else if (First->next == First)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete Last->next;
        Last->next = First;
    }
}

///////////////////////////////////////////////////////////
//
// Function name        : Delete Last
// Parameter            : NONE
// Description          : to use Delete Last Node of Linked List
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::DeleteLast()
{
    if (First == NULL & Last == NULL)
    {
        cout << "LL is empty"
             << "\n";
        return;
    }
    else if (First->next == First)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        nodeS<T> *temp = First;
        while (temp->next != Last)
        {
            temp = temp->next;
        }
        delete temp->next;
        Last = temp;
        Last->next = First;
    }
}
///////////////////////////////////////////////////////////
//
// Function name        : Delete At Positon
// Parameter            : Postion number
// Description          : to use Delete node from any postion
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    if (First == NULL)
    {
        return;
    }
    else if (First->next == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        nodeS<T> *temp = First;
        nodeS<T> *temp2;
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
    }
}

///////////////////////////////////////////////////////////
//
// Function name        : Count
// Parameter            : NONE
// Description          : use to Count all nodes of Linked List
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
int SinglyCL<T>::Count()
{
    int iCnt = 0;
    do
    {
        iCnt++;
        First = First->next;
    } while (First != Last->next);
    return iCnt;
}

////////////// Class of Doubly Linear Linked List //////////////

template <class T>
class DoublyLL
{
public:
    struct nodeD<T> *First;

    DoublyLL();

    void InsertFirst(T no);
    void InsertLast(T no);
    void InsertAtPos(T no, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);

    void Display();
    int Count();
};

//--------------> Functions of Doubly Linear Linked List

template <class T>
DoublyLL<T>::DoublyLL()
{
    First = NULL;
}

///////////////////////////////////////////////////////////
//
// Function name        : Inser First
// Parameter            : Number or float or alphabet
// Description          : use to Insert Node on First Postion in Linked List
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::InsertFirst(T iNo)
{
    nodeD<T> *newn = new nodeD<T>;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
}

///////////////////////////////////////////////////////////
//
// Function name        : Inser Last
// Parameter            : Number or float or alphabet
// Description          : use to Insert Node on last Postion in Linked List
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::InsertLast(T iNo)
{
    nodeD<T> *newn = new nodeD<T>;
    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        nodeD<T> *temp = First;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
}

///////////////////////////////////////////////////////////
//
// Function name        : Inser At Postion
// Parameter            : Number which you want to insert, and Postion on insert
// Description          : use to Insert Node any where in to the Linked List
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::InsertAtPos(T iNo, int iPos)
{
    if (iPos > Count() + 1 || iPos < 1)
    {
        cout << "invaid entry";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if (iPos == Count() + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        nodeD<T> *temp = First;
        nodeD<T> *newn = new nodeD<T>;

        newn->data = iNo;
        newn->next = NULL;
        newn->prev = NULL;

        for (int i = 0; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;
    }
}

///////////////////////////////////////////////////////////
//
// Function name        : Delete First
// Parameter            : Number or float or alphabet
// Description          : use to Delete Node on First Postion in Linked List
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if (First == NULL)
    {
        cout << "LL is empty"
             << "\n";
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First->next;
        delete (First->prev);
        First->prev = NULL;
    }
}

///////////////////////////////////////////////////////////
//
// Function name        : Delete At Positon
// Parameter            : Position Number
// Description          : to use Delete node from any postion
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == Count())
    {
        DeleteLast();
    }
    else
    {
        nodeD<T> *temp = First;
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
    }
}

///////////////////////////////////////////////////////////
//
// Function name        : Delete Last
// Parameter            : NONE
// Description          : to use Delete Last Node of Linked List
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::DeleteLast()
{
    nodeD<T> *temp = First;

    if (First == NULL)
    {
        cout << "LL is emptyy"
             << "\n";
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
}

///////////////////////////////////////////////////////////
//
// Function name        : Display
// Parameter            : NONE
// Description          : use to Display all nodes of Linked List
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::Display()
{
    nodeD<T> *temp = First;
    while (temp != NULL)
    {
        cout << "| " << temp->data << " ";
        temp = temp->next;
    }
    cout << "| NULL";

    cout
        << "\n";
}

///////////////////////////////////////////////////////////
//
// Function name        : Count
// Parameter            : NONE
// Description          : use to Count all nodes of Linked List
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
int DoublyLL<T>::Count()
{
    int iCnt = 0;
    nodeD<T> *temp = First;
    while (temp != NULL)
    {
        temp = temp->next;
        iCnt++;
    }
    return iCnt;
}

//////////////Class of Doubly Circular Linked List////////////////

template <class T>
class DoublyCL
{
public:
    struct nodeD<T> *First;
    struct nodeS<T> *Last;

    DoublyCL();

    void InsertFirst(T no);
    void InsertLast(T no);
    void InsertAtPos(T no, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);

    void Display();
    int Count();
};

// ---------------> Functions of Doubly Circular Linked List

///////////////////////////////////////////////////////////
//
// Function name        : Constructor of Doubly Circular Linked List
// Description          : This is the Constructor of Class Doubly Circular Linked List
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
DoublyCL<T>::DoublyCL()
{
    First = NULL;
    Last = NULL;
}

///////////////////////////////////////////////////////////
//
// Function name        : Inser First
// Parameter            : Number or float or alphabet
// Description          : use to Insert Node on First Postion in Linked List
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::InsertFirst(T iNo)
{
    nodeD<T> *newn = new nodeD<T>;
    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if (First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    First->prev = Last;
    Last->next = First;
}

///////////////////////////////////////////////////////////
//
// Function name        : Inser At Postion
// Parameter            : Number which you want to insert, and Postion on insert
// Description          : use to Insert Node any where in to the Linked List
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::InsertAtPos(T iNo, int iPos)
{
    nodeD<T> *newn = new nodeD<T>;
    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if (iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if (iPos == Count() + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        nodeD<T> *temp = First;
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;
    }
}

///////////////////////////////////////////////////////////
//
// Function name        : Inser Last
// Parameter            : any kind of data type
// Description          : use to Insert Node on Last Postion in Linked List
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::InsertLast(T iNo)
{
    nodeD<T> *newn = new nodeD<T>;
    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if (First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->prev = Last;
        newn->next = First;
        Last->next = newn;
        Last = newn;
    }
}

///////////////////////////////////////////////////////////
//
// Function name        : Delete First
// Parameter            : NODE
// Description          : use to Delete Node on First Postion in Linked List
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if (First == NULL && Last == NULL)
    {
        cout << "LL is Empty"
             << "\n";
        return;
    }
    else if (First->next == First)
    {
        delete First;
        First = NULL;
        Last = NULL;
        cout << "Last node deleted"
             << "\n";
    }
    else
    {
        First = First->next;
        delete Last->next;
        Last->next = First;
        First->prev = Last;
    }
}

///////////////////////////////////////////////////////////
//
// Function name        : Delete At Positon
// Parameter            : Position Number
// Description          : to use Delete node From any postion
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == Count())
    {
        DeleteLast();
    }
    else
    {
        nodeD<T> *temp = First;
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
    }
}

///////////////////////////////////////////////////////////
//
// Function name        : Delete Last
// Parameter            : NONE
// Description          : to use Delete Last Node of Linked List
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if (First == NULL && Last == NULL)
    {
        cout << "LL is Empty\n";
        return;
    }
    else if (First->next == First)
    {
        delete First;
        First = NULL;
        Last = NULL;
        cout << "Last node deleted\n";
    }
    else
    {
        Last = Last->prev;
        delete First->prev;
        First->prev = Last;
        Last->next = First;
    }
}

///////////////////////////////////////////////////////////
//
// Function name        : Display
// Parameter            : NONE
// Description          : use to Display all nodes of Linked List
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::Display()
{
    nodeD<T> *temp = First;

    if (First == NULL && Last == NULL)
    {
        cout << "LL is empty"
             << "\n";
        return;
    }

    do
    {
        cout << temp->data << " | ";
        temp = temp->next;
    } while (temp != Last->next);
    cout << "\n";
}

///////////////////////////////////////////////////////////
//
// Function name        : Count
// Parameter            : NONE
// Description          : use to Count all nodes of Linked List
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
int DoublyCL<T>::Count()
{
    int iCnt = 0;
    nodeD<T> *temp = First;
    do
    {
        iCnt++;
        temp = temp->next;
    } while (temp != Last->next);
    return iCnt;
}

///////////////////////////////////////////////////////////
//
// Function name        : SumAll
// Parameter            : NONE
// Description          : use to Sumation of all elements in Linked List
// Return               : NONE
//
///////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>::SumAll()
{
    int Sum = 0;
    nodeS<T> *temp = First;
    while (temp != NULL)
    {
        Sum = temp->data + Sum;
        temp = temp->next;
    }
    cout << "Sumation is :- " << Sum << "\n";
}

///////////////////////////////////////////////////////////
//
// Function name        : OddCount
// Parameter            : NONE
// Description          : use to Display Odd Counts of all elements in Linked List
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::OddCount()
{
    int iCnt = 0;
    nodeS<T> *temp = First;

    while (temp != NULL)
    {
        if (temp->data % 2 != 0)
        {
            iCnt++;
        }
        temp = temp->next;
    }
    cout << "Odd Count is :- " << iCnt << "\n";
}

///////////////////////////////////////////////////////////
//
// Function name        : Search First
// Parameter            : NONE
// Description          : Occurance of First element which you want to search first
// Return               : Integer
//
///////////////////////////////////////////////////////////

template <class T>
int SinglyLL<T>::SearchFirst(int value)
{
    int i = 0;
    nodeS<T> *temp = First;

    while (temp != NULL)
    {
        i++;
        if (temp->data == value)
        {
            break;
        }
    }

    return i + 1;
}

///////////////////////////////////////////////////////////
//
// Function name        : Search First
// Parameter            : NONE
// Description          : Occurance of Last element which you want to search
// Return               : Integer
//
///////////////////////////////////////////////////////////

template <class T>
int SinglyLL<T>::SearchLast(int value)
{
    int iCnt = 0;
    int i = 0;
    nodeS<T> *temp = First;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            iCnt = i + 1;
        }
        i++;
    }
    return iCnt;
}

///////////////////////////////////////////////////////////
//
// Function name        : EvenCount
// Parameter            : NONE
// Description          : Use to Count the even elements of linked list
// Return               : NONE
//
///////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::EvenCount()
{
    int iCnt = 0;
    nodeS<T> *temp = First;
    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
        {
            iCnt++;
        }
    }
    cout << "Even Count is :- " << iCnt << "\n";
}

int main()
{

    return 0;
}