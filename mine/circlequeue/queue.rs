#![allow(dead_code)]
use std::fmt::Display;

fn main() {
    let mut q: Queue<i32> = Queue::new(4);
    q.build(&0);
    println!("{}", q.empty());
    println!("{}", q.full());
    q.push(&3);
    println!("{}", q.empty());
    println!("{}", q.full());
    q.push(&4);
    q.push(&5);
    q.push(&6);
    println!("{}", q.empty());
    println!("{}", q.full());
    q.dump();
    q.pop();
    println!("-----------------");
    q.dump();
    q.push(&7);
    q.dump();
    println!("{}", q.empty());
    println!("{}", q.full());
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    println!("{}", q.empty());
    println!("{}", q.full());
}

struct Queue<T> {
    queue: Vec<T>,
    front: usize,
    back: usize,
    capacity: usize
}

impl<T> Queue<T> where T: Copy + Display {
    fn new(capacity: usize) -> Queue<T> {
        Queue {
            queue: Vec::with_capacity(capacity + 1),
            front: 0,
            back: 0,
            capacity: capacity + 1
        }
    }

    fn build(&mut self, t: &T) {
        for _i in 0..self.capacity {
            self.queue.push(*t);
        }
    }

    fn full(&self) -> bool {
        (self.back + 1) % self.capacity == self.front
    }

    fn empty(&self) -> bool {
        self.front == self.back
    }

    fn front(&self) -> &T {
        &self.queue[self.front + 1]
    }

    fn back(&self) -> &T {
        &self.queue[self.back]
    }

    fn push(&mut self, t: &T) -> bool {
        if self.full() {
            return true;
        }
        self.back = (self.back + 1) % self.capacity;
        self.queue[self.back] = *t;
        true
    }

    fn pop(&mut self) -> bool {
        if self.empty() {
            return false;
        }
        self.front = (self.front + 1) % self.capacity;
        true
    }

    fn dump(&self) {
        if self.front < self.back {
            for i in self.front + 1..self.back + 1 {
                println!("{}", self.queue[i]);
            }
        } else if self.front > self.back {
            println!("~~~~~~~~~~~~~~{}, {}", self.front + 1, self.queue.capacity());
            for i in self.front + 1..self.queue.capacity() {
                println!("{}", self.queue[i]);
            }

            println!("~~~~~~~~~~~~~~{}, {}", self.front + 1, self.queue.capacity());

            for i in 0..self.back + 1 {
                println!("{}", self.queue[i]);
            }
        }
    }
}
