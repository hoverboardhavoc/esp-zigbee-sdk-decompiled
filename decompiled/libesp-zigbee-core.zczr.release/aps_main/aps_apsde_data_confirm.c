/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_main.o -> aps_apsde_data_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_apsde_data_confirm(int param_1)

{
  log_write(3,"aps_main.c",">>>>>>>>>>>>>>>>>>>>");
  log_write(3,"aps_main.c","Tx APS Frame Done (0x%02x): 0x%04x:%d profile(0x%04x) cluster(0x%04x)",
            *(undefined1 *)(param_1 + 0x10),*(undefined2 *)(param_1 + 2),
            *(undefined1 *)(param_1 + 0xb),*(undefined2 *)(param_1 + 0xc),
            *(undefined2 *)(param_1 + 0xe));
  log_write(3,"aps_main.c","<<<<<<<<<<<<<<<<<<<<");
  zmsg_free(*(undefined4 *)(param_1 + 0x14));
  return;
}

