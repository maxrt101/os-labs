# OS Labs

## Lab 2: Syscalls

1. Write / Read  
   - Write a program that will read 15 symbols inputed by the user (`read.c`)
   - Write a program that print number of symbols read by `read` (`read.c`)
2. Open  
   - Write a program that will write some data into file (`open.c`)
   - Write a program that will read 8 chars from file and write them into new file (`open2.c`)
   - Write a program that will write contents of file1 into file2 without deleting or rewriting it (`open3.c`)
3. Fork  
   - Write a program that will create 2 child processes (`fork.c`)
   - Write a program that will create a child process that will create a child process (`fork2.c`)
4. Wait
   - Write a program that will print parent and child messages in that specific order (2 implementations `wait.c`, `wait2.c`)
   - Write a program that will create file in child and write used data to it from parent (`wait3.c`)
   - Write a program that will create 2 child processes and parent should wait for them to exit (implemented in `fork.c`) 

## Lab3: Services
Setup mysql, nginx and database lab from previous semester.  
Nginx should act like a proxy from DB lab.  
Nginx should use self-signed (using openssl) ssl keys.  
DB lab should start authomatically on boot, and restart if it is killed.  

## Lab4: Docker
Migrate 3rd lab into docker.  
Create separate containers for DB app, nginx and mysql.  
Mysql container should store its data using a volume.   
Use docker-compose for managing the containers.  
Also set up graphana with prometheus to monitor other containers.  
