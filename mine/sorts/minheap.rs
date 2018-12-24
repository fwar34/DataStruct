use std::fmt::Display;

struct MinHeap<T> {
    heap: Vec<T>,
}

impl<T: Copy + PartialOrd + Display> MinHeap<T> {
    fn new(heap: &[T]) -> MinHeap<T> {
        let minheap = MinHeap {
            heap: Vec::new(),
        };

        minheap.heap.push(-1);
        for i in heap {
            minheap.heap.push(*i);
        }

        minheap
    }

    fn new2(capacity: usize) -> MinHeap<T> {
        MinHeap {
            heap: Vec::with_capacity(capacity),
        }
    }

    fn min(&self) -> &T {
        &self.heap[1]
    }

    fn push(&self, t: &T) {

    }

    fn pop(&self) {

    }

    fn sink(&mut self, mut i: usize) {
        let t: T = self.heap[i].clone();
        while 2 * i <= self.heap.len() { // node i have leaf
            let mut child = 2 * i;
            // node i have right leaf and right leaf is less than left leaf
            if child < self.heap.len() && self.heap[child] > self.heap[child + 1] { 
                child = child + 1;
            }

            if &self.heap[i] > &self.heap[child] {
                self.heap[i] = self.heap[child].clone();
                i = child;
            } else {
                break;
            }
        }
        self.heap[i] = t;
    }

    fn swim(&mut self, mut i: usize) {
        let t: T = self.heap[i].clone();
        while i > 1 && &self.heap[i / 2] < &self.heap[i] {
            self.heap[i] = self.heap[i / 2].clone();
            i = i / 2;
        }
        self.heap[i] = t;
    }

    fn dump(&self) {
        for i in 1..self.heap.len() {
            println!("{} ", self.heap[i]);
        }
    }

    fn move_to(&mut self, other: Vec<T>) {
        self.heap = other;
    }
}

fn main() {
    let heap = MinHeap { heap: vec![100, -5, 9, 0, -108, 33] };
    let heap = MinHeap::new(&vec![100, -5, 9, 0, -108, 33]);
    let heap = MinHeap::new(&[100, -5, 9, 0, -108, 33]);
    heap.dump();
}
