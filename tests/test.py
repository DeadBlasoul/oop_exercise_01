import sys
import subprocess

def main(argv):
    test_file = argv[1]
    exec_file = argv[2]

    out = subprocess.Popen(
        [exec_file],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE)

    with open(test_file, "r") as test_file:
        test_name = test_file.readline()
        print(test_name)

        lines = test_file.readlines()
        size = len(lines)
        i = 0
        while i < size:
            test = lines[i + 0].rstrip()
            result = lines[i + 1].rstrip()
            print(f"Test: {test} \t->\t {result}")

            btest = str.encode(test)

            out.stdin.write(btest + b'\n')
            out.stdin.flush()
            answer = bytes.decode(out.stdout.readline().rstrip(), 'utf-8')

            assert answer == result, f"Answer for test '{test}' should be '{result}' but received '{answer}'"

            i += 2

if __name__ == "__main__":
    main(sys.argv)
