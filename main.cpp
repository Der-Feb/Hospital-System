
#include <iostream>
#include <string>
using namespace std;

struct BaseNode {
    BaseNode* next;
    BaseNode() : next(nullptr) {}
    virtual ~BaseNode() {}
    virtual int getId() const = 0;
    virtual void display() const = 0;
};

struct PatientNode : public BaseNode {
    int patient_id;
    string name;
    string dob;
    string gender;

    PatientNode(int id, string n, string d, string g)
        : patient_id(id), name(n), dob(d), gender(g) {}

    int getId() const override {
        return patient_id;
    }

    void display() const override {
        cout << "Patient: ID: " << patient_id << ", Name: " << name
             << ", DoB: " << dob << ", Gender: " << gender << endl;
    }
};

struct DoctorNode : public BaseNode {
    int doctor_id;
    string name;
    string specialization;

    DoctorNode(int id, string n, string s)
        : doctor_id(id), name(n), specialization(s) {}

    int getId() const override {
        return doctor_id;
    }

    void display() const override {
        cout << "Doctor: ID: " << doctor_id << ", Name: " << name
             << ", Specialization: " << specialization << endl;
    }
};

struct AppointmentNode : public BaseNode {
    int appointment_id;
    int patient_id;
    int doctor_id;
    string appointment_date;

    AppointmentNode(int appId, int patId, int docId, string date)
        : appointment_id(appId), patient_id(patId), doctor_id(docId), appointment_date(date) {}

    int getId() const override {
        return appointment_id;
    }

    void display() const override {
        cout << "Appointment: ID: " << appointment_id << ", Patient ID: " << patient_id
             << ", Doctor ID: " << doctor_id << ", Date: " << appointment_date << endl;
    }
};

template <typename NodeType>
class RecordLL {
protected:
    BaseNode* head;

public:
    RecordLL() : head(nullptr) {}

    ~RecordLL() {
        BaseNode* current = head;
        while (current != nullptr) {
            BaseNode* temp = current;
            current = current->next;
            delete temp;
        }
    }

    bool exists(int id) const {
        BaseNode* current = head;
        while (current != nullptr) {
            if (current->getId() == id) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool add(NodeType* newNode) {
        if (exists(newNode->getId())) {
            return false;
        }
        if (head == nullptr) {
            head = newNode;
        } else {
            BaseNode* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        return true;
    }

    void displayAll() const {
        BaseNode* current = head;
        if (current == nullptr) {
            cout << "No records registered." << endl;
            return;
        }
        while (current != nullptr) {
            current->display();
            current = current->next;
        }
    }
};

class PatientsLL : public RecordLL<PatientNode> {
public:
    void registerPatient() {
        int id;
        string name, dob, gender;

        cout << "\nPATIENT REGISTRATION" << endl;
        cout << "--------------------" << endl;
        cout << "ID: ";
        cin >> id;

        if (exists(id)) {
            cout << "Error: Patient ID " << id << " already exists." << endl;
            return;
        }

        cout << "NAME: ";
        cin.ignore();
        getline(cin, name);
        cout << "DoB: ";
        getline(cin, dob);
        cout << "GENDER: ";
        getline(cin, gender);

        add(new PatientNode(id, name, dob, gender));
    }

    void displayPatients() const {
        cout << "\nPATIENTS LIST" << endl;
        cout << "-------------" << endl;
        displayAll();
    }
};

class DoctorsLL : public RecordLL<DoctorNode> {
public:
    void registerDoctor() {
        int id;
        string name, specialization;

        cout << "\nDOCTOR REGISTRATION" << endl;
        cout << "-------------------" << endl;
        cout << "ID: ";
        cin >> id;

        if (exists(id)) {
            cout << "Error: Doctor ID " << id << " already exists." << endl;
            return;
        }

        cout << "NAME: ";
        cin.ignore();
        getline(cin, name);
        cout << "SPECIALIZATION: ";
        getline(cin, specialization);

        add(new DoctorNode(id, name, specialization));
    }

    void displayDoctors() const {
        cout << "\nDOCTORS LIST" << endl;
        cout << "------------" << endl;
        displayAll();
    }
};

class AppointmentsLL : public RecordLL<AppointmentNode> {
private:
    PatientsLL& patients;
    DoctorsLL& doctors;

public:
    AppointmentsLL(PatientsLL& p, DoctorsLL& d) : patients(p), doctors(d) {}

    void registerAppointment() {
        int id, patientId, doctorId;
        string date;

        cout << "\nAPPOINTMENT REGISTRATION" << endl;
        cout << "------------------------" << endl;
        cout << "ID: ";
        cin >> id;

        if (exists(id)) {
            cout << "Error: Appointment ID " << id << " already exists." << endl;
            return;
        }

        cout << "PATIENT ID: ";
        cin >> patientId;

        if (!patients.exists(patientId)) {
            cout << "Error: Patient ID " << patientId << " does not exist." << endl;
            return;
        }

        cout << "DOCTOR ID: ";
        cin >> doctorId;

        if (!doctors.exists(doctorId)) {
            cout << "Error: Doctor ID " << doctorId << " does not exist." << endl;
            return;
        }

        cout << "APPOINTMENT DATE: ";
        cin.ignore();
        getline(cin, date);

        add(new AppointmentNode(id, patientId, doctorId, date));
    }

    void displayAppointments() const {
        cout << "\nAPPOINTMENTS LIST" << endl;
        cout << "-----------------" << endl;
        displayAll();
    }
};

int main() {
    PatientsLL patientsLL;
    DoctorsLL doctorsLL;
    AppointmentsLL appointmentsLL(patientsLL, doctorsLL);

    int choice;
    do {
        cout << "\nMenu:" << endl;
        cout << "1: register patient" << endl;
        cout << "2: register doctor" << endl;
        cout << "3: register appointment" << endl;
        cout << "4: display patients" << endl;
        cout << "5: display doctors" << endl;
        cout << "6: display appointments" << endl;
        cout << "7: Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                patientsLL.registerPatient();
                break;
            case 2:
                doctorsLL.registerDoctor();
                break;
            case 3:
                appointmentsLL.registerAppointment();
                break;
            case 4:
                patientsLL.displayPatients();
                break;
            case 5:
                doctorsLL.displayDoctors();
                break;
            case 6:
                appointmentsLL.displayAppointments();
                break;
            case 7:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
