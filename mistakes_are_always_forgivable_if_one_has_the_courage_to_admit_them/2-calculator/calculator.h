int print_char(char c);
void print_number(int n);
void print_negative(int n);
int (*get_op_func(char c))(int, int);
int op_mod(int, int);
int op_mul(int, int);
int op_add(int, int);
int op_sub(int, int);
int op_div(int, int);
