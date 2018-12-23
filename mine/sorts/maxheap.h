/*************************************************************************
    > File Name: heap.h
    > Author: Feng
    > Created Time: Thursday, December 20, 2018 PM08:25:19 CST
    > Content: 
 ************************************************************************/

#include <iostream>

using namespace std;

template <typename T>
class MaxHeap
{
public:
    explicit MaxHeap(int32_t capacity);
    explicit MaxHeap(MaxHeap&& other);
    MaxHeap& operator=(MaxHeap&& other);

    explicit MaxHeap(const MaxHeap& other) = delete;
    MaxHeap& operator=(const MaxHeap& other) = delete;

    ~MaxHeap();
    void BuildHeap(const T* t, int32_t len);

    const T& Max();
    void Sink(int32_t i);
    void Swim(int32_t i);
    void Push(const T& t);
    void Pop();
    int32_t capacity();
    int32_t size();
    bool Empty();
    void Dump();

private:
    void Resize();

private:
    T* heap_;
    int32_t capacity_;
    int32_t size_;
};

template <typename T>
MaxHeap<T>::MaxHeap(int32_t capacity)
{
    capacity_ = capacity + 1;
    heap_ = new T[capacity_];
    size_ = 0;
}

template <typename T>
MaxHeap<T>::~MaxHeap()
{
    if (heap_) {
        delete[] heap_;
    }
    capacity_ = 0;
    size_ = 0;
}

template <typename T>
void MaxHeap<T>::Resize()
{
    capacity_ = 2 * capacity_;
    T* t = new T[capacity_];
    for (int32_t i = 0; i < size_; ++i) {
        t[i] = heap_[i];
    }
    delete[] heap_;
    heap_ = t;
}

template <typename T>
MaxHeap<T>::MaxHeap(MaxHeap&& other)
{
    if (this != &other) {
        heap_ = other.heap_;
        capacity_ = other.capacity_;
        size_ = other.size_;

        other.heap_ = nullptr;
        other.capacity_ = 0;
        other.size_ = 0;
    }
}

template <typename T>
MaxHeap<T>& MaxHeap<T>::operator=(MaxHeap&& other)
{
    if (this != &other) {
        heap_ = other.heap_;
        capacity_ = other.capacity_;
        size_ = other.size_;

        other.heap_ = nullptr;
        other.capacity_ = 0;
        other.size_ = 0;
    }

    return *this;
}

template <typename T>
void MaxHeap<T>::Sink(int32_t i)
{
    T t = heap_[i];
    int32_t child = 0;
    while (2 * i <= size_) { //node i has leaf
        child = 2 * i;
        if (child < size_ && heap_[child] < heap_[child + 1]) {
            child++;
        }

        if (t < heap_[child]) {
            heap_[i] = heap_[child];
            i = child;
        } else {
            break;
        }
    }
    heap_[i] = t;
}

template <typename T>
void MaxHeap<T>::Swim(int32_t i)
{
    T t = heap_[i];
    while (i > 1 && heap_[i] > heap_[i / 2]) {
        heap_[i] = heap_[i / 2];
        i = i / 2;
    }
    heap_[i] = t;
}

template <typename T>
const T& MaxHeap<T>::Max()
{
    return heap_[1];
}

template <typename T>
void MaxHeap<T>::Push(const T& t)
{
    if (size_ == capacity_) {
        Resize();
    }

    heap_[++size_] = t;
    Swim(size_);
}

template <typename T>
void MaxHeap<T>::Pop()
{
    heap_[1] = heap_[size_--];
    Sink(1);
}

template <typename T>
void MaxHeap<T>::BuildHeap(const T* t, int32_t len)
{
    for (int32_t i = 1; i <= len; ++i) {
        heap_[i] = t[i];
    }
    size_ = len;

    for (int32_t i = size_ / 2; i > 0; i--) {
        Sink(i);
    }
}

template <typename T>
void MaxHeap<T>::Dump()
{
    for (int32_t i = 1; i <= size_; ++i) {
        cout << heap_[i] << " ";
    }
}
