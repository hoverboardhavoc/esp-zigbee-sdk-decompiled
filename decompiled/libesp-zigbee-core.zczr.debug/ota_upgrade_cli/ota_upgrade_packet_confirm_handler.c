/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_packet_confirm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ota_upgrade_packet_confirm_handler(char *param_1,int param_2)

{
  int iVar1;
  
  if (param_1 == (char *)0x0) {
    iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c"
                          ,0x15c,"ota_upgrade_packet_confirm_handler",&_L0);
  }
  else {
    if (param_2 == 0) {
      return;
    }
    iVar1 = param_2;
    if (*param_1 != '\0') {
      ota_upgrade_download_retry(param_2);
      return;
    }
  }
  milli_timer_stop(iVar1 + 0x3c);
  milli_timer_start(iVar1 + 0x3c,*(undefined4 *)(param_2 + 0x34));
  return;
}

