class Person:
        def __init__(self, firstName, lastName, idNumber):
                self.firstName = firstName
                self.lastName = lastName
                self.idNumber = idNumber
        def printPerson(self):
                print "Name:", self.lastName + ",", self.firstName
                print "ID:", self.idNumber

class Student(Person):
        def __init__(self, firstName, lastName, idNumber, scores):
                Person.__init__(self, firstName, lastName, idNumber)
                self.scores = scores
        def calculate(self):
                avg = sum(scores) / float(len(scores))
                return {
                        avg < 40: 'T',
                        40 <= avg < 55: 'D',
                        55 <= avg < 70: 'P',
                        70 <= avg < 80: 'A',
                        80 <= avg < 90: 'E',
                        90 <= avg <= 100: 'O',
                }[True]

line = raw_input().split()
firstName = line[0]
lastName = line[1]
idNum = line[2]
numScores = int(raw_input()) # not needed for Python
scores = map(int, raw_input().split())
s = Student(firstName, lastName, idNum, scores)
s.printPerson()
print "Grade:", s.calculate()
