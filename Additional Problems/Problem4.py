import time
x = input().split()

end = int(x[1])
start = int(x[0])

count = 0

while (start != end):
	if (end > (2*start)):
		start *=2
		count += 1
	elif ((abs(end-start)) > ((abs(end-(2*(start-1)))))):
		start = 2 * (start-1)
		count += 2
	elif ((abs(end-start)) > (abs(end-(start+1)))):
		start += 1
		count +=1
	else:
		start -= 1
		count += 1

print()
print(count)