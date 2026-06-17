Ruhengeri Referral Hospital is requesting a C/C++ programmer to develop its healthcare system to manage patients' appointments using 3 linked lists. The three linked list and data for each are:

- PatientsLL (patient_id INTEGER, name STRING, dob STRING, gender STRING)
- DoctorsLL (doctor_id INTEGER, name STRING, specialization STRING)
- Appointments (appointment_id INTEGER, patient INTEGER, doctor_id INTEGER, appointment_date STRING)

We are requested to consider these:

- One patient_id references only one patient, one doctor_id references only one appointment_id references only one appointement otherwise, notify the user that the given id already exists.
- The appointment is possible only if both patinet_id and doctor_id exit in PatientLL and also DoctorsLL respectively. Otherwise, notify the user that one of them doesn't exist.
- TThe program will run on menus basis as follow:
  1: register patient
  2: register doctor
  3: register appointment
  4: display patients
  5: display doctors
  6: display appointments
  7: Exit

working demo:

```
  Menu:
  1: register patient
  2: register doctor
  3: register appointment
  4: display patients
  5: display doctors
  6: display appointments
  7: Exit
  Enter your choice: 1
  PATIENT REGISTRATION
  --------------------
  ID: 1
  NAME: Derick
  DoB: 17/07/2026
  Menu:
  1: register patient
  2: register doctor
  3: register appointment
  4: display patients
  5: display doctors
  6: display appointments
  7: Exit
  Enter your choice: 2
  DOCTOR REGISTRATION
  // same as patient but with its fields, and also the appintment
  Enter your choice: 4
  Patient: ID: 1, Name: ..., DoB: .... and other fields
  Patient: ID: 2, ....
  and we can also list the appointments

```
