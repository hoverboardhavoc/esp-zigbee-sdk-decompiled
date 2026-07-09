/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_key_pair_set_unverified
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_secur_key_pair_set_unverified(int param_1)

{
  byte bVar1;
  int iVar2;
  
  if (param_1 == 0) {
    param_1 = __assert_func(0,0,0);
  }
  secur_key_copy(param_1 + 0x12);
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(byte *)(param_1 + 0x34) = *(byte *)(param_1 + 0x34) & 0xf8 | 2;
  iVar2 = core_globals_get();
  bVar1 = *(byte *)(iVar2 + 0x9b4);
  *(ushort *)(param_1 + 0x10) = (ushort)bVar1;
  if (bVar1 == 0) {
    return;
  }
  time_ticker_register_receiver(3);
  return;
}

