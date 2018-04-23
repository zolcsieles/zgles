#include "initializer.h"

#include <stdio.h>
#include <dlfcn.h>

//EGL handle:
void* hnd_egl;
//EGL function types:
typedef void (*__eglMustCastToProperFunctionPointerType)(void);

#define ZLS_FUNC_DEFTYPES
#include "egl_shit_inc.c"

//GLES handle:
void* hnd_gles;
//GLES function types:
#define ZLS_FUNC_DEFTYPES
#include "gl2_shit_inc.c"


namespace gl {
//EGL functions:
#define ZLS_FUNC_DEFVARS
#include "egl_shit_inc.c"
//GLES functions:
#define ZLS_FUNC_DEFVARS
#include "gl2_shit_inc.c"
}


static Initializer initer = Initializer();
Initializer::Initializer()
{
    printf("Loading ZLSGLES...\n");
    
    //Loading egl...
    hnd_egl = dlopen("/usr/lib/i386-linux-gnu/mesa-egl/libEGL.so.1", RTLD_LAZY);
    if (hnd_egl == NULL)
    {
        printf("Unable to load egl!\n");
    }
    else
    {
        #define ZLS_FUNC_SETVARS
        #include "egl_shit_inc.c"
    }

    //Loading gles...
    hnd_gles = dlopen("/usr/lib/i386-linux-gnu/mesa-egl/libGLESv2.so.2", RTLD_LAZY);
    if (hnd_gles == NULL)
    {
        printf("Unable to load gles!\n");
    }
    else
    {
        #define ZLS_FUNC_SETVARS
        #include "gl2_shit_inc.c"
    }    
}

Initializer::~Initializer()
{
    printf("Unloading ZLSGLES...\n");

    //Unloading gles...
    dlclose(hnd_gles);
    //Unloading egl...
    dlclose(hnd_egl);
}

//#define XXXegl printf("egl: ---%s---\n", __FUNCTION__)
//#define XXXgl2 printf("gl2: ---%s---\n", __FUNCTION__)

#define XXXegl
#define XXXgl2

/***
 * EGL
 **/
