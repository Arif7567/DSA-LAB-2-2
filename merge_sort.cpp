 #include<iostream>
 using namespace std;
 void mergeArray(int ara[],int left,int mid,int right)
 {
     int n1=mid-left+1;
     int n2=right-mid;
     int ara1[n1],ara2[n2];
     for(int i=0;i<n1;i++)//copy
     {
         ara1[i]=ara[left+i];
     }
     for(int i=0;i<n2;i++)
     {
         ara2[i]=ara[mid+i+1];
     }
     int i=0,j=0,k=left;
     while(i<n1 && j<n2)
     {
        {

        if(ara1[i]<ara2[j])
           {

            ara[k]=ara1[i];
            i++;}
            else
            {
                ara[k]=ara2[j];
                j++;

            }
            k++;
        }


     }
     while(i<n1)
     {
         ara[k]=ara1[i];
         i++;
         k++;
     }
     while(j<n2)
     {
         ara[k]=ara2[j];
         j++;
         k++;
     }
 }
 void divideArray(int ara[],int left,int right)
 {
     if(left>=right)
     {
         return ;
     }
     int mid=left+(right-left)/2;


     divideArray(ara,left,mid);
     divideArray(ara,mid+1,right);
     mergeArray(ara,left,mid,right);
 }
 int main()
 {
     int len;
     cout<<"Enter the length of the array :";
     cin>>len;

        int ara[len];
        cout<<"Enter the elements of the array :";
        for(int i=0;i<len;i++)
        {
            cin>>ara[i];
        }
     divideArray(ara,0,len-1);
     cout<<"Sorted array is :"<<endl;
     for(int i=0;i<len;i++)
     {
         cout<<ara[i]<<" ";
     }
     return 0;
 }
