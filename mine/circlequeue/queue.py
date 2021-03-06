import logging

class QError(BaseException):
    def __init__(self, value, message):
        self.value = value
        self.message = message

    def __str__(self):
        # return repr(self.message)
        return self.message

class Queue:

    def __init__(self, capacity):
        self.queue = []
        self.front = 0
        self.back = 0
        self.capacity = capacity + 1
        for i in range(capacity + 1):
            self.queue.append(0)

    def Front(self):
        return self.queue[self.front + 1]

    def Back(self):
        return self.queue[self.back]

    def Push(self, element):
        if self.Full():
            raise QError(-1, 'Queue full')
        else:
            self.back = (self.back + 1) % self.capacity
            self.queue[self.back] = element

    def Pop(self):
        if self.Empty():
            raise QError(-2, 'Queue empty')
        else:
            self.front = (self.front + 1) % self.capacity

    def Full(self):
        return (self.back + 1) % self.capacity == self.front

    def Empty(self):
        return self.front == self.back


if __name__ == '__main__':
    q = Queue(5)
    print(q.Empty())
    print(q.Full())

    try:
        q.Push(3)
        print(q.Empty())
        print(q.Full())
        q.Push(4)
        q.Push(5)
        q.Push(6)
        q.Push(7)
        print(q.Empty())
        print(q.Full())

        q.Pop()
        print(q.Empty())
        print(q.Full())
        q.Pop()
        q.Pop()
        q.Pop()
        print(q.Empty())
        print(q.Full())
        q.Pop()
        print(q.Empty())
        print(q.Full())

        #queue already empty
        q.Pop()
    except QError as e:
        # 通过配置，logging还可以把错误记录到日志文件里，方便事后排查
        logging.exception(e)

    print('END')
