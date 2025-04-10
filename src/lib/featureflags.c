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

#include <os/base_private.h>
#include <os/alloc_once_private.h>
#include <os/lock.h>
#include <os/stdlib.h>
#include <os/feature_internal.h>
#include <os/debug_private.h>
#include <System/sys/kdebug.h>

bool _os_feature_is_enabled_simple_impl(const char *domain, const char *feature, bool fallback)
{
    os_feature_log("unimplemented.");
    return fallback;
}

bool _os_feature_is_enabled_impl(const char *domain, const char *feature)
{
    os_feature_table_t table = _os_feature_table();
    uint64_t hash;
    char str[2048];
    
    os_feature_log("%s: incoming request for domain %s; feature: %s", __FUNCTION__, domain, feature);
    
    if (table) {
        snprintf(str, 2048, "%s%s", domain, feature);
        hash = os_simple_hash_string(str);
        
        for (int i = 0; i < table->count; i++) {
            if (table->entries[i].hash == hash) {
                return table->entries[i].enabled;
            }
        }
    }
    
    /*
     * Fallback to reading the system disk.
     */
    return _os_feature_is_enabled_slow(domain, feature);
}
