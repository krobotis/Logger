
#ifndef Logger_EXPORT_H
#define Logger_EXPORT_H

#ifdef SHARED_EXPORTS_BUILT_AS_STATIC
#  define Logger_EXPORT
#  define LOGGER_NO_EXPORT
#else
#  ifndef Logger_EXPORT
#    ifdef Logger_EXPORTS
        /* We are building this library */
#      define Logger_EXPORT 
#    else
        /* We are using this library */
#      define Logger_EXPORT 
#    endif
#  endif

#  ifndef LOGGER_NO_EXPORT
#    define LOGGER_NO_EXPORT 
#  endif
#endif

#ifndef LOGGER_DEPRECATED
#  define LOGGER_DEPRECATED __declspec(deprecated)
#endif

#ifndef LOGGER_DEPRECATED_EXPORT
#  define LOGGER_DEPRECATED_EXPORT Logger_EXPORT LOGGER_DEPRECATED
#endif

#ifndef LOGGER_DEPRECATED_NO_EXPORT
#  define LOGGER_DEPRECATED_NO_EXPORT LOGGER_NO_EXPORT LOGGER_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef LOGGER_NO_DEPRECATED
#    define LOGGER_NO_DEPRECATED
#  endif
#endif

#endif /* Logger_EXPORT_H */
