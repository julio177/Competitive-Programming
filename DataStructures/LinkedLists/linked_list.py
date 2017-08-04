'''Linked list class file'''
from node import Node

class LinkedList(object):
    '''Basic linked list class'''
    def __init__(self):
        '''Initializes linked list with empty head'''
        self.head = None

    def push(self, data):
        '''Adds data at the end of the linked list'''
        if self.head is None:
            self.head = Node(data)
            return

        aux = self.head
        while aux.next:
            aux = aux.next

        aux.next = Node(data)

    def print(self):
        '''Prints data of the linked list'''
        aux = self.head
        while aux:
            print(aux.data, end=' ')
            aux = aux.next
        print('\n')

    def delete_data(self, data):
        '''Deletes node given the value'''
        aux = self.head
        if aux.data == data:
            self.head = self.head.next
            return

        while aux.next:
            previous = aux
            aux = aux.next
            if aux.data == data:
                previous.next = aux.next
                break
        return

    def delete_head(self):
        '''Removes head from linked list'''
        if self.head is None:
            return

        self.head = self.head.next

    def delete_last(self):
        '''Deletes last item of linked list'''
        if self.head is None:
            return
        elif self.head.next is None:
            self.head = None
            return
        aux = self.head
        while aux.next:
            previous = aux
            aux = aux.next
        previous.next = None