extern "C" {

EGLAPI EGLint EGLAPIENTRY eglGetError(void) //
{
    XXXegl;
    return gl::eglGetError();
}



EGLAPI EGLDisplay EGLAPIENTRY eglGetDisplay(EGLNativeDisplayType display_id) //
{
    XXXegl;
    return gl::eglGetDisplay(display_id);
}

EGLAPI EGLBoolean EGLAPIENTRY eglInitialize(EGLDisplay dpy, EGLint *major, EGLint *minor) //
{
    XXXegl;
    return gl::eglInitialize(dpy, major, minor);
}

EGLAPI EGLBoolean EGLAPIENTRY eglTerminate(EGLDisplay dpy)
{
    XXXegl;
    return gl::eglTerminate(dpy);
}



EGLAPI const char * EGLAPIENTRY eglQueryString(EGLDisplay dpy, EGLint name) //
{
    XXXegl;
    return gl::eglQueryString(dpy, name);
}

EGLAPI EGLBoolean EGLAPIENTRY eglGetConfigs(EGLDisplay dpy, EGLConfig *configs, EGLint config_size, EGLint *num_config) //
{
    XXXegl;
    return gl::eglGetConfigs(dpy, configs, config_size, num_config);
}

EGLAPI EGLBoolean EGLAPIENTRY eglChooseConfig(EGLDisplay dpy, const EGLint *attrib_list, EGLConfig *configs, EGLint config_size, EGLint *num_config) //
{
    XXXegl;
    return gl::eglChooseConfig(dpy, attrib_list, configs, config_size, num_config);
}

EGLAPI EGLBoolean EGLAPIENTRY eglGetConfigAttrib(EGLDisplay dpy, EGLConfig config, EGLint attribute, EGLint *value) //
{
    XXXegl;
    return gl::eglGetConfigAttrib(dpy, config, attribute, value);
}



EGLAPI EGLSurface EGLAPIENTRY eglCreateWindowSurface(EGLDisplay dpy, EGLConfig config, EGLNativeWindowType win, const EGLint *attrib_list) //
{
    XXXegl;
    return gl::eglCreateWindowSurface(dpy, config, win, attrib_list);
}

EGLAPI EGLSurface EGLAPIENTRY eglCreatePbufferSurface(EGLDisplay dpy, EGLConfig config, const EGLint *attrib_list) //
{
    XXXegl;
    return gl::eglCreatePbufferSurface(dpy, config, attrib_list);
}

EGLAPI EGLSurface EGLAPIENTRY eglCreatePixmapSurface(EGLDisplay dpy, EGLConfig config, EGLNativePixmapType pixmap, const EGLint *attrib_list) //
{
    XXXegl;
    return gl::eglCreatePixmapSurface(dpy, config, pixmap, attrib_list);
}

EGLAPI EGLBoolean EGLAPIENTRY eglDestroySurface(EGLDisplay dpy, EGLSurface surface) //
{
    XXXegl;
    return gl::eglDestroySurface(dpy, surface);
}

EGLAPI EGLBoolean EGLAPIENTRY eglQuerySurface(EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint *value) //
{
    XXXegl;
    return gl::eglQuerySurface(dpy, surface, attribute, value);
}




EGLAPI EGLBoolean EGLAPIENTRY eglBindAPI(EGLenum api) //
{
    XXXegl;
    return gl::eglBindAPI(api);
}

EGLAPI EGLenum EGLAPIENTRY eglQueryAPI(void)
{
    XXXegl;
    return gl::eglQueryAPI();
}




EGLAPI EGLBoolean EGLAPIENTRY eglWaitClient(void)
{
    XXXegl;
    return gl::eglWaitClient();
}




EGLAPI EGLBoolean EGLAPIENTRY eglReleaseThread(void)
{
    XXXegl;
    return gl::eglReleaseThread();
}




EGLAPI EGLSurface EGLAPIENTRY eglCreatePbufferFromClientBuffer(EGLDisplay dpy, EGLenum buftype, EGLClientBuffer buffer, EGLConfig config, const EGLint *attrib_list)
{
    XXXegl;
    return gl::eglCreatePbufferFromClientBuffer(dpy, buftype, buffer, config, attrib_list);
}




EGLAPI EGLBoolean EGLAPIENTRY eglSurfaceAttrib(EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint value) //
{
    XXXegl;
    return gl::eglSurfaceAttrib(dpy, surface, attribute, value);
}

EGLAPI EGLBoolean EGLAPIENTRY eglBindTexImage(EGLDisplay dpy, EGLSurface surface, EGLint buffer) //
{
    XXXegl;
    return gl::eglBindTexImage(dpy, surface, buffer);
}

EGLAPI EGLBoolean EGLAPIENTRY eglReleaseTexImage(EGLDisplay dpy, EGLSurface surface, EGLint buffer) //
{
    XXXegl;
    return gl::eglReleaseTexImage(dpy, surface, buffer);
}




EGLAPI EGLBoolean EGLAPIENTRY eglSwapInterval(EGLDisplay dpy, EGLint interval) //
{
    XXXegl;
    return gl::eglSwapInterval(dpy, interval);
}




EGLAPI EGLContext EGLAPIENTRY eglCreateContext(EGLDisplay dpy, EGLConfig config, EGLContext share_context, const EGLint *attrib_list) //
{
    XXXegl;
    return gl::eglCreateContext(dpy, config, share_context, attrib_list);
}

EGLAPI EGLBoolean EGLAPIENTRY eglDestroyContext(EGLDisplay dpy, EGLContext ctx) //
{
    XXXegl;
    return gl::eglDestroyContext(dpy, ctx);
}

EGLAPI EGLBoolean EGLAPIENTRY eglMakeCurrent(EGLDisplay dpy, EGLSurface draw, EGLSurface read, EGLContext ctx) //
{
    XXXegl;
    return gl::eglMakeCurrent(dpy, draw, read, ctx);
}




EGLAPI EGLContext EGLAPIENTRY eglGetCurrentContext(void) //
{
    XXXegl;
    return gl::eglGetCurrentContext();
}

EGLAPI EGLSurface EGLAPIENTRY eglGetCurrentSurface(EGLint readdraw) //
{
    XXXegl;
    return gl::eglGetCurrentSurface(readdraw);
}

EGLAPI EGLDisplay EGLAPIENTRY eglGetCurrentDisplay(void) //
{
    XXXegl;
    return gl::eglGetCurrentDisplay();
}

EGLAPI EGLBoolean EGLAPIENTRY eglQueryContext(EGLDisplay dpy, EGLContext ctx, EGLint attribute, EGLint *value) //
{
    XXXegl;
    return gl::eglQueryContext(dpy, ctx, attribute, value);
}


EGLAPI EGLBoolean EGLAPIENTRY eglWaitGL(void) //
{
    XXXegl;
    return gl::eglWaitGL();
}

EGLAPI EGLBoolean EGLAPIENTRY eglWaitNative(EGLint engine) //
{
    XXXegl;
    return gl::eglWaitNative(engine);
}

EGLAPI EGLBoolean EGLAPIENTRY eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) //
{
    XXXegl;
    return gl::eglSwapBuffers(dpy, surface);
}

