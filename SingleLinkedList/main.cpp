#include <iostream>
#include <unistd.h>

#define TRACE 1 /*Trace level:                  */
                /*              0 - disable     */
                /*              1 - test        */
                /*              2 - debug       */
#define MIN_INT -32768;

//template<class T> will be added lateron
class Node {
    public:
        int data;
        Node *next;
        Node(int _data);
};

Node::Node(int _data) : data(_data), next(nullptr) {
    if(TRACE & 2)
        std::cout << "Node Constructor Node(int data) called." << std::endl;
}

//template<class T> will be added lateron
class LinkedList {
private:
    Node *head;
    int size;
public:
    ~LinkedList();
    // Implement Copy Semantics => the rule of three including destructor
    LinkedList(const LinkedList &ll);
    LinkedList& operator=(const LinkedList &ll);
    // Implement move Semantics => the rule of five including destructor
    LinkedList(LinkedList &&ll);
    LinkedList& operator=(LinkedList &&ll);
    LinkedList();

    void _displayRec(Node *currNode);
    void _pushFront(int data);
    void _pushBack(int data);
    void _insert(int index, int data);
    int _popFront();
    int _popBack();
    int _erase(int index);
    void _reverse();
    void _removeDuplicate();
    static int _max(Node *currentNode);
    int _isSorted();
    static LinkedList _merge(LinkedList linkedListA, LinkedList linkedListB);
    void _merge(LinkedList linkedListB);
    Node* _getHead() { return this->head;}
    int _getSize() { return this->size;}
};

LinkedList::LinkedList(const LinkedList &ll) : head(nullptr), size(0) {
    if(TRACE & 2)
        std::cout << "Linked List Constructor LinkedList(const LinkedList &ll) called." << std::endl;
    Node* rhsHead = ll.head;
    while(rhsHead != nullptr) {
        this->_pushBack(rhsHead->data);
        rhsHead = rhsHead->next;
    }
}

LinkedList& LinkedList::operator=(const LinkedList &ll) {
    if(TRACE & 2)
        std::cout << "Assigment operator operator=(const LinkedList &linkedList) called." << std::endl;
    if(this != &ll) {
        LinkedList copyLl(ll);                  //copy with copy constructor
        std::swap(this->head, copyLl.head);     //swap the heads
    }
    this->size = ll.size;
    return *this;
}

LinkedList::LinkedList(LinkedList &&ll) : head(nullptr), size(0) {
    if(TRACE & 2)
        std::cout << "Linked List Constructor LinkedList(LinkedList &&ll) called." << std::endl;
    std::swap(this->head, ll.head);
    std::swap(this->size, ll.size);
}

LinkedList& LinkedList::operator=(LinkedList &&ll) {
    if(TRACE & 2)
        std::cout << "Assigment operator operator=(LinkedList &&ll) called." << std::endl;
    if(this != &ll) {
        std::swap(this->head, ll.head);
        std::swap(this->size, ll.size);
    }
    return *this;
}

LinkedList::LinkedList() : head(nullptr), size(0) {
    if(TRACE & 2)
        std::cout << "Linked List Constructor LinkedList() called." << std::endl;
}

LinkedList::~LinkedList() {
    if(TRACE & 2)
        std::cout << "Linked List destructor LinkedList() called." << std::endl;
    Node *temp = this->head;
    while(this->head != nullptr) {
        this->_popFront();
    }
}

void LinkedList::_displayRec(Node *currNode) {
    if(currNode == nullptr)
        return;
    else if(currNode->next != nullptr) {
        std::cout << currNode->data << ", ";
        _displayRec(currNode->next);
    } else {
        std::cout << currNode->data << std::endl;
    }
}

void LinkedList::_pushFront(int data) {
    Node *newNode;

    newNode = new Node(data);
    if(this->head != nullptr) {
        newNode->next = this->head;
    }
    this->head = newNode;
    this->size++;
    if(TRACE &2)
        std::cout << "New node added at the front of LinkedList." << std::endl;
}

void LinkedList::_pushBack(int data) {
    Node *currentNode;
    Node *newNode;

    currentNode = this->_getHead();
    newNode = new Node(data);
    if(currentNode != nullptr) {
        while(currentNode->next != nullptr) {
            currentNode = currentNode->next;
        }
            currentNode->next = newNode;
    } else {
        this->head = newNode;
    }
    this->size++;
    if(TRACE & 2)
        std::cout << "New node added at the end of LinkedList." << std::endl;
}

