#include <visual_2010.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int br_cikli(FILE *, int, int, int);
int br_znacheshti(FILE *, int);
int main()
{
  FILE *fp;
  int brf=0, brw=0, brd=0, brz=0;

  if((fp = fopen("test.txt","r"))==NULL) {
    printf("Greshka pri otvarqne na faila.\n");
    return 1;
  }

	br_cikli(fp, &brf, &brw, &brd);
	br_znacheshti(fp, &brz);
   
   printf("for: %d\nwhile: %d\ndo/while:%d\n", brf, brw, brd);
   printf("\nBroi znacheshtite simvoli v komentarite(bez simvolite /* i */): %d\n", brz);
   fclose(fp);
  system("pause");
  return 0;
}

int br_cikli(FILE *fp, int *pbrf, int *pbrw, int *pbrd)
{
  unsigned int i=0;
  char ch[100];

   while(!feof(fp))
   {
		
		fgets(ch, 100, fp);
		for(i=0; i<=strlen(ch); i++)//proverka na vseki element na ch s uvelichavane na i
			{
				if(ch[i]=='f'&&ch[i+1]=='o'&&ch[i+2]=='r'&&ch[i+3]=='(') (*pbrf)++;

				if(ch[i]=='w'&&ch[i+1]=='h'&&ch[i+2]=='i'&&ch[i+3]=='l'&&ch[i+4]=='e'&&ch[i+5]=='(') (*pbrw)++;

				if(ch[i]=='d'&&ch[i+1]=='o'&&ch[i+2]=='{' || ch[i]=='d'&&ch[i+1]=='o'&&ch[i+2]=='\n')
					{
						(*pbrd)++;
						(*pbrw)--;//trqbva da se namali broqt na while, zashtoto sled do sledva while
					}
		
			}
   }
   return 0;
}

int br_znacheshti(FILE *fp, int *pbrz)
{
	int j=1;

	unsigned int i=0, k=0, p=0;
	char vr[100];
	char ch[100];

   while(!feof(fp))
   {
		
		fgets(ch, 100, fp);
		for(i=0; i<=strlen(ch); i++)//proverka za komentar v ch s uvelichavane na i
			{
				if(ch[i]=='/'&&ch[i+1]=='*')
					{
						while(ch[i+2]!='*'&&ch[i+3]!='/')//prehvurlqme samo komentara vuv vr
						{
							vr[i]=ch[i];
						}
						p=strlen(vr);
					 for(k=0; k<=p; k++)
						{
							if(vr[k]=='\n'||vr[k]=='\t'||vr[k]==' ')//proverqvame za neznacheshti simvoli
								p--;
						}
					}
		
			}
   }
   *pbrz=p;
   printf("%s\n", vr);
   return 0;
}