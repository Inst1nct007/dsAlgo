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

    def search(self, node, data):

        if node == None:
            return "Node not found"

        elif data < node.data:
            return self.search(node.left, data)
        
        elif data > node.data:
            return self.search(node.right, data)

        else:
            return node
        
    def searchMin(self, node):
        while node.left != None:
            node = node.left

        return node
    
    def searchMax(self, node):
        while node.right != None:
            node = node.right

        return node
        
    def depth(self, node, data):
        if data < node.data:
            return 1 + self.depth(node.left, data)
        
        elif data > node.data:
            return 1 + self.depth(node.right, data)
        
        else:
            return 0
        
    def height(self, node, data):
        try:
            while data != node.data:
                if data < node.data:
                    node = node.left
                elif data > node.data:
                    node = node.right
            else:
                if node.left == None and node.right == None:
                    return 0
                elif node.left == None:
                    return 1 + self.height(node.right, node.right.data)
                elif node.right == None:
                    return 1 + self.height(node.left, node.left.data)
                else:
                    x = self.height(node.left, node.left.data)
                    y = self.height(node.right, node.right.data)

                    return 1 + (x if x >= y else y)
        except:
            return "Element Not Found"


    def deleteInorderPredecessor(self, node, data):
        if data < node.data:
            node.left = self.deleteInorderPredecessor(node.left, data)
            return node
        
        elif data > node.data:
            node.right = self.deleteInorderPredecessor(node.right, data)
            return node
        
        elif data == node.data:
            if node.left == None and node.right == None:
                return None
            elif node.left == None:
                return node.right
            elif node.right == None:
                return node.left
            elif node.left != None and node.right != None:
                node.data = self.searchMax(node.left).data
                node.left = self.deleteInorderPredecessor(node.left, self.searchMax(node.left).data)
                return node

    def inorderTraverse(self, currentNode) -> None:

        if currentNode.left != None:
            self.inorderTraverse(currentNode.left)

        print(currentNode.data)

        if currentNode.right != None:
            self.inorderTraverse(currentNode.right)


x = Tree(5, 2, 10, 8, 15, 12, 20, 30, 6, 9, 7)

x.deleteInorderPredecessor(x.firstNode, 15)
print(x.firstNode.right.right.right.data)
