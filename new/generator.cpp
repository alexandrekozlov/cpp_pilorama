#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string_view>
#include <string>
#include <filesystem>

/// $name: General C++ code understanding.
/// $keywords: codereading
/// $level: beginner

/// $code
#if defined(MSVC_VER)

int Compile(const char *source_file, bool log)
{
    const char *e = std::strrchr(source_file, '.');
    const auto output_file = std::string_view(source_file, e - source_file);

    std::error_code ec;
    std::filesystem::create_directory("out", ec);

    std::string command_line;
    command_line += "cl /std:c++17 ";
    command_line += " ";
    command_line += source_file;
    if (log)
        command_line += " > out\\compile_log.tmp";
    else
        command_line += " > NUL";

    return system(command_line.c_str());
}

#else

int Compile(const char *source_file, bool log)
{
    const char *e = std::strrchr(source_file, '.');
    const auto output_file = std::string_view(source_file, e - source_file);

    std::error_code ec;
    std::filesystem::create_directory("out", ec);

    std::string command_line;
    command_line += "c++ --std=c++17 -o ";
    command_line += "out/";
    command_line += output_file;
    command_line += " ";
    command_line += source_file;
    if (log)
        command_line += " > out/compile_log.tmp 2>&1";
    else
        command_line += " > /dev/null 2>&1";

    return system(command_line.c_str());
}

#endif

#if defined(WINDOWS)

int Run(const char *source_file)
{
    Compile(source_file, false);

    const char *e = std::strrchr(source_file, '.');
    const auto output_file = std::string_view(source_file, e - source_file);

    std::error_code ec;
    std::filesystem::create_directory("out", ec);

    std::string command_line;
    command_line += ".\\";
    command_line += output_file;
    command_line += " > out\\run_log.tmp";
    return system(command_line.c_str());
}

#else

int Run(const char *source_file)
{
    Compile(source_file, false);

    const char *e = std::strrchr(source_file, '.');
    const auto output_file = std::string_view(source_file, e - source_file);

    std::error_code ec;
    std::filesystem::create_directory("out", ec);

    std::string command_line;
    command_line += "./out/";
    command_line += output_file;
    command_line += " > out/run_log.tmp 2>&1";
    return system(command_line.c_str());
}

#endif

bool IsKeywordLine(std::string_view sv, std::string &keyword, std::string &content, size_t &prefix_size)
{
    keyword.clear();
    content.clear();
    prefix_size = 0;

    if (sv.size() < 5)
        return false;

    if (sv[0] != '/' || sv[1] != '/' || sv[2] != '/')
        return false;

    sv.remove_prefix(3);

    auto kwpos = sv.find("$");
    if (kwpos == std::string_view::npos)
        return false;

    prefix_size = 3 + kwpos;

    sv.remove_prefix(kwpos);
    auto kwend = sv.find_first_of(" \t");
    if (kwend == std::string_view::npos)
    {
        keyword = sv;
        return true;
    }

    keyword = sv.substr(0, kwend);
    sv.remove_prefix(kwend);

    auto kwarg = sv.find_first_not_of(" \t");
    if (kwarg != std::string_view::npos)
        content = sv.substr(kwarg);
    else
        content = sv;

    auto eoa = content.find_last_not_of(" \t\n\r");
    if (eoa != std::string_view::npos)
        content = content.substr(0, eoa + 1);

    return true;
}


std::string ReadFile(const char *file, size_t from_line = 0, int lines = -1)
{
    std::string content;

    auto is = std::ifstream(file);
    if (is.fail())
    {
        return content;
    }

    std::string buffer;
    while(std::getline(is, buffer))
    {
        if (from_line != 0)
        {
            from_line --;
            continue;
        }

        if (lines > 0)
            lines --;
        else if (lines == 0)
            break;

        content += buffer;
        content += '\n';
    }

    return content;
}


std::string ReadBlock(std::istream &is, size_t prefix)
{
    std::string content;

    int lines = 0;

    std::string buffer;
    while(std::getline(is, buffer))
    {
        std::string_view sv = buffer;
        std::string keyword;
        std::string arg;
        size_t prefix_size = 0;
        if (IsKeywordLine(sv, keyword, arg, prefix_size))
        {
            if (keyword == "$$")
                break;
        }

        sv.remove_prefix(std::min(sv.size(), prefix));

        if (lines ++ > 0)
            content += '\n';

        content += sv;
    }

    return content;
}


