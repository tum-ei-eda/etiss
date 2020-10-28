#ifndef DEBUG_SYSTEM
// The default implementation pulls in printf, so replace it for minimal code size.
namespace __gnu_cxx
{
void __verbose_terminate_handler();
}
void __gnu_cxx::__verbose_terminate_handler() {}
#endif
