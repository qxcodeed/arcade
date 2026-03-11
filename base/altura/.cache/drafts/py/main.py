class Node:
    def __init__(self, value=0, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

class BTree:
    def __init__(self, serial=None):
        self.root = None
    def __clone(self, ss, index=[0]):
        if index[0] >= len(ss):
            return None
            
        value = ss[index[0]]
        index[0] += 1
        
        if value == '#':
            return None
            
        try:
            num = int(value)
            node = Node(num)
            node.left = self.__clone(ss, index)
            node.right = self.__clone(ss, index)
            return node
        except ValueError:
            return None
    def bshow(self):
        self.__bshow(self.root)
    
    def __bshow(self, node, inheritance=""):
        if node is not None and (node.left is not None or node.right is not None):
            self.__bshow(node.left, inheritance + "l")
        
        for i in range(len(inheritance) - 1):
            print("│   " if inheritance[i] != inheritance[i+1] else "    ", end="")
        
        if inheritance:
            print("┌───" if inheritance[-1] == 'l' else "└───", end="")
        
        print("#" if node is None else node.value)
        
        if node is not None and (node.left is not None or node.right is not None):
            self.__bshow(node.right, inheritance + "r")

if __name__ == "__main__":
    line = input().strip()
    bt = BTree(line)
    line = input().strip()
    values = line.split()
    
    bt.bshow()
