# Bank-Management-Application

Banking applications are crucial tools that facilitate essential banking operations, including but not limited to loan requests, money transfers, bill payments, and more. As a result, these applications are among the most significant and commonly used applications available.



ENQUEUE :

This code defines the function enqueue(), which adds a new node to the end of a linked list. The linked list represents a bank queue for customers who want to deposit or withdraw cash.

The function starts by creating a new withdrawDepositNode object, which contains information about the transaction, such as the account number, cash amount, and transaction type.

Then, the user is prompted to choose between withdrawing cash or depositing cash. If an invalid option is entered, the function exits.

Next, the user is prompted to enter the account number and cash amount for the transaction. The information entered is displayed on the screen, and the user is asked to confirm the transaction by typing 'Y' or 'N'.

If the user confirms the transaction, the new node is added to the end of the linked list. If the list is empty, the new node becomes the front and rear node. Otherwise, the new node is linked to the previous rear node and becomes the new rear node.

If the user does not confirm the transaction, the new node is deleted and the function exits.

Finally, the user is asked to press any key to return to the bank menu.




DEQUEUE :

This code implements a queue data structure for a banking system that can handle withdrawal and deposit transactions. The enqueue() function is used to add a transaction to the back of the queue and the dequeue() function is used to remove the transaction from the front of the queue. The displayWithdrawDepositQueue() function is used to display all transactions currently in the queue.

The withdrawDepositNode struct represents a node in the queue and contains fields for the account number, cash amount, and transaction type (withdrawal or deposit). The front and rear pointers are used to keep track of the front and back of the queue.

In enqueue(), the user is prompted to choose between a withdrawal or deposit transaction and then asked to enter the account number and cash amount. The transaction details are displayed for confirmation and the user is asked to confirm the transaction. If confirmed, the new transaction is added to the back of the queue using dynamic memory allocation.

In dequeue(), if the queue is empty, a message is displayed indicating that there are no transactions left to process. If not empty, the transaction at the front of the queue is removed and its details are displayed.

In displayWithdrawDepositQueue(), all transactions currently in the queue




Bank database :

This code seems to be a part of a larger program for managing bank accounts. The class bankAccountsDatabase represents a database of bank accounts and has a newAccountNode as a nested class that represents a node of the linked list that will hold the bank accounts.

The insertNewAccount() function allows a user to create a new account by taking input from the user for various fields such as name, email address, phone number, etc. The function then creates a new node of type newAccountNode and initializes it with the provided data. If the user opts for a debit card, the function also prompts them to enter a 4-digit PIN for the debit card. Similarly, if the user wants a chequebook, the function sets the chequeBook flag in the node to true.

After initializing the node, the function prints out the details of the new account and prompts the user to confirm the details. If the user confirms, the function adds the new node to the linked list. If the linked list is empty, the new node becomes the head of the list.


Encapsulation -
billPaymentQueue,payBillNode,withdrawDepositQueue,newAccountNode,BankQueue
The code uses classes to encapsulate related functions and data together, such as the BankQueue class and the Address class.The code defines two classes, billPaymentQueue and withdrawDepositQueue, which encapsulate the properties and behavior of a queue for bill payments and withdraw/deposit transactions, respectively.

Inheritance : billPaymentQueue and bankAccountDatabase are in a parent and child relationship, where billPaymentQueue inherits functions and data from bankAccountsDatabase.  Its a single inheritance.  In single inheritance, a class is allowed to inherit from only one class. i.e. one subclass is inherited by one base class only.


Polymorphism - isEmpty()(uses function overloading)
The code does not explicitly use polymorphism, but it does use function overloading, which is a form of polymorphism. For example, the isEmpty() function is overloaded in both the billPaymentQueue and withdrawDepositQueue classes to provide different behavior based on the queue type.


Abstraction - billPaymentQueue,withdrawDepositQueue,newAccountNode,BankMenu,enqueue(),dequeue()
The code creates instances of the billPaymentQueue and withdrawDepositQueue classes using the new keyword to allocate memory dynamically. The instances are then manipulated using member functions, such as enqueue() and dequeue(), to perform operations on the queues.
