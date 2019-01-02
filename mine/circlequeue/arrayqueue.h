/*************************************************************************
    > File Name: arrayqueue.h
    > Author: Feng
    > Created Time: Sunday, December 30, 2018 AM09:23:51 CST
    > Content: 
 ************************************************************************/

#include <iostream>

using namespace std;

template <typename T>
class ArrayQueue
{
public:
    ArrayQueue();
    ~ArrayQueue();
    ArrayQueue(const ArrayQueue& other) = delete;
    ArrayQueue& operator=(const ArrayQueue& other) = delete;

    ArrayQueue(ArrayQueue&& other);
    ArrayQueue& operator=(ArrayQueue&& other);

    bool Empty() const;
    uint32_t Size() const;
    T& Front();
    T& Back();
    void Pop();
    void Push(const T &element);

private:
    T *queue_;
    uint32_t queue_capacity_;
    uint32_t queue_front_;
    uint32_t queue_back_;
};

template <typename T>
ArrayQueue<T>::ArrayQueue()
{
    queue_ = new T[queue_len];
    queue_capacity_ = 1024;
    queue_front_ = 0;
    queue_back_ = 0;
}

template <typename T>
ArrayQueue<T>::~ArrayQueue()
{
    if (queue_) {
        delete[] queue_;
    }
    queue_front_ = 0;
    queue_back_ = 0;
}

template <typename T>
ArrayQueue<T>::ArrayQueue(ArrayQueue&& other)
{
    if (this != &other) {
        queue_ = other.queue_;
        other.queue_ = nullptr;
        queue_front_ = other.queue_front_;
        queue_back_ = other.queue_back_;
        other.queue_front_ = 0;
        other.queue_back_ = 0;
    }
}

template <typename T>
ArrayQueue& ArrayQueue<T>::operator=(ArrayQueue&& other)
{
    if (this != &other) {
        queue_ = other.queue_;
        other.queue_ = nullptr;
        queue_front_ = other.queue_front_;
        queue_back_ = other.queue_back_;
        other.queue_front_ = 0;
        other.queue_back_ = 0;
    }

    return *this;
}

template <typename T>
bool ArrayQueue<T>::Empty() const
{
    return queue_front_ == queue_back_;
}

template <typename T>
uint32_t ArrayQueue<T>::Size() const
{

}

template <typename T>
T& ArrayQueue<T>::Front()
{
    return queue_[queue_front_ + 1];
}

template <typename T>
T& ArrayQueue<T>::Back()
{
    return queue_[queue_back_];
}

template <typename T>
void ArrayQueue<T>::Pop()
{
    T& t = queue_[queue_front_];
    if (t) {
        delete t;
    }
    
    queue_front_ = ++queue_front_ % queue_capacity_;
}

template <typename T>
void ArrayQueue<T>::Push(const T& element)
{
    if ((queue_back_ + 1) % queue_capacity_ == queue_front_) {
        T* t = new T[2 * queue_capacity_];
        for (uint32_t i = 0; i < queue_capacity_; ++i) {
            t[i] = std::move(queue_[i]);
        }
        queue_capacity_ *= 2;
    }

    queue_[++queue_back_ % queue_capacity_] = std::move(t);
}
