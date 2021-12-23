void Oasys::Util::TidyString(CStr& cWord)
{
	cWord.Trim();

	const int nChar = cWord.GetLength();
	if (nChar < 2)
		return;

	if (cWord[0] == '"' && cWord[nChar - 1] == '"')
		cWord = cWord.Mid(1, nChar - 2);
}