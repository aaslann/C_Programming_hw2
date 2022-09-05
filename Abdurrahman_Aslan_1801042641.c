#include <stdio.h>
void readfile(char * filename); 
int main() {
  readfile("input.txt");
  return 0;
}
void readfile(char * filename) {  //function opening
  FILE * fp, * fp2;
  double n = 0.0, a = 0.0, b = 0.0, temp = 0, count = 0.0;
  const double p1 = 0.5, p2 = 20;
  fp = fopen("input.txt", "r");    //input file opened read mode
  fp2 = fopen("output.txt", "w");  //output file opened write mode
  fscanf(fp, "%lf", & n);
  fprintf(fp2, "%f ", n);
  b = n;
  count++;
  while (!feof(fp)) {        //file reading process
    if (count == 0) {
      a = 0;
      b = n;
      count++;
    }
    fscanf(fp, "%lf", & n); 
    a = b;
    b = ((b * count) + n) / (count + 1);
    if (!(b > a * (1 + p1) || b < a * (1 - p1) || a > n * p2 || a < n / p2)) {  //condition operations
      fprintf(fp2, "%f ", n);
      count++;
    } else {
      fprintf(fp2, "average: %f\n", a);
      fprintf(fp2, "%f ", n);
      a = 0;
      b = 0;
      count = 0;
    }
  }  	
  	// according to the given conditions, the number is read from the file and the average calculations are made.
  fprintf(fp2, "average: %lf\n", b); 
  fclose(fp);   //closing life	
  fclose(fp2);	//closing file
}