class Node:
    def __init__(self,value):
        self.value=value
        self.left=None
        self.right=None

    def printNode(self):
        print(self.value)

    def printAlbero(self):
        if self.left:
            self.left.printAlbero()
        self.printNode()
        if self.right:
            self.right.printAlbero()

    def printAlberoPreordine(self):
        self.printNode()
        if self.left:
            self.left.printAlbero()
        if self.right:
            self.right.printAlbero()

    def printAlbero(self):
        if self.left:
            self.left.printAlbero()
        if self.right:
            self.right.printAlbero()
        self.printNode()

    def getDeep(self):
        n,nleft,nright=0,0,0
        if self.left:
            nleft+=self.left.getDeep()+1
        if self.right:
            nright+=self.right.getDeep()+1
        if nright> nleft:
            n+=nright
        else:
            n+=nleft
        return n

    def findNode(self,value):
        n=False
        if value==self.value:
            n=self
        elif value < self.value:
            if self.left:
                n=self.left.findNode(value)
            else:
                return False
        elif value > self.value:
            if self.right:
                n=self.right.findNode(value)
            else:
                return False
        return n

    def insertNode(self, value):
        if self.value:
            if value > self.value:
                if self.right is None:
                    self.right=Node(value)
                else:
                    self.right.insertNode(value)
            elif value < self.value:
                if self.left is None:
                    self.left=Node(value)
                else:
                    self.left.insertNode(value)
        else:
            self.value=value
    
def main():
    albero=Node(60)
    albero.insertNode(50)
    albero.insertNode(40)
    albero.insertNode(30)
    albero.insertNode(35)
    n1= albero.findNode(30)
    if n1!=False:
        n1.printNode()
    print(albero.getDeep())
if __name__=="__main__":
    main()