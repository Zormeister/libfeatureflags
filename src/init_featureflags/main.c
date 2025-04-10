/*
 * Copyright (c) 2025 PureDarwin Project, All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted providing that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <fcntl.h>
#include <os/stdio.h>
#include <os/stdlib.h>
#include <os/feature_internal.h>
#include <os/variant_private.h>
#include <sys/mman.h>
#include <fts.h>
#include <CoreFoundation/CoreFoundation.h>

static void ifflog(const char *fmt, ...)
{
    va_list list;
    CFStringRef cfFormat;
    CFStringRef cfString;

    va_start(list, fmt);

    cfFormat = CFStringCreateWithCString(kCFAllocatorDefault, fmt, kCFStringEncodingASCII);
    cfString = CFStringCreateWithFormatAndArguments(kCFAllocatorDefault, NULL, cfFormat, list);

    fprintf(stderr, "init_featureflags: %s\n", CFStringGetCStringPtr(cfString, kCFStringEncodingASCII));

    CFRelease(cfFormat);
    CFRelease(cfString);
    va_end(list);
}

int main(int argc, const char * argv[])
{
    os_fd_t shm_fd;
    const char **paths;
    int i = 0;
    
    ifflog("loading feature flags...");
    
    paths = _os_feature_search_paths();
    
    while (const char *path = paths[i++]; paths != NULL) {
        ifflog("processing %s", path);
    }

    return 0;
}
