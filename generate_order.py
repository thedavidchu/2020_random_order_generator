# Random order generator

import random


people = ['Nicky', 'Shane', 'Jimmy', 'Vanessa', 'Zan', 'David']
random.shuffle(people)
order = 'The order is:\n'
for i in range(len(people)):
    order += str(i + 1) + '. ' + str(people[i]) + '\n'

print(order)
print('\nNicky, don\'t you dare run it again to make David first on the list!\n\n')

while(True):
    r = input('Type \'Yes\' to agree: ')
    if r == 'Yes':
        break
    else:
        continue
