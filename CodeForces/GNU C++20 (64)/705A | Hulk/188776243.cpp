#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<n;i++)
        {
            if(i%2==1)
                printf("I hate that ");
            else printf("I love that ");
        }
        if(n%2==0) printf("I love it\n");
        else printf("I hate it\n");
    }
    return 0;
}