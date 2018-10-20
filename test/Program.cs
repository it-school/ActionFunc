using System;
using System.Collections.Generic;

namespace ConsoleApplication1
{
    class ArrSort
    {
        // Реализуем обобщенный метод сортировки
        public static void Sort<T>(IList<T> sortArray, Func<T, T, bool> res)
        {
            bool mySort = true;
            do
            {
                mySort = false;
                for (int i = 0; i < sortArray.Count - 1; i++)
                {
                    if (res(sortArray[i + 1], sortArray[i]))
                    {
                        T j = sortArray[i];
                        sortArray[i] = sortArray[i + 1];
                        sortArray[i + 1] = j;
                        mySort = true;
                    }
                }
            } while (mySort);
        }
    }

    class UserInfo
    {
        public string Name { get; private set; }
        public string Family { get; private set; }
        public decimal Salary { get; private set; }

        public UserInfo(string Name, string Family, decimal Salary)
        {
            this.Name = Name;
            this.Family = Family;
            this.Salary = Salary;
        }

        public override string ToString()
        {
            return string.Format("{0} {1}, {2:C}", Name, Family, Salary);
        }

        // Данный метод введен для соответствия сигнатуре делегата Func
        public static bool UserSalary(UserInfo obj1, UserInfo obj2)
        {
            return obj1.Salary < obj2.Salary;
        }
    }

    class Program
    {
        static void Main()
        {
            UserInfo[] userinfo = { new UserInfo("Дмитрий","Петров", 50000),
                                    new UserInfo("Алексей","Ермолаев", 10000),
                                    new UserInfo("Евгений","Малкин", 40000),
                                    new UserInfo("Василий","Палкин", 100000)};

            ArrSort.Sort(userinfo, UserInfo.UserSalary);

            Console.WriteLine("Сортируем исходный объект по доходу: \n-------------------------------------\n");
            foreach (var ui in userinfo)
                Console.WriteLine(ui);

        }
    }
}