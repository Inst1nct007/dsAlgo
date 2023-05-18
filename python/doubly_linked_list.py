class Node:
    def __init__(self, data) -> None:
        self.data = data
        self.prev = None
        self.next = None


class DoublyLinkedList:
    def __init__(self, *args) -> None:
        self.head = Node(None)
        self.head.prev = None
        self.head.next = None
        prevNode = self.head
        for i in args:
            newNode = Node(i)
            newNode.prev = prevNode
            prevNode.next = newNode
            newNode.next = None
            prevNode = newNode

    def push(self, data):
        newNode = Node(data)
        lastNode = self.head
        while lastNode.next is not None:
            lastNode = lastNode.next
        newNode.prev = lastNode
        lastNode.next = newNode
        newNode.next = None

    def insert(self, data, pos):
        newNode = Node(data)
        prevNode = self.head
        for i in range(1, pos):
            prevNode = prevNode.next
        try:
            newNode.next = prevNode.next
            newNode.prev = prevNode
            prevNode.next = newNode
        except:
            print("You cannot insert data outside the linked list")

    def pop(self):
        lastNode = self.head
        prevNode = lastNode
        while lastNode.next is not None:
            prevNode = lastNode
            lastNode = lastNode.next

        prevNode.next = None
        del lastNode

    def popAt(self, pos):
        lastNode = self.head
        prevNode = lastNode
        for i in range(pos):
            prevNode = lastNode
            lastNode = lastNode.next
        try:
            prevNode.next = lastNode.next
        except:
            print("You cannot remove an item from outside the linked list")
        try:
            lastNode.next.prev = prevNode
        except:
            pass
        finally:
            del lastNode

    def search(self):
        pass

    def __str__(self) -> str:
        nodes = []
        node = self.head.next
        while node is not None:
            nodes.append(str(node.data))
            node = node.next
        return " <=> ".join(nodes)


class CircularDoublyLinkedList(DoublyLinkedList):
    def __init__(self, *args) -> None:
        self.head = Node(None)
        self.head.next = None
        self.head.prev = None
        prevNode = self.head
        for i in args:
            newNode = Node(i)
            newNode.prev = prevNode
            prevNode.next = newNode
            newNode.next = self.head.next
            prevNode = newNode

    def push(self, data):
        newNode = Node(data)
        lastNode = self.head.next
        while lastNode.next is not self.head.next:
            lastNode = lastNode.next
        newNode.prev = lastNode
        lastNode.next = newNode
        newNode.next = self.head.next

    def insert(self, data, pos):
        newNode = Node(data)
        prevNode = self.head.next
        while prevNode.next is not self.head.next:
            prevNode = prevNode.next
        for i in range(1, pos):
            prevNode = prevNode.next
        newNode.next = prevNode.next
        newNode.prev = prevNode
        prevNode.next = newNode
        if pos == 1:
            self.head.next = newNode

    def pop(self):
        lastNode = self.head
        prevNode = lastNode
        i = 1
        while lastNode.next is not self.head.next or i == 1:
            i += 1
            prevNode = lastNode
            lastNode = lastNode.next

        prevNode.next = self.head.next
        if lastNode is self.head.next:
            del prevNode
            self.head.next = None
        del lastNode

    def popAt(self, pos):
        prevNode = self.head.next
        while prevNode.next is not self.head.next:
            prevNode = prevNode.next
        lastNode = prevNode.next
        for i in range(1, pos):
            prevNode = lastNode
            lastNode = lastNode.next
        prevNode.next = lastNode.next
        lastNode.next.prev = prevNode
        if pos == 1:
            if prevNode == lastNode:
                self.head.next = None
            else:
                self.head.next = prevNode.next
        del lastNode

    def __str__(self) -> str:
        nodes = []
        node = self.head.next
        i = 1
        try:
            while node.next is not self.head.next:
                nodes.append(str(node.data))
                node = node.next
            nodes.append(str(node.data))
        except:
            pass
        return " <=> ".join(nodes)


newLinkedList = CircularDoublyLinkedList(1, 2, 3)
print(newLinkedList)
