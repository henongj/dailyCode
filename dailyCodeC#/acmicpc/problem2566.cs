using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace problem_2566
{
    //https://www.acmicpc.net/problem/2566
    //최댓값
    class solution_2566
    {
        int[,] DataMatrix = new int[9, 9];
        int max = 0;
        int MaxPositionX = 0;
        int MaxPositionY = 0;

        public void Solution()
        {
            string? Input = "";

            for (int i = 0; i < 9; i++)
            {
                Input = Console.ReadLine();
                string[] InputArray = new string[9];
                if (Input != null)
                {
                     InputArray = Input.Split(' ');
                }

                for (int j = 0; j < 9; j++)
                {
                    DataMatrix[i, j] = int.Parse(InputArray[j]);

                    if (max < DataMatrix[i, j])
                    {
                        max = DataMatrix[i, j];
                        MaxPositionX = i;
                        MaxPositionY = j;
                    }
                }
            }

            Console.WriteLine(max);
            Console.WriteLine("{0} {1}", MaxPositionX + 1, MaxPositionY + 1);
        }
    }
}