EGLAPI EGLBoolean EGLAPIENTRY eglCopyBuffers(EGLDisplay dpy, EGLSurface surface, EGLNativePixmapType target) //
{
    XXXegl;
    return gl::eglCopyBuffers(dpy, surface, target);
}

typedef void (*__eglMustCastToProperFunctionPointerType)(void);
EGLAPI __eglMustCastToProperFunctionPointerType EGLAPIENTRY eglGetProcAddress(const char *procname) //
{
    XXXegl;
    printf("\t%s\n", procname);
    return gl::eglGetProcAddress(procname);
}


/***
 * GLES v2
 **/
GL_APICALL void         GL_APIENTRY glActiveTexture (GLenum texture)
{
    XXXgl2;
    gl::glActiveTexture(texture);
}

GL_APICALL void         GL_APIENTRY glAttachShader (GLuint program, GLuint shader)
{
    XXXgl2;
    gl::glAttachShader(program, shader);
}

GL_APICALL void         GL_APIENTRY glBindAttribLocation (GLuint program, GLuint index, const GLchar* name)
{
    XXXgl2;
    gl::glBindAttribLocation(program, index, name);
}

GL_APICALL void         GL_APIENTRY glBindBuffer (GLenum target, GLuint buffer)
{
    XXXgl2;
    gl::glBindBuffer(target, buffer);
}

GL_APICALL void         GL_APIENTRY glBindFramebuffer (GLenum target, GLuint framebuffer)
{
    XXXgl2;
    gl::glBindFramebuffer(target, framebuffer);
}

GL_APICALL void         GL_APIENTRY glBindRenderbuffer (GLenum target, GLuint renderbuffer)
{
    XXXgl2;
    gl::glBindRenderbuffer(target, renderbuffer);
}

GL_APICALL void         GL_APIENTRY glBindTexture (GLenum target, GLuint texture)
{
    XXXgl2;
    gl::glBindTexture(target, texture);
}

GL_APICALL void         GL_APIENTRY glBlendColor (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
    XXXgl2;
    gl::glBlendColor(red, green, blue, alpha);
}

GL_APICALL void         GL_APIENTRY glBlendEquation ( GLenum mode )
{
    XXXgl2;
    gl::glBlendEquation(mode);
}

GL_APICALL void         GL_APIENTRY glBlendEquationSeparate (GLenum modeRGB, GLenum modeAlpha)
{
    XXXgl2;
    gl::glBlendEquationSeparate(modeRGB, modeAlpha);
}

GL_APICALL void         GL_APIENTRY glBlendFunc (GLenum sfactor, GLenum dfactor)
{
    XXXgl2;
    gl::glBlendFunc(sfactor, dfactor);
}

GL_APICALL void         GL_APIENTRY glBlendFuncSeparate (GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
{
    XXXgl2;
    gl::glBlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha);
}

GL_APICALL void         GL_APIENTRY glBufferData (GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage)
{
    XXXgl2;
    gl::glBufferData(target, size, data, usage);
}

GL_APICALL void         GL_APIENTRY glBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid* data)
{
    XXXgl2;
    gl::glBufferSubData(target, offset, size, data);
}

GL_APICALL GLenum       GL_APIENTRY glCheckFramebufferStatus (GLenum target)
{
    XXXgl2;
    return gl::glCheckFramebufferStatus(target);
}

GL_APICALL void         GL_APIENTRY glClear (GLbitfield mask)
{
    XXXgl2;
    gl::glClear(mask);
}

GL_APICALL void         GL_APIENTRY glClearColor (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
    XXXgl2;
    gl::glClearColor(red, green, blue, alpha);
}

GL_APICALL void         GL_APIENTRY glClearDepthf (GLclampf depth)
{
    XXXgl2;
    gl::glClearDepthf(depth);
}

GL_APICALL void         GL_APIENTRY glClearStencil (GLint s)
{
    XXXgl2;
    gl::glClearStencil(s);
}

GL_APICALL void         GL_APIENTRY glColorMask (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
{
    XXXgl2;
    gl::glColorMask(red, green, blue, alpha);
}

GL_APICALL void         GL_APIENTRY glCompileShader (GLuint shader)
{
    XXXgl2;
    gl::glCompileShader(shader);
}

GL_APICALL void         GL_APIENTRY glCompressedTexImage2D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid* data)
{
    XXXgl2;
    gl::glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
}

