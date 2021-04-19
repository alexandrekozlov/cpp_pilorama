cl /std:c++17 /EHsc generator.cpp

mkdir reference
mkdir questions
for %%n in (*.cpp) do (
	generator full "%%n" > "reference\%%~nn.md"
	generator short "%%n" > "questions\%%~nn.md"
)


