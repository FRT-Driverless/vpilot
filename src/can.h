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
#include <fcntl.h>

#include "renderers/raylib/raylib.h"

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
    int flags = fcntl(s, F_GETFL, 0);
    if (fcntl(s, F_SETFL, flags | O_NONBLOCK)<0){
        return 3;
    }
    return 0; 
}

void can_read(){
    struct can_frame frame;
    int nbytes;
    assert(s>=0);

    // printf("before: %d\n", nbytes);
    nbytes = read(s, &frame, sizeof(struct can_frame));
    // printf("after: %d\n", nbytes);
    if (nbytes>=0){
        TraceLog(LOG_INFO, "Received id %d, data: %d | %d", frame.can_id, frame.data[0], frame.data[1]);
    }
}

#define array_len(arr) sizeof(arr) / sizeof(arr[0])
int can_write(uint32_t id, uint8_t dlc, uint8_t* data){
    assert(dlc == array_len(data));
    
    int nbytes;
    struct can_frame frame;
    
    frame.can_id = id;
    frame.can_dlc = dlc;
    memcpy(frame.data, data, array_len(data));
    
    nbytes = write(s, &frame, sizeof(struct can_frame));
}
#endif