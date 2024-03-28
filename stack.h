#pragma once

#include <windows.h>
#include <stdio.h>
#include <locale.h>
#include <conio.h>

struct list
{
   char elem;
   list *next;

   list( char _elem = 0, list *_next = NULL ) :
      elem( _elem ), next( _next ) { };
};

struct stack
{
   list *s;

   inline int empty( ) { return !s; }

   void push( char e ) { s = new list( e, s ); }

   UCHAR pop( char *c )
   {
      if ( empty( ) ) return 0;
      *c = s->elem;
      list *p = s;
      s = s->next;
      delete p;

      return 1;
   }

   bool belong( char c )
   {
      if ( empty( ) ) return 0;

      stack b;
      bool HAVE = false;
      char n = 0;

      for ( ; pop( &n ); b.push( n ) )
         if ( c == n )
            HAVE = true;
      for ( ; b.pop( &n ); push( n ) );
      return HAVE;
   }

   void print( )
   {
      setlocale( 0, "" );
      printf_s( "Стек%s", empty( ) ? " пуст" : ": " );
      
      if ( !empty( ) )
      {
         stack b;
         char c = 0;

         for ( ; pop( &c ); b.push( c ) );
         for ( ; b.pop( &c ); printf_s( "%c ", c ), push( c ) );
      }
      printf_s( "\n" );
   }

   UCHAR input( )
   {
      FILE *f = NULL;
      if ( fopen_s( &f, "in.txt", "r" ) )
      {
         errno = 0;
         return 0;
      }

      for ( char b = 0 ; fscanf_s( f, "%c ", &b ) != EOF; push( b ) );
      errno = 0;

      return 1;
   }

   stack( ) :
      s( NULL ) { };
};