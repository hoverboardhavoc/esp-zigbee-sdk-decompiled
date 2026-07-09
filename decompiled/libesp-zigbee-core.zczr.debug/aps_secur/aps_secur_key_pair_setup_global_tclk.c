/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_key_pair_setup_global_tclk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_secur_key_pair_setup_global_tclk(int param_1)

{
  ushort uVar1;
  int iVar2;
  void *__src;
  ushort uVar3;
  
  iVar2 = core_globals_get();
  iVar2 = secur_is_key_valid(iVar2 + 0x990);
  if (iVar2 == 0) {
    iVar2 = aps_secur_is_centralized();
    if (iVar2 == 0) {
      __src = (void *)aps_secur_get_wellknown_secret(1);
    }
    else {
      __src = (void *)aps_secur_get_wellknown_secret(0);
    }
  }
  else {
    iVar2 = core_globals_get();
    __src = (void *)(iVar2 + 0x990);
  }
  uVar1 = *(ushort *)(param_1 + 0x34);
  uVar3 = uVar1 & 0xfff9;
  *(ushort *)(param_1 + 0x34) = uVar3;
  *(ushort *)(param_1 + 0x34) = uVar3 | 1;
  *(ushort *)(param_1 + 0x34) = uVar1 & 0xff39 | 1;
  *(undefined2 *)(param_1 + 0x10) = 0xffff;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  memcpy((void *)(param_1 + 0x12),__src,0x10);
  return;
}