GL_APICALL void         GL_APIENTRY glCompressedTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid* data)
{
    XXXgl2;
    gl::glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}

GL_APICALL void         GL_APIENTRY glCopyTexImage2D (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
{
    XXXgl2;
    gl::glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
}

GL_APICALL void         GL_APIENTRY glCopyTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
    XXXgl2;
    gl::glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
}

GL_APICALL GLuint       GL_APIENTRY glCreateProgram (void)
{
    XXXgl2;
    return gl::glCreateProgram();
}

GL_APICALL GLuint       GL_APIENTRY glCreateShader (GLenum type)
{
    XXXgl2;
    return gl::glCreateShader(type);
}

GL_APICALL void         GL_APIENTRY glCullFace (GLenum mode)
{
    XXXgl2;
    gl::glCullFace(mode);
}

GL_APICALL void         GL_APIENTRY glDeleteBuffers (GLsizei n, const GLuint* buffers)
{
    XXXgl2;
    gl::glDeleteBuffers(n, buffers);
}

GL_APICALL void         GL_APIENTRY glDeleteFramebuffers (GLsizei n, const GLuint* framebuffers)
{
    XXXgl2;
    gl::glDeleteFramebuffers(n, framebuffers);
}

GL_APICALL void         GL_APIENTRY glDeleteProgram (GLuint program)
{
    XXXgl2;
    gl::glDeleteProgram(program);
}

GL_APICALL void         GL_APIENTRY glDeleteRenderbuffers (GLsizei n, const GLuint* renderbuffers)
{
    XXXgl2;
    gl::glDeleteRenderbuffers(n, renderbuffers);
}

GL_APICALL void         GL_APIENTRY glDeleteShader (GLuint shader)
{
    XXXgl2;
    gl::glDeleteShader(shader);
}

GL_APICALL void         GL_APIENTRY glDeleteTextures (GLsizei n, const GLuint* textures)
{
    XXXgl2;
    gl::glDeleteTextures(n, textures);
}

GL_APICALL void         GL_APIENTRY glDepthFunc (GLenum func)
{
    XXXgl2;
    gl::glDepthFunc(func);
}

GL_APICALL void         GL_APIENTRY glDepthMask (GLboolean flag)
{
    XXXgl2;
    gl::glDepthMask(flag);
}

GL_APICALL void         GL_APIENTRY glDepthRangef (GLclampf zNear, GLclampf zFar)
{
    XXXgl2;
    gl::glDepthRangef(zNear, zFar);
}

GL_APICALL void         GL_APIENTRY glDetachShader (GLuint program, GLuint shader)
{
    XXXgl2;
    gl::glDetachShader(program, shader);
}

GL_APICALL void         GL_APIENTRY glDisable (GLenum cap)
{
    XXXgl2;
    gl::glDisable(cap);
}

GL_APICALL void         GL_APIENTRY glDisableVertexAttribArray (GLuint index)
{
    XXXgl2;
    gl::glDisableVertexAttribArray(index);
}

GL_APICALL void         GL_APIENTRY glDrawArrays (GLenum mode, GLint first, GLsizei count)
{
    XXXgl2;
    gl::glDrawArrays(mode, first, count);
}

GL_APICALL void         GL_APIENTRY glDrawElements (GLenum mode, GLsizei count, GLenum type, const GLvoid* indices)
{
    XXXgl2;
    gl::glDrawElements(mode, count, type, indices);
}

GL_APICALL void         GL_APIENTRY glEnable (GLenum cap)
{
    XXXgl2;
    gl::glEnable(cap);
}

GL_APICALL void         GL_APIENTRY glEnableVertexAttribArray (GLuint index)
{
    XXXgl2;
    gl::glEnableVertexAttribArray(index);
}

GL_APICALL void         GL_APIENTRY glFinish (void)
{
    XXXgl2;
    gl::glFinish();
}

GL_APICALL void         GL_APIENTRY glFlush (void)
{
    XXXgl2;
    gl::glFlush();
}

GL_APICALL void         GL_APIENTRY glFramebufferRenderbuffer (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
{
    XXXgl2;
    gl::glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
}

GL_APICALL void         GL_APIENTRY glFramebufferTexture2D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
    XXXgl2;
    gl::glFramebufferTexture2D(target, attachment, textarget, texture, level);
}

GL_APICALL void         GL_APIENTRY glFrontFace (GLenum mode)
{
    XXXgl2;
    gl::glFrontFace(mode);
}

GL_APICALL void         GL_APIENTRY glGenBuffers (GLsizei n, GLuint* buffers)
{
    XXXgl2;
    gl::glGenBuffers(n, buffers);
}

