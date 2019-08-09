//Algo Lab, Q3

//By - Teja Juluru

//Solve the partition technique using brute force.
//Partition problem is finding two disjoint sets where 
//sum of elements in first is equal to second.
//Solve by generating power sets.
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

typedef struct{
	int set_size;
	int ele[128];
}set;


//generate the power set
set* power_set_generator(set s,unsigned long int* power_set_size) {
	*power_set_size = pow(2,s.set_size);
	set* power_set = (set*)malloc((*power_set_size)*sizeof(set));

	for(unsigned long int i = 0;i < *power_set_size;i++) {
		power_set[i].set_size = 0;
		for(int j = 0;j < s.set_size;j++) {
			if(i & (1<<j)) {
				power_set[i].ele[power_set[i].set_size] = s.ele[j];
				power_set[i].set_size += 1;
			}
		}
	}
	return power_set;
}

//return the sum of elements of the set
int sum_of_ele(set set_x) {
	int sum = 0;
	for(int i = 0;i < set_x.set_size;i++)
		sum += set_x.ele[i];
	return sum;
}

//print the set
void print_set(set set_x) {
	printf("{");
	for(int i = 0;i < set_x.set_size;i++)
		printf("%d ",set_x.ele[i]);
	printf("}\n");
}

//return 1 if disjoint, else return 0
int check_disjoint(set set_x,set set_y){
	for(int i = 0;i < set_x.set_size;i++) {
		for(int j = 0;j < set_y.set_size;j++) {
			if(set_x.ele[i] == set_y.ele[j])
				return 0;
		}
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	set set_a;
	
	printf("Enter the number of elements is set A : ");
	scanf("%d",&(set_a.set_size));
	printf("Enter the elements of set A : \n");
	for(int i = 0;i < set_a.set_size;i++) {
		scanf("%d",&(set_a.ele[i]));
	}

	//Generate power set of set A
	unsigned long int power_set_size_a = 0;
	set* power_set_a = power_set_generator(set_a,&power_set_size_a);
	
	//Debug
	// for(int i = 0;i < power_set_size_a;i++) {
	// 	print_set(power_set_a[i]);
	// }
	
	//Print all disjoint subsets who satisfy the partition problem
	printf("All the disjoint subsets of set A which satisfy the partition problem : \n");
	for(unsigned long int i = 0;i < power_set_size_a;i++) {
		int set_sum = sum_of_ele(power_set_a[i]);
		unsigned long int j;
		int flag = 0;

		for(j = i+1;j < power_set_size_a;j++) {
			
			//check the next set if the two are not disjoint
			if(!check_disjoint(power_set_a[i],power_set_a[j]))
				continue;

			//if the two sets satisfy the conditions, break
			if(set_sum == sum_of_ele(power_set_a[j])) {
				flag = 1;
				break;
			}
		}
		if(flag == 0)
			continue;

		//print the sets which satisfy the partition porblem
		print_set(power_set_a[i]);
		print_set(power_set_a[j]);
		printf("\n");
	}

	return 0;
}