Main Objective: To apply data sorting algorithms for statistical analysis of data series. Specific objectives include finding minimum and maximum values, calculating median, quartiles, and deciles, identifying most frequent and distinct values, and comparing algorithm efficiency.

Programming:
The program is made in C using standard libraries like stdio.h, stdlib.h, math.h, and time.h. Only the clock() function is recommended for time measurement.

Data Files:
	The files behave on the following manner:
		A: Scientific Notation (example 123123123e7)
		B: Floating Points (example 2.4)
		C: Scientific Notation (example 123123e+4)

Functions:

	read(): Reads file and stores data in a list_type.
	menu(): Creates an options menu.
	show(): Displays elements of a list_type.
	destroy_list_type(): Frees memory for list_type.

	Sorting Algorithms:

		mergesort(): Splits and sorts list using Merge Sort.
		merge(): Divides and orders the list.
		quicksort(): Sorts list using Quick Sort.
		partition(): Partitions the list for Quick Sort.
		swap(): Swaps data positions.

	AVL Tree Functions:

		altitude(): Gets tree height.
		AVL_tree(): Initializes struct elements.
		insert_AVL(): Inserts elements into AVL tree.
		inorder_AVL(): Inorder tree traversal.
		rotation_left(): Performs left rotation.
		rotation_right(): Performs right rotation.
		max(): Finds max between a & b.
		creates_AVL(): Populates AVL tree from list_type.
		deletes_AVL(): Deletes AVL tree.

	Heap Tree Functions:

		heapsort(): Performs Heap Sort.
		create_heap(): Creates heap from list_type.
		show_heap(): Displays heap elements.
		destroy_heap(): Destroys heap.

	Time-Memory:

		create_counting(): Initializes counting sort array.
		counting_sort(): Performs counting sort.
		counting_show(): Displays sorted array.
	
	Statistical Analysis:

		analysis_list_type(): Analyses list_type data.
		analysis_heap(): Analyses heap data.
		distinct_values_l(): Finds distinct values in list_type.
		distinct_values_m(): Finds distinct values in heap.
		most_repeated_l(): Finds most repeated value in list_type.
		most_repeated_m(): Finds most repeated value in heap.

Details:

	File Handling:

		Uses lista struct to read file.
		Struct has double *numero and long largo.
		User inputs file name; program checks if file exists and reads its length.

	Program Usage:

		Prompts for file name.
		Main menu offers sorting methods and statistical analysis.
		AVL sorting doesn't include analysis.
		Results not immediately displayed due to large datasets.

	Sorting Methods:

		Mergesort: Splits lists, compares, merges.
		Quicksort: Uses pivot, sorts using swap().
		Montículo (Heap): Built from file list, sorts numbers, moves largest to top.

	AVL Tree:

		Uses AVL struct.
		Inserts one by one, compares height, performs rotations.
		Duplicate numbers are not inserted.

	Counting Sort:

		Uses auxiliary array to count occurrences.
		Sorts based on count.
		
	Time Measurement:

		Uses time.h and clock() for measuring time.
		Time is in milliseconds for precision.
		Time recorded before displaying results to avoid skew.