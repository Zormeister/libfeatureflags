#  libfeatureflags

The system libraries for working with OS feature flags.

> [!WARNING]
> This is experimental software!
>
> It also requires various private SDK headers, which you need to install yourself.
>

## Info

The libfeatureflags project is used by many pieces of low level infrastructure in modern versions of Apple's source code; notably it is used in libSystem, libmalloc, and WebKit.

The library is initialised by `launchd` running `init_featureflags` during the boot process, it parses the configuration and stores the values into a shared memory file, which is read by `libsystem_featureflags` on initialisation.

As it stands, current open source variants of `launchd` don't have the boot task system in place, meaning `libsystem_featureflags` will likely be slow to process flags.

## Components

libfeatureflags is made up of a few components, namely:
- `libsystem_featureflags`
- `init_featureflags`
- `FeatureFlagsSupport.framework` (tbd)

## Requirements

### libsystem_featureflags

`libsystem_featureflags.dylib` requires numerous private SDK headers from `libsystem_darwin.dylib` and other libSystem components
