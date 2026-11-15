def gradient_descent(x, learning_rate, iterations):
    for i in range(iterations):
        gradient = 2 * (x + 3)
        x = x - learning_rate * gradient
        print(f"Iteration {i + 1}: x = {x:.6f}, y = {(x + 3) ** 2:.6f}")

    return x


x_start = 2

learning_rate = 0.1
iterations = 20

minimum_x = gradient_descent(x_start, learning_rate, iterations)

print("\nLocal minimum occurs at x =", minimum_x)
print("Minimum value =", (minimum_x + 3) ** 2)
