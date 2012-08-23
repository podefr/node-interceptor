#define BUILDING_NODE_EXTENSION
#include <node.h>
#include "Interceptor.h"

using namespace v8;

void InitAll(Handle<Object> target) {
	Interceptor::Init(target);
}

NODE_MODULE(Interceptor, InitAll);
