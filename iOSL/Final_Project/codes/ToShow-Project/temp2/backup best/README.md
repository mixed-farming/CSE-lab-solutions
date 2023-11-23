# Birthday-Tracker
Simple Swift app for educational purposes.
My first app.
It was challenging to figure out why data doesnt show in BirthdaysTableViewController. To refresh data you had to restart app.
The reason was:
ViewController presented modally doesnt close TableViewController. Thats why viewWillAppear didnt run after saveTapped.
