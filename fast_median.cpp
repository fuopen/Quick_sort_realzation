#include"fast_median.h"

void random_quicksort(double* sort_array,const int& begin,const int& end){
	if(begin>=end){
		return;
	}
	int q = random_partition(sort_array,begin,end);
	random_quicksort(sort_array,begin,q-1);
	random_quicksort(sort_array,q+1,end);
}

int main(int argc,char** argv){
	double test1[20] = {0.1098,0.2342,0.1011,0.1232,0.9321,0.12321,0.1098,0.1222,0.3321,0.4321,0.1102,0.6632,0.3224,0.3532,0.4732,0.2404,0.4523,0.2098,0.2342,0.2249};
	double test2[17] = {0.21,0.12,0.19,0.11,0.01,0.05,0.04,0.09,0.12,0.21,0.11,0.134,0.89,0.124,0.00012,0.09,0.08};
	double db1=fast_median(test1,20);
	double db2=fast_median(test2,17);

	printf("the first test1's median is:%f\n",db1);
	printf("the second test2's median is:%f\n",db2);

	printf("sort test1:\n");
	random_quicksort(test1,0,19);
	for(int k=0;k<20;k++){
		printf("%f ",test1[k]);
	}
	printf("\nsort test2:\n");
	random_quicksort(test2,0,16);
	for(int k=0;k<17;k++){
		printf("%f ",test2[k]);
	}
	printf("\n");
	return 0;
}
