/*************************************************************************
    > File Name: arrayqueue.h
    > Author: Feng
    > Created Time: Sunday, December 30, 2018 AM09:23:51 CST
    > Content: front + 1是第一个元素，full是(back + 1) % capacity == front
 ************************************************************************/

#include <iostream>

using namespace std;

template <typename T>
class ArrayQueue
{
public:
    ArrayQueue(uint32_t capacity);
    ~ArrayQueue();
    ArrayQueue(const ArrayQueue& other) = delete;
    ArrayQueue& operator=(const ArrayQueue& other) = delete;

    ArrayQueue(ArrayQueue&& other);
    ArrayQueue& operator=(ArrayQueue&& other);

    bool Empty() const;
    bool Full() const;
    T& Front();
    T& Back();
    bool Pop();
    bool Push(const T &element);

private:
    T *queue_;
    uint32_t queue_capacity_;
    uint32_t queue_front_;
    uint32_t queue_back_;
};

template <typename T>
ArrayQueue<T>::ArrayQueue(uint32_t capacity)
{
    queue_ = new T[capacity + 1];
    queue_capacity_ = capacity;
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
    queue_capacity_ = 0;
}

template <typename T>
ArrayQueue<T>::ArrayQueue(ArrayQueue&& other)
{
    if (this != &other) {
        queue_ = other.queue_;
        queue_front_ = other.queue_front_;
        queue_back_ = other.queue_back_;
        queue_capacity_ = other.queue_capacity_;

        other.queue_ = nullptr;
        other.queue_front_ = 0;
        other.queue_back_ = 0;
        other.queue_capacity_ = 0;
    }
}

template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(ArrayQueue&& other)
{
    if (this != &other) {
        queue_ = other.queue_;
        queue_front_ = other.queue_front_;
        queue_back_ = other.queue_back_;
        queue_capacity_ = other.queue_capacity_;

        other.queue_ = nullptr;
        other.queue_front_ = 0;
        other.queue_back_ = 0;
        other.queue_capacity_ = 0;
    }

    return *this;
}

template <typename T>
bool ArrayQueue<T>::Empty() const
{
    return queue_front_ == queue_back_;
}

template <typename T>
bool ArrayQueue<T>::Full() const
{
    return (queue_back_ + 1) % queue_capacity_ == queue_front_;
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
bool ArrayQueue<T>::Pop()
{
    if (Empty()) {
        return false;
    }

    queue_front_ = ++queue_front_ % queue_capacity_;
    return true;
}

template <typename T>
bool ArrayQueue<T>::Push(const T& element)
{
    if (Full()) {
        return false;
    }

    queue_[++queue_back_ % queue_capacity_] = std::move(element);
    return true;
}