GL_APICALL void         GL_APIENTRY glGenerateMipmap (GLenum target)
{
    XXXgl2;
    gl::glGenerateMipmap(target);
}

GL_APICALL void         GL_APIENTRY glGenFramebuffers (GLsizei n, GLuint* framebuffers)
{
    XXXgl2;
    gl::glGenFramebuffers(n, framebuffers);
}

GL_APICALL void         GL_APIENTRY glGenRenderbuffers (GLsizei n, GLuint* renderbuffers)
{
    XXXgl2;
    gl::glGenRenderbuffers(n, renderbuffers);
}

GL_APICALL void         GL_APIENTRY glGenTextures (GLsizei n, GLuint* textures)
{
    XXXgl2;
    gl::glGenTextures(n, textures);
}

GL_APICALL void         GL_APIENTRY glGetActiveAttrib (GLuint program, GLuint index, GLsizei bufsize, GLsizei* length, GLint* size, GLenum* type, GLchar* name)
{
    XXXgl2;
    gl::glGetActiveAttrib(program, index, bufsize, length, size, type, name);
}

GL_APICALL void         GL_APIENTRY glGetActiveUniform (GLuint program, GLuint index, GLsizei bufsize, GLsizei* length, GLint* size, GLenum* type, GLchar* name)
{
    XXXgl2;
    gl::glGetActiveUniform(program, index, bufsize, length, size, type, name);
}

GL_APICALL void         GL_APIENTRY glGetAttachedShaders (GLuint program, GLsizei maxcount, GLsizei* count, GLuint* shaders)
{
    XXXgl2;
    gl::glGetAttachedShaders(program, maxcount, count, shaders);
}

GL_APICALL int          GL_APIENTRY glGetAttribLocation (GLuint program, const GLchar* name)
{
    XXXgl2;
    return gl::glGetAttribLocation(program, name);
}

GL_APICALL void         GL_APIENTRY glGetBooleanv (GLenum pname, GLboolean* params)
{
    XXXgl2;
    gl::glGetBooleanv(pname, params);
}

GL_APICALL void         GL_APIENTRY glGetBufferParameteriv (GLenum target, GLenum pname, GLint* params)
{
    XXXgl2;
    gl::glGetBufferParameteriv(target, pname, params);
}

GL_APICALL GLenum       GL_APIENTRY glGetError (void)
{
    XXXgl2;
    return gl::glGetError();
}

GL_APICALL void         GL_APIENTRY glGetFloatv (GLenum pname, GLfloat* params)
{
    XXXgl2;
    gl::glGetFloatv(pname, params);
}

GL_APICALL void         GL_APIENTRY glGetFramebufferAttachmentParameteriv (GLenum target, GLenum attachment, GLenum pname, GLint* params)
{
    XXXgl2;
    gl::glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);
}

GL_APICALL void         GL_APIENTRY glGetIntegerv (GLenum pname, GLint* params)
{
    XXXgl2;
    gl::glGetIntegerv(pname, params);
}

GL_APICALL void         GL_APIENTRY glGetProgramiv (GLuint program, GLenum pname, GLint* params)
{
    XXXgl2;
    gl::glGetProgramiv(program, pname, params);
}

GL_APICALL void         GL_APIENTRY glGetProgramInfoLog (GLuint program, GLsizei bufsize, GLsizei* length, GLchar* infolog)
{
    XXXgl2;
    gl::glGetProgramInfoLog(program, bufsize, length, infolog);
}

GL_APICALL void         GL_APIENTRY glGetRenderbufferParameteriv (GLenum target, GLenum pname, GLint* params)
{
    XXXgl2;
    gl::glGetRenderbufferParameteriv(target, pname, params);
}

GL_APICALL void         GL_APIENTRY glGetShaderiv (GLuint shader, GLenum pname, GLint* params)
{
    XXXgl2;
    gl::glGetShaderiv(shader, pname, params);
}

GL_APICALL void         GL_APIENTRY glGetShaderInfoLog (GLuint shader, GLsizei bufsize, GLsizei* length, GLchar* infolog)
{
    XXXgl2;
    gl::glGetShaderInfoLog(shader, bufsize, length, infolog);
}

GL_APICALL void         GL_APIENTRY glGetShaderPrecisionFormat (GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision)
{
    XXXgl2;
    gl::glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision);
}

GL_APICALL void         GL_APIENTRY glGetShaderSource (GLuint shader, GLsizei bufsize, GLsizei* length, GLchar* source)
{
    XXXgl2;
    gl::glGetShaderSource(shader, bufsize, length, source);
}

