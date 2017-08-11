/*
----------------------------------------------
--- Author         : Ahmet Özlü
--- Mail           : ahmetozlu93@gmail.com
--- Date           : 1st August 2017
----------------------------------------------
*/

#include<stdio.h>
#include<string.h>
#include <sys/time.h>
#define MAX 10000

int count=0;
int t[MAX];

void shifttable(char p[]) {
	int i,j,m;
	m=strlen(p);
    
	for(i=0;i<MAX;i++)
  		t[i]=m;
    
	for(j=0;j<m-1;j++)
		t[p[j]]=m-1-j;
}

int horspool(char src[],char p[]) {
	int i,j,k,m,n;
	n=strlen(src);
	m=strlen(p);
	i=m-1;
    
	while(i<n) {
        count++;		
		k=0;
		while((k<m)&&(p[m-1-k]==src[i-k]))
			k++;
		if(k==m)
			return(i-m+1);
		else
			i+=t[src[i]];
	}
    
	return -1;
}

void main() {
	char src[MAX],p[MAX],temp[MAX],temp2[MAX],tempP[MAX],out[MAX];
	char *b;
	FILE *input = fopen("input.txt","r");
	FILE *output = fopen("output.html","w");
	int pos;
	int control;
	char v;
	
    printf("%c",v);
	printf("Enter the text in which pattern is to be searched:\n");
	
    fgets(p, MAX, stdin);
	struct timeval  tv1, tv2;
	gettimeofday(&tv1, NULL);
	strcpy(tempP,p);
	strcat(tempP,"</mark>");
	p[strlen(p) - 1] = '\0';
	
    int leng = strlen(p);
	int srcleng,sum,i,g;
	
    while(!feof(input)) {
		if(fgets (src, MAX, input)!=NULL){
			src[strlen(src) - 1] = '\0';
			srcleng = strlen(src);
			shifttable(p);
			pos=horspool(src,p);
			sum +=count;
			
            if(pos>=0) {
				printf("The desired pattern was found starting from %d. line at position %d\n",g+1,pos+1);
				control++;
			}
			
			if(pos!=-1) {
				strncpy(temp, src, pos);
				temp[pos] = '\0';
				strcat(temp,"<mark>");
				strcat(temp,tempP);
                for(i=0;i<MAX;i++){
                    if((pos+leng+i)<strlen(src))										
                        temp2[i] = src[pos+leng+i];
                    else
                        temp2[i] = v;
				}
				strcat(temp,temp2);
				fprintf(output,"%s\n",temp);
			}
			else
				fprintf(output,"%s\n",src);		
		}
		g++;
	}
    
	if(control==0) {
		printf("\nThe pattern was not found in the given text\n\n");
	}
    
	gettimeofday(&tv2, NULL);
	printf ("Total time = %f seconds\n", (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec));

	fclose(input);
	fclose(output);

	printf("The number of character comparison: %d\n",sum);
}