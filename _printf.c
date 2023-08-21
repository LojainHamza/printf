#include <stdio.h>
#include <stdarg.h>
#include <main.h>

/**
 * _printf - prints formatted output
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int i = 0;
	char c;
	const char *s;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					c = (char)va_arg(args, int);
					putchar(c), i++;
					break;
				case 's':
					s = va_arg(args, const char *);
					while (*s != '\0')
					{
						putchar(*s), s++, i++; }
					break;
				case '%':
					putchar('%'), i++;
					break;
				default:
					putchar('%');
					putchar(*format);
					i += 2;
					break; }
		else
		{
			putchar(*format);
			i++; }
		format++; }
	va_end(args);
	return (i); }
