#ifndef USERPROG_PROCESS_H
#define USERPROG_PROCESS_H

#include "threads/thread.h"

tid_t process_create_initd (const char *file_name);
tid_t process_fork (const char *name, struct intr_frame *if_);
int process_exec (void *f_name);
int process_wait (tid_t);
void process_exit (void);
void process_activate (struct thread *next);
// project 3 add prototype
static bool install_page (void *upage, void *kpage, bool writable);
static bool load_segment (struct file *file, off_t ofs, uint8_t *upage,	uint32_t read_bytes, uint32_t zero_bytes, bool writable);
// project 3 add prototype
// project 3 add struct
struct off_f {
    struct file *file;
    off_t ofs;
    uint8_t *upage;
    uint32_t read_bytes;
    uint32_t zero_bytes;
    bool writable;
};
// project 3 add struct
void push_args(char **argv, int argc, struct intr_frame *if_);

#endif /* userprog/process.h */
