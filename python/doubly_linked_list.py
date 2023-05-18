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

    def __str__(self) -> str:
        nodes = []
        node = self.head.next
        while node is not None:
            nodes.append(str(node.data))
            node = node.next
        return " <-> ".join(nodes)
