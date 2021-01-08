for((i = 1; ; ++i)); do
    echo $i
    ./Problem_1_My_Cow_Ate_My_Homework_generator $i > int
    ./Problem_1_My_Cow_Ate_My_Homework > out1
    ./Problem_1_My_Cow_Ate_My_Homework_solution > out2
    diff -w out1 out2 || break
    # diff -w <(./Problem_2_Convention_II < int) <(./convention_solution < int) || break
done