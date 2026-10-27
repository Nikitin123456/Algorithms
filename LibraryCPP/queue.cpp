#include "queue.h"
#include "vector.h"

struct Queue
{
    Vector *vec;
    size_t head;
    size_t tail;
    size_t count;
};

Queue *queue_create()
{
    Queue *queue = new Queue;
    queue->vec = vector_create();
    vector_resize(queue->vec, 1);
    queue->head = 0;
    queue->tail = 0;
    queue->count = 0;
    return queue;
}

void queue_delete(Queue *queue)
{
    vector_delete(queue->vec);
    delete queue;
}

void queue_insert(Queue *queue, Data data)
{
    if (queue->count == vector_size(queue->vec))
    {
        size_t old_capacity = vector_size(queue->vec);
        size_t new_capacity = old_capacity * 2;
        vector_resize(queue->vec, new_capacity);

        if (queue->tail <= queue->head)
        {
            for (size_t i = 0; i < queue->tail; ++i)
            {
                vector_set(queue->vec, i + old_capacity, vector_get(queue->vec, i));
            }
            queue->tail += old_capacity;
        }
    }
    vector_set(queue->vec, queue->tail, data);
    queue->tail = (queue->tail + 1) % vector_size(queue->vec);
    queue->count++;
}

Data queue_get(const Queue *queue)
{
    return vector_get(queue->vec, queue->head);
}

void queue_remove(Queue *queue)
{
    queue->head = (queue->head + 1) % vector_size(queue->vec);
    queue->count--;
}

bool queue_empty(const Queue *queue)
{
    return queue->count == 0;
}
