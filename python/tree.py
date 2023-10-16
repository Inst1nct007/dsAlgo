class Node:
    def __init__(self, data) -> None:
        self.left = None
        self.data = data
        self.right = None

class Tree:
    def __init__(self, *args) -> None:
        self.firstNode = Node(args[0])
        for i in range(1, len(args)):
            self.__createNode(self.firstNode, args[i])

    def __createNode(self, node, data):
        if data <= node.data:
            if node.left == None:
                node.left = Node(data)
            else:
                self.__createNode(node.left, data)
        else:
            if node.right == None:
                node.right = Node(data)
            else:
                self.__createNode(node.right, data)
        


x = Tree(5, 2, 10, 7, 15, 12)
