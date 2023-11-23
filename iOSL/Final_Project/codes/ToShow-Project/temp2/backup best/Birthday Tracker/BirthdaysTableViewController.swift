import UIKit
import CoreData
import UserNotifications

class BirthdaysTableViewController: UITableViewController {
    
    var events = [Birthday]()
    let dateFormatter = DateFormatter()
   
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        dateFormatter.dateStyle = .full
        dateFormatter.timeStyle = .none
        
        if let navigationController = self.navigationController {
        let navigationBar = navigationController.navigationBar
            navigationBar.titleTextAttributes = [NSAttributedString.Key.foregroundColor: UIColor.systemGray5]
        }
    }
   
    
    override func viewWillAppear(_ animated: Bool) {
         super.viewWillAppear(animated)

        loadData()
    }
//   This block helps to reload TableView after new data is saved in ViewController presented modally (saveTapped).
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        guard let addBirthdayVC = segue.destination as? AddBirthdayViewController else {
            return
        }
        addBirthdayVC.saveCompletion = {
            self.loadData()
        }
    }
    
    func loadData() {
        let appDelegate = UIApplication.shared.delegate as! AppDelegate
        let context = appDelegate.persistentContainer.viewContext
        let fetchRequest = Birthday.fetchRequest() as NSFetchRequest<Birthday>
        let sortDescriptor1 = NSSortDescriptor(key: "lastName", ascending: true)
        let sortDescriptor2 = NSSortDescriptor(key: "firstName", ascending: true)
        fetchRequest.sortDescriptors = [sortDescriptor1, sortDescriptor2]
        do {
            events = try context.fetch(fetchRequest)
        } catch let error {
            print("Failed to load data due to \(error).")
        }
        tableView.reloadData()
    }
    
    // MARK: - Table view data source

    override func numberOfSections(in tableView: UITableView) -> Int {
        // #warning Incomplete implementation, return the number of sections
        return 1
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        // #warning Incomplete implementation, return the number of rows
        return events.count
    }

    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "birthdayCellIdentifier", for: indexPath)
        let eventSelector = events[indexPath.row]
        
        let firstName = eventSelector.firstName
        let venue = eventSelector.venue
        let event = eventSelector.event
        let eventDataGlobal: String
        let venueDataGlobal: String
        
        if let eventData = event{
            eventDataGlobal = eventData
        }else{
            eventDataGlobal = "(No event selected)"
        }
        
        if let venueData = venue{
            venueDataGlobal = venueData
        }else{
            venueDataGlobal = " "
        }
        
        if let firstNameLet = firstName, !firstNameLet.isEmpty {
            // firstName is not empty, you can use it here
            let newFirstName = firstNameLet
            cell.textLabel?.text = newFirstName + " - " + eventDataGlobal
        } else {
            // firstName is empty, reassign it to "No title"
            let newFirstName = "(No name)"
            cell.textLabel?.text = newFirstName + " - " + eventDataGlobal
        }
        
        
        if let date = eventSelector.eventDate as Date? {
            cell.detailTextLabel?.text = dateFormatter.string(from: date) + " - " + venueDataGlobal
        } else {
            cell.detailTextLabel?.text = " "
        }
        return cell
    }


    // Override to support conditional editing of the table view.
    override func tableView(_ tableView: UITableView, canEditRowAt indexPath: IndexPath) -> Bool {
        // Return false if you do not want the specified item to be editable.
        return true
    }



    // Override to support editing the table view.
    override func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCell.EditingStyle, forRowAt indexPath: IndexPath) {
        if events.count > indexPath.row {
            let event = events[indexPath.row]
            if let identifier = event.eventID {
                let center = UNUserNotificationCenter.current()
                center.removePendingNotificationRequests(withIdentifiers: [identifier])
            }
            let appDelegate = UIApplication.shared.delegate as! AppDelegate
            let context = appDelegate.persistentContainer.viewContext
            context.delete(event)
            events.remove(at: indexPath.row)
            do {
                try context.save()
            } catch let error {
                print("Failed to save \(error).")
            }
            tableView.deleteRows(at: [indexPath], with: .fade)
        }
    }
}
