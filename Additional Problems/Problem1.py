
x = [6,2,4,7,7,9,3]

range_cow = x[0]

cow_height = []

for i in range(range_cow):
	cow_height.append(x[i])

sorted_cow = cow_height.sort()

my_sorted = []

count = 0 

while not (sorted_cow == my_sorted):
	smallest = min(cow_height)
	
	while (smallest in cow_height):
		cow_height.remove(smallest)
		my_sorted.append(smallest)
	count += 1

print(count)


