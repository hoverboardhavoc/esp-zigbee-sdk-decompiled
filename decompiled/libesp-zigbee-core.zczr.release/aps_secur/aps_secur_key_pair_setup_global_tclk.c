/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_key_pair_setup_global_tclk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_secur_key_pair_setup_global_tclk(int param_1)

{
  int iVar1;
  undefined1 *__src;
  
  iVar1 = core_globals_get();
  iVar1 = secur_is_key_valid(iVar1 + 0x990);
  if (iVar1 == 0) {
    iVar1 = aps_secur_is_centralized();
    if (iVar1 == 0) {
      __src = s_secur_wellknown_secret_0;
    }
    else {
      __src = s_secur_wellknown_secret_0;
    }
  }
  else {
    iVar1 = core_globals_get();
    __src = (undefined1 *)(iVar1 + 0x990);
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(byte *)(param_1 + 0x34) = *(byte *)(param_1 + 0x34) & 0x38 | 1;
  *(undefined2 *)(param_1 + 0x10) = 0xffff;
  memcpy((void *)(param_1 + 0x12),__src,0x10);
  return;
}

