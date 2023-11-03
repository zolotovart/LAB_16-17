
#include <stdio.h>
#include <Windows.h>
#define NUM_ELEMENTS 10

int arr[NUM_ELEMENTS];
int n = 0;
int ch4 = 0;
int ii;
int iii;
int indmin;
int findIndexMax() {
	int ma = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] > ma) {
			ma = arr[i];
			iii = i;
		}
	}
	return iii;
}
int findIndexMin() {
	int mi = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] < mi) {
			mi = arr[i];
			ii = i;
		}
	}
	return ii;
}
void addElement(int addIndex, int Val) {
	for (int i = n; i > addIndex; i--) {
		arr[i] = arr[i - 1];
	}
	n++;
	arr[addIndex] = Val;
	
}
void deleteElement(int delIndex) {
	for (int i = delIndex; i < n - 1; i++) {
		arr[i] = arr[i + 1];
	}
	n--;
}
void findLastEven() {
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			ii = 2 * arr[i];
		}
	}
	printf("%d", ii);
}
void NUM7() {
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			arr[i] = arr[i] * -1;
		}
	}
}
void NUM8() {
	for (int i = 0; i < n; i++) {
		if (arr[i] < 4) {
			arr[i] = 4;
		}
	}
}
void bol10() {
	for (int i = 0; i < n; i++) {
		if (arr[i] > 10) {
			ch4++;
		}
	}
	printf(" %d", ch4);
	ch4 = 0;
}
void printElements() {
	printf(" <");
	for (int i = 0; i < n; i++) {
		printf(" %d", arr[i]);
	}
	printf(" >\n");
}
void keyboardInput() {
	printf("n = ");
	scanf_s("%d", &n);
	printf("input %d values: ", n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
}
void oddsX10() {
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 != 0) {
			arr[i] *= 10;
		}
	}	
}
int findMin() {
	int mi = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] < mi) {
			mi = arr[i];
			indmin = i;
		}
	}
	return mi;
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int item;
	do {
		printf("\n");
		printf("------------------------------\n");
		printf("Содержимое массива:");
		printElements();
		printf("Выберите нужную вам операцию:\n");
		printf("1: Ввести с клавиатуры массив\n");
		printf("2: x10 для всех нечетных элементов\n");
		printf("3: Найти минимальный элемент\n");
		printf("4: Сколько элементов больше 10\n");
		printf("5: Увеличивать в 2 раза последний четный\n");
		printf("6: Сколько четных левее минимального\n");
		printf("7: Увеличить в 10 раз все нечетные элементы, стоящие правее минимального\n");
		printf("8: Все четные элементы массива умножить на - 1\n");
		printf("9: Все элементы массива имеющие значения меньше 4 заменить на 4\n");
		printf("10: Все элементы стоящие между максимальным и минимальным увеличить в 10 раз\n");
		printf("11: Удаление заданного элемента массива\n");
		printf("12: Вставка нового элемента в заданное место\n");
		printf("13: Удалить минимальный элемент\n");
		printf("14: Перед минимальным элементом вставить 0\n");
		printf("15: Удалить все четные элементы\n");
		printf("16: Продублировать все четные элементы\n");
		printf("17: Добавить в начало элемент, равный минимальному\n");
		printf("\n");
		printf("0: Выйти из программы\n");
		printf("Выбранная операция >>>>>> ");

		scanf_s("%d", &item);

		switch (item) {
		case 1:
			keyboardInput();
			break;

		case 2:
			oddsX10();
			break;

		case 3:
		{
			int mi = findMin();
			printf("min = %d\n", mi);
		}
		break;

		case 4:
			bol10();
			break;

		case 5:
		{
			findLastEven();
			break;
		}
		break;

		case 6:
		{
			int index = findIndexMin();
			printf("Индекс минимального элемента  %d\n", index);

			int cnt = 0;
			for (int i = 0; i < index; i++) {
				if (arr[i] % 2 == 0) {
					cnt++;
				}
			}
			printf("Левее минимального %d четных элементов\n", cnt);
		}
		break;

		case 7:
		{
			int index = findIndexMin();
			printf("Индекс минимального элемента  %d\n", index);

			int cnt = 0;
			for (index; index < n; index++) {
				if (arr[index] % 2 != 0) {
					arr[index] *= 10;
				}
			}
		}
		break;

		case 8:
			NUM7();
			break;
		case 9:
			NUM8();
			break;

		case 10:
		{
			int index1 = findIndexMin();
			int index2 = findIndexMax();

			if (index1 < index2) {
				for (int i = index1 + 1; i < index2; i++) {
					arr[i] *= 10;
				}
			}
			else {
				for (int i = index1 - 1; i > index2; i--) {
					arr[i] *= 10;
				}

			}
		}
		break;

		case 11:
		{
			printf("Индекс удалённого элемента = ");
			int index;
			scanf_s("%d", &index);
			deleteElement(index);
		}
		break;

		case 12:
		{
			printf("Перед каким элементом нужно вставить новый? Индекс = ");
			int index;
			scanf_s("%d", &index);
			printf("Значение которые нужно вставить = ");
			int value;
			scanf_s("%d", &value);

			addElement(index, value);

		}
		break;

		case 13:
		{
			findMin();
			deleteElement(indmin);
		}
		break;

		case 14:
		{
			int indexMin = findIndexMin();
			printf("Индекс элемента = %d\n", indexMin);
			addElement(indexMin, 0);
		}
		break;
		case 15:
		{
			for (int i1 = 0; i1 < n; i1++) {
				if (arr[i1] % 2 == 0) {
					deleteElement(i1);
					i1--;
				}
			}
		}
		break;
		case 16:
		{
			for (int i1 = 0; i1 < n; i1++) {
				if (arr[i1] % 2 == 0) {
					addElement(i1, arr[i1]);
					i1++;
				}
			}
		}
		break;

		case 17:
		{
			int z17 = findMin();
			printf("%d", z17);
			addElement(0, z17);
		}
		break;


		}


	} while (item != 0);
}