void LinkedList::_insert(int index, int data) {
    Node *currentNode;
    Node *newNode;
    int i;

    currentNode = this->head;

    if(index < 0 || index > size) {
        if(TRACE & 2)
            std::cout << "Index is out of range." << std::endl;
        return;
    }
    if(index == 0) {
        _pushFront(data);
    } else {
        for(i=0; i<index-1; i++) {
            currentNode = currentNode->next;
        }
        newNode = new Node(data);
        newNode->next = currentNode->next;
        currentNode->next = newNode;
        this->size++;
        if(TRACE & 2)
            std::cout << "New node added at the position " << index << " of LinkedList." << std::endl;
    }
}

int LinkedList::_popFront() {
    Node *tmpNode;
    int ret;

    if(size == 0)
        return MIN_INT;

    tmpNode = this->head;
    this->head = tmpNode->next;
    ret = tmpNode->data;
    delete tmpNode;
    if(TRACE & 2)
         std::cout << "Node deletet at the front of LinkedList with val=<" << ret << ">." << std::endl;
    this->size--;
    return ret;
}

int LinkedList::_popBack() {
    Node *tmpNode;
    Node *tmpPrevNode = nullptr;
    int ret;

    if(size == 0)
        return MIN_INT;

    tmpNode = this->head;
    while(tmpNode->next != nullptr) {
        tmpPrevNode = tmpNode;
        tmpNode = tmpNode->next;
    }
    ret = tmpNode->data;
    tmpPrevNode->next = nullptr;
    delete tmpNode;
    if(TRACE & 2)
         std::cout << "Node deletet at the end of LinkedList with val=<" << ret << ">." << std::endl;
    this->size--;
    return ret;
}

int LinkedList::_erase(int index) {
    Node *currentNode;
    Node *tmpPrevNode = nullptr;
    int i;
    int ret;
    
    if(index < 0 || index >= size) {
        if(TRACE & 2)
            std::cout << "Index is out of range." << std::endl;
        return MIN_INT;
    }
    if(index == 0) {
        ret = this->_popFront();
    } else if(index-1 == size) {
        ret = this->_popBack();
    } else {
        currentNode = this->_getHead();
        for(i=0; i<index; i++) {
            tmpPrevNode = currentNode;
            currentNode = currentNode->next;
        }
        tmpPrevNode->next = currentNode->next;
        ret = currentNode->data;
        delete currentNode;
        this->size--;
    }
    return ret;
}

void LinkedList::_reverse() {
    Node *currentNode = this->_getHead();
    Node *prevNode = nullptr;
    Node *tmpNode = nullptr;

    while(currentNode != nullptr) {
        prevNode = tmpNode;
        tmpNode = currentNode;
        currentNode = currentNode->next;
        tmpNode->next = prevNode;
    }
    this->head = tmpNode;
    if(TRACE & 2)
        std::cout << "Linked list has been reversed." << std::endl;
}

void LinkedList::_removeDuplicate() {
    Node *currentNode = this->_getHead();
    Node *tmpDelete;

    while(currentNode->next != nullptr) {
        tmpDelete = currentNode->next;
        if(tmpDelete->data == currentNode->data) {
            currentNode->next = tmpDelete->next;
            delete(tmpDelete);
            continue;
        }
        currentNode = currentNode->next;
    }
    if(TRACE & 2) 
        std::cout << "Remove duplicate done." << std::endl;
}

int LinkedList::_max(Node *currentNode) {
    int tmp;
    if(currentNode == nullptr) {
        return MIN_INT;
    } else {
        tmp = _max(currentNode->next);
        return (tmp > currentNode->data) ? tmp : currentNode->data;
    }
}

int LinkedList::_isSorted() {
    int tmpComparator = MIN_INT;
    Node *currentNode;

    currentNode = this->_getHead();
    if(this->size == 0)
        return 0;
    while(currentNode != nullptr) {
        if(tmpComparator > currentNode->data) {
            return 0;
        } else {
            tmpComparator = currentNode->data;
            currentNode = currentNode->next;
        }
    }
    return 1;
}

