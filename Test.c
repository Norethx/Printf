#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

 void	ft_print_char(char* str,...)
//void	ft_print_char(const char* a,...)
{
	int i = 0;
	size_t j;
	void *sr;
	int n;
	va_list s;
	va_start(s,str);
	sr = va_arg(s,void *);
	j = sizeof(sr);
	while(i < 2)
	{
		sr = va_arg(s,void *);
 			j = sizeof(sr);
		i++;
	}
}

int	main(void)
{

	int num = 123;
    double pi = 3.1415926;
    char str[] = "Olá";
	// ft_print_char(&ft_putchar,2,'c','a');
	ft_print_char("%d%d%d",1000,"-0.# +spdiuxX%");
	printf("|%020d|",233);

    printf("|%10d| : inteiro com largura 10, justificado à direita\n", num);
    printf("|%10f| : float com largura 10, 2 casas decimais, justificado à direita\n", pi);
    printf("|%10s| : string com largura 10, justificado à direita\n", str);

    // Left justification (alinhado à esquerda) — flag '-'
    printf("|%-10d| : inteiro com largura 10, justificado à esquerda\n", num);
    printf("|%-10f| : float com largura 10, 2 casas decimais, justificado à esquerda\n", pi);
    printf("|%-10s| : string com largura 10, justificado à esquerda\n", str);

	// write(2,&"teste",5);
// • %c Imprime um único caractere.
// • %s Imprime uma string (conforme definido pela convenção comum do C).
// • %p O endereço do ponteiro void * deve ser impresso em formato hexadecimal.
// • %d Imprime um número decimal (base 10).
// • %i Imprime um inteiro em base 10.
// • %u Imprime um número decimal (base 10) sem sinal.
// • %x Imprime um número em formato hexadecimal (base 16) em minúsculas.
// • %X Imprime um número em formato hexadecimal (base 16) em maiúsculas.
// • %% Imprime um sinal de porcentagem.
}
