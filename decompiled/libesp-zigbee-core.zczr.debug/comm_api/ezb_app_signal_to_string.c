/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> comm_api.o -> ezb_app_signal_to_string
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined * ezb_app_signal_to_string(uint param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while ((uVar1 < 0x16 && ((ushort)(&s_app_signal_table)[uVar1 * 4] != param_1))) {
    uVar1 = uVar1 + 1 & 0xff;
  }
  return (&PTR__LC0_000103b8)[uVar1 * 2];
}

