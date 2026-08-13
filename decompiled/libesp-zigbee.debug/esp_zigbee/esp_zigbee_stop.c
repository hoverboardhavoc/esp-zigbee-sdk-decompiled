/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee.debug -> esp_zigbee.o -> esp_zigbee_stop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zigbee_stop(void)

{
  undefined4 uVar1;
  
  fence();
  fence();
  if (s_mainloop_running == '\0') {
    uVar1 = 0;
  }
  else {
    uVar1 = esp_zigbee_task_queue_post(0x10000,0);
  }
  return uVar1;
}

