  #include<stdio.h>


  int main()
  {
    //   一、每个字母只出现一次，且只含小写字母
        //   =================哈希表=================
        // char A[] = "decimal";
        // char B[] = "medical";
        // int i, H[26] = {0};

        // for (i = 0; A[i] != '\0'; i++)
        // {
        //     H[A[i] - 97]++;
        // }

        // for (i = 0; B[i] != '\0'; i++)
        // {
        //     H[B[i] - 97]--;
        //     if(H[B[i] - 97] < 0)
        //     {
        //         printf("not anagram");
        //         break;
        //     }
        // }

        // if(B[i] == '\0')
        // {
        //     printf("it is anagram");
        // }
        //   =================位运算=================
        char A[] = "medical";
        char B[] = "decimal";
        int i, H = 0, x = 0;
        for (i = 0; A[i] != '\0'; i++)
        {
            x = 1 << (A[i] - 97);
            H |= x;
        }

        for (i = 0; B[i] != '\0'; i++)
        {
            if(((1 << (B[i] - 97)) & H) == 0)
            {
                printf("not anagram");
                break;
            }
        }

        if(B[i] == '\0')
        {
            printf("it is anagram");
        }

        return 0;
  }