/*
----------------------------------------------
--- Author         : Ahmet Özlü
--- Mail           : ahmetozlu93@gmail.com
--- Date           : 1st August 2017
----------------------------------------------
*/

# include <limits.h>
# include <string.h>
# include <stdio.h>
#include <sys/time.h>
# define NO_OF_CHARS 256
# define MAX 10000

int sum = 0;
int control = 0;

// A utility function to get maximum of two integers
int max (int a, int b) { return (a > b)? a: b; }

// The preprocessing function for Boyer Moore's bad character heuristic
void badCharHeuristic( char *str, int size, int badchar[NO_OF_CHARS]) {
    int i;

    // Initialize all occurrences as -1
    for (i = 0; i < NO_OF_CHARS; i++)
         badchar[i] = -1;

    // Fill the actual value of last occurrence of a character
    for (i = 0; i < size; i++)
         badchar[(int) str[i]] = i;
}

/* A pattern searching function that uses Bad Character Heuristic of Boyer Moore Algorithm */
void search( char *txt,  char *pat,char temp3[MAX],int k) {
    int m = strlen(pat);
    int n = strlen(txt);
    char src[MAX],p[MAX],temp[MAX],temp2[MAX],tempP[MAX],out[MAX];
    int badchar[NO_OF_CHARS],i,leng,l,count;
    char v;
    
    /* Fill the bad character array by calling the preprocessing function badCharHeuristic() for given pattern */
    badCharHeuristic(pat, m, badchar);
	leng = strlen(pat);
	strcpy(tempP,pat);
	strcat(tempP,"</mark>");
	leng = strlen(pat);
	l = strlen(txt);
    
    int s = 0;  // s is shift of the pattern with respect to text
    while(s <= (n - m)) {
        int j = m-1;

        /* Keep reducing index j of pattern while characters of pattern and text are matching at this shift s */
        while(j >= 0 && pat[j] == txt[s+j]) {
            count++;
            j--;
        }

        /* If the pattern is present at current shift, then index j will become -1 after the above loop */
        if (j < 0) {
            //printf("pattern occurs at shift = %d\n", s);

            /* Shift the pattern so that the next character in text
               aligns with the last occurrence of it in pattern.
               The condition s+m < n is necessary for the case when
               pattern occurs at the end of text */
            
            printf("The desired pattern was found starting from %d. line at position %d\n",k,s+1);
            strncpy(temp, txt, s);
            temp[s] = '\0';
            strcat(temp,"<mark>");
            control++;
            strcat(temp,tempP);
            
            for(i=0;i<MAX;i++) {
                if((s+leng+i)<strlen(txt))										
                    temp2[i] = txt[s+leng+i];
                else
                    temp2[i] = v;
            }
            
            strcat(temp,temp2);
            strcpy(temp3,temp);
            s += (s+m < n)? m-badchar[txt[s+m]] : 1;
        }

        else
            /* Shift the pattern so that the bad character in text
               aligns with the last occurrence of it in pattern. The
               max function is used to make sure that we get a positive
               shift. We may get a negative shift if the last occurrence
               of bad character in pattern is on the right side of the
               current character. */
            s += max(1, j - badchar[txt[s+j]]);
    }
    
	sum +=count;
}

/* Driver program to test above funtion */
int main() {
	char txt[MAX],p[MAX],temp[MAX],temp2[MAX],tempP[MAX],out[MAX];
	int k = 1;
	FILE *input = fopen("input.txt","r");	
	FILE *output = fopen("output.html","w");
	
    printf("Enter the text in which pattern is to be searched:\n");
	fgets(p, MAX, stdin);
	struct timeval  tv1, tv2;
	gettimeofday(&tv1, NULL);
	p[strlen(p)-1]='\0';
	temp[1]='a';
    
	while(!feof(input)){
		if(fgets (txt, MAX, input)!=NULL) {
			txt[strlen(txt)-1] = '\0';
    		search(txt, p,temp,k);
			if(temp[1]!='a') {
				fprintf(output,"%s\n",temp);
				temp[1]='a';
			}
			else
				fprintf(output,"%s\n",txt);
		}
		k++;
	}
    
	if(control==0) {
				printf("\nThe pattern was not found in the given text\n\n");
	}
    
	gettimeofday(&tv2, NULL);
	printf ("Total time = %f seconds\n", (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec));
	
    fclose(input);
	fclose(output);
	
    printf("The number of character comparison: %d\n",sum);
   
   return 0;
}
