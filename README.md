# CodeAlpha Tasks

This repository contains C++ implementations for two programming tasks completed as part of the CodeAlpha internship program.

## Projects Overview

### 1. 🔐 Login & Registration System
A secure user authentication system that allows users to register new accounts and login with existing credentials.

### 2. 📊 CGPA Calculator
An academic grade management system that calculates semester GPA and cumulative CGPA based on course grades and credit hours.

---

## 🔐 Login & Registration System

### Features
- **User Registration**: Create new user accounts with unique usernames
- **Password Validation**: Ensures passwords don't contain spaces
- **Login Authentication**: Secure login with username/password verification
- **File-based Storage**: User credentials stored in `users.txt` file
- **Input Validation**: Robust error handling for invalid inputs
- **User-friendly Interface**: Clear menu system with success/error messages

### How to Use
1. **Compile**: `g++ Login_Registration_System.cpp -o login_system`
2. **Run**: `./login_system`
3. **Options**:
   - Choose `1` to register a new account
   - Choose `2` to login with existing credentials
   - Choose `3` to exit the program

### Technical Details
- **Language**: C++
- **Libraries**: `<iostream>`, `<fstream>`, `<string>`, `<limits>`
- **Storage**: Plain text file (`users.txt`)
- **Validation**: Space detection in passwords using custom `hasSpace()` function

---

## 📊 CGPA Calculator

### Features
- **Multi-course Input**: Handle multiple courses in a semester
- **Grade Conversion**: Convert letter grades (A+, A, B+, etc.) to numeric points
- **Credit Hours**: Account for different credit weights per course
- **SGPA Calculation**: Calculate Semester Grade Point Average
- **CGPA Calculation**: Compute overall Cumulative GPA including previous semesters
- **Detailed Report**: Display individual course details and final results
- **Previous Records**: Include past semester data for accurate CGPA

### Grading Scale
| Grade | Points | Grade | Points |
|-------|--------|-------|--------|
| A+    | 10.0   | C+    | 6.5    |
| A     | 9.0    | C     | 6.0    |
| B+    | 8.0    | D+    | 5.5    |
| B     | 7.0    | D     | 5.0    |
|       |        | E     | 4.0    |
|       |        | F     | 0.0    |

### How to Use
1. **Compile**: `g++ CGPA-calculator.cpp -o cgpa_calculator`
2. **Run**: `./cgpa_calculator`
3. **Input Process**:
   - Enter number of courses for current semester
   - For each course: provide grade (A+, B, C, etc.) and credit hours
   - Enter previous total credits (0 if first semester)
   - Enter previous CGPA (0 if first semester)
4. **Output**: Detailed mark sheet with SGPA and overall CGPA

### Calculation Formula
- **SGPA** = Total Credit Points ÷ Total Credits
- **CGPA** = (Previous Credits × Previous CGPA + Current Credit Points) ÷ (Previous Credits + Current Credits)

### Technical Details
- **Language**: C++
- **Libraries**: `<iostream>`, `<iomanip>`, `<string>`, `<vector>`
- **Data Structures**: Vectors for dynamic course storage
- **Precision**: Results displayed with 2 decimal places

---

## 🚀 Getting Started

### Prerequisites
- C++ compiler (GCC, Clang, or MSVC)
- Basic understanding of C++ compilation

### Installation & Running
1. **Clone the repository**:
   ```bash
   git clone <repository-url>
   cd CodeAlpha_Tasks
   ```

2. **Compile individual programs**:
   ```bash
   # For Login System
   g++ Login_Registration_System.cpp -o login_system
   
   # For CGPA Calculator
   g++ CGPA-calculator.cpp -o cgpa_calculator
   ```

3. **Run the programs**:
   ```bash
   # Run Login System
   ./login_system
   
   # Run CGPA Calculator
   ./cgpa_calculator
   ```

### Sample Usage

#### Login System Example:
```
===== Login & Registration System =====
1. Register
2. Login
3. Exit
Enter your choice: 1
Enter a new username: john_doe
Enter a new password (no spaces allowed): mypassword123
[SUCCESS] Registration successful! You can now login.
```

#### CGPA Calculator Example:
```
Enter the number of courses: 3
Enter grade for course 1 (e.g., A+, B, C, F): A+
Enter credit hours for course 1: 4
Enter grade for course 2 (e.g., A+, B, C, F): B+
Enter credit hours for course 2: 3
Enter grade for course 3 (e.g., A+, B, C, F): A
Enter credit hours for course 3: 3
Enter your previous total credits (0 if none): 0
Enter your previous CGPA (0 if none): 0

--- Statement of Marks ---
Course	Grade	Credits	Grade Points	Credit Points
1	A+	4	10.00		40.00
2	B+	3	8.00		24.00
3	A	3	9.00		27.00

Total Credits: 10.00
Total Credit Points: 91.00
Semester GPA (SGPA): 9.10
Overall CGPA: 9.10
```

---

## 📁 File Structure
```
CodeAlpha_Tasks/
├── Login_Registration_System.cpp    # Authentication system
├── CGPA-calculator.cpp             # Grade calculation system
├── users.txt                       # User credentials storage (auto-generated)
└── README.md                       # Project documentation
```

---

## 🛠️ Technical Implementation

### Error Handling
- **Input Validation**: Both programs handle invalid menu choices and input types
- **File Operations**: Safe file reading/writing with proper error checking
- **Password Security**: Space validation and secure storage practices
- **Memory Management**: Efficient use of STL containers

### Code Quality
- **Modular Design**: Functions separated by responsibility
- **Clear Comments**: Comprehensive code documentation
- **User Experience**: Intuitive menus and helpful error messages
- **Standards Compliance**: Modern C++ practices

---

## 🏆 Features Completed

### Login & Registration System ✅
- [x] User registration with unique username validation
- [x] Password validation (no spaces allowed)
- [x] Secure login authentication
- [x] File-based persistent storage
- [x] Input validation and error handling
- [x] User-friendly menu interface

### CGPA Calculator ✅
- [x] Multiple course input handling
- [x] Letter grade to numeric conversion
- [x] Credit hour weighting
- [x] SGPA calculation
- [x] CGPA calculation with previous semester data
- [x] Detailed mark sheet generation
- [x] Formatted output with proper precision

---

## 📈 Future Enhancements

### Potential Improvements
- **Login System**:
  - Password encryption for enhanced security
  - User profile management
  - Password reset functionality
  - Session management

- **CGPA Calculator**:
  - GPA trend analysis
  - Multiple semester history storage
  - Export results to file
  - Graphical grade visualization

---

## 👨‍💻 Author

**CodeAlpha Intern i.e Param Chauhan**  
*C++ Programming Tasks*

---

## 📄 License

This project is created for educational purposes as part of the CodeAlpha internship program.

---

## 🤝 Contributing

Feel free to fork this repository and submit pull requests for any improvements or bug fixes.

---

*Last Updated: September 2025*
