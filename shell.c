void exec(char* name);
void type(char* name);
main()
{
	char input[80];
	syscall(0,"SHELL>");
	syscall(1,input);
	if((input[0]=='e')&&(input[1]=='x')&&(input[2]=='e')&&(input[3]=='c'))
		exec(input);
	else if((input[0]=='t')&&(input[1]=='y')&&(input[2]=='p')&&(input[3]=='e'))
		type(input);
	else
		syscall(0,"Bad Command!\r\n");
	syscall(5);
}


void exec(char* name)
{
	int i;
	int j=0;
	char file[80];
	for(i=5;i<80;i++)
	{
		if(name[i]!='\0')
			file[j++]=name[i];
	}
	syscall(4,file);
	syscall(0,"\r\n");
}

void type(char* name)
{
	int i;
	int readSectors=0;
	int j=0;
	char file[80];
	char buff[13312];
	for(i=5;i<80;i++)
	{
		if(name[i]!='\0')
			file[j++]=name[i];
	}
	syscall(3,file,buff,&readSectors);
	if(readSectors!=0)
		syscall(0,buff);
	else
		syscall(0,"File not found");
	syscall(0,"\r\n");
}
