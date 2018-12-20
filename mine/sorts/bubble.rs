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

/**
 * 原因，当冒泡排序发现元素已经是排序好了的时候，并不会停止这将会浪费时间复杂度。
 * 分析：当把大的数不断后移的时候，在下一次再次进行排序检验的时候发现当前已经是排好序的了，那么不再继续循环直接跳出
 * 这里节省的时间复杂度值得是：减少了for循环的次数：比如{1， 3， 2 ，9 ，4} 经过
 * 第一次冒泡后变为{1,2,3,4,9}，此时的flag仍为false，然后继续下一波外层循环，flag此时为true了，但是内部for循环还是要走一遍
 * 这个是必须的否则就会和第二种优化一样不够健壮，在内部for循环里面，没有一次可以进入if判断了，
 * 说明在已经排好的最大数的前面的数组已经为有序的了
 * 此时才应该是break，这种优化只是部分上优化了冒泡。
 **/
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
