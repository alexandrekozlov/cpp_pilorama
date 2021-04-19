cl /std:c++17 /EHsc generator.cpp

mkdir full
mkdir short
for %%n in (*.cpp) do (
	generator full "%%n" > "full\%%~nn.md"
	generator short "%%n" > "short\%%~nn.md"
)


