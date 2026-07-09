/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> ota_upgrade_cli.o -> ota_upgrade_download_stop_timer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ota_upgrade_download_stop_timer(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    param_1 = ota_upgrade_download_stop_timer_part_0();
  }
  iVar1 = milli_timer_is_running(param_1 + 0x3c);
  if (iVar1 != 0) {
    milli_timer_stop(param_1 + 0x3c);
    zcl_packet_free(param_1 + 0x4c);
    *(undefined1 *)(param_1 + 0x38) = 0;
  }
  return iVar1;
}

