#if defined(ZLS_FUNC_DEFTYPES)
#undef ZLS_FUNC_DEFTYPES
#define ZLS_FUNC(ret, funcname, parms)  typedef ret (*PType##funcname)parms
#elif defined(ZLS_FUNC_DEFVARS)
#undef ZLS_FUNC_DEFVARS
#define ZLS_FUNC(ret, funcname, parms)  PType##funcname funcname
#elif defined(ZLS_FUNC_SETVARS)
#undef ZLS_FUNC_SETVARS
#define ZLS_FUNC(ret, funcname, parms)  gl::funcname = (PType##funcname)dlsym(hnd_egl, #funcname)
#endif

ZLS_FUNC(EGLint, eglGetError, (void));

ZLS_FUNC(EGLDisplay, eglGetDisplay, (EGLNativeDisplayType display_id));
ZLS_FUNC(EGLBoolean, eglInitialize, (EGLDisplay dpy, EGLint *major, EGLint *minor));
ZLS_FUNC(EGLBoolean, eglTerminate, (EGLDisplay dpy));

ZLS_FUNC(const char *, eglQueryString, (EGLDisplay dpy, EGLint name));

ZLS_FUNC(EGLBoolean, eglGetConfigs, (EGLDisplay dpy, EGLConfig *configs, EGLint config_size, EGLint *num_config));
ZLS_FUNC(EGLBoolean, eglChooseConfig, (EGLDisplay dpy, const EGLint *attrib_list, EGLConfig *configs, EGLint config_size, EGLint *num_config));
ZLS_FUNC(EGLBoolean, eglGetConfigAttrib, (EGLDisplay dpy, EGLConfig config, EGLint attribute, EGLint *value));

ZLS_FUNC(EGLSurface, eglCreateWindowSurface, (EGLDisplay dpy, EGLConfig config, EGLNativeWindowType win,const EGLint *attrib_list));
ZLS_FUNC(EGLSurface, eglCreatePbufferSurface, (EGLDisplay dpy, EGLConfig config, const EGLint *attrib_list));
ZLS_FUNC(EGLSurface, eglCreatePixmapSurface, (EGLDisplay dpy, EGLConfig config, EGLNativePixmapType pixmap, const EGLint *attrib_list));
ZLS_FUNC(EGLBoolean, eglDestroySurface, (EGLDisplay dpy, EGLSurface surface));
ZLS_FUNC(EGLBoolean, eglQuerySurface, (EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint *value));

ZLS_FUNC(EGLBoolean, eglBindAPI, (EGLenum api));
ZLS_FUNC(EGLenum, eglQueryAPI, (void));

ZLS_FUNC(EGLBoolean, eglWaitClient, (void));

ZLS_FUNC(EGLBoolean, eglReleaseThread, (void));

ZLS_FUNC(EGLSurface, eglCreatePbufferFromClientBuffer, (EGLDisplay dpy, EGLenum buftype, EGLClientBuffer buffer, EGLConfig config, const EGLint *attrib_list)); 

ZLS_FUNC(EGLBoolean, eglSurfaceAttrib, (EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint value));
ZLS_FUNC(EGLBoolean, eglBindTexImage, (EGLDisplay dpy, EGLSurface surface, EGLint buffer));
ZLS_FUNC(EGLBoolean, eglReleaseTexImage, (EGLDisplay dpy, EGLSurface surface, EGLint buffer));

ZLS_FUNC(EGLBoolean, eglSwapInterval, (EGLDisplay dpy, EGLint interval));

ZLS_FUNC(EGLContext, eglCreateContext, (EGLDisplay dpy, EGLConfig config, EGLContext share_context, const EGLint *attrib_list));
ZLS_FUNC(EGLBoolean, eglDestroyContext, (EGLDisplay dpy, EGLContext ctx));
ZLS_FUNC(EGLBoolean, eglMakeCurrent, (EGLDisplay dpy, EGLSurface draw, EGLSurface read, EGLContext ctx));

ZLS_FUNC(EGLContext, eglGetCurrentContext, (void));
ZLS_FUNC(EGLSurface, eglGetCurrentSurface, (EGLint readdraw));
ZLS_FUNC(EGLDisplay, eglGetCurrentDisplay, (void));
ZLS_FUNC(EGLBoolean, eglQueryContext, (EGLDisplay dpy, EGLContext ctx, EGLint attribute, EGLint *value));

ZLS_FUNC(EGLBoolean, eglWaitGL, (void));
ZLS_FUNC(EGLBoolean, eglWaitNative, (EGLint engine));
ZLS_FUNC(EGLBoolean, eglSwapBuffers, (EGLDisplay dpy, EGLSurface surface));
ZLS_FUNC(EGLBoolean, eglCopyBuffers, (EGLDisplay dpy, EGLSurface surface, EGLNativePixmapType target));

ZLS_FUNC(__eglMustCastToProperFunctionPointerType, eglGetProcAddress, (const char *procname));

#undef ZLS_FUNC
