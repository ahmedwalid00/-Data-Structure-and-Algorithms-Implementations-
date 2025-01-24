class node : 
    def __init__(self , data , next = None):
        self.data = data
        self.next = next

class LinkedList : 
    def __init__(self):
        self.head = None
    
    def add(self,value) :
        newNode = node(value)

        if(self.head == None) :
            self.head = newNode
        else : 
            current = self.head

            while(current.next != None) : 
                current = current.next
            current.next = newNode
    
    def display(self) : 
        
        if(self.head == None) : 
            print("The list is empty ")
        else : 
            temp = self.head

            while(temp != None) : 
                print(temp.data , end= " ")
                temp = temp.next
    
    def delete_value(self, value):
        if self.head is None:
            print("The list is empty.")
            return
        
        if self.head.data == value:
            self.head = self.head.next
            return
        
        current = self.head
        previous = None
        
        while current is not None and current.data != value:
            previous = current
            current = current.next
        
        if current is None:  
            print("Item not found.")
            return
        
        previous.next = current.next
        current.next = None
    
 

           
ob1 = LinkedList()
ob1.add(1)
ob1.add(2)
ob1.add(3)
ob1.add(4)
ob1.add(5)
ob1.delete_value(3)

ob1.display()




           

        

