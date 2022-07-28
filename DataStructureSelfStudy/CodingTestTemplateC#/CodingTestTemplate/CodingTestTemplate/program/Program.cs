using System;
using Programmers.notNumPlus;

namespace CodingTestTemplate
{

    class Program
    {
        

        static void Main(string[] args)
        {
            notNumPlus solClass = new notNumPlus();
            int answer = solClass.solution(new int[] {1, 2, 3, 4, 6, 7, 8, 0});

            Console.WriteLine(answer);
        }
    }
}
