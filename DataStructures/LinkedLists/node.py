'''Node class file'''
class Node(object):
    '''Node class'''
    def __init__(self, data):
        '''Init'''
        self.data = data
        self.next = None

    def get_next(self):
        '''Gets next node'''
        return self.next

    def get_data(self):
        '''Gets data of current node'''
        return self.data
