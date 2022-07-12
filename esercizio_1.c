int main(){
    int fd = open("leggi.txt", O_RDONLY);
    char buffer[13];
    pid_t pid;
    pid = fork();
    // processo figlio
    if(pid == 0){
        ssize_t res = read(fd, buffer, 2);
        close(fd);
        if(res > 0){
            buffer[2] = "\0";
            printf("%s", buffer);
            return 0;
        }
        else{
            // errore durante la lettura
            printf("Errore durante la lettura");
            return -1;
        }
    }
    // processo padre
    sleep(3);
    ssize_t res;
    res = read(fd, buffer, 12);
    if(res > 0){
        buffer[13] = "\0";
        printf("%s", buffer);
        return 0;
    }
    else{
        // errore durante la lettura
        printf("Errore");
        return -1;
    }
}