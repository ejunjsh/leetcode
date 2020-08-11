# Find Cumulative Salary of an Employee

The Employee table holds the salary information in a year.

Write a SQL to get the cumulative sum of an employee's salary over a period of 3 months but exclude the most recent month.

The result should be displayed by 'Id' ascending, and then by 'Month' descending.

Example

Input

    | Id | Month | Salary |
    |----|-------|--------|
    | 1  | 1     | 20     |
    | 2  | 1     | 20     |
    | 1  | 2     | 30     |
    | 2  | 2     | 30     |
    | 3  | 2     | 40     |
    | 1  | 3     | 40     |
    | 3  | 3     | 60     |
    | 1  | 4     | 60     |
    | 3  | 4     | 70     |

Output

    | Id | Month | Salary |
    |----|-------|--------|
    | 1  | 3     | 90     |
    | 1  | 2     | 50     |
    | 1  | 1     | 20     |
    | 2  | 1     | 20     |
    | 3  | 3     | 100    |
    | 3  | 2     | 40     |
 