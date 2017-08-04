from linked_list import LinkedList

my_list = LinkedList()
for i in range(0, 10):
    my_list.push(i)

my_list.print()
my_list.delete_head()
my_list.print()
my_list.delete_last()
my_list.print()
my_list.delete_data(5)
my_list.print()
