#![allow(dead_code)]
use std::fmt::Display;

fn main() {
    println!("hello");
}

struct Queue<T> {
    queue: Vec<T>,
    front: u32,
    back: u32,
    capacity: u32
}

impl<T> Queue<T> where T: Copy + Display {
    fn new(capacity: usize) -> Queue<T> {

    }
}
