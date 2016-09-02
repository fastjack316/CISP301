"""
	Conversion Test Program
	fj316
	9/1/2016
	convert C program to python
"""

employees = {}

def addemployee():
	firstname = raw_input("Enter employee's first name ")
	lastname = raw_input("Enter employee's last name ")
	payrate = float(raw_input("Enter hourly pay rate "))
	hours = int(raw_input("Enter hours worked this pay period "))
	if hours <= 40:
		gross = hours * payrate
	else:
		gross = 40 * payrate + 1.5 * payrate * (hours - 40)
	tax = gross * 0.15
	net = gross - tax
	employees[firstname] = [firstname, lastname, payrate, hours, gross, tax, net]
	return employees

yeses = ['y', 'Y', 'yes', 'Yes']
another = 'y'
	
while another in yeses:
	addemployee()
	another = raw_input("Do you have another employee (Y / N)")
print employees