x = input().split()
x = [int(i) for i in x]

range1 = x[0]
book_height = x[1]

cow_heights = []

for i in range(range1):
	cow_heights.append(int(input()))

cow_height = 0

while (cow_height < book_height):
	maximum = max(cow_heights)

	try:
		cow_heights.remove(maximum)
	except:
		pass

	cow_height += maximum

cow_heights.append(maximum)
cow_height -= maximum

excess = []

for i in cow_heights:
	excess_val = i + cow_height - book_height
	if excess_val >= 0:
		excess.append(excess_val)

print()
print(min(excess))