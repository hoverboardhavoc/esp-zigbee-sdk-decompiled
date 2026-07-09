/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac_pal.o -> mac_pal_handle_tx_started
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_pal_handle_tx_started(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = should_handle_ack_timeout();
  if ((iVar1 != 0) && ((*(ushort *)*param_1 & 0x20) != 0)) {
    start_timer(0x36);
  }
  return;
}

