#include <bits/stdc++.h>
using namespace std;

void matrix_transpose()
{
    int n;
    cin>>n;

    int arr[n][n];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>arr[i][j];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<"\t";
        cout<<endl;
    }

    int transpose[n][n];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            transpose[i][j] = arr[j][i];

    cout<<"\nTranspose\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<transpose[i][j]<<"\t";
        cout<<endl;
    }

}

void swap(int *a, int*b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void matrix_transpose_square_optimised()
{
    int n;
    cin>>n;

    int arr[n][n];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>arr[i][j];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<"\t";
        cout<<endl;
    }

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
            swap(&arr[i][j], &arr[j][i]);
    }

    cout<<"\nTranspose\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<"\t";
        cout<<endl;
    }
}

void matrix_multiplication()
{
    int row1,col1;
    cin>>row1>>col1;

    int arr1[row1][col1];

    for(int i=0;i<row1;i++)
        for(int j=0;j<col1;j++)
            cin>>arr1[i][j];

    int row2,col2;
    cin>>row2>>col2;
    int arr2[row2][col2];

    for(int i=0;i<row2;i++)
        for(int j=0;j<col2;j++)
            cin>>arr2[i][j];

    cout<<"\nA\n";
    for(int i=0;i<row1;i++)
    {  
        for(int j=0;j<col1;j++)
            cout<<arr1[i][j]<<"\t";
        cout<<endl;
    }

    cout<<"\nB\n";
    for(int i=0;i<row2;i++)
    {  
        for(int j=0;j<col2;j++)
            cout<<arr2[i][j]<<"\t";
        cout<<endl;
    }

    if(col1 != row2)
        cout<<"\nMultiplication Not Possible";
    else
    {
        int ans[row1][col2];

        for(int i=0;i<row1;i++)
        {
            for(int j=0;j<col2;j++)
            {
                ans[i][j] = 0;
                for(int k =0;k<col1;k++)
                    ans[i][j] = ans[i][j] + arr1[i][k]*arr2[k][j];
            }

        }

        cout<<"\nC = A*B\n";
        for(int i=0;i<row1;i++)
        {  
            for(int j=0;j<col2;j++)
                cout<<ans[i][j]<<"\t";
            cout<<endl;
        }
    }
    
}

void matrix_search_optimised()
{
    int n,m;
    cin>>n>>m;

    int arr[n][m];

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];

    int value;
    cin>>value;

    int i = 0;
    int j=m-1;

    int found = 0;

    while(i>=0 && j>= 0 && i<n && j<m)
    {
       if(arr[i][j] == value)
        {      
            found = 1;
            break;
        }
        
        if(arr[i][j] > value)
            j--;
        else
            i++;
    }

    if(found == 0)
        cout<<value<<" is not present\n";
    else 
        cout<<value<<" is present\n";
}
int main()
{
    matrix_search_optimised();
    return 0;
}