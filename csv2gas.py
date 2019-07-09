import sys
import re

clients = []
seconds = []
tests = []
data = {}

# read in csv file
for line in sys.stdin:

	# read the header
	if not clients:
		clients = [word for word in line.rstrip().split(', ')]
		clients.pop(0)
		continue

	# read the data
	seconds = [second for second in line.rstrip().split(', ')]
	test = seconds.pop(0)
	if test not in tests:
		tests += [test]
	if test not in data:
		data[test] = {}
	for i, second in enumerate (seconds):
		data[test][clients[i]] = second

# print extended header
sys.stdout.write("(ns/gas)")
for client in clients:
	sys.stdout.write(", " + client)
sys.stdout.write("\n")

# nanos = ns/gas is run time scaled by amount of gas
# print the test, gas, nanos ...
gas_per_pop = int(data['pop']['gas'])
for test in tests:
	if test in ['nop', 'pop']:
		continue
	sys.stdout.write(test)
	for client in clients:
		if client == 'gas':
			gas_per_test = int(data[test]['gas'])
			gas_per_test -= gas_per_pop
			sys.stdout.write(", %d" % gas_per_test)
			continue
		nanos_per_test = float(data[test][client])*10**9
		nanos_per_pops = float(data['pop'][client])*10**9
		nanos_per_test -= nanos_per_pops
		nanos_per_gas = nanos_per_test/gas_per_test
		sys.stdout.write(", %.2f" % nanos_per_gas)
	sys.stdout.write("\n")
