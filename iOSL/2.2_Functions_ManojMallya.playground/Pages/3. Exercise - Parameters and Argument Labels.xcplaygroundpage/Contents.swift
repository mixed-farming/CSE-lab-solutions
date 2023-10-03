/*:
## Exercise - Parameters and Argument Labels
 
 Write a new introduction function called `introduction`. It should take two `String` parameters, `name` and `home`, and one `Int` parameter, `age`. The function should print a brief introduction. I.e. if "Mary," "California," and 32 were passed into the function, it might print "Mary, 32, is from California." Call the function and observe the printout.
 */
func introduction(name: String, home: String, age: Int){
    print(name + ", " + String(age) + ", is from " + home)
}

let names="Manoj"
let ages=21
let homes="India"
introduction(name: names, home: homes, age:  ages)

//:  Write a function called `almostAddition` that takes two `Int` arguments. The first argument should not require an argument label. The function should add the two arguments together, subtract 2, then print the result. Call the function and observe the printout.
func almostAddtion(_ firstNumber: Int, secondNumber: Int)
{
    print(firstNumber+secondNumber-2)
}

let num1=5,num2=10
almostAddtion(num1, secondNumber: num2)


//:  Write a function called `multiply` that takes two `Double` arguments. The function should multiply the two arguments and print the result. The first argument should not require a label, and the second argument should have an external label, `by`, that differs from the internal label. Call the function and observe the printout.
func multiply(firstNumber: Double, secondNumber: Double)
{
    print(firstNumber*secondNumber)
}

let num3=4.0,num4=9.0
multiply(firstNumber: num3, secondNumber: num4)

/*:
[Previous](@previous)  |  page 3 of 6  |  [Next: App Exercise - Progress Updates](@next)
 */
