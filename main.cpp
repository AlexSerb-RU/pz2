#include "stack.h"

int main( )
{
   stack s;

   setlocale( 0, "" );

   enum Commands { INPUT = 1, PUSH, POP, PRINT, BELONG, EXIT };

   const char *text =
      "Команды: "
      "\n<1> Ввод с файла"
      "\n<2> Добавить элемент"
      "\n<3> Взять элемент"
      "\n<4> Содержимое стека"
      "\n<5> Проверить наличие элемента"
      "\n<6> Выход";
   char c = 0;

   for (UCHAR n = 0 ; true; system( "pause" ), system( "cls" ), n = 0, c = 0)
   {
      system( "cls" );
      printf_s( "%s\nВведите команду: ", text );

      scanf_s( "%hhu", &n );

      switch ( n )
      {
         case INPUT: 
            printf_s( "in.txt %sсчитан.\n", s.input( ) ? "успешно " : "не " );
         case PRINT:
            s.print( );
            break;
         case PUSH: printf_s( "\nВведите элемент: " );
            if ( !scanf_s( "\n%c", &c ) )
               printf_s( "Не корректный ввод." );
            else
            {
               s.push( c );
               s.print( );
            }
            break;
         case BELONG: printf_s( "\nВведите элемент: " );
            if ( !scanf_s( "\n%c", &c ) )
               printf_s( "Не корректный ввод." );
            else
               printf_s( "Элемент%s найден\n", s.belong( c ) ? "" : " не");
            break;
         case POP: if ( s.pop( &c ) ) printf_s( "Взят элемент: %c\n", c );
            s.print( );
            break;
         case EXIT:
            system( "pause" );
            return 0;
         default:
            printf_s( "Введите номер команды из списка!\n" );
      }
      scanf_s( "%*[^\n]" );
   }

   return 0 * _getch( );
}
