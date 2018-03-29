#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int string_len(char* str)
{
  int i;

  for( i = 0; str[i] != '\0' ;i++);
  return i;
}

void string_reverse(char* str)
{
  int i,len;
  char* str2;
  
  len = string_len(str);
  
  str2 = malloc(sizeof(char)*string_len(str));
  
  memcpy(str2, str, sizeof(char)*string_len(str));

	/*for( i = 0 ; i < len ; i++){
	str2[i] = str[i];  
  } */	// igual a memcopy
  
  for( i = 0 ; i < len ; i++){
	str[i] = str2[len-1-i];  
	}
  
  free(str2);
}

int string_concat(char* str1, char* str2, int max)
{
	int len1 = string_len(str1);
	int len2 = string_len(str2);
	int iter = 0;

	for(; iter + len1 < max ; iter++)
	{
		str1[iter + len1] = str2[iter];
	}
	
	str1[iter + len1] = '\0';
	return (iter + len1);
}

void string_concat2(char* str1, char* str2)
{
	int len1 = string_len(str1);
	int iter = 0;


	for(; str2[iter] != '\0' ; iter++)
	{
		str1[iter + len1] = str2[iter];
	}
	
	str1[iter + len1] = '\0';
	return;
}

int string_compare(char* str1, char* str2)
{
	int s1 = string_len(str1);
	int s2 = string_len(str2);
	int i = 0;
	
	for(; i < s1  || i < s2 ; i++)
	{
		if(str1[i] < str2[i])
			return -1;
		if(str1[i] > str2[i])
			return 1;
	}
	return 0;
}

int string_subcadena(char* str1, char* str2){
	int s1 = string_len(str1);
	int s2 = string_len(str2);
	
	for(int i = 0; i < s1; i++)
		if( str1[i] == str2[0])
			for(int j = 1; j < s2; j++){
				if(str1[i+j] != str2[j]) break;
				if(j == s2-1) return i;
			}
	return -1;
}

void string_unir(char* arregloStrings[], int capacidad, char* sep, char* res){
	int i = 0;
	printf("%s\n",res);
	for(; i != capacidad -1; i++){
		string_concat2(res, arregloStrings[i]);
		printf("%s\n",res);
		string_concat2(res, sep);
	}
	string_concat2(res, arregloStrings[i]);
}


int main(){
	
	char str1[10] = "solesol";
	char str2[10] = "sol";
	int c;

	//string_reverse(str1);
/*
	c = string_concat(str1, str2, 10);
	
	int i = string_compare(str1,str2);
	printf("%i\n",i);
	printf("%d\n", c);
	printf("%s\n", str1);

	int s = string_subcadena(str1,str2);
	printf("%i\n",s);
	* */
	
	char* arregloStrings[] = {"hola", "k", "ace"};
	char sep[] = "-";
	char res[20];
	res[0] = '\0';
	int capacidad = 3;
	
	string_unir(arregloStrings, capacidad, sep, res);
	
	printf("%s\n", res);
	return 0;
}