LinkedList LinkedList::_merge(LinkedList linkedListA, LinkedList linkedListB) {
    LinkedList mergeLinkedList;
    Node *currentLlA;
    Node *currentLlB;

    if(!linkedListA._isSorted() || !linkedListB._isSorted()) {
        std::cout << "One of linked list is not sorted! Imposible operation." << std::endl;
        return mergeLinkedList;
    }
    currentLlA = std::move(linkedListA._getHead());
    currentLlB = std::move(linkedListB._getHead());

    while(currentLlA != nullptr && currentLlB != nullptr) {
        if(TRACE & 2)
            std::cout << "Compare headA == headB: " << currentLlA->data << " = " << currentLlB->data << " ." << std::endl;
        if(currentLlA->data < currentLlB->data) {
            mergeLinkedList._pushBack(currentLlA->data);
            currentLlA = std::move(currentLlA->next);
        } else {
            mergeLinkedList._pushBack(currentLlB->data);
            currentLlB = std::move(currentLlB->next);
        }
    }
    if(TRACE & 2)
        std::cout << "Merge rest of the list." << std::endl;
    while(currentLlA != nullptr) {
        mergeLinkedList._pushBack(currentLlA->data);
        currentLlA = std::move(currentLlA->next);
    }
    while(currentLlB != nullptr) {
        mergeLinkedList._pushBack(currentLlB->data);
        currentLlB = std::move(currentLlB->next);
    }

    return mergeLinkedList;
}

void LinkedList::_merge(LinkedList linkedListB) {
    Node *currentLlA;
    Node *currentLlB;
    Node *tmpHead;
    Node *tmpHolder;
    int headSign = 0;

    currentLlA = this->_getHead();
    currentLlB = linkedListB._getHead();
    if(currentLlA->data < currentLlB->data) {
        tmpHead = currentLlA;
        headSign = 0;
        currentLlA = currentLlA->next;
    } else {
        tmpHolder = new Node(currentLlB->data);
        tmpHead = tmpHolder;
        headSign = 1;
        currentLlB = currentLlB->next;
    }

    while(currentLlA != nullptr && currentLlB != nullptr) {
        if(TRACE & 2)
            std::cout << "Compare headA == headB: " << currentLlA->data << " = " << currentLlB->data << " ." << std::endl;
        
        if(currentLlA->data < currentLlB->data) {
            tmpHead->next = currentLlA; 
            currentLlA = currentLlA->next;
            tmpHead = tmpHead->next;
        } else {
            tmpHead->next = new Node(currentLlB->data); 
            currentLlB= currentLlB->next;
            tmpHead = tmpHead->next;
        }
    }
    if(TRACE & 2)
        std::cout << "Merge rest of the list." << std::endl;
    if(currentLlA != nullptr) {
        tmpHead->next = currentLlA;
    }
    while(currentLlB != nullptr) {
        tmpHead->next = new Node(currentLlB->data); 
        currentLlB= currentLlB->next;
        tmpHead = tmpHead->next;
    }
    if(!headSign) {
        this->head = this->head;
        this->size = this->size + linkedListB._getSize();
    } else {
        this->head = linkedListB._getHead();
    }
}

