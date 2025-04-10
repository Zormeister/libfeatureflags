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

#include <os/assumes.h>
#include <os/alloc_once_private.h>
#include <os/lock.h>
#include <os/stdlib.h>
#include <os/feature_internal.h>
#include <xpc/xpc.h>

void _os_feature_globals_init(void *ctx)
{
    struct _os_feature_globals_s *globals = (struct _os_feature_globals_s *)ctx;
    
    globals->once_token = 0;
}

void _os_feature_table_once(void *ctx)
{
    os_fd_t fd = shm_open("org.puredarwin.featureflags.shm", O_RDONLY, 0644);
    os_feature_log("feature table is unimplemented.");
}

os_feature_table_t _os_feature_table(void)
{
    struct _os_feature_globals_s *feat = _os_feature_globals();

    os_once(&feat->once_token, feat, _os_feature_table_once);

    return feat->feature_table;
}
