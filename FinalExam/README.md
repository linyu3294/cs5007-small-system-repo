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
      
        The front end performs syntatic and semantic anaylysis and then produces 
        a Abstract Syntactic Tree. The Backend optimizes and produces the object 
        code that the machine can understand.

    * Know about Compile-Time and Link-Time Interpositioning.
    
        Compile-Time Interposition optimizes code within the compiled code base.
        Link-Time Interposition is a technique used to override existing code 
        during linking time.
    
    * What is the purpose of compile-time and link-time interpositioning and what could it be used for.
      
        The purpose of compile-time and link-time interpositioning is to provide a 
        way to change the code base, either add/replace a piece of code.
      
    * What is a linker?
        
        A linker connects 2 or more files such that the linked file can have access 
        to the code in the file. The linker is the glue that binds code together so
        to speak.
        
    * Why do we use them?
        
        The linking process happens after the compilation process. To increase accessibility
        and efficiency, programmers do not always want to recompile the entire code 
        base of application. Instead, it may be better to compile each pieces of the 
        application as a executable object file, and then link them together after 
        the compilation. Here is where the linker has the role of connecting compiled 
        object files.
        
        
    *Describe the linking process
    
        There are two ways linking, dyanmic and static. Static linking is basiscally
        copying and pasting one file to another. Whereas dynamic linking does not copy,
        but merely provde a reference of an address of the first file to another file.
    
* **Processor and Processes**
    * What is a context switch? What information gets saved?
     
        A context switch is a procedure that takes a process to put in the foreground
        and rest of the running processes in the background.The foreground proceedure 
        has features to allow access to keyboard, mouse and any other devices.
        
    * What are signals?
        
        A signal is a message send to a process to interrupt it normal proceedure. For 
        example when the user presses control-c, a signal is sent to end the current 
        process.
        
    * How do you write a signal handler? What goes on when a signal is found?
    
        You will have to first import signal.h library. You can then use the 
        signal(SIGINT, sigint_handler) to call the signal handler. When a signal handler
        is found, the signal will be sent to the desginated process.
        
    * What does a fork() do? Why is it a strange function?
      
        The fork() function clones the current process and creates a child process. It is 
        a strange function because it returns twice. 
        
    * What does execve(...) do?
        
        execve() runs the program desginated by the filename. Filename must be a executable.
    
* **The Memory Hierarchy**
    * What is pipelining?
    
        Pipelining is a way for one program to execute while another program is already
        running. 
        
    * Why is branching bad for performance?
    
        Branching is bad for perforrmance because processors are pipelined and depend on 
        a predetermined sequence. When branches occur, they cause jumping logic and cause
        the pipeline in cpu to restart, and is therefore less efficient.
         
    * What is caching?
        
        Cache is a space for storing a limited and usually small amount of memory. Caching
        helps performance.
    
    * What is a directly mapped cache?
    
    
    
* **Virtual Memory**
    *What is virtual memory?
        
        Virtual Memeory is a region in RAM that is duplicated in a desginated
        place in the hard-disk. Once the region in the RAM is freed up, it give
        the user the illusion that there is unlimited space in RAM.
         
* **Concurrency**
    * What is a thread? What is a process? What is the difference?
     
        A thread is an instance that hosts a running process. A thread has its
        own id, logic, and stack/ local variables. Threads are a computational
        cheaper way or excecuting processes.
       
    * What is fork(), wait(), a child process, zombie processes, orphan processes
    
       A fork creates a new child process that's a clone of its parent process.
       A waint  b
    
    * How do you spawn a thread, and what does it mean to join a thread?.
    
    
    * Talk about the problems with concurrency and sharing memory.
    
    
    
Lets us know if you have any questions. 

      













 
 
