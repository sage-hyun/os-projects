#include <stdio.h>
#include <unistd.h>    // open, close, ioctl
#include <sys/fcntl.h> // O_RDWR, O_NONBLOCK
#include <sys/ioctl.h> // _IOR, _IOW
#define MY_IOCTL_NUMBER100
#define MY_IOCTL_READ_IOR(MY_IOCTL_NUMBER, 0, int)
#define MY_IOCTL_WRITE_IOW(MY_IOCTL_NUMBER, 1, int)
int main()
{
    int fd;
    int debug_flag = 0;

    if ((fd = open("/dev/virtual_buffer", O_RDWR)) > 0)
    {
        ioctl(fd, MY_IOCTL_READ, &debug_flag);
        debug_flag = !debug_flag; // toggle debug flag
        ioctl(fd, MY_IOCTL_WRITE, &debug_flag);
        close(fd);
    }
    return 0;
}
