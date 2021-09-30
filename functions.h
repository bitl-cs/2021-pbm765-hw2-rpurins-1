int read_line(int fd, char *buffer);
int add_person(char *name, char *father, char *mother, char *data_structure);
int print_persons(int fd, char *data_structure);
int read_persons(int fd, char *data_structure);

void print_error(int error_code);
