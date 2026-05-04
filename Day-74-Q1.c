//Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.
/*
Input Format
First line contains an integer n representing number of votes.
Second line contains n space-separated strings representing candidate names.

Output Format
Print the name of the winning candidate followed by the number of votes received.

Sample Input
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

Sample Output
john 4

Explanation
Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.
*/
#include <stdio.h>
#include <string.h>

int main()
{
    int n, i, j, maxVotes = 0;
    char names[100][50];
    int count[100] = {0};

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%s", names[i]);

    // Count votes
    for (i = 0; i < n; i++)
    {
        count[i] = 1;
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(names[i], names[j]) == 0)
            {
                count[i]++;
            }
        }
    }

    // Find winner
    char winner[50];
    for (i = 0; i < n; i++)
    {
        if (count[i] > maxVotes)
        {
            maxVotes = count[i];
            strcpy(winner, names[i]);
        }
        else if (count[i] == maxVotes)
        {
            if (strcmp(names[i], winner) < 0)
            {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("%s %d", winner, maxVotes);

    return 0;
}