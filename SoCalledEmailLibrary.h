#pragma once

typedef struct {
    char *toaddr;
    char *fromaddr;
    char *body;    
}EmailContent_t;


extern void Email(EmailContent_t Content);
