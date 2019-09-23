#include<iostream>
#include<algorithm>
#include<climits>
#include<math.h>



using namespace std;

void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

int partition(int arr[], int l, int r, int x) 
{ 
    int i; 
    for (i=l; i<r; i++) 
        if (arr[i] == x) 
           break; 
    swap(&arr[i], &arr[r]); 
  
    i = l; 
    for (int j = l; j <= r - 1; j++) 
    { 
        if (arr[j] <= x) 
        { 
            swap(&arr[i], &arr[j]); 
            i++; 
        } 
    } 
    swap(&arr[i], &arr[r]); 
    return i; 
} 

int findMedian(int arr[], int n) 
{ 
    sort(arr, arr+n);  
    return arr[n/2];    
} 

int mdn(int ar[], int l, int r, int k)
{
	if(k>0 && k<=r-l+1)
	{
		int n = r-l+1;
		int i, median[(n+4)/5]; 
        for (i=0; i<n/5; i++) 
            median[i] = findMedian(ar+l+i*5, 5); 
        if (i*5 < n) 
        { 
            median[i] = findMedian(ar+l+i*5, n%5);  
            i++; 
        }     
  
        int mfmd = (i == 1)? median[i-1]: mdn(median, 0, i-1, i/2); 
  
        int pos = partition(ar, l, r, mfmd); 
  
        if (pos-l == k-1) 
            return ar[pos]; 
        if (pos-l > k-1) 
            return mdn(ar, l, pos-1, k); 
  
        return mdn(ar, pos+1, r, k-pos+l-1); 
    } 
    return INT_MAX; 
}


int main()
{
	long long quer;
	cin>>quer;
	for (int a= 0; a<quer;a++)
	{
		int test;
		cin>>test;
		int x,y;
		int pts[test];
		for (int b= 0; b<test;b++)
		{
			cin>>x>>y;
			pts[b]=(x*x)+(y*y);
		}
		
		double rad = mdn(pts,0,test-1,(test+1)/2);
		rad = sqrt(rad);
		cout<<rad<<endl;		
	}
	return 0;
}