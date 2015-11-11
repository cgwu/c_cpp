using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NumCounter
{
    class Program
    {
        /// <summary>
        /// 求万位数字不是5且各位数字互异的5位数的个数
        /// 符合条件的数字个数为:24192
        /// </summary>
        /// <param name="num"></param>
        /// <returns></returns>
        static bool IsGoodNum(int num)
        {
            string sNum = num.ToString();
            if (sNum.Length != 5) return false;
            var narr = sNum.ToCharArray();
            if (narr[0] == '0' || narr[0] == '5') return false;
            var q = from n in sNum
                    group n by n into g
                    select g.Key;
            return q.Count() == 5;
        }

        static void Main(string[] args)
        {
            /*
            Console.WriteLine(IsGoodNum(12345));
            Console.WriteLine(IsGoodNum(52346));
            Console.WriteLine(IsGoodNum(12341));
            */
            int correctNum = 0;
            for (int i = 10000; i < 100000; i++)
            {
                if (IsGoodNum(i)) correctNum++;
            }
            Console.WriteLine("符合条件的数字个数为:{0}", correctNum);

            Console.ReadKey();
        }
    }
}
