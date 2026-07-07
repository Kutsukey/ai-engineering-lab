class Stack:
    def __init__(self):
        self.arr = []

    def push(self, x):
        self.arr.append(x)
        return None

    def pop(self):
        if self.is_empty():
            return "Underflow"
        return self.arr.pop()


    def peek(self):
        if self.is_empty():
            return "Stack Boş"
        return self.arr[-1]


    def size(self):
        return len(self.arr) # self.top + 1


    def is_empty(self):
        return len(self.arr) == 0
        
stack = Stack()

print(stack.push(x=5))

print(stack.push(10))

print(stack.peek())

print(stack.pop())

print(stack.is_empty())

print(stack.size())
