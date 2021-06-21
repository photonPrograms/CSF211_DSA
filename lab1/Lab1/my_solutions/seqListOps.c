/***********file:   Ops.c *********/
#include <stdio.h>

#include "storage.h"
#include "compare.h"
int nextfreeloc = 0;
Store st;

SeqList createlist()
{
 SeqList sl;
 sl.head = nextfreeloc++;
 sl.size = 0;
 st[sl.head].next = -1;
 return (sl);
}

void printJob (Job j)
{
printf ("JOB ID = %d, Priority = %d, Arr time = %d, Arrival time = %d \n",j.id,j.pri,j.et,j.at);
}


int inputJobs (JobList list)
{
 int i; int size;

 printf("\n Enter the Number of Jobs :");
 scanf("%d", &size);

 for (i=0;i<size;i++)
 {
  printf ("\nEnter job ID");
  scanf ("%d",&list[i].id);
  printf ("Enter Priority (from 0 - 2)");
  scanf ("%d",&list[i].pri);
  printf ("Execution Time");
  scanf ("%d",&list[i].et);
  printf ("Arrival Time");
  scanf ("%d",&list[i].at);
 }
 return size;
}

SeqList insert(Job j, SeqList sl) {
	// taking care of empty SeqList case
	if (sl.size == 0) {
		st[sl.head].ele = j;
		st[sl.head].next = -1;
		sl.size++;
		return sl;
	}
	
	int i = sl.head;

	// inserting the elements in the correct order
	// for non-empty lists
	for (int k = 0; k < sl.size; k++) {
		if (compare(j, st[i].ele) != GREATER) {
			Job temp = st[i].ele;
			st[i].ele = j;
			j = temp;
		}
		if (st[i].next >= 0)
			i = st[i].next;
	}

	// updating the end of the SeqList
	sl.size++;
	st[i].next = nextfreeloc;

	// occupying and updating the next free location
	st[nextfreeloc].ele = j;
	st[nextfreeloc].next = -1;
	nextfreeloc++;

	return sl;
}
  
void insertelements (JobList list, int size, SeqList s[3]) {
	/*
	// traversing the joblist once only
	for (int i = 0; i < size; i++)
		s[list[i].pri] = insert(list[i], s[list[i].pri]);
	*/

	// modified to traverse the joblist thrice
	for (int j = 2; j >= 0; j--)
		for (int i = 0; i < size; i++)
			if (list[i].pri == j)
				s[j] = insert(list[i], s[j]);
}

// I have changed the parameter name from JobList ele to JobList list
// to make the parameter name consistent with its meaning.
void copy_sorted_ele(SeqList s[3] , JobList list) {
	int j = 0;
	for (int i = 2; i >= 0; i--) {
		int curr = s[i].head;
		for (int k = 0; k < s[i].size; k++) {
			list[j++] = st[curr].ele;
			curr = st[curr].next;
		}
	}
}

void printlist(SeqList sl) {
	int i = sl.head;
	for (int k = 0; k < sl.size; k++) {
		printJob(st[i].ele);
		i = st[i].next;
	}
}

void printJobList(JobList list, int size) {
	for (int i = 0; i < size; i++)
		printJob(list[i]);
}

void sortJobList(JobList list, int size)
{
 SeqList seq[3];
 seq[0] = createlist();
 seq[1] = createlist();
 seq[2] = createlist();
 insertelements (list, size, seq);

 printf("\n***");
 printlist(seq[0]);   
 printlist(seq[1]);
 printlist(seq[2]);
 printf("***\n");
 copy_sorted_ele (seq , list); 
}
