import UIKit
import CoreData
import UserNotifications

class AddBirthdayViewController: UIViewController, UIPickerViewDelegate, UIPickerViewDataSource {
    @IBOutlet var firstNameTextField: UITextField!
    @IBOutlet var eventDatePicker: UIDatePicker!
    @IBOutlet weak var pickerView: UIPickerView!
    var selectedEvent: String?
    @IBOutlet var venueField: UITextField!
    
    let data = ["Birthday", "Wedding", "Reception", "Festival", "Get-together", "Reunion", "Convocation"]
    
    func numberOfComponents(in pickerView: UIPickerView) -> Int {
            return 1 // For a single-column picker
        }

        func pickerView(_ pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
            return data.count
        }

        // MARK: - UIPickerViewDelegate

        func pickerView(_ pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String? {
            return data[row]
        }

        func pickerView(_ pickerView: UIPickerView, didSelectRow row: Int, inComponent component: Int) {
            selectedEvent = data[row]
            // Add any additional handling for the selected value
        }
    
    var saveCompletion: (() -> Void)?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        eventDatePicker.maximumDate = Date()
        // Do any additional setup after loading the view.
        pickerView.delegate = self
        pickerView.dataSource = self
        eventDatePicker.setValue(UIColor.white, forKey: "textColor")
        pickerView.setValue(UIColor.white, forKey: "textColor")
    }
    
    @IBAction func saveTapped (_ sender: UIBarButtonItem){
        print("Save Button Pressed")
        var firstName = firstNameTextField.text
        
        let eventDate = eventDatePicker.date
        
        let appDelegate = UIApplication.shared.delegate as! AppDelegate
        let context = appDelegate.persistentContainer.viewContext
        
        
        let newEvent = Birthday(context: context)
        if let firstNameLet = firstName, !firstNameLet.isEmpty {
            // firstName is not empty, you can use it here
            let newFirstName = firstNameLet
            newEvent.firstName = newFirstName
            firstName = newFirstName
        } else {
            // firstName is empty, reassign it to "No title"
            let newFirstName = "(No name)"
            newEvent.firstName = newFirstName
            firstName = newFirstName
        }

        newEvent.eventDate = eventDate
        newEvent.eventID = UUID().uuidString
        newEvent.venue = venueField.text
        
        
        if let uniqueID = newEvent.eventID {
            print("eventID:\(uniqueID)")
        }
        do {
            try context.save()
            let message: String
            if let selectedEventData = selectedEvent {
                message = "\(String(describing: firstName!)) - \(String(describing: selectedEventData)) - \(String(describing: (venueField.text)!))!"
                newEvent.event = selectedEventData
            } else {
                message = "No event!"
            }
            
            let content = UNMutableNotificationContent()

            content.title = "Event Reminder!"
            content.body = message
            content.sound = UNNotificationSound.default
            
            var dateComponents = Calendar.current.dateComponents([.month, .day], from: eventDate)
            dateComponents.hour = 12
            dateComponents.minute = 24
            let trigger = UNCalendarNotificationTrigger(dateMatching: dateComponents, repeats: true)
            if let identifier = newEvent.eventID {
                let request = UNNotificationRequest(identifier: identifier, content: content, trigger: trigger)
                UNUserNotificationCenter.current().add(request) { error in
                if let error = error {
                    print("Error adding notification request: \(error.localizedDescription)")
                } else {
                    print("Notification request added successfully")
                }
                        }
            }
            } catch let error {
                print("Failed to save. Please try again. \(error)")
            }
        
        dismiss(animated: true, completion: saveCompletion)

        
        print("Event record created")
        print("First Name: \(newEvent.firstName!)")
        print("Event: \(newEvent.eventDate!)")
        
    }
    @IBAction func cancelTapped (_ sender: UIBarButtonItem) {
        dismiss(animated: true, completion: nil)
    }
    
    
}

