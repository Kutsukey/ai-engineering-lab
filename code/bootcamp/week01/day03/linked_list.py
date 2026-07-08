class Node:
    def __init__(self, x):
        self.data = x
        self.next = None

    def prepend(self, x):
        newNode = Node(x)
        newNode.next = self
        return newNode

    def append(self,x):
        newNode = Node(x)
        if self is None:
            return newNode
        last = self
        while last.next is not None:
            last = last.next
        last.next = newNode
        return self
    
    def find(self,x):
        current = self
        while current is not None:
            if current.data == x : return True
            current = current.next
        return False

    def delete(self,x):
        if self.find(x) :
            current = self
            while current is not None:
                if current.next.data == x :
                    current.next = current.next.next
                    return self
                current = current.next
            return self
                    
    def insert_after(self,x,n):
        newNode = Node(n)
        current = self
        while current is not None:
            if current.data == x :
                next = current.next
                newNode.next = next
                current.next = newNode
                return self
            current = current.next
                


    def list_printer(self):
        current = self
        while current is not None:
            print(current.data, end=" ")
            current = current.next
        print()
    
if __name__ == "__main__":
    head = Node(10)
    head.next = Node(20)
    head.next.next = Node(30)


    head.list_printer()

    head.append(40)

    head.list_printer()

    print(head.find(50))

    head.insert_after(20,25)

    head.delete(25)

    head.list_printer()