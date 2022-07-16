Manoj M Mallya
200905130
Section : C2
Roll no. : 23
OOPL – 8 – JavaFX and Event Handling
Exercises :
1)
Code :
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.layout.*;
import javafx.scene.*;
import javafx.scene.text.*;
import javafx.scene.paint.*;
import javafx.scene.control.*;
import javafx.geometry.*;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
public class l11q1 extends Application{ 
@Override 
public void start(Stage mainStage){ 
mainStage.setTitle("This is the first JavaFX Application"); 
Label l1 = new Label("Welcome to JavaFX programming"); 
l1.setFont(new Font(20)); 
TextField tf = new TextField(); 
tf.setText(""); 
Button b1 = new Button("Display"); 
FlowPane root = new FlowPane(); 
root.setHgap(10); 
root.setVgap(10); 
l1.setTextFill(Color.MAGENTA); 
Scene s1 = new Scene(root,500,200); 
root.getChildren().addAll(l1); 
root.getChildren().addAll(tf); 
root.getChildren().addAll(b1); 
root.setAlignment(Pos.CENTER); 
b1.setOnAction(new EventHandler <ActionEvent>(){ 
@Override 
public void handle(ActionEvent arg0){ 
String s = tf.getText(); 
for(int i=1;i<=10;i++){ 
Label l = new Label(s + " X " + String.valueOf(i) + " = " + 
String.valueOf(Integer.parseInt(s)*i) + "," + "\n");
root.getChildren().addAll(l); 
} 
} 
});
mainStage.setScene(s1); 
mainStage.show(); 
} 
public static void main(String[] args) { 
launch(); 
}
}
Output :

2)
Code :
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.scene.canvas.*;
import javafx.scene.paint.*;
import javafx.scene.image.*;
import javafx.scene.text.*;
import javafx.geometry.*;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
public class l11q3 extends Application{
@Override 
public void start(Stage mainStage){
mainStage.setTitle("JavFX Calculator");
GridPane gridRoot = new GridPane();
Label l1 = new Label("Number 1 : ");
Label l2 = new Label("Number 2 : ");
TextField tf1 = new TextField();
TextField tf2 = new TextField();
Text t = new Text();
ImageView img = new ImageView("calculator.png");
img.setFitHeight(50);
img.setFitWidth(50);
Button cmp = new Button("Compute", img);
Scene s = new Scene(gridRoot, 300, 150);
gridRoot.addRow(0,l1,tf1);
gridRoot.addRow(1,l2,tf2);
gridRoot.add(cmp,1,2);
gridRoot.add(t,1,4);
gridRoot.setHgap(5);
gridRoot.setVgap(5);
cmp.setOnAction(new EventHandler <ActionEvent>(){
@Override
public void handle(ActionEvent arg0){
gridRoot.getChildren().clear();
String s1 = tf1.getText();
String s2 = tf2.getText();
GraphicsContext gc;
Canvas myCanvas = new Canvas(300, 150);
gc = myCanvas.getGraphicsContext2D();
gc.fillText("Sum: " + 
String.valueOf(Float.parseFloat(s1)+Float.parseFloat(s2)), 0, 10);
gc.fillText("Difference: " + String.valueOf(Float.parseFloat(s1)-
Float.parseFloat(s2)), 0, 30);
gc.fillText("Product: " + 
String.valueOf(Float.parseFloat(s1)*Float.parseFloat(s2)), 0, 50);
gc.fillText("Quotient: " + 
String.valueOf(Float.parseFloat(s1)/Float.parseFloat(s2)), 0, 70);
gridRoot.add(myCanvas,0,6);
}
});
mainStage.setScene(s);
mainStage.show();
}
public static void main(String[] args){
launch(args);
}
}
Output :

3)
Code :
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.scene.text.*;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
public class l11q2 extends Application{
@Override 
public void start(Stage mainStage){ 
mainStage.setTitle("JavaFX Welcome"); 
GridPane grid = new GridPane();
Label l1 = new Label("Welcome"); 
Label l2 = new Label("Username"); 
Label l3 = new Label("Password");
Text t1 = new Text(); 
l1.setFont(new Font(20));
l2.setFont(new Font(15));
l3.setFont(new Font(15));
t1.setFont(new Font(15));
TextField tf = new TextField(); 
tf.setText("");
PasswordField pf = new PasswordField(); 
Button b1 = new Button("Sign In");
grid.add(l1,1,0); 
//grid.addRow(0,l1);
grid.addRow(1,l2,tf);
grid.addRow(2,l3,pf);
grid.add(b1,2,3);
grid.add(t1,1,3);
grid.setVgap(5);
grid.setHgap(5);
b1.setOnAction(new EventHandler <ActionEvent>(){ 
@Override 
public void handle(ActionEvent arg0){ 
String s = tf.getText(); 
if(s.length()!=0) 
t1.setText("Welcome "+s); 
} 
}); 
Scene s1 = new Scene(grid, 350, 150); 
mainStage.setScene(s1); 
mainStage.show(); 
} 
public static void main(String[] args){ 
launch(args); 
}
}
Output :
**********
