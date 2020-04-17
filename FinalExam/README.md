# Final Exam

 ## Honor code: 
 
 By signing my name below, I affirm that:
 
 1. All the answers submitted by me has been written by me.
 
 2. I have not talked or otherwise communicated with anybody about 
    questions related to this take home exam. This includes, but is not limited to:
    a. All modes of communication, including face-to-face communication, text, 
       audio or video chat, emails or online posts.
    b. Asking for help from others, and providing help to others.

  3. I am aware that my submissions may be checked for plagiarism and 
     similarity with other submissions, and if I am found to have broken 
     any of these rules, I will get a 0 on the entirety of this exam, 
     and will be reported for an academic integrity violation.
  4 I have read and understand this honor code in full. 
   
  First and last name, ID, (Replace by your full name, and your ID)
  
# Take home Quiz/Exam Due Saturday 4/18  at Midnight

Answer each of the following questions in your own words. Two to three sentences each. I would recommend typing all of your
answers in a word document and when you are satisfied with your answers paste them here.

* **Operating System Overview**
    * What exactly is the kernel?
        A kernal is the essencial part of an operating system. It is the one
        program that rules it all and runs along any other program and manages
        time for each running program so that every program gets a share slice
        of the computer's resource.

* **C Programming**
    * What is a pointer? 
        A pointer is a variable that holds the address of another variable.    
        The pointer can be later accessed to retrive the addresss of the
        originally saved variable.

    * What is Pass by Value?
        Pass by Value is a technique used when a value of an object is transferred to
        the take in place the value of another object. A common way to pass by
        value is to use a pointer.

    * How do you dynamically allocate memory?
        You can dynamically allocate memory by calling the malloc function in C.
        Malloca will allocate memory on the heap for a amount of space specified
        by an user. It will persit until that memory is freed up.

* **Assembly and Machine Representation**
    * What are registers and how many registers do you have in x86-64
        There are 16 registers in the x86-64.

    * What are some of those registers reserved for?
        Some hold important values such as variables of the computer. Some hold
        the value of the stack pointer and program pointer.

    * What is a syscall?
        A syscall is a way for prococesses to access functions on the operating
        system/ kernal. A system can be called at various levels even at the
        assembly level.
        
    * How do the stack and the heap work?
        A stack is a part of the computer memeory where a called function uses
        to temporarily store data. When a function is called, a function pointer
        will be assigned on the stack. The function will be given memory allocated here
        for its variables and operations. And as the function finishes its
        tasks, the completed function will give up its memory and the previous
        function pointer will be restored.
        
    * What are opcodes?
        Opcode is short for saying "Operation Code". It is a very low level
        language. It is a single operation that can be executed by the machine's
        CPU.
        
    * What do the following instructions do mov, cmp, jmp, and add, etc.
        These are operations in Assembly code.
        mov - copies the data that lives in the second register to first
        register
        cmp - compares the values of the two data entities
        jmp - gives the control of the program to the location of the register
        add - performs addition of two data entities and stores the data in the
        first register

* **Compilers and Linkers**
    * What does a compiler do?
        Compilers consumes code written in general-purpose programing language
        and translates it to code that the machine can understand. It has a
        mulitples stages of transformations and anlysis. 

      * Why do we use them?
        We use compilers because it provides us the benefit of not having to
        deal with machine code. It makes us more productive as programers. It
        allows some baked in performance boost to apply to the generated machine
        code. 

      * What is the frontend responsible for? The backend?
        The front end performs syntatic and semantic anaylysis, which ensures
        that there are no typos

    * Know about Compile-Time and Link-Time Interpositioning.
      * What is the purpose of compile-time and link-time interpositioning and what could it be used for.
    * What is a linker?
      * Why do we use them?
    *Describe the linking process
* **Processor and Processes**
    * What is a context switch? What information gets saved?
    * What are signals?
    * How do you write a signal handler? What goes on when a signal is found?
    * What does a fork() do? Why is it a strange function?
    * What does execve(...) do?
* **The Memory Hierarchy**
    * What is pipelining?
    * Why is branching bad for performance?
    * What is caching?
    * What is a directly mapped cache?
* **Virtual Memory**
    *What is virtual memory?
* **Concurrency**
    * What is a thread? What is a process? What is the difference?
      * What is fork(), wait(), a child process, zombie processes, orphan processes
    * How do you spawn a thread, and what does it mean to join a thread?.
    * Talk about the problems with concurrency and sharing memory.
    
    
Lets us know if you have any questions. 

      













 
 
