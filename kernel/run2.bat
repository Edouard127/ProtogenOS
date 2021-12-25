set OSNAME=ProtOS
set BUILDDIR=%0/../bin
set OVMFDIR=%0/../../OVMFbin

set BUILDDIR=%BUILDDIR:"=%
set OVMFDIR=%OVMFDIR:"=%
"C:\Program Files\qemu\qemu-system-x86_64.exe" -drive file=%BUILDDIR%/%OSNAME%.img -m 256M -cpu qemu64 -drive if=pflash,format=raw,unit=0,file=%OVMFDIR%/OVMF_CODE-pure-efi.fd,readonly=on -drive if=pflash,format=raw,unit=1,file=%OVMFDIR%/OVMF_VARS-pure-efi.fd -display gtk -netdev user,id=n0 -device rtl8139,netdev=n0
pause
