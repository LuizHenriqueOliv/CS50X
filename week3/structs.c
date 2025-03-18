#include <cs50.h>
#include <stdio.h>

typedef struct
{
    string name;
    int votes;
} candidate;

int main(void)
{
    // define o número de candidatos
    const int n = 3;
    candidate candidates[n];

    for (int i = 0; i < n; i++)
    {
        candidates[i].name = get_string("Candidate: ");
        candidates[i].votes = get_int("Votes: ");
    }

    int highest_vote = 0;

    for (int i = 0; i < n; i++)
    {
        if (candidates[i].votes > highest_vote)
        {
            highest_vote = candidates[i].votes;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (candidates[i].votes == highest_vote)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}
