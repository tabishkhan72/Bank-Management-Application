# **🏦 Bank Management Application**  

A **comprehensive banking system** designed to handle **essential banking operations** such as **loan requests, money transfers, bill payments, and customer account management**. This system efficiently manages customer transactions using **queue-based operations** and follows core **Object-Oriented Programming (OOP) principles** like **encapsulation, inheritance, polymorphism, and abstraction**.  

---

## **🚀 Features**  

### **📌 Core Functionalities**  

#### ✅ **Banking Transactions (Queue System)**  
- **Enqueue (Deposit/Withdraw Transactions)**  
  - Users can **queue transactions** for deposits or withdrawals.  
  - Ensures **confirmation before processing** transactions.  
  - Uses **dynamic memory allocation** for queue management.  

- **Dequeue (Process Transactions)**  
  - Transactions are **processed in FIFO order**.  
  - If no transactions exist, displays a **queue empty message**.  
  - Provides **transaction details** for better transparency.  

#### ✅ **Bank Account Management**  
- Supports **new account creation** with customer details.  
- Allows users to request a **debit card (with PIN setup)** or a **cheque book**.  
- Implements **a linked list** to store multiple customer accounts.  

#### ✅ **Bill Payments (Queue System)**  
- Customers can **enqueue bill payment requests**.  
- Bills are **processed sequentially** to ensure accuracy.  
- Prevents **overlapping payments** via queue validation.  

---

## **🛠 Object-Oriented Programming (OOP) Principles**  

| **OOP Concept**  | **Implementation in the Project** |
|------------------|----------------------------------|
| **Encapsulation** | Uses classes like `billPaymentQueue`, `withdrawDepositQueue`, `newAccountNode`, and `BankQueue` to encapsulate data and operations. |
| **Inheritance** | `billPaymentQueue` inherits from `bankAccountsDatabase` (single inheritance). |
| **Polymorphism** | Uses **function overloading** (e.g., `isEmpty()` function behaves differently in `billPaymentQueue` and `withdrawDepositQueue`). |
| **Abstraction** | Implements abstraction in `enqueue()`, `dequeue()`, and banking operations by managing transactions via queues without exposing internal details. |

---

## **💻 Tech Stack**  

| **Component**  | **Technology Used** |
|---------------|----------------|
| **Programming Language** | C++ |
| **Data Structures** | Linked Lists, Queues |
| **OOP Concepts** | Encapsulation, Inheritance, Polymorphism, Abstraction |

---

## **📥 Installation & Usage**  

### **1️⃣ Clone the Repository**  
```bash
git clone https://github.com/tabishkhan72/Bank-Management-Application.git
cd Bank-Management-Application
```

### **2️⃣ Compile the Program**  
Use a C++ compiler to compile the code:  
```bash
g++ bank_management.cpp -o bank_management
```

### **3️⃣ Run the Application**  
```bash
./bank_management
```

---

## **📊 Key Functional Modules**  

### **🟢 Enqueue Function (Deposit/Withdraw Transactions)**  
- Users **choose** between **deposit or withdrawal**.  
- Requires **account number and cash amount** input.  
- **Transaction confirmation** before queuing.  
- Uses **linked list to manage queued transactions**.  

### **🔴 Dequeue Function (Process Transactions)**  
- Transactions are processed in **FIFO order**.  
- **Displays transaction detail** before removing them from the queue.  
- Handles **empty queue conditions** to avoid errors.  

### **🔵 Bank Database (Customer Management)**  
- Supports **new account creation** with user details.  
- Provides **optional features** like **debit card PIN setup** and **cheque book requests**.  
- Uses **linked list structure** to maintain multiple customer accounts.  

---

## **🚀 Future Enhancements**  

✅ **Implement a Graphical User Interface (GUI)** for better user interaction.  
✅ **Add authentication mechanisms** (Username/Password, OTP).  
✅ **Introduce AI-based fraud detection** for transaction security.  
✅ **Integrate real-time notifications** for successful transactions.  
✅ **Cloud-based storage** to maintain banking records securely.  

---
