






extern int printf (const char *__restrict __format, ...);


int add(int a, int b){

 return a + b;
}

int main(int argc, char const *argv[])
{
   int _a;

   printf("%d\n", argc);
   printf("%s\n", argv[0]);
   printf("%s\n", argv[1]);
   printf("Hello Wolrd!\n");
   return 0;
}
