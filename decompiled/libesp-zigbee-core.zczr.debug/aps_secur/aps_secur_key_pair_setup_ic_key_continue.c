/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_key_pair_setup_ic_key_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_secur_key_pair_setup_ic_key_continue(int param_1)

{
  ushort uVar1;
  
  memcpy((void *)(param_1 + 0x22),(void *)(param_1 + 0x12),0x10);
  uVar1 = *(ushort *)(param_1 + 0x34);
  *(ushort *)(param_1 + 0x34) = uVar1 & 0xfff9;
  *(ushort *)(param_1 + 0x34) = uVar1 & 0xfff8;
  *(ushort *)(param_1 + 0x34) = uVar1 & 0xff38 | 0x40;
  *(undefined2 *)(param_1 + 0x10) = 0xffff;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}

