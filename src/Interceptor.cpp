#define BUILDING_NODE_EXTENSION
#include <node.h>
#include <iostream>
#include "Interceptor.h"

using namespace v8;

Interceptor::Interceptor() {};
Interceptor::~Interceptor() {};

Persistent<Function> constructor;

void
Interceptor::Init( Handle<Object> target ) {

	Local<FunctionTemplate> tpl = FunctionTemplate::New( New );
	Local<String> name = String::NewSymbol( "Interceptor" );

	tpl->SetClassName( name );
	tpl->InstanceTemplate()->SetInternalFieldCount( 1 );
	tpl->PrototypeTemplate()->Set(String::NewSymbol( "Intercept" ),
		FunctionTemplate::New(Intercept)->GetFunction());

	constructor = Persistent<Function>::New(tpl->GetFunction());
	target->Set(name, constructor);

}

Handle<Value>
Interceptor::New( const Arguments& args ) {
	HandleScope scope;

	Interceptor * obj = new Interceptor();
	obj->Wrap( args.This() );

	return args.This();
}

Handle<Value>
Interceptor::Intercept( const Arguments& args ) {
	HandleScope scope;

	Interceptor* obs = ObjectWrap::Unwrap<Interceptor>( args.This() );


	return scope.Close( Undefined() );
}
