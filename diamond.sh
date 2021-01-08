for((i = 1; ; ++i)); do
    echo i
    ./diamond_generator i > int
    ./Problem_2_Diamond_Collector > out1
    ./diamond_sol > out2
    diff -w out1 out2 || break
    # diff -w <(./my_solution_filename < int) <(./model_solution_or_bruteforce_filenmae < int) || break
done