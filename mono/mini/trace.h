#ifndef __MONO_TRACE_H__
#define __MONO_TRACE_H__
#include <glib.h>

typedef enum {
	MONO_TRACEOP_ALL,
	MONO_TRACEOP_PROGRAM,
	MONO_TRACEOP_METHOD,
	MONO_TRACEOP_ASSEMBLY,
	MONO_TRACEOP_CLASS,
	MONO_TRACEOP_NAMESPACE
} MonoTraceOpcode;

typedef struct {
	MonoTraceOpcode op;
	int   exclude;
	void *data, *data2;
} MonoTraceOperation;

struct MonoTraceSpec {
	int len;
	gboolean enabled;
	MonoTraceOperation *ops;

	MonoAssembly *assembly;
};

G_BEGIN_DECLS

void
mono_trace_enter_method (MonoMethod *method, char *ebp);

void 
mono_trace_leave_method (MonoMethod *method, ...);

void mono_trace_enable (gboolean enable);
gboolean mono_trace_is_enabled (void);

G_END_DECLS

#endif /* __MONO_TRACE_H__ */
