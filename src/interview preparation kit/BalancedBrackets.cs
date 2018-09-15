using System.Collections.Generic;

namespace HackerRank.interview_preparation_kit
{
    public class BalancedBrackets
    {
        // Complete the isBalanced function below.
        public static string isBalanced(string s)
        {
            if (s.Length % 2 != 0) return "NO";

            var stack = new Stack<char>();
            foreach (var t in s)
            {
                switch (t)
                {
                    case ')':
                        if (stack.Count != 0 && stack.Pop().Equals('(')) continue;
                        return "NO";
                    case '}':
                        if (stack.Count != 0 && stack.Pop().Equals('{')) continue;
                        return "NO";
                    case ']':
                        if (stack.Count != 0 && stack.Pop().Equals('[')) continue;
                        return "NO";
                    default:
                        stack.Push(t);
                        continue;
                }
            }

            return stack.Count == 0 ? "YES" : "NO";
        }
    }
}

