for((i = 1; ; ++i)); do
    echo i
    ./generator_filename i > int
    ./my_solution_filename > out1
    ./model_solution_or_bruteforce_filenmae > out2
    diff -w out1 out2 || break
    # diff -w <(./my_solution_filename < int) <(./model_solution_or_bruteforce_filenmae < int) || break
done