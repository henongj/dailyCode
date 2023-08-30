using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace acmicpc1236
{
    //https://www.acmicpc.net/problem/1236
    //성 지키기

    public class problem_1236
    {
        int nRow;
        int nCol;
        List<string> matrix { get; set; } = new List<string>();
        int nGuardNeed = 0;
        //hash table
        Dictionary<int, int> dicNoGuardRow = new Dictionary<int, int>();
        Dictionary<int, int> dicNoGuardCol = new Dictionary<int, int>();

        public void solution_1236()
        {
            inputData();

            nGuardNeed = 0;

            nGuardNeed += dicNoGuardRow.Count;
            nGuardNeed += dicNoGuardCol.Count;

            nGuardNeed -= Math.Min(dicNoGuardRow.Count, dicNoGuardCol.Count);

            Console.WriteLine(nGuardNeed);

        }

        private void inputData()
        {
            string[]? strInput = Console.ReadLine()?.Split(' ');

            if (strInput != null)
            {
                nRow = int.Parse(strInput[0]);
                nCol = int.Parse(strInput[1]);
            }

            for (int i = 0; i < nRow; i++)
            {
                string? strRow = Console.ReadLine();
                if (strRow != null)
                {
                    matrix.Add(strRow);
                }
            }

            // 행에 가드가 없는지 확인
            bool bGuardExist = false;
            for (int i = 0; i < nRow; i++)
            {
                bGuardExist = false;
                for (int j = 0; j < nCol; j++)
                {
                    if (matrix[i][j] == 'X')
                    {
                        bGuardExist = true;
                        break;
                    }
                }

                if (bGuardExist == false)
                {
                    dicNoGuardRow.Add(i, 0);
                }
            }

            // 열에 가드가 없는지 확인
            for (int i = 0; i < nCol; i++)
            {
                bGuardExist = false;
                for (int j = 0; j < nRow; j++)
                {
                    if (matrix[j][i] == 'X')
                    {
                        bGuardExist = true;
                        break;
                    }
                }

                if (bGuardExist == false)
                {
                    dicNoGuardCol.Add(i, 0);
                }
            }


        }

    }
}
