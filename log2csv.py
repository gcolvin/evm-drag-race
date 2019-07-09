import sys
import re

# regex for the lines with relevant data
test_line = 'echo (.+) (.+) 1>&2 ; time -p.*touch .+\..*ran$'
gas_line = 'as used: +([0-9]+)'
secs_line = 'time: +([0-9.]+)'

# read in data
path = ''
client = ''
test = ''
clients = ['gas']
tests = []
data = {}
for line in sys.stdin:
	match = re.search(test_line, line)
	if match:
		client = match.group(1)
		test = match.group(2)
		if client not in clients:
			clients += [client]
		if test not in tests:
			tests += [test]
		continue
	match = re.search(gas_line, line)
	if match:
		if test not in data:
			data[test] = {}
		data[test]['gas'] = match.group(1)
		continue
	match = re.search(secs_line, line)
	if match:
		if test not in data:
			data[test] = {}
		data[test][client] = match.group(1)
		continue

# print the header
sys.stdout.write("(sec/test)")
for client in clients:
	sys.stdout.write(", %s" % client)
sys.stdout.write("\n")

# print the test, gas, secs, secs, ...
for test in tests:
	sys.stdout.write("%s" % test)
	for client in clients:
		sys.stdout.write(", %s" % data[test].get(client,0))
	sys.stdout.write("\n")
