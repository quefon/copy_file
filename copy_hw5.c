#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<libgen.h>
#define MAX 1000

char *dirc,*dname;
void name(char *path);

int main(int argc,char* argv[])
{
    if(argc == 3)
    {
		FILE *file,*stream;
	    char *path = argv[2];  
	    name(path);
	    
	    char tmpstr[] = "/tmpfile_XXXXXX";
	    char connect[MAX] = "";
	    strcpy(connect,dname);
	    strcat(connect,tmpstr);
	    //mkdtemp(connect);
	       
	    file = fopen(argv[1],"r+");
	    stream = fdopen(mkstemp(connect),"w");

	    char word[MAX];
	    size_t ret;
	    
	    while(!feof(file))
	    {
			ret = fread(word,1,MAX,file);           
			if(ret>0)
			{
			    fwrite(word,1,ret,stream);        
				fflush(stream);
			}
	    }
	    
	    printf("please input a char: ");
	    char disapper;
	    scanf(" %c",&disapper);  
	    int result;
	    
	    if(disapper == 'q')
		{
			fclose(file);
			fclose(stream);
			result = rename(connect,argv[2]);  
		}
		if(result==0) printf("All down !!");
		else printf("defeat !!");
		
    }
    else
   	{
   		printf("your need input two filename ! ");
   		exit(1);
   	}
    return 0;
}
void name(char *path)
{
    dirc = strdup(path);
    dname = dirname(dirc);        
}
