meal_cost = float(raw_input())
tip_percent = float(raw_input())
tax_percent = float(raw_input())

meal_cost = round(meal_cost + meal_cost * tip_percent / 100 + meal_cost * tax_percent / 100)

print "The total meal cost is " + str(int(meal_cost)) + " dollars."
