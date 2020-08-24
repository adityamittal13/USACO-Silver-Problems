x = input().split()

#List Composition
x = [int(i) for i in x]

#Declaring Sides of Variables
first_side = x[0]
second_side = x[1]
third_side = x[2]

#Function for Most Frequent
def most_frequent(list1):
	return max(set(list1), key = list1.count)
combos = []

#Saving all the combinations
for i in range(1, first_side+1):
	for j in range(1, second_side + 1):
		for k in range(1,third_side + 1):
			combos.append(i+j+k)

#Most Frequent Element
element = most_frequent(combos)

print()
print(element)


