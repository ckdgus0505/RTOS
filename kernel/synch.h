#ifndef KERNEL_SYNCH_H_
#define KERNEL_SYNCH_H_

typedef struct KernelMutext_t
{
	uint32_t owner;
	bool lock;
} KernelMutext_t;

void Kernel_sem_init(int32_t max);
bool Kernel_sem_pend(void);
void Kernel_sem_post(void);

void Kernel_mutex_init(void);
bool Kernel_mutex_lock(uint32_t owner);
bool Kernel_mutex_unlock(uint32_t oener);

#endif /* KERNEL_SYNCH_H_ */
