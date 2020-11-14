gcc -o MyApp window.c -Wall `pkg-config --cflags --libs gtk+-3.0` -export-dynamic && ./MyApp

