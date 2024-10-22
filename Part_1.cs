void pol_checekr (string word1)
{
    string word = word1.ToLower();
    string word_reverse = new string(word.Reverse().ToArray());
    if (word_reverse.Equals(word))
    {
        Console.WriteLine("true");
    }
    else
    {
        Console.WriteLine("false");
    }
}

string word = "raCecaR";
pol_checekr(word);