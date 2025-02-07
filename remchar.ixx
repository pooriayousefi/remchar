export module remchar;

import <stdexcept>;
import <filesystem>;
import <string>;
import <iostream>;
import <fstream>;
import <sstream>;
import <ranges>;
import <algorithm>;

// character remover data structure
export struct remove_character
{
	// type definitions
	using character_type = wchar_t;

	// member
	character_type specific_character;

	// default constructor
	remove_character() = delete;

	// constructor with parameter
	remove_character(character_type c) :specific_character{ c } {}

	// remover method
	inline void from_file(std::filesystem::path source_filepath) const
	{
		auto source_file_stream{ std::wifstream(source_filepath) };
		std::wstringstream source_file_buffer{};
		source_file_buffer << source_file_stream.rdbuf();
		auto source_file_string{ source_file_buffer.str() };

		auto source_filename{ source_filepath.stem().wstring() };
		source_filename += L"(specific character removed)";
		source_filename += source_filepath.extension().wstring();

		auto destination_filepath{ source_filepath.parent_path() / std::filesystem::path{ source_filename } };
		auto destination_file_stream{ std::wofstream(destination_filepath) };

		for (const auto& c : source_file_string)
		{
			if (c != specific_character)
				destination_file_stream << c;
			else
				continue;
		}

		source_file_stream.close();
		destination_file_stream.flush();
		destination_file_stream.close();
	}
};