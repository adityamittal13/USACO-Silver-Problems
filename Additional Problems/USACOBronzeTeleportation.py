x = int().input()
x = [int(i) for i in x]

Start = x[0]
End = x[1]
TeleStart = x[2]
TeleEnd = x[3]

Way1 = (abs(Start - TeleStart) + abs(End - TeleEnd))
Way2 = abs(Start - End)
Way3 = (abs(Start - TeleEnd) + abs(TeleStart - End))

Ways = [Way1, Way2, Way3]
print(min(Ways))