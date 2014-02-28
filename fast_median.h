#ifndef _FAST_MEDIAN_
#define _FAST_MEDIAN_


#include<cstdio>
#include<cstdlib>
#include<ctime>

void rswap(double& a, double& b){
	double tmp = a;
	a = b;
	b = tmp;
}

int sample(const int& begin,const int& end){
	if(begin>end){
		perror("error when the begin greater than end!\n");
		exit(2);
	}
	if(begin==end) return begin;
	int len = end-begin+1;
	//srand((unsigned)(time(NULL)+begin+end));
	int rand_index = rand() % len + begin;
	//int rand_index=(end-begin+1)%2==0? (begin+end-1)/2:(begin+end)/2;
	return rand_index;
}

int partition(double* sort_array,const int& begin, const int& end){
	double x = sort_array[end];
	int i = begin-1;
	for(int j=begin;j<end;j++){
		if(sort_array[j]<=x){
			i++;
			rswap(sort_array[i],sort_array[j]);
		}
	}
	rswap(sort_array[i+1],sort_array[end]);
	return i+1;
}

int  random_partition(double* sort_array, const int& begin, const int& end){
	int s = sample(begin,end);
	rswap(sort_array[end],sort_array[s]);
	return partition(sort_array,begin,end);
}

double random_select(double* sort_array, const int& begin, const int& end,const int& i){
	if(begin==end){
		return sort_array[begin];
	}
	int q = random_partition(sort_array,begin,end);
	int k = q-begin+1;

	if(i==k){
		return sort_array[q];
	}
	else if(i<k){
		return random_select(sort_array,begin,q-1,i);
	}
	else return random_select(sort_array,q+1,end,i-k);
}

double fast_median(double* sort_array,const int& array_len){
	if(array_len==0){
		perror("array length is invalid!\n");
		exit(2);
	}
	if(array_len==1){
		return sort_array[0];
	}
	srand(time(NULL));
	if(array_len%2==0){
		return random_select(sort_array,0,array_len-1,array_len/2);
	}
	else{
		return random_select(sort_array,0,array_len-1,(array_len+1)/2);
	}
}

#endif
