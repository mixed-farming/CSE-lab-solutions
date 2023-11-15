//
//  ViewController.swift
//  guided_project1
//
//  Created by Student on 11/10/23.
//

import UIKit

class Student{
    var name: String
    var age: String
    var semester: String
    var section: String
    var college: String
 
    init(name: String, age: String, semester: String, section: String, college: String){
        self.name = name
        self.age = age
        self.semester = semester
        self.section = section
        self.college = college
 
    }
}

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        updateUI()
        submitButton.isEnabled=false
    }
    var lightOn=true
    var emptyStudentArr: [Student] = []

    fileprivate func updateUI() {
//        if lightOn{
//            view.backgroundColor = .white
//            //lightButton.setTitle("Off", for: .normal)
//        }
//        else
//        {
//            view.backgroundColor = .black
//            //lightButton.setTitle("On", for: .normal)
//        }
        view.backgroundColor = lightOn ? .white : .black
    }
    
    @IBOutlet var lightButton: UIButton!
    @IBAction func buttonPressed(_ sender: Any) {
        lightOn.toggle()
        updateUI()
    }
    
    
    @IBOutlet var nameField: UITextField!
    
    @IBOutlet var ageField: UITextField!
    
    @IBOutlet var sectionField: UITextField!
    
    @IBOutlet var semesterField: UITextField!
    
    @IBOutlet var collegeField: UITextField!
    
    @IBOutlet var clearButton: UIButton!
    
    @IBOutlet var submitButton: UIButton!
    
    @IBAction func clearButton(_ sender: Any) {
        nameField.text=""
        ageField.text=""
        sectionField.text=""
        semesterField.text=""
        collegeField.text=""
        clearButton.isEnabled=false
    }
    
    @IBAction func submitButton(_ sender: Any) {
        submitButton.isEnabled=false
        let studentVar = Student(name: nameField.text!, age: ageField.text!, semester: semesterField.text!, section: sectionField.text!, college: collegeField.text!)
        emptyStudentArr.append(studentVar)
    }
    
}

