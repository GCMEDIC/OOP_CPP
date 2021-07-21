using System;

namespace Maybe
{
    class Program
    {
        static void Main(string[] args)
        {

            Console.WriteLine("Введите текст:");
            string[] textMass;
            string text = Console.ReadLine();
            textMass = text.Split(' ');
            Console.WriteLine("Количество слов:");
            Console.WriteLine(textMass.Length);
            Console.ReadLine();

        }
    }
}
