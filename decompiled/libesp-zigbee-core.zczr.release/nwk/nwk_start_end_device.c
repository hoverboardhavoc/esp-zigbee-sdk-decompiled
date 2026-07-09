/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk.o -> nwk_start_end_device
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_start_end_device(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = nwk_is_joined();
  if (((iVar1 == 0) || (iVar1 = nwk_secur_is_authenticated(), iVar1 == 0)) ||
     (iVar1 = nwk_is_device_zed(), iVar1 == 0)) {
    uVar2 = 0x2c2;
  }
  else {
    iVar1 = core_globals_get();
    if (*(char *)(iVar1 + 0x9ee) == '\0') {
      nwk_pim_start_poll();
    }
    nwk_ed_start_keepalive();
    uVar2 = 0;
  }
  return uVar2;
}

