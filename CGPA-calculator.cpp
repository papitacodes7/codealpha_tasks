#include <iostream>   // For input (cin) and output (cout)
#include <iomanip>    // For formatting numbers (like setting decimal places)
#include <string>     // For using string type (grades like "A+" etc.)
#include <vector>     // For using dynamic arrays (to store multiple course details)

using namespace std;  // So we don’t need to write std:: before cin/cout etc.

// Function that converts letter grades (A+, B, C...) into numeric grade points
double gradeToPoints(const string& grade) {
    // Check which grade is entered and return corresponding number
    if (grade == "A+" || grade == "a+") return 10.0; // A+ = 10 points
    else if (grade == "A" || grade == "a") return 9.0; // A = 9 points
    else if (grade == "B+" || grade == "b+") return 8.0; // B+ = 8 points
    else if (grade == "B" || grade == "b") return 7.0;   // B = 7 points
    else if (grade == "C+" || grade == "c+") return 6.5; // C+ = 6.5 points
    else if (grade == "C" || grade == "c") return 6.0;   // C = 6 points
    else if (grade == "D+" || grade == "d+") return 5.5; // D+ = 5.5 points
    else if (grade == "D" || grade == "d") return 5.0;   // D = 5 points
    else if (grade == "E" || grade == "e") return 4.0;   // E = 4 points (Pass)
    else if (grade == "F" || grade == "f") return 0.0;   // F = Fail = 0 points
    else return 0.0; // If invalid grade is entered, treat it as 0
}

int main() {
    int numCourses;  // Number of subjects this semester
    double totalCredits = 0.0;       // Sum of all credit hours in this semester
    double totalCreditPoints = 0.0;  // Sum of all gradePoints × credits
    double previousTotalCredits = 0.0; // Credits completed in past semesters
    double previousCGPA = 0.0;         // CGPA till last semester

    // Ask user: how many subjects this semester?
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    // Vectors (like arrays that can grow) to store data for each subject
    vector<string> grades(numCourses);      // Stores letter grades (A+, B, etc.)
    vector<double> credits(numCourses);     // Stores credit hours for each course
    vector<double> gradePoints(numCourses); // Stores converted grade points
    vector<double> creditPoints(numCourses);// Stores creditPoints = gradePoints × credits

    // Loop through each subject and take input
    for (int i = 0; i < numCourses; ++i) {
        cout << "Enter grade for course " << i + 1 << " (e.g., A+, B, C, F): ";
        cin >> grades[i]; // Save grade (like A, B+)

        cout << "Enter credit hours for course " << i + 1 << ": ";
        cin >> credits[i]; // Save credits (like 3, 4, etc.)

        // Convert grade into numeric value (using gradeToPoints function)
        gradePoints[i] = gradeToPoints(grades[i]);

        // Calculate credit points = gradePoints × credits
        creditPoints[i] = gradePoints[i] * credits[i];
    }

    // Now add all credits and credit points
    for (int i = 0; i < numCourses; ++i) {
        totalCredits += credits[i];          // Add credit hours
        totalCreditPoints += creditPoints[i];// Add gradePoints × credits
    }

    // Calculate SGPA = totalCreditPoints ÷ totalCredits
    double sgpa = totalCreditPoints / totalCredits;

    // Ask if the student has previous semester details
    cout << "Enter your previous total credits (0 if none): ";
    cin >> previousTotalCredits;

    cout << "Enter your previous CGPA (0 if none): ";
    cin >> previousCGPA;

    // Formula for overall CGPA (combine old and new semester)
    // (Old total credits × old CGPA + new credit points) ÷ (old credits + new credits)
    double overallCGPA = 
        (previousTotalCredits * previousCGPA + totalCreditPoints) 
        / (previousTotalCredits + totalCredits);

    // Format numbers to 2 decimal places
    cout << fixed << setprecision(2);

    // Print table header
    cout << "\n--- Statement of Marks ---\n";
    cout << "Course\tGrade\tCredits\tGrade Points\tCredit Points\n";

    // Print details of each subject
    for (int i = 0; i < numCourses; ++i) {
        cout << i + 1 << "\t" 
             << grades[i] << "\t" 
             << credits[i] << "\t" 
             << gradePoints[i] << "\t\t" 
             << creditPoints[i] << endl;
    }

    // Print totals and results
    cout << "\nTotal Credits: " << totalCredits << endl;
    cout << "Total Credit Points: " << totalCreditPoints << endl;
    cout << "Semester GPA (SGPA): " << sgpa << endl;
    cout << "Overall CGPA: " << overallCGPA << endl;

    return 0; // Program ends here
}
