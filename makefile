all: main
# Собираем объектные файлы (*.o) из исходников
main.o: main.c
	gcc -c $^ -o $@

MatrixOperations.o: MatrixOperations.c
	gcc -c $^ -o $@

AllocateMemory.o: AllocateMemory.c
	gcc -c $^ -o $@

# $^ это список всех зависимостей, в нашем случае main.c, MatrixOperations.c, AllocateMemory.c
# $@ это имя выходного файла
# На выходе получаем три файла:
# main.o, MatrixOperations.o, AllocateMemory.o
# Теперь нужно их слинковать, поэтому переходим к этапу линковки



# Далее нам нужно собрать исполняемый файл из трёх объектных файлов
# На выходе получаем исполняемый файл main.exe
main: main.o MatrixOperations.o AllocateMemory.o


# -c это входной файл исходного кода
# -o это имя выходного файла