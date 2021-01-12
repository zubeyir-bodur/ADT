/**
 * Author: Zubeyir Bodur
 * Date: 10.1.2021
 */
#include "linkedlist/header/LinkedList.h"
#include "linkedlist/source/LinkedList.cpp"
#include <string>

int main() {
    // TEST OF LINKED LISTS
    cout << "BEGINNING OF LL TEST" << endl;
    LinkedList<int> list = LinkedList<int>();
    list.display();
    list.addHead(2);
    list.display();
    list.addHead(3);
    list.display();
    list.addHead(5);
    list.display();
    list.displayReverse();
    list.displayR();
    LinkedList<int> copy = LinkedList<int>(list);
    copy.addTail(10);
    cout << "Copy LL : ";
    copy.displayR();
    cout << "Orig LL : ";
    list.display();
    cout << "Size of copy : " << copy.getSize() << endl;
    cout << "Size of orig : " << list.getSize() << endl;
    LinkedList<string> strList = LinkedList<string>();
    strList.addHead("one");
    strList.addHead("zero");
    strList.addHead("minus one!");
    strList.addHead("kinda fun");
    cout << "String LL : ";
    strList.display();
    strList.reverseR();
    strList.display();
    cout << "contains \"kinda fun\" : " << (strList.contains("kinda fun") ? "true" : "false") << endl;
    list.display();
    cout << strList.get(1) << endl;
    strList.insert("IM AT 1", 1);
    strList.display();
    LinkedList<string> reverseStr = strList.getReverse();
    reverseStr.display();
    cout << list;
    cout << "print the reversed version of the reverse : " << reverseStr;
    copy.removeHead();
    cout << copy;
    copy.sort();
    cout << copy;
    list.sort();
    cout << list;
    strList.sort();
    cout << strList;
    cout << "END OF LL TEST" << endl;
}