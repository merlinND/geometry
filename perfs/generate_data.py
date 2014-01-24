def generateData(outputPath, N):
	print('Doing...')

	with open(outputPath, 'w+') as output:
		for i in range(1, N):
			declaration = 'C object{} 0 0 1\n'.format(i)
			output.write(declaration)
			move = 'MOVE object{} 10 -1\n'.format(i)
			output.write(move)

	print('Done.')

#generateData('input/1.in', 1)
#generateData('input/10.in', 10)
#generateData('input/100.in', 100)
#generateData('input/1000.in', 1000)
#generateData('input/1500.in', 1500)
#generateData('input/2500.in', 2500)
#generateData('input/3250.in', 3250)
#generateData('input/4500.in', 4500)
#generateData('input/5000.in', 5000)
#generateData('input/6250.in', 6250)
#generateData('input/7500.in', 7500)
#generateData('input/8250.in', 8250)
#generateData('input/9000.in', 9000)
#generateData('input/9500.in', 9500)
#generateData('input/10000.in', 10000) # It's over 9000!
#generateData('input/100000.in', 100000)
#generateData('input/1000000.in', 1000000)
#generateData('input/10000000.in', 10000000)
