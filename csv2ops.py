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
		units = clients.pop(0)
		continue

	# read the data
	seconds = [second for second in line.rstrip().split(', ')]
	test = seconds.pop(0)
	if test not in ['nop', 'pop', 'add64', 'add128', 'add256', 'sub64', 'sub128', 'sub256',
	                'mul64', 'mul128', 'mul256', 'div64', 'div128', 'div256', 'exp']:
		continue
	if test not in tests:
		tests += [test]
	if test not in data:
		data[test] = {}
	for i, second in enumerate (seconds):
		client = clients[i]
		data[test][client] = second

# run time scaled by number of operations

# print header
sys.stdout.write("(ns/OP)")
for client in clients:
	if client == 'gas':
		continue
	sys.stdout.write(", " + client)
sys.stdout.write("\n")

# print the test, gas, nanos, ...
ops_per_loop = 324;
N_ops = 1000000*ops_per_loop
N_exp = 30000*ops_per_loop
for test in tests:
	if test == 'exp':
		N = N_exp
	else:
		N = N_ops
	sys.stdout.write(test)
	for client in clients:
		if client == 'gas':
			continue
		nanos_per_op = float(data[test][client])*10**9/N
		sys.stdout.write(", %.2f" % nanos_per_op)
	sys.stdout.write("\n")


# run time scaled by number of operations and offset by estimated overhead

# print header
sys.stdout.write("\n(ns/OP-POP)")
for client in clients:
	if client == 'gas':
		continue
	sys.stdout.write(", " + client)
sys.stdout.write("\n")

# print the test, gas, nanos, ...
N_pop = N_ops
for test in tests:
	if test in ['nop', 'pop']:
		continue
	if test == 'exp':
		N = N_exp
	else:
		N = N_ops
	sys.stdout.write(test)
	for client in clients:
		if client == 'gas':
			continue
		nanos_per_op = float(data[test][client])*10**9/N
		nanos_per_pop = float(data['pop'][client])*10**9/N_pop
		nanos_per_op -= nanos_per_pop
		sys.stdout.write(", %.2f" % nanos_per_op)
	sys.stdout.write("\n")
