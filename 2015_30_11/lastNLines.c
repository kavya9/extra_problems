//Print the last n lines of a file [done]
#include<stdio.h>
#include<stdlib.h>
struct test
{
	char str1[100];
	int n;
	char str2[100];
}testCase[10] = { { "", 2, '\0' }, { "kav\nkavya\nkavya1\n", 0, '\0' }, { "a\nb\nc\n", 4, "a\nb\nc\n" },
{ "kav\nkavya\nkavya1\n", 1, "kavya1\n" }, { "kav\nkavya\nkavya1\n", 2, "kavya\nkavya1\n" },
{ "kav\nkavya\nkavya1\n", 3, "kav\nkavya\nkavya1\n" }, { "kav\nkavya\nkavya1\n" ,-10,'\0'} };
int len(char *s)
{
	int i = 0; if (s == '\0')return 0;
	while (s[i] != '\0')
		i++;
	return i;
}
FILE *allocStrToFile(char *str)
{
	int i=0;
	FILE *f;
	f = fopen("test.txt", "w");
	while (str[i] != '\0')
	{
		putc(str[i], f);
		i++;
	}
	fclose(f);
	return f;
}
char *allocate(char *a)
{
	char  *r;
	int i = 0;
	r = (char*)malloc(1000 * sizeof(char));

	while (a[i] != '\0')
	{
		r[i] = a[i];
		i++;
	}
	r[i] = '\0';
	return r;
}
char * NLines(FILE *f,int n)
{
	char *str = (char *)malloc(100l * sizeof(char));
	FILE *f1,*t;
	f = fopen("test.txt", "r");
	if (n <= 0)return '\0';
	int cnt = 0,i=0,flag=0;
	char ch;
	while ((ch = fgetc(f)) != EOF)
	{
		if (ch == '\n')cnt++;
	}
	
	fseek(f, 0, SEEK_SET);
	if (cnt <= n)
	{
		while ((ch = fgetc(f)) != EOF)
		{
			str[i] = ch;
			i++;
		}
		str[i] = '\0';
	}
	else
	{
		int diff = cnt - n;
		while (diff > 0)
		{
			ch = fgetc(f);
			if (ch == '\n')diff--;
		}
		while ((ch = fgetc(f)) != EOF)
		{
			str[i] = ch;
			i++;
		}
		str[i] = '\0';
	}

	
	return str;
}
int compare(char *a, char *b)
{

	int i = 0, len1 = len(a);
	for (i = 0; i < len1; i++)
	if (a[i] == b[i])
		continue;
	else
		return 0;
	return 1;
}
void testMethods()
{
	int i, x;
	char *final, *result;
	FILE *f1;
	for (i = 0; i<7; i++)
	{
		f1 = allocStrToFile(testCase[i].str1);
		result = NLines(f1, testCase[i].n);
		//printf("\n\n%s", final);
		final = allocate(testCase[i].str2);
		x = compare(result, final);
		if (x == 1)
			printf("\n passed");
		else
			printf("\n failed");
	}
}

int main()
{
	testMethods();
	getch();
	return 0;
}