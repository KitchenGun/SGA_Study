using System;
using System.Collections.Generic;
using System.Text;

namespace Programmers.notNumPlus
{
    public class notNumPlus
    {
        public int solution(int[] numbers)
        {
            int answer = 0;
            int[] arr = new int[10];

            foreach(int temp in numbers)
            {
                arr[temp]++;
            }


            for (int i =0;i<10;i++)
            {
                if(arr[i]==0)
                {
                    answer += i;
                }
            }

            return answer;
        }
    }
}
