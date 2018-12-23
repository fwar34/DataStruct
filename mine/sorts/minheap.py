# element in index 0 is not the heap element
class MinHeap:
    
    def __init__(self, capacity):
        self.capacity = capacity
        self.heap = []

    def Dump(self):
        print(self.heap[1:])

    def Min(self):
        return self.heap[1]

    def Swim(self, i):
        t = self.heap[i]
        while i > 1 and self.heap[i // 2] > self.heap[i]:
            self.heap[i] = self.heap[i // 2]
            i = i // 2
        self.heap[i] = t

    def Sink(self, i):
        t = self.heap[i]
        while 2 * i <= len(self.heap) - 1:  # node i has leaf
            child = 2 * i
            if child < len(self.heap) - 1 and self.heap[child + 1] < self.heap[child]:
                child = child + 1
            if self.heap[child] < t:
                self.heap[i] = self.heap[child]
                i = child
            else:
                break;
        self.heap[i] = t
    
    def Min(self):
        return self.heap[1]

    def Push(self, t):
        self.heap.append(t)
        self.Swim(len(self.heap) - 1)

    def Pop(self):
        self.heap[1] = self.heap[len(self.heap) - 1]
        self.heap.pop()
        self.Sink(1)

    def BuildHeap(self, arr):
        self.heap.append(-1)
        for i in range(len(arr)):
            self.heap.append(arr[i])

        for i in range(len(arr) // 2, 0, -1):
            self.Sink(i)


if __name__ == '__main__':
    arr = [-100, 3, 88, 67, -8, 0, 99, 299, 9, -111]
    heap = MinHeap(20)
    heap.BuildHeap(arr)
    heap.Dump()

