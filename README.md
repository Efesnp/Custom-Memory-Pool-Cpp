C++ High-Performance Memory Pool Implementation
This project is a custom Memory Pool allocator designed to minimize the overhead of standard malloc and free calls and prevent memory fragmentation, focusing on low-latency system programming.

MotivationIn performance-critical environments—such as competitive gaming or real-time systems—frequent runtime memory allocations can lead to frame drops and increased latency. This implementation provides a pre-allocated memory structure to achieve O(1) allocation and deallocation time complexity.

Technical Features
Constant Time Allocation: Fast block retrieval using a free-list mechanism, ensuring zero search overhead during runtime.

Cache-Friendly Design: Contiguous memory layout optimized for modern CPU architectures like the AMD Ryzen 7 9800X3D, improving L1/L3 cache hit rates.

Memory Safety: Robust destructor implementation that ensures all pool-allocated memory is returned to the OS, preventing memory leaks.

Fixed-Block Architecture: Designed specifically for scenarios where multiple objects of the same size are frequently created and destroyed.

The project is built and optimized for Visual Studio 2022.

Clone the repository.

Open the .sln file in Visual Studio.


Future Roadmap
Implement Template support for generic type allocation.
Add Thread-Safety for multi-threaded applications.
Integrate a Benchmarking Module to compare performance against standard STL allocators.


