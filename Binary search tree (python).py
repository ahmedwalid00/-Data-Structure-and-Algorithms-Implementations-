class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


class BinaryTree:
    def __init__(self):
        self.root = None

    def insert(self, item):
        if self.root is None:
            self.root = Node(item)
        else:
            self.insert_recursively(self.root, item)

    def insert_recursively(self, node, item):
        if item < node.value:
            if node.left is None:
                node.left = Node(item)
            else:
                self.insert_recursively(node.left, item)
        else:
            if node.right is None:
                node.right = Node(item)
            else:
                self.insert_recursively(node.right, item)

    def pre_order_traversal(self):
        self.pre_order_recursively(self.root)

    def pre_order_recursively(self, node):
        if node:
            print(node.value, end=" ")
            self.pre_order_recursively(node.left)
            self.pre_order_recursively(node.right)

    def search(self, item):
        return self.search_recursively(self.root, item)

    def search_recursively(self, node, item):
        if node is None:
            return False
        
        if node.value == item:
            return True
        
        if item < node.value:
            return self.search_recursively(node.left, item)
        else:
            return self.search_recursively(node.right, item)

    def get_min(self):
        if self.root is None:
            print("The tree is empty.")
            return None
        else:
            return self.get_min_recursively(self.root)

    def get_min_recursively(self, node):
        while node.left is not None:
            node = node.left
        return node.value


ob1 = BinaryTree()
ob1.insert(5)
ob1.insert(3)
ob1.insert(1)
ob1.insert(4)
ob1.insert(2)

print("Pre-order Traversal:")
ob1.pre_order_traversal()  

print("\nSearch for 4:", ob1.search(4))  
print("Search for 6:", ob1.search(6))  

print("Minimum value in the tree:", ob1.get_min())  
