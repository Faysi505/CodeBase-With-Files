# CodeBase-With-Files
> This repository contains program that creates database with structure and then edit file studentlist.txt with changed information.
> All the function divided to the files wtih type H and then imported in to main.c.
> 
> It allows user to delete student from the list, add new students, edit student that already in the list,
> sort list by name, surname, age and class and filter it to see specific students that are in specific group,
> filter list by any information.





# Features
> Accepts specific integers to address user commands to the programm.
> 
> Efficiency: Optimized to handle big amount of information located in the list.
> 
> Free use of list: User have a lot ways to change and sort list by the command.
> 
> To use program user have to input specific integers that written in terminal by the program.
>
> This program also read files from file studentlist.txt and write back changed student list.





# How to Use
Prerequisites:
> Ensure you have a C++ compiler installed on your system.

# Running the Program

> To run a program first of all you need to create launch file by typing `make` to the terminal.
```
make
```
> After write "./sm" to the terminal.
```
./sm
```
> If you'd like to delete launch files just type "make clean" to terminal.
```
make clean
```





# Example of the communication with a programm.

### Programm output:
```
  _____________________________________________ 
  Введите действие которые хотите сделать:
  Добавить студента  - - - - - - - [1] 
  Удалить студента - - - - - - - - [2] 
  Изменить информацию о студенте - [3] 
  Отсортировать список - - - - - - [4] 
  Отфильтровать список - - - - - - [5] 
  Показать список  - - - - - - - - [6]
  Выйти из программы - - - - - - - [7]
_____________________________________________
```
### User input : 
```
4
```
### Programm output:
```
_____________________________________________
По какому критерию вы хотите сортировать?
_____________________________________________
1. Имя
2. Фамилия
3. Возраст
4. Класс
```
### User input: 
```
1
```
### Programm output:
```
_____________________________________________
Список студентов отсортирован!
_____________________________________________
```



# License
`This project is licensed under the MIT License. See the LICENSE file for details.`
# Contributions
`Contributions are welcome! If you have suggestions for improvements or find any bugs, please open an issue or submit a pull request.`
