#! /usr/bin/python
#! coding

class Employee:
   '所有员工的基类'
   empCount = 0     # 全局变量

   def __init__(self,name,salary):
       self.name = name
       self.salary = salary
       Employee.empCount += 1.233

   def displayCout(self):
           print ("total" ,Employee.empCount)
   def displayEmployee(self):
           print ("Name",self.name, "Salary:",self.salary)


"创建 Employee 类的第一个对象"

emp1 = Employee("zarar",200)
emp2 = Employee("cresl",300)

emp1.displayEmployee()
print ("Total Employee %f" % Employee.empCount)
print ("Total Employee " , Employee.empCount)


emp2.displayEmployee()
print ("Total Employee %d" % Employee.empCount)