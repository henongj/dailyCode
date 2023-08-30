using System;
using System.Collections.Generic;

namespace acmicpc_9086
{
    class Problem_9086
    {
        public void Solution()
        {
            List<string> strings = new List<string>();

            strings.Capacity = 1000;

            DataInput(strings);

            int count = strings.Count;

            for (int i = 0; i < strings.Count; i++)
            {
                char first = strings[i][0];
                char last = strings[i][strings[i].Length - 1];

                Console.WriteLine(first.ToString() + last.ToString());
            }

        }
        public void DataInput(List<string> inputList)
        {
            int inputCount = 0;
            string? input = "";
            input = Console.ReadLine();

            inputCount = Convert.ToInt32(input);

            for (int i = 0; i < inputCount; i++)
            {
                string? str = Console.ReadLine();

                if(str != null)
                {
                    inputList.Add(str);
                }
            }

        }
    }
}