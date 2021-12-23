std::vector<std::wstring> Oasys::split(std::wstring lookUpString, const std::wstring delimiter)
{
	size_t pos_start = 0, pos_end, delim_len = delimiter.length();
	std::vector<std::wstring> result;
	while ((pos_end = lookUpString.find(delimiter, pos_start)) != std::wstring::npos)
	{
		std::wstring token = lookUpString.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		result.push_back(token);
	}
	const auto& remaining = lookUpString.substr(pos_start);
	if (!remaining.empty())
		result.push_back(remaining);
	return result;
}