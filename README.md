# sysc-4001-assignment-1

## Usage


## Discussion 

Sample output from madatory test:
```
Memory attached at 4D7000
Matrix m:
1	2	3	4	
5	6	7	8	
4	3	2	1	
8	7	6	5	
Matrix n:
1	3	5	7	
2	4	6	8	
7	3	5	7	
8	6	4	2	
Enter the number of child processes to fork: 1
Child Process: working with row(s): 1 to 4
Elapsed Time: for child process working with rows(s): 1 to 4: 18 mirco sec
58	44	48	52	
130	108	128	148	
32	36	52	68	
104	100	132	164	
```
```
Memory attached at 4D7000
Matrix m:
1	2	3	4	
5	6	7	8	
4	3	2	1	
8	7	6	5	
Matrix n:
1	3	5	7	
2	4	6	8	
7	3	5	7	
8	6	4	2	
Enter the number of child processes to fork: 2
Child Process: working with row(s): 1 to 2
Elapsed Time: for child process working with rows(s): 1 to 2: 19 mirco sec
Child Process: working with row(s): 3 to 4
Elapsed Time: for child process working with rows(s): 3 to 4: 11 mirco sec
58	44	48	52	
130	108	128	148	
32	36	52	68	
104	100	132	164	
```
```
Memory attached at 4D8000
Matrix m:
1	2	3	4	
5	6	7	8	
4	3	2	1	
8	7	6	5	
Matrix n:
1	3	5	7	
2	4	6	8	
7	3	5	7	
8	6	4	2	
Enter the number of child processes to fork: 4
Child Process: working with row(s): 1 to 1
Child Process: working with row(s): 2 to 2
Elapsed Time: for child process working with rows(s): 1 to 1: 25 mirco sec
Elapsed Time: for child process working with rows(s): 2 to 2: 11 mirco sec
Child Process: working with row(s): 3 to 3
Elapsed Time: for child process working with rows(s): 3 to 3: 14 mirco sec
Child Process: working with row(s): 4 to 4
Elapsed Time: for child process working with rows(s): 4 to 4: 11 mirco sec
58	44	48	52	
130	108	128	148	
32	36	52	68	
104	100	132	164	
```
