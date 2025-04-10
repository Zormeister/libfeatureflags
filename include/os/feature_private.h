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


#ifndef __OS_FEATURE_PRIVATE__
#define __OS_FEATURE_PRIVATE__

#include <stdbool.h>
#include <os/availability.h>
#include <os/base.h>

/*!
 * @group Feature Flags
 *
 * @abstract
 * Flags set in the filesystem for libraries to read and use for runtime configuration.
 *
 * @discussion
 * A reboot is required for flags to have been changed, libfeatureflags does not update on the fly.
 */

__BEGIN_DECLS

/*!
 * @define os_feature_is_enabled_simple
 *
 * @abstract
 * This function checks for the specified feature flag in a domain
 *
 * @param domain
 * The specified domain of the feature, such as 'objc4'
 *
 * @param feature
 * The feature being checked
 *
 * @param fallback
 * The default value if the feature isn't found.
 */
#define os_feature_is_enabled_simple(domain, feature, default) _os_feature_is_enabled_simple_impl(#domain, #feature, default)

/*!
 * @define os_feature_is_enabled
 *
 * @abstract
 * This function checks for the specified feature flag in a domain
 *
 * @param domain
 * The specified domain of the feature, such as 'objc4'
 *
 * @param feature
 * The feature being checked
 */
#define os_feature_is_enabled(domain, feature) _os_feature_is_enabled_impl(#domain, #feature)

bool _os_feature_is_emabled_simple_impl(const char *domain, const char *feature, bool fallback)
API_AVAILABLE(macos(10.16), ios(14.0), tvos(14.0), watchos(7.0), bridgeos(5.0))
API_UNAVAILABLE(driverkit);

bool _os_feature_is_emabled_impl(const char *domain, const char *feature)
API_AVAILABLE(macos(10.15), ios(13.0), tvos(13.0), watchos(6.0), bridgeos(4.0))
API_UNAVAILABLE(driverkit);

__END_DECLS

#endif /* __OS_FEATURE_PRIVATE__ */
