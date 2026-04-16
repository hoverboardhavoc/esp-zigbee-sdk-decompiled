/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> .L0__1
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void _L0(int param_1,uint param_2,uint param_3)

{
  if (param_2 < param_3) {
    *(short *)(param_1 + 0x12) = (short)param_3 - (short)param_2;
  }
  else {
    *(undefined2 *)(param_1 + 0x12) = 0;
  }
  return;
}

