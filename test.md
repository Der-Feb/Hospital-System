
# Test Cases for Ruhengeri Referral Hospital Healthcare System

## How to Compile and Run
### Step 1: Create dist directory (if it doesn't exist)
- On Windows (Command Prompt): `mkdir dist`
- On Linux/macOS/Git Bash: `mkdir -p dist`

### Step 2: Compile the program
- Using g++: `g++ -o dist/main.exe main.cpp`
- Using Visual Studio's cl.exe (Developer Command Prompt): `cl /EHsc main.cpp /Fe:dist\main.exe`

### Step 3: Run the program
- On Windows: `dist\main.exe`
- On Linux/macOS/Git Bash: `./dist/main.exe`


## Test 1: Register Patients
### Input
1. Enter choice: 1
   - ID: 1
   - NAME: Derick
   - DoB: 17/07/2026
   - GENDER: Male
2. Enter choice: 1
   - ID: 2
   - NAME: Alice
   - DoB: 05/03/2000
   - GENDER: Female
3. Enter choice: 1
   - ID: 1
   - NAME: Duplicate
   - DoB: 01/01/2000
   - GENDER: Other

### Expected Results
- First 2 patients are registered successfully
- Third attempt shows error: "Error: Patient ID 1 already exists." and returns to menu


## Test 2: Register Doctors
### Input
1. Enter choice: 2
   - ID: 101
   - NAME: Dr. Smith
   - SPECIALIZATION: Cardiology
2. Enter choice: 2
   - ID: 102
   - NAME: Dr. Johnson
   - SPECIALIZATION: Pediatrics
3. Enter choice: 2
   - ID: 101
   - NAME: Duplicate
   - SPECIALIZATION: Any

### Expected Results
- First 2 doctors are registered successfully
- Third attempt shows error: "Error: Doctor ID 101 already exists." and returns to menu


## Test 3: Register Appointments
### Input
1. Enter choice: 3
   - ID: 1001
   - PATIENT ID: 1
   - DOCTOR ID: 101
   - APPOINTMENT DATE: 20/06/2026
2. Enter choice: 3
   - ID: 1002
   - PATIENT ID: 2
   - DOCTOR ID: 102
   - APPOINTMENT DATE: 21/06/2026
3. Enter choice: 3
   - ID: 1001
   - PATIENT ID: 2
   - DOCTOR ID: 102
   - APPOINTMENT DATE: 22/06/2026
4. Enter choice: 3
   - ID: 1003
   - PATIENT ID: 999
   - DOCTOR ID: 101
   - APPOINTMENT DATE: 23/06/2026
5. Enter choice: 3
   - ID: 1003
   - PATIENT ID: 1
   - DOCTOR ID: 999
   - APPOINTMENT DATE: 24/06/2026

### Expected Results
- First 2 appointments are registered successfully
- Third attempt shows error: "Error: Appointment ID 1001 already exists." and returns to menu
- Fourth attempt shows error: "Error: Patient ID 999 does not exist." and returns to menu
- Fifth attempt shows error: "Error: Doctor ID 999 does not exist." and returns to menu


## Test 4: Display Patients
### Input
1. Enter choice: 4

### Expected Results
```
PATIENTS LIST
-------------
Patient: ID: 1, Name: Derick, DoB: 17/07/2026, Gender: Male
Patient: ID: 2, Name: Alice, DoB: 05/03/2000, Gender: Female
```


## Test 5: Display Doctors
### Input
1. Enter choice: 5

### Expected Results
```
DOCTORS LIST
------------
Doctor: ID: 101, Name: Dr. Smith, Specialization: Cardiology
Doctor: ID: 102, Name: Dr. Johnson, Specialization: Pediatrics
```


## Test 6: Display Appointments
### Input
1. Enter choice: 6

### Expected Results
```
APPOINTMENTS LIST
-----------------
Appointment: ID: 1001, Patient ID: 1, Doctor ID: 101, Date: 20/06/2026
Appointment: ID: 1002, Patient ID: 2, Doctor ID: 102, Date: 21/06/2026
```


## Test 7: Exit Program
### Input
1. Enter choice: 7

### Expected Results
Program displays "Exiting program..." and terminates
