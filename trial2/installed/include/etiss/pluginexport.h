
#ifndef ETISS_PLUGIN_EXPORT_H
#define ETISS_PLUGIN_EXPORT_H

#ifdef ETISS_PLUGIN_STATIC_DEFINE
#  define ETISS_PLUGIN_EXPORT
#  define ETISS_PLUGIN_NOEXPORT
#else
#  ifndef ETISS_PLUGIN_EXPORT
#    ifdef ETISS_EXPORTS
        /* We are building this library */
#      define ETISS_PLUGIN_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define ETISS_PLUGIN_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef ETISS_PLUGIN_NOEXPORT
#    define ETISS_PLUGIN_NOEXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef ETISS_PLUGIN_DEPRECATED
#  define ETISS_PLUGIN_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef ETISS_PLUGIN_DEPRECATED_EXPORT
#  define ETISS_PLUGIN_DEPRECATED_EXPORT ETISS_PLUGIN_EXPORT ETISS_PLUGIN_DEPRECATED
#endif

#ifndef ETISS_PLUGIN_DEPRECATED_NO_EXPORT
#  define ETISS_PLUGIN_DEPRECATED_NO_EXPORT ETISS_PLUGIN_NOEXPORT ETISS_PLUGIN_DEPRECATED
#endif

#if 1 /* DEFINE_NO_DEPRECATED */
#  ifndef ETISS_PLUGIN_NODEPRECATED
#    define ETISS_PLUGIN_NODEPRECATED
#  endif
#endif

#endif /* ETISS_PLUGIN_EXPORT_H */
