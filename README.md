# AVL vs. std::map Performance Analysis 🚀

Welcome to our project where we put the AVL tree and std::map through a series of rigorous tests to determine which data structure reigns supreme in various scenarios. Dive into our testing battlegrounds and see the results for yourself!

## What We Did 🛠️

We rolled up our sleeves and put these structures to the test on Windows and Linux platforms, challenging them with:

- Correctness of Insertion & Deletion
- Maximum Size Handling
- Load Performance
- Memory Efficiency
- Search Speed (worst case)

## Our Test Suite 🧪

Our tests were as tough as they were fair, ensuring that both the AVL tree and std::map had an equal opportunity to showcase their strengths and weaknesses.

### Correctness
Can they add and remove without a hiccup? We used hard-coded data to check their moves!

### Maximum Size
How much can they handle before crying for mercy? We pushed until `std::bad_alloc` showed its face.

### Load Performance
They say pressure makes diamonds, or in our case, the fastest data structure. We inserted thousands of records with no break!

### Memory Leak Check
Using `valgrind` and macOS's `Leaks`, we made sure no bytes were left wandering.

### Search Speed
Seek and you shall find, but how fast? We looked for the trickiest nodes to find out.

## Benchmarks Unveiled 📊

- **std::map vs AVL Tree**: Which is faster?
- **Windows vs Linux**: Does the platform change the game?
- **Memory Leak**: Are we eco-friendly with our memory usage?

Check out the [results](path-to-results) to see who won each round!

## A Linux Spin 🐧

Not content with just Windows, we put on our penguin hats and repeated key tests on Linux. Did the cooler climate help our contenders? Find out!

## How to Run Tests 🏃‍♂️

1. Choose your OS: `Windows` or `Linux`.
2. Compile the tests: `g++ -o performance_tests PerformanceTests.cpp`.
3. Run and observe: `./performance_tests`.
4. Don't forget to compare with our results!

## Questions or Feedback? 💬

Got a question about our methods? Or perhaps you have an idea to make our tests even better? [Let us know!](ttasbi@mysenec.ca)

## Credits 👏

- **Tasbi**: The vigilant overseer of AVL Trees and the benchmarking guru.
- **Madhur**: The std::map strategist and Linux test conductor.

## Conclusion 🏁

After a grueling showdown, the insights are clear. But in the world of data structures, today's victor might be tomorrow's runner-up. So we keep testing, learning, and optimizing!

Want more? Follow us on [LinkedIn](https://www.linkedin.com/in/tasbi03) for more electrifying projects!

---

