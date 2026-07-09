/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> nwk_address_unlock_ref
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_address_unlock_ref(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = core_globals_get();
  do_unlock_ref(iVar1 + 0xc4c,param_1);
  iVar2 = *(int *)(iVar1 + 0xc50) + param_1 * 0x12;
  if ((*(byte *)(iVar2 + 0x11) & 4) != 0) {
    do_unlock_ref(iVar1 + 0xc4c,*(undefined2 *)(iVar2 + 0xe));
  }
  return;
}

