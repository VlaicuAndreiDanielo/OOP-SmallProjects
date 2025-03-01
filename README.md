# OOP-SmallProjects  

## 📌 Overview  
This repository contains **small Object-Oriented Programming (OOP) projects**, each focusing on different fundamental concepts such as **operator overloading, inheritance, and polymorphism**.  

## 🛠️ Projects  

### **➗ Rational Numbers**  
- Implements a **Rational Number class**, where each object represents a fraction (p/q).  
- All necessary **arithmetic operators (`+`, `-`, `*`, `/`) and comparison operators (`==`, `!=`, `<`, `>`, etc.)** are **overloaded** for easy manipulation of rational numbers.  
- Includes functions for **simplifying fractions**, **displaying values**, and **handling improper fractions**.  

### **📊 Matrices**  
- Implements a **Matrix class** that allows operations on matrices of any dimension.  
- Includes **overloaded operators** for:  
  - **Matrix addition and subtraction (`+`, `-`)**  
  - **Matrix multiplication (`*`)**  
  - **Comparison (`==`, `!=`)**  
  - **Accessing elements using `()` operator**  
- Supports **dynamic memory allocation**, ensuring efficient handling of large matrices.  
- Provides functions to **display matrices**, **transpose**, and **check matrix properties** (e.g., identity matrix, zero matrix).  

### **🔢 Complex Numbers**  
- Implements a **Complex Number class**, where each object represents a number of the form `a + bi`.  
- All **arithmetic operators** (`+`, `-`, `*`, `/`) are **overloaded** for seamless complex number calculations.  
- Implements **conjugate calculation**, **modulus computation**, and **polar form conversion**.  

### **👥 People (Inheritance & Diamond Problem Solution)**  
This project demonstrates **advanced inheritance concepts**, including **diamond problem resolution** using **virtual inheritance**.  
- Implements **four types of people**:  
  - **Person** (base class)  
  - **Employee** (inherits from `Person`)  
  - **Student** (inherits from `Person`)  
  - **Working Student** (inherits from both `Employee` and `Student`, resolving the diamond problem)  
- Uses **inherited functions** to ensure proper reuse of attributes and methods from the base classes.  

## 🔧 Technologies Used  
- **C++** for object-oriented programming.  
- **Operator Overloading**, **Inheritance**, **Dynamic Memory Management**, and **Virtual Functions**.  

## 🚀 Future Improvements  
- Add exception handling for invalid operations (e.g., division by zero in rational numbers).  
- Improve matrix operations by implementing determinant and inverse calculation.  
- Expand the complex number class to include trigonometric operations.
  
