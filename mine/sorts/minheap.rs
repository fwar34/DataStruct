#![allow(dead_code)]
use std::fmt::Display;

struct MinHeap<T> {
    heap: Vec<T>,
}

impl<T: Copy + PartialOrd + Display> MinHeap<T> {
    fn new() -> MinHeap<T> {
        MinHeap {
            heap: Vec::new(),
        }
    }

    fn build(&mut self, arr: &[T]) {
        self.heap.push(arr[0]);
        for i in arr.iter() {
            self.heap.push(*i);
        }

        let ib = arr.len() / 2 + 1;
        for i in (1..ib).rev() {
            self.sink(i);
        }
    }

    fn new2(capacity: usize) -> MinHeap<T> {
        MinHeap {
            heap: Vec::with_capacity(capacity),
        }
    }

    fn min(&self) -> &T {
        &self.heap[1]
    }

    fn push(&mut self, t: &T) {
        self.heap.push(*t);
        let i = self.heap.len() - 1;
        self.swim(i);
        //self.swim(self.heap.len() - 1); //error self.heap.len() --> immutable borrow
    }

    fn pop(&mut self) {
        if let Some(last) = self.heap.pop() {
            self.heap[1] = last;
            self.sink(1);
        }
    }

    fn sink(&mut self, mut i: usize) {
        let t: T = self.heap[i].clone();
        while 2 * i <= self.heap.len() - 1 { // node i have leaf
            let mut child = 2 * i;
            // node i have right leaf and right leaf is less than left leaf
            if child < self.heap.len() - 1 && self.heap[child] > self.heap[child + 1] { 
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
    let mut heap1: MinHeap<i32> = MinHeap::new();
    heap1.build(&vec![-11, 3, 0, 88, -87, 1]);
    heap1.dump();

    println!("ttttttttttttttttttttttt");

    let mut heap2: MinHeap<i32> = MinHeap::new();
    heap2.build(&[19, -11, 3, 0, 88, -87, 1]);
    heap2.dump();
}
