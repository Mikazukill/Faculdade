#include <string>
#include "QueueTAD.h"
#include "ListDoubleLinked.h"

using namespace std;

class QueueDoubleLinked : public QueueTAD {
    private:
        ListDoubleLinked *data;
        int count;

    public:
        QueueDoubleLinked();
        void enqueue(int element);
        int head();
        int dequeue();
        string toString();
        void clear();
        bool isEmpty();
        int size();
};