import subprocess
import os
import glob


class TestcaseError:
    def __init__(self, line, input, output, expected):
        self.line = line
        self.input = input
        self.output = output
        self.expected = expected


def run_testcase(input_file) -> list:
    # 執行測試案例
    with open(input_file, "r") as f:
        input_data = f.read()

    result = subprocess.run(
        ["./test"], input=input_data.encode(), stdout=subprocess.PIPE
    )
    return result.stdout.decode().split("\n") ,input_data.split("\n")


def compare_output(output, expected_output, input_data) -> bool:
    # 比對輸出結果
    with open(expected_output, "r") as f:
        expected_output = f.read().split("\n")

    error_list = []

    try:
        print(input_data[2431])
        print(output[2432])
        print(expected_output[2432])
    except:
        pass

    for i, (o, e) in enumerate(zip(output, expected_output)):
        if o != e:
            error_list.append(TestcaseError(i + 1, input_data[i], o, e))

    return error_list


def main():
    # 編譯 C 程式
    subprocess.run(["gcc", "test.c", "-o", "test"])

    # 取得所有測試案例
    test_dir = "testcase"
    input_files = sorted(glob.glob(os.path.join(test_dir, "*.in")))
    output_files = sorted(glob.glob(os.path.join(test_dir, "*.out")))

    for i, (input_file, output_file) in enumerate(zip(input_files, output_files)):
        output, input_data = run_testcase(input_file)
        error = compare_output(output, output_file, input_data)

        if len(error) == 0:
            print(f"Test {i+1} : All testcases passed!")
        else:
            error = error[:10]
            for e in error:
                e: TestcaseError
                print(f"Testcase {e.line} failed")
                print(f"Input: {e.input}")
                print(f"Output: {e.output}")
                print(f"Expected: {e.expected}")
                print("-" * 20)


if __name__ == "__main__":
    main()
