fn main() {
    let mut a: [i32; 10] = [-1, 19, -66, 78, 0, 7, 98, 11, -66, 100];
    bubble(&mut a);
    println!("{:?}", a);
    let mut a: [i32; 10] = [-1, 19, -66, 78, 0, 7, 98, 11, -66, 100];
    bubble2(&mut a);
    println!("{:?}", a);
}

fn bubble(a: &mut [i32]) {
    for i in 0..a.len() - 1 {
        for j in 0..a.len() - 1 - i {
            //if &a[j] > &a[j + 1] {
            if a[j] > a[j + 1] {
                //let tmp: i32 = a[j];
                let tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

fn bubble2(a: &mut [i32]) {
    for i in 0..a.len() - 1 {
        let mut change: bool = false;
        for j in 0..a.len() - i - 1 {
            if &a[j] > &a[j + 1] {
                let tmp: i32 = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                change = true;
            }
        }
        if !change {
            break;
        }
    }
}
