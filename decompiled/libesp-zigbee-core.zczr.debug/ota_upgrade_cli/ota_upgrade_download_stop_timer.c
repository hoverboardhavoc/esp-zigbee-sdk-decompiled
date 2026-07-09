/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_download_stop_timer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ota_upgrade_download_stop_timer(int param_1)

{
  int unaff_s1;
  int unaff_s2;
  
  if (param_1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c",
                  0x194,"ota_upgrade_download_stop_timer","context");
  }
  else {
    unaff_s2 = param_1 + 0x3c;
    unaff_s1 = milli_timer_is_running(unaff_s2);
    if (unaff_s1 == 0) {
      return 0;
    }
  }
  milli_timer_stop(unaff_s2);
  zcl_packet_free(param_1 + 0x4c);
  *(undefined1 *)(param_1 + 0x38) = 0;
  return unaff_s1;
}

