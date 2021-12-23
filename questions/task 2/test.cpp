SCENARIO("Tidy string with start and end quote is returned without those quotess")
{
	GIVEN("A string with start and end quotes")
	{
		THEN("Find a substring @-")
		{
			CStr string = L"\"This is @-a string\"";
			CHECK(Oasys::Util::TidyString(string) == L"This is @-a string");
		}
	}
}

SCENARIO("Tidy string without quotes is not modified")
{
	GIVEN("A string with no quotes")
	{
		THEN("Find a substring @-")
		{
			CStr string = L"This is @-a string";
			CHECK(Oasys::Util::TidyString(string) == L"This is @-a string");
		}
	}
}
SCENARIO("Short strring is returned unmodified")
{
	GIVEN("A string with no quotes")
	{
		THEN("Find a substring @-")
		{
			CStr string = L"T";
			CHECK(Oasys::Util::TidyString(string) == L"T");
		}
	}
}