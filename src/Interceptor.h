#ifndef INTERCEPTOR_H
#define INTERCEPTOR_H

#include <node.h>

using namespace v8;


class Interceptor: public node::ObjectWrap {
	public:
		static void Init(Handle<Object>);

	protected:
		Interceptor();
		virtual ~Interceptor();

	private:
		static Handle<Value> New( const Arguments& );
		static Handle<Value> Intercept( const Arguments& );
};

#endif
