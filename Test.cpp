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
#include "avltree/source/AVLTree.cpp"

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
    BinarySearchTree<int, string> searchTree = BinarySearchTree<int, string>();
    searchTree.display();
    searchTree.insert(38, "my");
    cout << searchTree << endl;
    searchTree.insert(27, "name");
    cout << searchTree << endl;
    searchTree.insert(67, "is");
    cout << searchTree << endl;
    searchTree.insert(15, "binary");
    cout << searchTree << endl;
    searchTree.insert(32, "search");
    cout << searchTree << endl;
    searchTree.insert(54, "tree");
    cout << searchTree << endl;
    searchTree.insert(107, "i'm not balanced");
    cout << searchTree << endl;
    searchTree.insert(19, "but i'm able to sort"); // should remain after removals
    cout << searchTree << endl;
    searchTree.insert(28, "i");
    cout << searchTree << endl;
    searchTree.insert(37, "work");
    cout << searchTree << endl;
    searchTree.insert(47, "with");
    cout << searchTree << endl;
    searchTree.insert(87, "average time complexity");
    cout << searchTree << endl;
    searchTree.insert(29, "of");
    cout << searchTree << endl;
    searchTree.insert(36, "o(logn)");
    cout << searchTree << endl;
    searchTree.insert(49, "but it's o(n)");
    cout << searchTree << endl;
    searchTree.insert(98, "at the worst case");
    cout << searchTree << endl;
    searchTree.insert(50, "goodbye"); // should remain after removals
    cout << searchTree << endl;
    searchTree.insert(91, "my friend");
    cout << "size : " << searchTree.getSize() << endl;
    cout << "balance factor : " << searchTree.getBalanceFactor() << endl;
    cout << "height: " << searchTree.getHeight() << endl;
    cout << "is balanced : " << (searchTree.isBalanced() ? "Yes" : "No") << endl;
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
    Heap<int, string> minHeap = Heap<int, string>(true);
    //Heap<int> minHeap = Heap<int>(true);
    // it is impossible for user not to choose a item field
    // meaning that key and items are seperate from each other
    // in a pair
    minHeap.insert(12, "King");
    minHeap.insert(8, "White Collar");
    minHeap.insert(3, "General");
    minHeap.insert(7, "BLue Collar");
    minHeap.insert(4, "Alcohol");
    minHeap.insert(5, "Gaming");
    minHeap.insert(13, "Earth");
    minHeap.insert(2, "Tobacco");
    minHeap.insert(6, "Citizen");
    minHeap.insert(10, "Queen");
    minHeap.insert(1, "Drug");
    minHeap.display();
    cout << endl;
    minHeap.remove();
    minHeap.display();
    cout << endl;
    minHeap.remove();
    minHeap.display();
    cout << endl;
    minHeap.remove();
    minHeap.display();
    cout << endl;
    minHeap.remove();
    minHeap.display();
    cout << endl;
    minHeap.remove();
    minHeap.display();
    cout << endl;
    cout << endl << "END OF HEAP TEST" << endl;

    // TEST OF PQ
    cout << endl << "BEGINNING OF PQ TEST" << endl;
    // pq is just a max heap
    PriorityQueue<int, string> pq = PriorityQueue<int, string>();
    pq.enqueue(12, "King");
    pq.enqueue(8, "White Collar");
    pq.enqueue(3, "General");
    pq.enqueue(7, "BLue Collar");
    pq.enqueue(4, "Alcohol");
    pq.enqueue(5, "Gaming");
    pq.enqueue(13, "Earth");
    pq.enqueue(2, "Tobacco");
    pq.enqueue(6, "Citizen");
    pq.enqueue(10, "Queen");
    pq.enqueue(1, "Drug");
    pq.display();
    cout << endl;
    pq.dequeue();
    pq.display();
    cout << endl;
    pq.dequeue();
    pq.display();
    cout << endl;
    pq.dequeue();
    pq.display();
    cout << endl;
    pq.dequeue();
    pq.display();
    cout << endl;
    pq.dequeue();
    pq.display();
    cout << endl;
    cout << endl << "END OF PQ TEST" << endl;

    // TEST OF AVL TREE
    cout << endl << "BEGINNING OF AVL TREE TEST" << endl;
    auto avlTree = AVLTree<int, string>();
    avlTree.display();
    avlTree.insert(50, "bo");
    avlTree.insert(70, "bo");
    avlTree.insert(90, "bo");
    avlTree.insert(115, "bo");
    avlTree.insert(95, "bo");
    avlTree.insert(100, "bo");
    avlTree.insert(80, "bo");
    avlTree.insert(125, "bo");
    avlTree.insert(105, "bo");
    avlTree.insert(110, "bo");
    avlTree.insert(140, "bo");
    avlTree.display();
    avlTree.remove(95);
    cout << endl;
    avlTree.remove(125);
    avlTree.display();
    cout << endl;
    avlTree.remove(105);
    avlTree.display();
    cout << endl << "END OF AVL TREE TEST" << endl;
}