GL_APICALL const GLubyte* GL_APIENTRY glGetString (GLenum name)
{
    XXXgl2;
    return gl::glGetString(name);
}

GL_APICALL void         GL_APIENTRY glGetTexParameterfv (GLenum target, GLenum pname, GLfloat* params)
{
    XXXgl2;
    gl::glGetTexParameterfv(target, pname, params);
}

GL_APICALL void         GL_APIENTRY glGetTexParameteriv (GLenum target, GLenum pname, GLint* params)
{
    XXXgl2;
    gl::glGetTexParameteriv(target, pname, params);
}

GL_APICALL void         GL_APIENTRY glGetUniformfv (GLuint program, GLint location, GLfloat* params)
{
    XXXgl2;
    gl::glGetUniformfv(program, location, params);
}

GL_APICALL void         GL_APIENTRY glGetUniformiv (GLuint program, GLint location, GLint* params)
{
    XXXgl2;
    gl::glGetUniformiv(program, location, params);
}

GL_APICALL int          GL_APIENTRY glGetUniformLocation (GLuint program, const GLchar* name)
{
    XXXgl2;
    return gl::glGetUniformLocation(program, name);
}

GL_APICALL void         GL_APIENTRY glGetVertexAttribfv (GLuint index, GLenum pname, GLfloat* params)
{
    XXXgl2;
    gl::glGetVertexAttribfv(index, pname, params);
}

GL_APICALL void         GL_APIENTRY glGetVertexAttribiv (GLuint index, GLenum pname, GLint* params)
{
    XXXgl2;
    gl::glGetVertexAttribiv(index, pname, params);
}

GL_APICALL void         GL_APIENTRY glGetVertexAttribPointerv (GLuint index, GLenum pname, GLvoid** pointer)
{
    XXXgl2;
    gl::glGetVertexAttribPointerv(index, pname, pointer);
}

GL_APICALL void         GL_APIENTRY glHint (GLenum target, GLenum mode)
{
    XXXgl2;
    gl::glHint(target, mode);
}

GL_APICALL GLboolean    GL_APIENTRY glIsBuffer (GLuint buffer)
{
    XXXgl2;
    return gl::glIsBuffer(buffer);
}

GL_APICALL GLboolean    GL_APIENTRY glIsEnabled (GLenum cap)
{
    XXXgl2;
    return gl::glIsEnabled(cap);
}

GL_APICALL GLboolean    GL_APIENTRY glIsFramebuffer (GLuint framebuffer)
{
    XXXgl2;
    return gl::glIsFramebuffer(framebuffer);
}

GL_APICALL GLboolean    GL_APIENTRY glIsProgram (GLuint program)
{
    XXXgl2;
    return gl::glIsProgram(program);
}

GL_APICALL GLboolean    GL_APIENTRY glIsRenderbuffer (GLuint renderbuffer)
{
    XXXgl2;
    return gl::glIsRenderbuffer(renderbuffer);
}

GL_APICALL GLboolean    GL_APIENTRY glIsShader (GLuint shader)
{
    XXXgl2;
    return gl::glIsShader(shader);
}

GL_APICALL GLboolean    GL_APIENTRY glIsTexture (GLuint texture)
{
    XXXgl2;
    return gl::glIsTexture(texture);
}

GL_APICALL void         GL_APIENTRY glLineWidth (GLfloat width)
{
    XXXgl2;
    gl::glLineWidth(width);
}

GL_APICALL void         GL_APIENTRY glLinkProgram (GLuint program)
{
    XXXgl2;
    gl::glLinkProgram(program);
}

GL_APICALL void         GL_APIENTRY glPixelStorei (GLenum pname, GLint param)
{
    XXXgl2;
    gl::glPixelStorei(pname, param);
}

GL_APICALL void         GL_APIENTRY glPolygonOffset (GLfloat factor, GLfloat units)
{
    XXXgl2;
    gl::glPolygonOffset(factor, units);
}

GL_APICALL void         GL_APIENTRY glReadPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid* pixels)
{
    XXXgl2;
    gl::glReadPixels(x, y, width, height, format, type, pixels);
}

GL_APICALL void         GL_APIENTRY glReleaseShaderCompiler (void)
{
    XXXgl2;
    gl::glReleaseShaderCompiler();
}

GL_APICALL void         GL_APIENTRY glRenderbufferStorage (GLenum target, GLenum internalformat, GLsizei width, GLsizei height)
{
    XXXgl2;
    gl::glRenderbufferStorage(target, internalformat, width, height);
}

