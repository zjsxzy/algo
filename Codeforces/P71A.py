n = raw_input()
list = n.split()
x = int(list[0])
y = int(list[1])

while x >= 0 or y >= 0:
	if x >= 2 and y >= 2:
		x -= 2
		y -= 2
	elif x == 1 and y >= 12:
		x -= 1
		y -= 12
	elif y >= 22:
		y -= 22
	else:
		print "Hanako"
		break

	if y >= 22:
		y -= 22
	elif y >= 12 and x >= 1:
		y -= 12
		x -= 1
	elif y >= 2 and x >= 2:
		y -= 2
		x -= 2
	else:
		print "Ciel"
		break
