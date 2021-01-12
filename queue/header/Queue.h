/**
 * Author: Zubeyir Bodur
 * Date: 9.1.2021
 */
#ifndef ADT_EXERCISE_QUEUE_H
#define ADT_EXERCISE_QUEUE_H
template <typename T>
class Queue {
    friend ostream& operator<<(ostream& out, const Queue<T>& queue) {
        return out << queue.list << endl;
    };
public:

private:
    LinkedList<T> list;
};
#endif
