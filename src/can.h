#ifndef CAN_H
#define CAN_H
//std library
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//socket
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
//can
#include <linux/can.h>
#include <linux/can/raw.h>
//other crap
#include <string.h>
#include <assert.h>
#include <errno.h>


int s = -1;
int can_init(const char* channel){
    assert(strcmp(channel, "can0") == 0 || strcmp(channel,"vcan0") == 0);

    struct sockaddr_can addr;
	struct ifreq ifr;
    s = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    if(s < 0){
        return 1;
    }
    strcpy(ifr.ifr_name, channel);
	ioctl(s, SIOCGIFINDEX, &ifr);

    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;
    if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0){
        fprintf(stderr, "%s\n", strerror(errno));
        return 2;
    }
    return 0; 
}

void can_read(){
    struct can_frame frame;
    int nbytes;
    assert(s>=0);

    printf("%d\n", nbytes);
    nbytes = read(s, &frame, sizeof(struct can_frame));
    printf("%d\n", nbytes);
    if (nbytes>0){
        printf("Received id %d, data: %d | %d", frame.can_id, frame.data[0], frame.data[1]);
    }
}
#endif