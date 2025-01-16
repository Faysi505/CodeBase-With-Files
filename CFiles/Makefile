CC = gcc
CFLAGS = -I.

# Название файла
TARGET = sm
# переменная кода
OBJECTS = main.o

all: $(TARGET)

# С main.c в main.o
main.o: main.c
	$(CC) -c -o main.o main.c $(CFLAGS)

# Все в файл sm
$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

# Clean
clean:
	rm -f *.o $(TARGET)
