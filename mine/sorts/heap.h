/*************************************************************************
    > File Name: heap.h
    > Author: Feng
    > Created Time: Thursday, December 20, 2018 PM08:25:19 CST
    > Content: 
 ************************************************************************/

#include <iostream>

using namespace std;

template <typename T, typename cmp>
class MaxHeap
{
public:
    explicit MaxHeap(int32_t capacity);
    explicit MaxHeap(MaxHeap&& other);
    MaxHeap& operator=(MaxHeap&& other);

    explicit MaxHeap(const MaxHeap& other) = delete;
    MaxHeap& operator=(const MaxHeap& other) = delete;

    ~MaxHeap();
    void Initialize(T* t, int32_t len);

    const T& Max();
    void Push(const T& t);
    void Pop();
    int32_t capacity();
    int32_t size();
    bool Empty();

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
MaxHeap<T>::MaxHeap(const MaxHeap&& other)
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
const T& MaxHeap<T>::Max()
{
    return heap_[1];
}

template <typename T>
void MaxHeap<T>::Push(const T& t)
{
    if (size_ == capacity_ - 1) {
        Resize<T>();
    }

    int32_t hole = size_ + 1;

    while (hole > 1 && heap_[hole / 2] < t) {
        heap_[hole] = heap_[hole / 2];
        hole = hole / 2;
    }
    heap_[hole] = t;
}

template <typename T>
void MaxHeap<T>::Pop()
{
    int32_t hole = 1;
    int32_t child = 0;
    heap_[hole] = heap_[size_];
    T& t = heap_[hole];
    size_--;
    while (hole * 2 <= size_) {
        child = hole * 2;
        if (hole * 2 + 1 <= size_ && heap_[hole * 2] < heap_[hole * 2 + 1]) {
            child++;
        }

        if (t < heap_[child]) {
            heap_[hole] = heap_[child];
        } else {
            break;
        }

        hole = child;
    }
    heap_[hole] = t;
}

