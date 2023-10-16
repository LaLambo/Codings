/*
	Compiler: Dev-C++ 5.11
	OS: Windows 10
	AMD Ryzen 5 3500U 2.10GHz
	RAM: 8 GB
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct list_type //Define an struct of type list_type
{
	double *number;	
	long large;
	
}list_type;

struct AVL ///Create the AVL Structure
{
	int altitude; ///Altitude
	double number; ///Numbers value
	struct AVL *left; ///Left tree branch
	struct AVL *right; ///Right tree branch
};

typedef struct heap ///Create the Heap structure
{
	double *number;	
	long large;
	
}heap;


list_type read();///read the file and store its data in a list_type
void menu(list_type A,long large);///Create a Options menu
void show(list_type A, long large);///Displays the elements of the list_type
void destroy_list_type(list_type A);
void mergesort(list_type A, long a, long b);///Perform mergesort, split the list_type into halves
void merge(list_type A, long a, long b, long half);///Divide and order the list_type
void quicksort(list_type A, long a,long b);///Makes a Quicksort
long partition(list_type A,long a,long b);///makes the Partition
void swap(list_type A,long a,long b);///Change the positions of the data to be changed
///AVL Tree 
int altitude(struct AVL *A);///Detects the altitude of the tree
struct AVL* AVL_tree(double a);///Start the STRUCT elements
struct AVL* insert_AVL(struct AVL* Tree, double num);///Insert the elements into the trees
void inorder_AVL(struct AVL *root);///Shows the inorder data
struct AVL *rotation_left(struct AVL *a);///rotation left
struct AVL *rotation_right(struct AVL *a);///rotation right
int max(double a, double b);///Detects the max between a & b
struct AVL *creates_AVL(list_type A,long large);///Returns the elements of the list_type to the tree
void deletes_AVL(struct AVL *root);
///Heap Tree 
void heapsort(heap M);//Realiza heapsort
heap create_heap(list_type A);///Crea el heap
void show_heap(heap M);///Shows the elements
void destroy_heap(heap M);///Destroys the heap
///Time-Memory
double *create_counting(list_type A);///Receive file data
void counting_sort(double **array, long large);///Makes the counting
void counting_show(double *array, long large); ///Shows the elements
///Statistical Analysis
void analysis_list_type(list_type A,long large);///Analysis of the list_types
void analysis_heap(heap M);///Analysis of the montículo
long distinct_values_l(list_type A,long large);///Distinct Values on list_types
long distinct_values_m(heap M);///Distinct Values on heap
double most_repeated_l(list_type A, long large);////Most Repeated on list_types
double most_repeated_m(heap M);///Most Repeated on heap
///Auxiliar Menus
void menu2(list_type A, long large);///Auxiliar Menu
void menu3(heap M);///Auxiliar Menu
void menu4(struct AVL *root);///Auxiliar Menu
void menu5(double *array, long large);///Auxiliar Menu


///Functions
int main()///Main Function
{	
	list_type A = read(); ///Call to function read
	
	return 0;
}

list_type read() ///Called from main
{	
	double num; //stores file data
	char a,name[20],aux[20];
	long large,i,j=0; //large of file
	list_type A;
	FILE *f; ///File f declared
	
	printf(" Enter the file Name: ");
	scanf("%s",name);	///Detects the file name
	f = fopen(name,"r");
	
	if(f == NULL)
	{
		printf("The file couldn't be found");
	}
	
	large=1;
	while((a=fgetc(f)) != EOF) ///Scan through the file to detect its large
	{	if(a == ' ')
		{	large++;
		}
	}
	f = fopen(name,"r");
	
	A.large= large;
	A.number= calloc(large,sizeof(double)); ///It will be the size of the large obtained
	
	if(f == NULL)
	{
		printf("The file couldn't be read");
	}
	i=0;
	while((a=fgetc(f)) != EOF) ///While the file isn't null
	{
		if(a == ' ')
		{	aux[i]='\n';
			num=atof(aux); ///converts the aux from string to float
			A.number[j] = num;
			i=0;
			j++;
		}
		else
		{	aux[i++] = a;
		}
	}
	aux[i]='\n';
	num=atof(aux);
	A.number[j] = num;	
	printf("%ld",large);
	fclose(f); ///Closes the file
	menu(A,large); ///Call to Menu
	return A;
}

void menu(list_type A,long large) ///Shows a menu of options
{	
	int op;
	long *aux;
	double *array;
	heap M; 
	struct AVL *root;
	clock_t start,end;
	double time;
	
	do /// Start of cycle to poright execute the menu
	{
    ///system(" cls");
	printf("\n\n ----Principal Menu-----\n\n"); 
	printf("  | 1.-  Mergesort  |\n\n");
	printf("  | 2.-  Quicksort  |\n\n");
	printf("  | 3.-  heap       |\n\n");
	printf("  | 4.-  AVL        |\n\n");
	printf("  | 5.-  count     |\n\n");
	printf("  | 6.-  Exit       |\n\n");

    printf("Select an option to get started : ");
    scanf( "%d", &op );
       
    switch(op)
    {
		case 1: 
			start=clock();///Start of clock
			aux = (long*) malloc((A.large) *sizeof(A));
			mergesort(A,0,large-1);///Call to function
			end=clock();///End of clock
			time=(((double) (end-start))/CLOCKS_PER_SEC)*1000;
			printf("\nCalculated in %f ms\n",time);
			analysis_list_type(A,large);
			menu2(A,large);
			destroy_list_type(A);
			
			break;
		
		case 2:
			start=clock();///Start of clock
			aux = (long*) malloc((A.large) *sizeof(A));
			quicksort(A,0,large-1);///Call to function
			end=clock();///End of clock
			time=(((double) (end-start))/CLOCKS_PER_SEC)*1000;
			printf("\nCalculated in %f ms\n",time);
			analysis_list_type(A,large);
			menu2(A,large);
			destroy_list_type(A);

			break;
			
		case 3:
			start=clock();///Start of clock
			M=create_heap(A);///Call to function
			end=clock();///End of clock
			time=(((double) (end-start))/CLOCKS_PER_SEC)*1000;
			printf("\nCalculated in %f ms\n",time);
		 	analysis_heap(M);
		 	menu3(M);
		 	destroy_heap(M); ///Destruye el heap
		 	
			break;
				
		case 4:
			start=clock();///Start of clock
			root=creates_AVL(A,large);///Call to function
			end=clock();///End of clock
			time=(((double) (end-start))/CLOCKS_PER_SEC)*1000;
			printf("\nCalculated in %f ms\n",time);
			menu4(root);
			deletes_AVL(root); ///Elimina el AVL
			break;
						
		case 5:
			start=clock();///Start of clock
			array = create_counting(A);///Call to function
			counting_sort(&array,large);
			end=clock();///End of clock
			time=(((double) (end-start))/CLOCKS_PER_SEC)*1000;
			printf("\nCalculated in %f ms\n",time);
			menu5(array,large);
				
		case 6:    /// Exits Program
			exit (1); 
	}
		
	}while(op!=1 && op!=2 && op!=3 && op!=4 && op!=5 && op!=6);
	
}

void show(list_type A, long large)///Shows the elements
{
	long k=0;
	for(k=0;k<large;k++)
	{
		printf("%7.3f",A.number[k]); ///The elements shown will be of this large
	}
}

void destroy_list_type(list_type A)///Destroys the Heap
{
	free(A.number);	
}

void mergesort(list_type A,long a, long b)///Makes the mergesort, separates the list_type on halves
{
	long half = ((a+b+1)/2);
	
	if (a != b)
	{	mergesort(A,a,half-1);
		mergesort(A,half,b);
		merge(A,a,b,half); ///Last Index of the first half
	}
}

void merge(list_type A, long a, long b, long half)///Divide and order list_type
{
	long i=a,j=half,k=0;
	double *C; //otra estructura
	C =calloc(b-a+1,sizeof(double));///C takes the subtraction of the positions as memory space b y a + 1
	while(i<half & j<b+1)///Compare the two halves
	{	
		if(A.number[i]<A.number[j])///If the numbers between the positions of the first half is less than the position of the second
		{
			C[k]=A.number[i];
			i++;
			k++;	
		}  
		else ///In other case
		{
			C[k]=A.number[j];
			j++;
			k++;
		}
	}	
	while(i<half)///As long as all the elements of the first half are not finished
	{
		C[k]=A.number[i];
		i++;
		k++;
	}
	while(j<b+1)///As long as all the elements of the second half are not finished
	{
		C[k]=A.number[j];
		j++;
		k++;
	}
	i=a;
	for(k=0;k<b-a+1;k++)
	{
		A.number[i]= C[k];
		i++;
	}

}

void quicksort(list_type A, long a,long b) ///Makes the Quicksort
{
	long pivot; ///Pivot position
  	
	if(a==b-1) ///Make the value change
		swap(A,a,a+1);
	  
	if(a<b)
  	{	pivot = partition(A,a,b); ///Pivot will be partition
    	quicksort(A,a,pivot-1); ///Recursive Quicksort 
    	quicksort(A,pivot+1,b); ///Recursive Quicksort 
  	}
} 

long partition(list_type A,long a,long b)///Makes the partition
{
	long i,j;
	double pivot;

  	pivot=A.number[a]; ///pivot is the first position
  	i=a+1;
  	j=b;

	while(i<j)
  	{
    	while (A.number[j]>pivot) ///Loops through list_type
		{	j--;
    	}
		while ((i<j)&&(A.number[i]<= pivot)) ///Loops through list_type
		{	i++;
    	}

		if(i<j)
			swap(A,i,j); ///Change positions
	}
	swap(A,i,j); ///Change positions
	swap(A,a,j); ///Change positions

  return j;
}

void swap(list_type A,long a,long b)///Change positions
{
	double valor; //Value to be changed
	valor= A.number[a];
	A.number[a]=A.number[b];
	A.number[b] = valor; ///Final Value	 	
}

///---------------Tree Functions---------------

int altitude(struct AVL *A) ///Returns the altitude
{
	if (A == NULL) // If tree is empty
		return 0;
	return A->altitude;		
}

struct AVL* AVL_tree(double a)///Start the STRUCT elements by giving them values
{
	struct AVL* Tree = (struct AVL*)
    malloc(sizeof(struct AVL)); ///It gives you the size of the AVL
	Tree->number = a; ///The number takes the first value
	Tree->left = NULL; ///lef is NULL
	Tree->right = NULL; ///right is NULL
	Tree->altitude = 1; ///Starts the altitude

	return(Tree);
}

void inorder_AVL(struct AVL *root) //Shows Inorder data
{
    if(root)
    {	inorder_AVL(root->left);
        printf("%7.3f", root->number); ///Shows the number with this large
        inorder_AVL(root->right);
    }
}

struct AVL *rotation_right(struct AVL *a) ///rotation to the right
{
	struct AVL *i = a->left; ///Assigns values to numbers
	struct AVL *j = i->right; ///Assigns values to numbers

	i->right = a;
	a->left = j;
	a->altitude = max(altitude(a->left), altitude(a->right))+1;
	i->altitude = max(altitude(i->left), altitude(i->right))+1;

	return i;
}

struct AVL *rotation_left(struct AVL *a) ///rotation to the left
{
	struct AVL *i = a->right; ///Assigns values to numbers
	struct AVL *j = i->left; ///Assigns values to numbers
  
	i->left = a;
	a->right = j;
	a->altitude = max(altitude(a->left), altitude(a->right))+1;
	i->altitude = max(altitude(i->left), altitude(i->right))+1;

	return i;
}

int balance(struct AVL *A) ///Calculate if the Tree is not balanced
{
	if (A == NULL)
		return 0;
	return altitude(A->left) - altitude(A->right);
}

struct AVL* insert_AVL(struct AVL* Tree, double num) ///Insert the elements into the Trees
{
	int balancing;
	///Casos de AVL
	if (Tree== NULL)
		return(AVL_tree(num));

	if (num < Tree->number) ///If the number is lower than
		Tree->left = insert_AVL(Tree->left, num); ///It is positioned to the left

	else if (num > Tree->number) ///If the number is greater than
		Tree->right = insert_AVL(Tree->right, num); ///It is positioned to the right
	else
		return Tree;
	Tree->altitude = 1 + max(altitude(Tree->left),
	altitude(Tree->right));
	balancing = balance(Tree);

	if (balancing > 1 && num< Tree->left->number) ///Calculate whether a balance is owed to the right
		return rotation_right(Tree);
    
	if (balancing < -1 && num > Tree->right->number) ///Calculate whether a balance is owed to the left
		return rotation_left(Tree);
    
	if (balancing > 1 && num > Tree->left->number) ///Calculate whether a balance is owed to the left - right
	{	Tree->left = rotation_left(Tree->left);
		return rotation_right(Tree);
	}
	if (balancing < -1 && num < Tree->right->number)///Calculate whether a balance is owed to the right - left
	{	Tree->right = rotation_right(Tree->right);
		return rotation_left(Tree);
	}
	return Tree;
} 

int max(double a, double b)///Review max
{
	return (a > b)? a : b;
}

struct AVL *creates_AVL(list_type A, long large) ///Transfer the elements from list_type to Tree
{
	struct AVL *root = NULL;
	long i=0;
	
	while(i<large)
	{	root=insert_AVL(root,A.number[i]); ///Transfer of elements
		i++;
	}
	
	return root;
}

void deletes_AVL(struct AVL *root) ///Deletes AVL
{
    if(root)
    {	deletes_AVL(root->left);
        deletes_AVL(root->right);
		free(root);
    }
}

void heapsort(heap M) ///Makes the heapsort
{
    if(M.large==0) ///Verify if the heap is empty
      return;

    double t; ///Temporary Variable
    long  i = M.large, father = i/2, j, son; ///Variables declared
    
    while (1) { ///Until it is ordered
        if (father > 0) 	///Orders
		{ 
            t = M.number[--father];  
        }
		else 
		{  
            i--;               
            if (i == 0) 
			{
                return; ///Return if the heap is empty
            }
            t = M.number[i];       ///Save it in the temporary variable
            M.number[i] = M.number[0];    ///Save the other numbers
        }
        
        j = father; ///father starts in j
        son = j * 2 + 1; ///The son is positioned to the left
        while (son < i) 
		{    
            if (son + 1 < i  &&  M.number[son + 1] > M.number[son]) 
			{
                son++; ///The son of the right exists and is the greater
            }
            if (M.number[son] > t) 
			{
                M.number[j] = M.number[son];
                j = son; 
                son = j * 2 + 1; ///Receive the son of the left
            } 
			else 
			{
                break; 
            }
        }
        
        M.number[j] = t; ///Returns heap
    }
}

heap create_heap(list_type A)///Create the heap
{
	heap M; ///Crea heap M
	M.number= calloc(A.large,sizeof(double)); ///Define the memory space
	M.large=A.large;
	long i=0;
	
	while(i<A.large)
	{	M.number[i]= A.number[i]; ///Transfer of elements
		i++;
	}
	
	heapsort(M);
	return M;
}

void show_heap(heap M) ///Show the elements
{
	long k=0;
	
	for(k=0;k<M.large;k++)
	{
		printf("%7.3f",M.number[k]); ///The elements shown will be of this large
	}	
}

void destroy_heap(heap M)///Destroys the heap
{
	free(M.number);	
}

double *create_counting(list_type A)///Receive file data
{
	double *array;
	array= (double*) calloc(A.large,sizeof(double));
	long i=0;
	
	while(i<A.large)
	{	array[i]= A.number[i]; ///Transfer of elements
		i++;
	}
	
	return array;

}

void counting_sort(double **A, long large)///Makes the counting
{
	int *count = (int *) calloc(large,sizeof (int ));
	double *b = (double *) calloc(large, sizeof (double));
	int i,j;
	for(i=0;i<large;i++)
	{
		for(j=i+1;j<large;j++)
		{
			if((*A)[i]>=(*A)[j])
			{
				count[i]++;
			}
			else
			{
				count[j]++;
			}
		}
	}
	for(i=0;i<large;i++)
	{
		b[count[i]] = (*A)[i];
	}
	free(count);
	free(*A);
	*A=b;
}

void counting_show(double *array, long large) ///Shows the elements
{
	long k=0;
	
	for(k=0;k<large;k++)
	{
		printf("%7.3lf",array[k]); ///The elements shown will be of this large
	}	
}	
	
void analysis_list_type(list_type A,long large)///Perform basic statistics analysis on list_types
{
	
	long median= (large-1)/2 , quartile= (large-3)/4;
	 
	printf("\n\nMinor Data: %.2lf\n",A.number[0]);
	printf("Major Data: %.2lf\n",A.number[large-1]);

	printf("Median: %.2lf\n",A.number[median]);   
    
	////quartiles///
 	
 	printf("First quartile : %.2lf\n",A.number[quartile]);	
 	printf("Second quartile : %.2lf\n",A.number[median]);
 	printf("Third quartile : %.2lf\n",A.number[(3*quartile)+2]);
 	printf("Fourth quartile : %.2lf\n",A.number[large-1]);
 	
    printf("Amount of different data: %d\n",distinct_values_l(A,large));
    printf("Most repeated data: %.2lf\n",most_repeated_l(A,large));
}
	
void analysis_heap(heap M)///Heap Analysis
{
	long median= (M.large-1)/2 , quartile= (M.large-3)/4;
	 
	printf("\n\nMinor Data: %.2lf\n",M.number[0]);
	printf("Major Data: %.2lf\n",M.number[M.large-1]);

	printf("Median: %.2lf\n",M.number[median]);   
    
	////quartiles///
 	
 	printf("First quartile : %.2lf\n",M.number[quartile]);	
 	printf("Second quartile : %.2lf\n",M.number[median]);
 	printf("Third quartile : %.2lf\n",M.number[(3*quartile)+2]);
 	printf("Fourth quartile : %.2lf\n",M.number[M.large-1]);
 	
	printf("Amount of different data: %d\n",distinct_values_m(M));
    printf("Most repeated data: %.2lf\n",most_repeated_m(M));
}
	
long distinct_values_l(list_type A,long large)///Find the distinct values in list_types
{
    long distincts=1,i;
    double aux=A.number[0];
    for(i=1;i<large;i++)
    {
        if(aux!=A.number[i])
        {
            aux=A.number[i];
            distincts++;
        }
    }
    return distincts;
}	
	
long distinct_values_m(heap M)///Distinct Values in heap
{
    long distincts=1,i;
    double aux=M.number[0];
    for(i=1;i<M.large;i++)
    {
        if(aux!=M.number[i])
        {
            aux=M.number[i];
            distincts++;
        }
    }
    return distincts;
}		
	
double most_repeated_l(list_type A, long large)///Most repeated in list_types
{
	long cont1=1,cont2=0,i;
    double num[1],auxiliar=A.number[0];
    num[0]=auxiliar;
    num[1]=cont1;
    for (i=1;i<large;i++)
    {
        if(A.number[i]==auxiliar)
        {	cont1++;
			if(cont1>=cont2)
				num[0]= auxiliar;
		}	 
        if(cont2==0)
        {	cont2=cont1;
        	cont1=1;
		}
		else
		{
			if(cont2<cont1)
			{	cont2=cont1;
				cont1=1;
			}
			else
				cont1=1;
		auxiliar=A.number[i];
		}
	}		

    return num[0];
}
	
double most_repeated_m(heap M)///Most repeated in heap
{
	long cont1=1,cont2=0,i;
    double num[1],auxiliar=M.number[0];
    num[0]=auxiliar;
    num[1]=cont1;
    for (i=1;i<M.large;i++)
    {
        if(M.number[i]==auxiliar)
        {	cont1++;
			if(cont1>=cont2)
				num[0]= auxiliar;
		}	 
        if(cont2==0)
        {	cont2=cont1;
        	cont1=1;
		}
		else
		{
			if(cont2<cont1)
			{	cont2=cont1;
				cont1=1;
			}
			else
				cont1=1;
		auxiliar=M.number[i];
		}
	}		

    return num[0];
}	
	
void menu2(list_type A, long large)///Auxiliar Menu
{
	int op;

	do /// Cycle start for run menu
	{
    ///system(" cls");
	printf(" Do you wish to see your data?\n\n");  
	printf(" 1.- Yes \n\n");
	printf(" 2.- No \n\n");
	printf("Enter Option: ");
    scanf( "%d", &op );
	
	switch(op)
    {
		case 1:
			show(A,large);	
		
		case 2:
			exit (1); 
	}
	}while(op!=1 && op!=2);
}	

void menu3(heap M)///Auxiliar Menu
{
	int op;

	do /// Cycle start for run menu
	{
    ///system(" cls");
	printf(" Do you wish to see your data?\n\n");  
	printf(" 1.- Yes \n\n");
	printf(" 2.- No \n\n");
	printf("Enter Option: ");
    scanf( "%d", &op );
	
	switch(op)
    {
		case 1:
			show_heap(M);	
		
		case 2:
			exit (1); 
	}
	}while(op!=1 && op!=2);
}

void menu4(struct AVL *root)///Auxiliar Menu
{
	int op;

	do /// Cycle start for run menu
	{
    ///system(" cls");
	printf(" Do you wish to see your data?\n\n");  
	printf(" 1.- Yes \n\n");
	printf(" 2.- No \n\n");
	printf("Enter Option: ");
    scanf( "%d", &op );
	
	switch(op)
    {
		case 1:
			inorder_AVL(root);	
		
		case 2:
			exit (1); 
	}
	}while(op!=1 && op!=2);
}

void menu5(double *array, long large)///Auxiliar Menu
{
	int op;

	do /// Cycle start for run menu
	{
    ///system(" cls");
	printf(" Do you wish to see your data?\n\n");  
	printf(" 1.- Yes \n\n");
	printf(" 2.- No \n\n");
	printf("Enter Option: ");
    scanf( "%d", &op );
	
	switch(op)
    {
		case 1:
			counting_show(array, large);	
		
		case 2:
			exit (1); 
	}
	}while(op!=1 && op!=2);
}

