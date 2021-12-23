SCENARIO("WString is addon feature is working as expected", "[OaString]")
{
	GIVEN("A string")
	{
		THEN("Split string at _")
		{
			std::wstring strintToSplit = L"This is_a string";
			std::wstring expectedStringLeft = L"This is";
			std::wstring expectedStringRight = L"a string";
			const auto& strings = Oasys::split(strintToSplit, L"_");
			std::wstring stringLeft = strings.at(0);
			std::wstring stringRight = strings.at(1);
			int size = (int)strings.size();
			CHECK(size == 2);
			CHECK(stringLeft == expectedStringLeft);
			CHECK(stringRight == expectedStringRight);
		}
	}
}