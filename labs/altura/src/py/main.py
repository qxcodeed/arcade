class Node:
    def __init__(self, value=0, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

class BTree:
    def __init__(self, serial=None):
        self.root = None
        # @DROP
        if serial is not None:
            ss = serial.split()
            self.root = self.__clone(ss)
    
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
    # @DROP
    def __find(self, node, value):
        if node is None:
            return None
        if node.value == value:
            return node
        left = self.__find(node.left, value)
        if left is not None:
            return left
        return self.__find(node.right, value)
    
    def find(self, value):
        return self.__find(self.root, value)
    
    def get_altura(self, node):
        if node is None:
            return 0
        return max(self.get_altura(node.left), self.get_altura(node.right)) + 1
    
    def get_height(self):
        return self.get_altura(self.root)
    
    def get_nivel(self, node, nivel, value):
        if node is None:
            return 0
        if node.value == value:
            return nivel
        left = self.get_nivel(node.left, nivel + 1, value)
        if left != 0:
            return left
        return self.get_nivel(node.right, nivel + 1, value)
    
    def get_profundidade(self, value):
        return self.get_nivel(self.root, 1, value)
    # @UNC
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