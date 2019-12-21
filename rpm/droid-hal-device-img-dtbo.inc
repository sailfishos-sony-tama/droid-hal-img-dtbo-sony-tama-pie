# This file should be %%included into a device specific spec file
# where macros are defined:
#
# Device information:
# device:        device name used in droid-hal-* package names

%define kernelver %(rpm -ql droid-hal-%{device}-kernel-modules | sort | grep /lib/modules/ | head -1 | rev | cut -d '/' -f 1 | rev)
%define localver %(echo "%{kernelver}" | cut -d '-' -f1 | cut -d '+' -f1)
%define rel_date %(date +'%%Y%%m%%d%%H%%M')

Name:       droid-hal-%{device}-img-dtbo
Summary:    Device tree overlays image for %{device}
Version:    %{localver}
Release:    %{rel_date}
Group:      Kernel/Linux Kernel
License:    GPLv2
Source0:    dtbo-%{device}.img

BuildRequires:  droid-hal-%{device}-kernel
BuildRequires:  droid-hal-%{device}-kernel-modules

Requires:   kernel = %{localver}

%description
%{summary}

%build
pwd
ls -lh

%install

mkdir -p $RPM_BUILD_ROOT/boot
cp dtbo-%{device}.img $RPM_BUILD_ROOT/boot/dtbo.img

%files
%defattr(-,root,root,-)
/boot/dtbo.img
