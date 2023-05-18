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

    def pushAt(self):
        pass

    def insert(self):
        pass

    def pop(self):
        pass

    def popAt(self):
        pass

    def __str__(self) -> str:
        nodes = []
        node = self.head.next
        while node is not None:
            nodes.append(str(node.data))
            node = node.next
        return " <-> ".join(nodes)


newLinkedList = DoublyLinkedList(2, 3, 5, "a", "c")
print(newLinkedList)
newLinkedList.push("d")
newLinkedList.push("f")
print(newLinkedList)
