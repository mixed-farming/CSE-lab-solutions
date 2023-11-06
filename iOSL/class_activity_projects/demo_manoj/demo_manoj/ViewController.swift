//
//  ViewController.swift
//  demo_manoj
//
//  Created by Student on 09/10/23.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }


    @IBOutlet var nameTextBox: UITextField!
    
    
    
    @IBOutlet var passwordInput: UITextField!
    
    
    @IBOutlet var submitButton: UIButton!
    
    
    @IBAction func submitButton(_ sender: Any) {
        nameTextBox.text="Manoj"
        passwordInput.text="Canara2167*"
        print("Submit button clicked.")
        print("Welcome",nameTextBox.text)
    }
}