int main() {
    int i;
    std::cout <<"\nPerform test 1. Display and pushFront.\n" << std::endl;
    sleep(1);
    LinkedList ll_1;
    for(i=0; i<10; i++)
        ll_1._pushFront(i);
    std::cout << "display ll_1: " << "max: " << ll_1._max(ll_1._getHead()) << ", size:"  << ll_1._getSize() << std::endl;
    ll_1._displayRec(ll_1._getHead());

    std::cout <<"\nPerform test 2. Display and copy constructor.\n" << std::endl;
    sleep(1);
    LinkedList ll_2(ll_1);
    std::cout << "display ll_2: " << "max: " << ll_1._max(ll_1._getHead()) << ", size:"  << ll_2._getSize() << std::endl;
    ll_2._displayRec(ll_2._getHead());

    std::cout <<"\nPerform test 3. Display and move constructor.\n" << std::endl;
    sleep(1);
    LinkedList ll_3(std::move(ll_2));
    std::cout << "display ll_2: " << "max: " << ll_2._max(ll_2._getHead()) << ", size:"  << ll_2._getSize()<< std::endl;
    ll_2._displayRec(ll_2._getHead());
    std::cout << "display ll_3: " << "max: " << ll_3._max(ll_3._getHead()) << ", size:"  << ll_3._getSize() << std::endl;
    ll_3._displayRec(ll_3._getHead());
    
    std::cout <<"\nPerform test 4. Display and insert.\n" << std::endl;
    sleep(1);
    ll_3._displayRec(ll_3._getHead());
    ll_3._insert(0,10);
    std::cout << "display ll_3: " << "max: " << ll_3._max(ll_3._getHead()) << ", size:"  << ll_3._getSize() << std::endl;
    ll_3._displayRec(ll_3._getHead());
    ll_3._insert(5,15);
    std::cout << "display ll_3: " << "max: " << ll_3._max(ll_3._getHead()) << ", size:"  << ll_3._getSize() << std::endl;
    ll_3._displayRec(ll_3._getHead());
    ll_3._insert(20,20);
    std::cout << "display ll_3: " << "max: " << ll_3._max(ll_3._getHead()) << ", size:" << ll_3._getSize() << std::endl;
    ll_3._displayRec(ll_3._getHead());

    std::cout <<"\nPerform test 5. Display and popBack.\n" << std::endl;
    sleep(1);
    ll_3._popBack();
    std::cout << "display ll_3: " << "max: " << ll_3._max(ll_3._getHead()) << ", size:" << ll_3._getSize() << std::endl;
    ll_3._displayRec(ll_3._getHead());

    std::cout <<"\nPerform test 6. Display and erase.\n" << std::endl;
    sleep(1);
    ll_3._erase(5);
    std::cout << "display ll_3 erase: "  << "max: " << ll_3._max(ll_3._getHead()) << ", size:" << ll_3._getSize() << std::endl;
    ll_3._displayRec(ll_3._getHead());
    ll_3._erase(10);
    std::cout << "display ll_3 erase: "  << "max: " << ll_3._max(ll_3._getHead()) << ", size:" << ll_3._getSize() << std::endl;
    ll_3._displayRec(ll_3._getHead());
    ll_3._erase(9);
    std::cout << "display ll_3 erase: "  << "max: " << ll_3._max(ll_3._getHead()) << ", size:" << ll_3._getSize() << std::endl;

    std::cout <<"\nPerform test 7. Display and reverse.\n" << std::endl;
    sleep(1);
    ll_3._displayRec(ll_3._getHead());
    ll_3._reverse();

    std::cout <<"\nPerform test 8. Display and remove duplicate.\n" << std::endl;
    sleep(1);
    ll_3._insert(4, 5);
    ll_3._insert(4, 5);
    ll_3._displayRec(ll_3._getHead());
    ll_3._removeDuplicate();

    std::cout <<"\nPerform test 9. Merge 2 list with result of new list\n" << std::endl;
    sleep(1);
    LinkedList ll_4;
    for(i=0; i<10; i+=2)
        ll_4._pushBack(i);
    LinkedList ll_5;
    for(i=1; i<10; i+=2)
        ll_5._pushBack(i);
    ll_4._displayRec(ll_4._getHead());
    ll_5._displayRec(ll_5._getHead());
    LinkedList ll_6(std::move(LinkedList::_merge(ll_4, ll_5)));
    std::cout << "display ll_6 erase: "  << "max: " << ll_6._max(ll_6._getHead()) << ", size:" << ll_6._getSize() << std::endl;
    ll_6._displayRec(ll_6._getHead());
    ll_4._displayRec(ll_4._getHead());
    ll_5._displayRec(ll_5._getHead());

    std::cout <<"\nPerform test 10. Merge 2 list with result of first list\n" << std::endl;
    sleep(1);
    LinkedList ll_7;
    for(i=10; i<20; i+=2)
        ll_7._pushBack(i);
    LinkedList ll_8;
    for(i=11; i<20; i+=2)
        ll_8._pushBack(i);
    ll_7._displayRec(ll_7._getHead());
    ll_8._displayRec(ll_8._getHead());
    std::cout << "Merge " << std::endl;
    sleep(1);
    ll_7._merge(ll_8);
    ll_7._displayRec(ll_7._getHead());
    ll_8._displayRec(ll_8._getHead());

    std::cout <<"\nPerform test 11. Merge 2 list with move semantics\n" << std::endl;
    sleep(1);
    LinkedList ll_9;
    for(i=10; i<20; i+=2)
        ll_9._pushBack(i);
    LinkedList ll_10;
    for(i=11; i<20; i+=2)
        ll_10._pushBack(i);
    ll_9._displayRec(ll_9._getHead());
    ll_10._displayRec(ll_10._getHead());
    std::cout << "Merge " << std::endl;
    sleep(1);
    ll_9._merge(std::move(ll_10));
    ll_9._displayRec(ll_9._getHead());
    ll_10._displayRec(ll_10._getHead());
    
    return 0;
}