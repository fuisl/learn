for (int i = 0; i < = n; i++) // runs n times

    for (int j = 1; j <= i * i; j++) // same reasoning as 1. n^2

        if (j % i == 0)

            for (int k = 0; k < j; k++) // runs n^2 times? <- same reasoning as above.

                sum++;