/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> ota_upgrade_cli.o -> ota_upgrade_download_stop_retry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ota_upgrade_download_stop_retry(int param_1,uint param_2)

{
  uint extraout_a1;
  
  if (param_1 == 0) {
    param_1 = ota_upgrade_download_stop_retry_part_0();
    param_2 = extraout_a1;
  }
  if (*(byte *)(param_1 + 0x6c) == param_2) {
    milli_timer_stop(param_1 + 0x3c);
    zcl_packet_free();
    memset((void *)(param_1 + 0x4c),0,0x28);
    *(undefined1 *)(param_1 + 0x38) = 0;
  }
  return;
}

