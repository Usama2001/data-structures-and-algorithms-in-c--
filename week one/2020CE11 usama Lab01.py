# LAB 01 task A 
# annual_salary=float(input("Enter your annual salary >> "))
# saved_salary_percentage=float(input("Enter the salary you saved in  precentage >> "))
# Total_cost=float(input("Enter the cost of your dream home >> "))
# No_of_month=0
# current_savings=0
# while current_savings<=Total_cost* 0.25 :
#     No_of_month+=1
#     current_savings=current_savings+((annual_salary/12)*saved_salary_percentage)+current_savings*0.003
# print(No_of_month)


# LAB1 TASK(B)
Total_cost=float(input("enter the cost of your dream home"))
annual_salary=float(input("enter your annual salary"))
percent=float(input("enter the percent of your salary you saved"))
semi_annual_salary_raised=float(input("enter the semi annual salary raised"))
month=0
current_savings=0
per_month_salary=annual_salary/12
per_month_salary_savings=per_month_salary*percent
while current_savings<=Total_cost*0.25:
    per_month_salary_savings = per_month_salary * percent
    if month%6==0:
         month+=1
         per_month_salary+=per_month_salary*semi_annual_salary_raised
         current_savings += per_month_salary_savings + current_savings * 0.003
    else:
         month+=1
         current_savings += per_month_salary_savings+current_savings*0.003
print(month)