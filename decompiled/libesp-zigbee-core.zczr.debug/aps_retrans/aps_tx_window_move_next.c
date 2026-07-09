/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_tx_window_move_next
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 aps_tx_window_move_next(byte *param_1)

{
  uint uVar1;
  uint uVar2;
  
  if (param_1[4] == 0xff) {
    uVar2 = (uint)param_1[3];
    uVar1 = param_1[1] + uVar2;
    if (uVar1 < *param_1) {
      param_1[1] = (byte)uVar1;
      param_1[2] = 0;
      uVar1 = (uint)*param_1 - (uVar1 & 0xff);
      if ((int)uVar1 < (int)uVar2) {
        uVar2 = uVar1;
      }
      param_1[3] = (byte)uVar2;
      param_1[4] = -(char)(1 << (uVar2 & 0x1f));
      return 1;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_retrans.c",99,
                  "aps_tx_window_move_next",
                  "w->slot_done == (((1 << ((8) % (sizeof(unsigned long) * 8))) - 1) << (0))");
  }
  return 0;
}

