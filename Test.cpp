/**
 * Author: Zubeyir Bodur
 * Date: 10.1.2021
 */
#include "linkedlist/source/LinkedList.cpp"
#include "queue/source/Queue.cpp"
#include "stack/source/Stack.cpp"
#include "bst/source/BinarySearchTree.cpp"
#include "heap/source/Heap.cpp"
#include "priorityq/source/PriorityQueue.cpp"

int main() {
    // TEST OF LINKED LIST
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
    strList.reverse();
    strList.display();
    cout << "contains \"kinda fun\" : " << (strList.contains("kinda fun") ? "true" : "false") << endl;
    list.display();
    cout << strList.get(1) << endl;
    strList.insert("IM AT 1", 1);
    strList.display();
    LinkedList<string> reverseStr = strList.getReverse();
    reverseStr.display();
    cout << list << endl;
    cout << "print the reversed version of the reverse : " << reverseStr << endl;
    copy.removeHead();
    cout << copy << endl;
    copy.sort();
    cout << copy << endl;
    list.sort();
    cout << list << endl;
    strList.sort();
    cout << strList << endl;
    strList.removeTail();
    cout << strList << endl;
    cout << "END OF LL TEST" << endl;

    // TEST OF QUEUE
    cout << endl << "BEGINNING OF QUEUE TEST" << endl;
    Queue<int> queue = Queue<int>();
    queue.enqueue(1);
    queue.enqueue(12);
    queue.enqueue(-32);
    cout << queue << endl;
    cout << "Front : " << queue.getFront() << endl;
    cout << "Dequeue 1st : " << queue.dequeue() << endl;
    queue.display();
    cout << "Dequeue 2nd : " << queue.dequeue() << endl;
    queue.display();
    cout << "Dequeue 3rd : " << queue.dequeue() << endl;
    queue.display();
    try {
        queue.dequeue();
    }
    catch (Exception& e) {
        cout << e.what() << endl;
    }
    cout << "END OF QUEUE TEST" << endl;

    // TEST OF STACK
    cout << endl << "BEGINNING OF STACK TEST" << endl;
    Stack<int> stack = Stack<int>();
    stack.push(-2);
    stack.display();
    stack.push(6);
    stack.push(10);
    stack.push(43);
    stack.push(7);
    cout << stack << endl;
    cout << "Pop : " << stack.pop() << endl;
    stack.display();
    cout << "Final stack size : " << stack.getSize() << endl;
    cout << "Stack top : " << stack.getTop() << endl;
    cout << "END OF STACK TEST" << endl;

    // TEST OF BST
    cout << endl << "BEGINNING OF BST TEST" << endl;
    BinarySearchTree<int> searchTree = BinarySearchTree<int>();
    searchTree.display();
    searchTree.insert(38);
    cout << searchTree << endl;
    searchTree.insert(27);
    cout << searchTree << endl;
    searchTree.insert(67);
    cout << searchTree << endl;
    searchTree.insert(15);
    cout << searchTree << endl;
    searchTree.insert(32);
    cout << searchTree << endl;
    searchTree.insert(54);
    cout << searchTree << endl;
    searchTree.insert(107);
    cout << searchTree << endl;
    searchTree.insert(19); // should remain after removals
    cout << searchTree << endl;
    searchTree.insert(28);
    cout << searchTree << endl;
    searchTree.insert(37);
    cout << searchTree << endl;
    searchTree.insert(47);
    cout << searchTree << endl;
    searchTree.insert(87);
    cout << searchTree << endl;
    searchTree.insert(29);
    cout << searchTree << endl;
    searchTree.insert(36);
    cout << searchTree << endl;
    searchTree.insert(49);
    cout << searchTree << endl;
    searchTree.insert(98);
    cout << searchTree << endl;
    searchTree.insert(50); // should remain after removals
    cout << searchTree << endl;
    searchTree.insert(91);
    cout << "END OF INSERTION" << endl << endl;
    cout << searchTree << endl;
    searchTree.remove(38);
    cout << searchTree << endl;
    searchTree.remove(67);
    cout << searchTree << endl;
    searchTree.remove(107);
    cout << searchTree << endl;
    searchTree.remove(29);
    cout << searchTree << endl;
    searchTree.remove(15);
    cout << searchTree << endl;
    searchTree.remove(87);
    cout << searchTree << endl;
    searchTree.remove(54);
    cout << searchTree << endl;
    searchTree.remove(49);
    cout << searchTree << endl;
    searchTree.remove(59); // should be no change
    searchTree.display();
    cout << endl;
    searchTree.remove(47);
    cout << searchTree << endl;
    searchTree.remove(37);
    cout << searchTree << endl;
    searchTree.remove(36);
    cout << searchTree << endl;
    searchTree.remove(28);
    cout << searchTree << endl;
    searchTree.remove(91);
    cout << searchTree << endl;
    searchTree.remove(32);
    cout << searchTree << endl;
    searchTree.remove(27);
    cout << searchTree << endl;
    searchTree.remove(98);
    searchTree.display();
    cout << endl;
    cout << "END OF BST TEST" << endl;

    // TEST OF HEAP
    cout << endl << "BEGINNING OF HEAP TEST" << endl;
    Heap<int, string> priorityQ = Heap<int, string>(false);
    //Heap<int, string> minHeap = Heap<int>(true);
    // it is impossible for user not to choose a data field
    priorityQ.insert(12, "King");
    priorityQ.insert(8, "Queen");
    priorityQ.insert(3, "General");
    priorityQ.insert(7, "Citizen");
    priorityQ.insert(4, "Earth");
    priorityQ.insert(5, "Earth");
    priorityQ.insert(13, "Earth");
    priorityQ.insert(2, "Earth");
    priorityQ.insert(6, "Earth");
    priorityQ.insert(10, "Earth");
    priorityQ.insert(1, "Earth");
    priorityQ.display();
    cout << endl;
    priorityQ.remove();
    priorityQ.display();
    cout << endl;
    priorityQ.remove();
    priorityQ.display();
    cout << endl;
    priorityQ.remove();
    priorityQ.display();
    cout << endl;
    priorityQ.remove();
    priorityQ.display();
    cout << endl;
    priorityQ.remove();
    priorityQ.display();
    cout << endl;
    cout << endl << "END OF HEAP TEST" << endl;
}