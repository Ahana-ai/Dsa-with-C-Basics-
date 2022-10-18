#include<stdio.h>
int main(){
	int n,i,sec_min,min,arr[50];
	printf("enter the number of the element in the array: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("enter %d element: ",i+1);
		scanf("%d",&arr[i]);
}
	min=arr[0];
	sec_min=arr[0];
	for(i=0;i<n;i++){
		if(arr[i]<min){
			min=arr[i];
		}
	}
	
	for(i=0;i<n;i++){
		if(arr[i]<sec_min && arr[i]!=min){
			sec_min=arr[i];
	}}
	printf("The second smallest element is:
     %d",sec_min);
}