#define mul32x32_64(a,b) (((uint64_t)(a))*(b))

#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DONNA_INLINE
#undef ALIGN
#ifdef _MSC_VER
#define ALIGN(x) __declspec(align(x))
#else
#define ALIGN(x) __attribute__((aligned(x)))
#endif

static inline void U32TO8_LE(unsigned char *p, const uint32_t v) {
	p[0] = (unsigned char)(v      );
	p[1] = (unsigned char)(v >>  8);
	p[2] = (unsigned char)(v >> 16);
	p[3] = (unsigned char)(v >> 24);
}

static inline uint32_t U8TO32_LE(const unsigned char *p) {
	return
	(((uint32_t)(p[0])      ) |
	 ((uint32_t)(p[1]) <<  8) |
	 ((uint32_t)(p[2]) << 16) |
	 ((uint32_t)(p[3]) << 24));
}

#ifdef __cplusplus
} /* extern "C" */
#endif
