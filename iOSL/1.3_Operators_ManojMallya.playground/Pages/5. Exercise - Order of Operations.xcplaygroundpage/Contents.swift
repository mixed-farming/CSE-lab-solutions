/*:
## Exercise - Order of Operations

 Print out what you think 10 + 2 * 5 evaluates to. Then print out the actual expression (i.e. `print(10 + 2 * 5)`)
 */
print(20)
print(10+2*5)

//:  In a separate `print` statement, add in the necessary parentheses so that addition takes place before multiplication.
print((10+2)*5)
//:  Print out what you think 4 * 9 - 6 / 2 evaluates to. Then print out the actual expression.
print(33)
print(4*9-6/2)
//:  In a separate `print` statement, add in the necessary parentheses so that the subtraction is prioritized over the multiplication and division.
print(4*(9-6)/2)

/*:
[Previous](@previous)  |  page 5 of 8  |  [Next: App Exercise - Complex Fitness Calculations](@next)
 */
let temaperature=70
switch temaperature{
case Int.min...64:
    print("It's too cold.")
case 65...75:
    print("The temperature is just right.")
case 76...Int.max:
    print("It's too hot.")
default:
    print("Invalid temperature.")
}
