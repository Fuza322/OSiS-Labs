using System;
using System.Collections.Generic;
using System.IO;

namespace ConsoleApp2
{
    class Program
    {
        static string[] SearchDirectory(string path) // метод который получает папку по пути
        {
            string[] searchResult = Directory.GetDirectories(path);
            return searchResult;
        }

        static string[] SearchFiles(string path, string pattern) // метод который 
        {
            string[] searchResult = Directory.GetFiles(path, pattern, SearchOption.AllDirectories);
            return searchResult;
        }

        static List<string> FoundFiles(string[] result, string pathForSearch) // метод, который ищет файлы по введённому паттерну
        {
            string printRes = "\nFound files on " + pathForSearch + " :\n";
            List<string> allFiles = new List<string>();
            foreach (string folder in result)
            {
                try
                {
                    string[] files = SearchFiles(folder, "*lol*" + "*.txt"); //Выбор имени файла для поиска
                    foreach (string file in files)
                    {
                        printRes += file + "\n";
                        allFiles.Add(file);
                    }
                }
                catch
                {
                    Console.WriteLine("Access denied: " + folder);
                }
            }
            if (allFiles.Count != 0)
                Console.WriteLine(printRes);
            else Console.WriteLine("\nHaha, nothing found");
            Console.WriteLine("- - - - - - - - - - - -");
            return allFiles;
        }

        static void WriteResult(string resultFile, List<string> allFiles)
        {
            List<string> resultText = new List<string>();
            foreach (string file in allFiles)
            {
                resultText.AddRange(File.ReadAllLines(file));
            }
            File.AppendAllLines(resultFile, resultText);
        }

        static void DriveSearch(string pathForSearch, string resultFile) // метод который ищет в выбранном каталоге файл по конкретному пути 
        {
            Console.WriteLine($"Searching files on {pathForSearch} drive...");
            string[] result = SearchDirectory(pathForSearch);
            List<string> allFiles = FoundFiles(result, pathForSearch);
            WriteResult(resultFile, allFiles);
        }

        static void Main(string[] args)
        {
            DriveSearch("D:\\", "D:\\Education\\Laboratory_works\\ОСиС\\lab1\\result.txt");
            DriveSearch("C:\\", "D:\\Education\\Laboratory_works\\ОСиС\\lab1\\result.txt");
            Console.ReadKey();
        }
    }
}