class QuestionContent
{
public:
    void Read(std::istream &is);

    std::string name;
    std::string description;
    std::string keywords;
    std::string level;
    std::string question;
    std::string code;

    bool output_compile_log = false;
    bool output_run_log = false;

    std::string compile_log;
    std::string run_log;
};

void QuestionContent::Read(std::istream &is)
{
    std::string buffer;

    while(std::getline(is, buffer))
    {
        std::string_view sv = buffer;
        std::string keyword;
        std::string arg;
        size_t prefix_size = 0;

        if (IsKeywordLine(sv, keyword, arg, prefix_size))
        {
            if (keyword == "$name:")
            {
                name = arg;
            }
            else if (keyword == "$description:")
            {
                description = arg;
            }
            else if (keyword == "$description")
            {
                description = ReadBlock(is, prefix_size);
            }
            else if (keyword == "$keywords:")
            {
                keywords = arg;
            }
            else if (keyword == "$level:")
            {
                level = arg;
            }
            else if (keyword == "$question:")
            {
                question = arg;
            }
            else if (keyword == "$question")
            {
                question = ReadBlock(is, prefix_size);
            }
            else if (keyword == "$output:")
            {
                if (arg == "compile")
                {
                    output_compile_log = true;
                }
                else if (arg == "run")
                {
                    output_run_log = true;
                }
                else if (arg == "both")
                {
                    output_compile_log = true;
                    output_run_log = true;
                }
            }
            else if (keyword == "$code")
            {
                code = ReadBlock(is, 0);
            }
        }
    }

    return;
}


QuestionContent PrepareQuestion(const char *question_file)
{
    QuestionContent q;

    auto is = std::ifstream(question_file);
    if (is.fail())
    {
        return q;
    }

    q.Read(is);

    is.close();

    if (q.output_compile_log)
    {
        Compile(question_file, true);
        q.compile_log = ReadFile("out/compile_log.tmp");
    }

    if (q.output_run_log)
    {
        Run(question_file);
        q.run_log = ReadFile("out/run_log.tmp");
    }

    return q;
}


int main(int argc, char **argv)
{
    if (argc < 3)
    {
        std::cout << "usage: generator <full|short> file" << std::endl;
        return 0;
    }

    if (std::strcmp(argv[1], "full") == 0)
    {
        auto q = PrepareQuestion(argv[2]);
        auto &os = std::cout;

        os << "## " << q.name << "\n\n";

        if (!q.description.empty())
        {
            os << q.description << "\n\n";
        }

        if (!q.keywords.empty())
        {
            os << "Keywords: " << q.keywords << "\n\n";
        }

        os << "Level: " << q.level << "\n\n";

        if (!q.code.empty())
        {
            os << "### The code:\n"
                << "```c++\n"
                << q.code << '\n'
                << "```\n"
                << '\n';
        }

        if (q.output_compile_log)
        {
            os << "### The compiler output:\n"
                << "```\n"
                << q.compile_log << '\n'
                << "```\n\n";
        }

        if (q.output_run_log)
        {
            os << "### The result:\n"
                << "```\n"
                << q.run_log << '\n'
                << "```\n\n";
        }

        if (!q.question.empty())
        {
            os << "### The question:\n"
                << q.question << "\n\n";
        }
    }
    else if (std::strcmp(argv[1], "short") == 0)
    {
        auto q = PrepareQuestion(argv[2]);
        auto &os = std::cout;

        os << "## " << "Question" << "\n\n";

        if (!q.code.empty())
        {
            os << "### The code:\n"
                << "```c++\n"
                << q.code << '\n'
                << "```\n"
                << '\n';
        }

        if (q.output_compile_log)
        {
            os << "### The compiler output:\n"
                << "```\n"
                << q.compile_log << '\n'
                << "```\n\n";
        }

        if (q.output_run_log)
        {
            os << "### The result:\n"
                << "```\n"
                << q.run_log << '\n'
                << "```\n\n";
        }

        if (!q.question.empty())
        {
            os << "### The question:\n"
                << q.question << "\n\n";
        }
    }
    else
    {
        std::cout << "error: unknown template name\n";
        return 1;
    }

    return 0;
}