GL_APICALL void         GL_APIENTRY glSampleCoverage (GLclampf value, GLboolean invert)
{
    XXXgl2;
    gl::glSampleCoverage(value, invert);
}

GL_APICALL void         GL_APIENTRY glScissor (GLint x, GLint y, GLsizei width, GLsizei height)
{
    XXXgl2;
    gl::glScissor(x, y, width, height);
}

GL_APICALL void         GL_APIENTRY glShaderBinary (GLsizei n, const GLuint* shaders, GLenum binaryformat, const GLvoid* binary, GLsizei length)
{
    XXXgl2;
    gl::glShaderBinary(n, shaders, binaryformat, binary, length);
}

GL_APICALL void         GL_APIENTRY glShaderSource (GLuint shader, GLsizei count, const GLchar** string, const GLint* length)
{
    XXXgl2;
    gl::glShaderSource(shader, count, string, length);
}

GL_APICALL void         GL_APIENTRY glStencilFunc (GLenum func, GLint ref, GLuint mask)
{
    XXXgl2;
    gl::glStencilFunc(func, ref, mask);
}

GL_APICALL void         GL_APIENTRY glStencilFuncSeparate (GLenum face, GLenum func, GLint ref, GLuint mask)
{
    XXXgl2;
    gl::glStencilFuncSeparate(face, func, ref, mask);
}

GL_APICALL void         GL_APIENTRY glStencilMask (GLuint mask)
{
    XXXgl2;
    gl::glStencilMask(mask);
}

GL_APICALL void         GL_APIENTRY glStencilMaskSeparate (GLenum face, GLuint mask)
{
    XXXgl2;
    gl::glStencilMaskSeparate(face, mask);
}

GL_APICALL void         GL_APIENTRY glStencilOp (GLenum fail, GLenum zfail, GLenum zpass)
{
    XXXgl2;
    gl::glStencilOp(fail, zfail, zpass);
}

GL_APICALL void         GL_APIENTRY glStencilOpSeparate (GLenum face, GLenum fail, GLenum zfail, GLenum zpass)
{
    XXXgl2;
    gl::glStencilOpSeparate(face, fail, zfail, zpass);
}

GL_APICALL void         GL_APIENTRY glTexImage2D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* pixels)
{
    XXXgl2;
    gl::glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
}

GL_APICALL void         GL_APIENTRY glTexParameterf (GLenum target, GLenum pname, GLfloat param)
{
    XXXgl2;
    gl::glTexParameterf(target, pname, param);
}

GL_APICALL void         GL_APIENTRY glTexParameterfv (GLenum target, GLenum pname, const GLfloat* params)
{
    XXXgl2;
    gl::glTexParameterfv(target, pname, params);
}

GL_APICALL void         GL_APIENTRY glTexParameteri (GLenum target, GLenum pname, GLint param)
{
    XXXgl2;
    gl::glTexParameteri(target, pname, param);
}

GL_APICALL void         GL_APIENTRY glTexParameteriv (GLenum target, GLenum pname, const GLint* params)
{
    XXXgl2;
    gl::glTexParameteriv(target, pname, params);
}

GL_APICALL void         GL_APIENTRY glTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* pixels)
{
    XXXgl2;
    gl::glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
}

GL_APICALL void         GL_APIENTRY glUniform1f (GLint location, GLfloat x)
{
    XXXgl2;
    gl::glUniform1f(location, x);
}

GL_APICALL void         GL_APIENTRY glUniform1fv (GLint location, GLsizei count, const GLfloat* v)
{
    XXXgl2;
    gl::glUniform1fv(location, count, v);
}

GL_APICALL void         GL_APIENTRY glUniform1i (GLint location, GLint x)
{
    XXXgl2;
    gl::glUniform1i(location, x);
}

GL_APICALL void         GL_APIENTRY glUniform1iv (GLint location, GLsizei count, const GLint* v)
{
    XXXgl2;
    gl::glUniform1iv(location, count, v);
}

GL_APICALL void         GL_APIENTRY glUniform2f (GLint location, GLfloat x, GLfloat y)
{
    XXXgl2;
    gl::glUniform2f(location, x, y);
}

GL_APICALL void         GL_APIENTRY glUniform2fv (GLint location, GLsizei count, const GLfloat* v)
{
    XXXgl2;
    gl::glUniform2fv(location, count, v);
}

GL_APICALL void         GL_APIENTRY glUniform2i (GLint location, GLint x, GLint y)
{
    XXXgl2;
    gl::glUniform2i(location, x, y);
}

GL_APICALL void         GL_APIENTRY glUniform2iv (GLint location, GLsizei count, const GLint* v)
{
    XXXgl2;
    gl::glUniform2iv(location, count, v);
}

