# Tinkerix-regarding-question-for-internship
The goal is to find the best plans for a customer based on usage. To keep things simple, we only deal with the number minutes a user spent talking on the phone. Let's say the customer's usage in a month is: N local minutes and M STD minutes.

If the customer doesn't buy any plan she pay Rs. 1/min for both local and long distance calls.

To reduce her cost, she can buy one or more plans.

Each plan costs Rs. X, is valid for Y days and gives a discounted rate of Z paise/min. A plan can give the discounted rate for both local and/or STD.

Write a program that returns the best plans given the usage of a customer. Define necessary data structures and classes. Note that a customer can buy more than one plan. The below is just an example. DO NOT write code that works only for the plans below. Your code has to be general. Don't worry about reading input from file or standard input. The class design and the algorithm to determine which plans to select are important. NOT the code that reads files or stdio.

Ex. John's usage is 100 local minutes and 100 STD minutes in 30 days. If he doesn't buy any plan he pays 100x1 + 100x1 = Rs. 200/30 days.

Let's say the plans she can choose from are
1) Rs. 35, Valid for 30 days, Offers 50p/min for both local and STD. If she chooses this plan her cost will be Rs. 35 + 100 (50p/min * 200) = Rs. 135 for 30 days.
2) Rs. 50, Valid for 15 days. Offers 20p/min for both local and STD. If she chooses this plan her cost will be Rs. 50 + (20p/min * 100) = Rs. 70 for 15 days. Since the plan is only for 15 days, we scaled down the usage.
3) Rs. 20, valid for 30 days, Offers 50p/min for Local calls only. The cost for this plan is: Rs. 20 + Rs. 50 (50p/min * 100 local minutes) + 100 (Rs. 1 * 100 STD minutes) = Rs. 170.

In the above example the best plan is the Rs. 35 plan.
