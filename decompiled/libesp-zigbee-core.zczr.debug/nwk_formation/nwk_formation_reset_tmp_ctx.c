/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_formation.o -> nwk_formation_reset_tmp_ctx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_formation_reset_tmp_ctx(uint *param_1)

{
  *param_1 = *param_1 & 0x7ffffff;
  *param_1 = 0;
  *(undefined1 *)(param_1 + 2) = 0x7f;
  *(undefined1 *)((int)param_1 + 5) = 0xff;
  *(undefined1 *)((int)param_1 + 6) = 0xff;
  *(undefined1 *)((int)param_1 + 7) = 0xff;
  return;
}