GL_APICALL void         GL_APIENTRY glUniform3f (GLint location, GLfloat x, GLfloat y, GLfloat z)
{
    XXXgl2;
    gl::glUniform3f(location, x, y, z);
}

GL_APICALL void         GL_APIENTRY glUniform3fv (GLint location, GLsizei count, const GLfloat* v)
{
    XXXgl2;
    gl::glUniform3fv(location, count, v);
}

GL_APICALL void         GL_APIENTRY glUniform3i (GLint location, GLint x, GLint y, GLint z)
{
    XXXgl2;
    gl::glUniform3i(location, x, y, z);
}

GL_APICALL void         GL_APIENTRY glUniform3iv (GLint location, GLsizei count, const GLint* v)
{
    XXXgl2;
    gl::glUniform3iv(location, count, v);
}

GL_APICALL void         GL_APIENTRY glUniform4f (GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    XXXgl2;
    gl::glUniform4f(location, x, y, z, w);
}

GL_APICALL void         GL_APIENTRY glUniform4fv (GLint location, GLsizei count, const GLfloat* v)
{
    XXXgl2;
    gl::glUniform4fv(location, count, v);
}

GL_APICALL void         GL_APIENTRY glUniform4i (GLint location, GLint x, GLint y, GLint z, GLint w)
{
    XXXgl2;
    gl::glUniform4i(location, x, y, z, w);
}

GL_APICALL void         GL_APIENTRY glUniform4iv (GLint location, GLsizei count, const GLint* v)
{
    XXXgl2;
    gl::glUniform4iv(location, count, v);
}

GL_APICALL void         GL_APIENTRY glUniformMatrix2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
{
    XXXgl2;
    gl::glUniformMatrix2fv(location, count, transpose, value);
}

GL_APICALL void         GL_APIENTRY glUniformMatrix3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
{
    XXXgl2;
    gl::glUniformMatrix3fv(location, count, transpose, value);
}

GL_APICALL void         GL_APIENTRY glUniformMatrix4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
{
    XXXgl2;
    gl::glUniformMatrix4fv(location, count, transpose, value);
}

GL_APICALL void         GL_APIENTRY glUseProgram (GLuint program)
{
    XXXgl2;
    gl::glUseProgram(program);
}

GL_APICALL void         GL_APIENTRY glValidateProgram (GLuint program)
{
    XXXgl2;
    gl::glValidateProgram(program);
}

GL_APICALL void         GL_APIENTRY glVertexAttrib1f (GLuint indx, GLfloat x)
{
    XXXgl2;
    gl::glVertexAttrib1f(indx, x);
}

GL_APICALL void         GL_APIENTRY glVertexAttrib1fv (GLuint indx, const GLfloat* values)
{
    XXXgl2;
    gl::glVertexAttrib1fv(indx, values);
}

GL_APICALL void         GL_APIENTRY glVertexAttrib2f (GLuint indx, GLfloat x, GLfloat y)
{
    XXXgl2;
    gl::glVertexAttrib2f(indx, x, y);
}

GL_APICALL void         GL_APIENTRY glVertexAttrib2fv (GLuint indx, const GLfloat* values)
{
    XXXgl2;
    gl::glVertexAttrib2fv(indx, values);
}

GL_APICALL void         GL_APIENTRY glVertexAttrib3f (GLuint indx, GLfloat x, GLfloat y, GLfloat z)
{
    XXXgl2;
    gl::glVertexAttrib3f(indx, x, y, z);
}

GL_APICALL void         GL_APIENTRY glVertexAttrib3fv (GLuint indx, const GLfloat* values)
{
    XXXgl2;
    gl::glVertexAttrib3fv(indx, values);
}

GL_APICALL void         GL_APIENTRY glVertexAttrib4f (GLuint indx, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    XXXgl2;
    gl::glVertexAttrib4f(indx, x, y, z, w);
}

GL_APICALL void         GL_APIENTRY glVertexAttrib4fv (GLuint indx, const GLfloat* values)
{
    XXXgl2;
    gl::glVertexAttrib4fv(indx, values);
}

GL_APICALL void         GL_APIENTRY glVertexAttribPointer (GLuint indx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* ptr)
{
    XXXgl2;
    gl::glVertexAttribPointer(indx, size, type, normalized, stride, ptr);
}

GL_APICALL void         GL_APIENTRY glViewport (GLint x, GLint y, GLsizei width, GLsizei height)
{
    XXXgl2;
    gl::glViewport(x, y, width, height);
}

}