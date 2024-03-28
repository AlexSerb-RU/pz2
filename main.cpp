#include "stack.h"

int main( )
{
   stack s;

   setlocale( 0, "" );

   enum Commands { INPUT = 1, PUSH, POP, PRINT, BELONG, EXIT };

   const char *text =
      "�������: "
      "\n<1> ���� � �����"
      "\n<2> �������� �������"
      "\n<3> ����� �������"
      "\n<4> ���������� �����"
      "\n<5> ��������� ������� ��������"
      "\n<6> �����";
   char c = 0;

   for (UCHAR n = 0 ; true; system( "pause" ), system( "cls" ), n = 0, c = 0)
   {
      system( "cls" );
      printf_s( "%s\n������� �������: ", text );

      scanf_s( "%hhu", &n );

      switch ( n )
      {
         case INPUT: 
            printf_s( "in.txt %s������.\n", s.input( ) ? "������� " : "�� " );
         case PRINT:
            s.print( );
            break;
         case PUSH: printf_s( "\n������� �������: " );
            if ( !scanf_s( "\n%c", &c ) )
               printf_s( "�� ���������� ����." );
            else
            {
               s.push( c );
               s.print( );
            }
            break;
         case BELONG: printf_s( "\n������� �������: " );
            if ( !scanf_s( "\n%c", &c ) )
               printf_s( "�� ���������� ����." );
            else
               printf_s( "�������%s ������\n", s.belong( c ) ? "" : " ��");
            break;
         case POP: if ( s.pop( &c ) ) printf_s( "���� �������: %c\n", c );
            s.print( );
            break;
         case EXIT:
            system( "pause" );
            return 0;
         default:
            printf_s( "������� ����� ������� �� ������!\n" );
      }
      scanf_s( "%*[^\n]" );
   }

   return 0 * _getch( );
}
