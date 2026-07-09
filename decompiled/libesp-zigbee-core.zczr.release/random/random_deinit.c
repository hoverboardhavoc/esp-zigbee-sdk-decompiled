/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> random.o -> random_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void random_deinit(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0x10000;
  uVar2 = (uint)s_init_count;
  if (uVar2 == 0) {
    __assert_func(0,0,0,0);
  }
  *(short *)(iVar1 + 0x1b8) = (short)((uVar2 - 1) * 0x10000 >> 0x10);
  if ((uVar2 - 1 & 0xffff) == 0) {
    ezb_plat_crypto_random_deinit();
    return;
  }
  return;
}

