use std::fmt::Display;

struct MinHeap<T> {
    heap: Vec<T>,
}

impl<T: Copy + PartialOrd + Display> MinHeap<T> {
    fn new(heap: &Vec<T>) -> MinHeap<T> {
        MinHeap {
            heap: heap,
        }
    }

    fn new_c(capacity: usize) -> MinHeap<T> {
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

    fn sink(&self, i: i32) {

    }

    fn swim(&self, i: i32) {

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
    heap.dump();
}
