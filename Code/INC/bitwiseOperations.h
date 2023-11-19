#ifndef BITWISEOPERATIONS_H_
#define BITWISEOPERATIONS_H_

#define CLEAR_BIT(reg,bit)		(reg &= ~(1<<bit))
#define SET_BIT(reg,bit)		(reg |= (1<<bit))
#define TOGGLE_BIT(reg,bit)		(reg ^= (1<<bit))
#define READ_BIT(reg,bit)		((reg>>bit)&1)

#endif /* BITWISE_OPERATIONS_H_ */