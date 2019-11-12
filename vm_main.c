/* main function begins */
int main(int argc, char *argv[])
{
    stack = createStack(10000);

    readfile("code.txt");

    calculate();

    double answer = pop(stack);
    printf("%.2f", answer);

    return 0;
}
