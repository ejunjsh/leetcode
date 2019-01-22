class Solution{
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth)
    {
        vector<string> justifiedText;

        for (unsigned i = 0, j, lineWordsLength = 0; i < words.size(); i = j, lineWordsLength = 0)
        {
            for (j = i; j < words.size() && lineWordsLength + words[j].size() + (j - i) <= maxWidth; lineWordsLength += words[j++].size());

            string line = words[i];
            for (unsigned k = i + 1; k < j; ++k)
            {
                int paddingSize = 1;
                if (j < words.size())
                {
                    paddingSize = (maxWidth - lineWordsLength) / (j - k) + ((maxWidth - lineWordsLength) % (j - k) != 0 ? 1 : 0);
                    lineWordsLength += paddingSize;
                }

                line.append(paddingSize, ' ').append(words[k]);
            }

            line.append(maxWidth - line.size(), ' ');
            justifiedText.push_back(line);
        }

        return justifiedText;
    }
};
