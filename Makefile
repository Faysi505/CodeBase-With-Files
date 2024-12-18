CC = gcc
CFLAGS = -I.

# Название файла
TARGET = StudentManager
# переменная кода
OBJECTS = main.o

all: $(TARGET)

# С main.c в main.o
main.o: main.c
	$(CC) -c -o main.o main.c $(CFLAGS)

# Все в файл StudentManager
$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

# Clean
clean:
	rm -f *.o $(TARGET)
