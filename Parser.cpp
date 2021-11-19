#include "Headers.h"

int main() {
	setlocale(LC_ALL, "ru");
	// the string to find
	const wstring words = L"</a>Электрическая";
	// del trash
	const wstring word = L"</a>";
	// open file
	FILE* file = fopen("doc.html", "rb");

	fseek(file, 0, SEEK_END);
	const size_t fileSize = ftell(file);
	fseek(file, 0, SEEK_SET);
	wchar_t* buffer = new wchar_t[fileSize];

	const size_t readed = fread(buffer, 1, sizeof(wchar_t) * fileSize, file);

	wchar_t* begin = buffer + 1;
	wchar_t* end = begin + readed - words.size();
	for (wchar_t* curr = begin; curr < end; curr++) {
		const wstring szCurr(curr, words.size());
		if (szCurr == words) {
			wchar_t* curr2 = curr + word.size();
			wchar_t* line_begin = curr2;

			while (*curr2) {
				if (wstring(curr2, 4) == L"</p>") {
					const wstring szCurr2(line_begin, curr2);
					printf("%S", szCurr2.c_str());
					break;
				}
				++curr2;
			}

		}
	}
	return 0;
}
