/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee.debug -> esp_zigbee.o -> esp_zigbee_launch_mainloop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zigbee_launch_mainloop(void)

{
  int iVar1;
  int aiStack_40 [6];
  int iStack_28;
  timeval tStack_20;
  __fd_mask _Stack_18;
  
  fence();
  s_mainloop_running = '\x01';
  fence();
  iVar1 = 0;
  while( true ) {
    fence();
    fence();
    if (s_mainloop_running == '\0') {
      return iVar1;
    }
    iVar1 = 2;
    while (iVar1 != 0) {
      iVar1 = iVar1 + -1;
      aiStack_40[iVar1] = 0;
    }
    for (iVar1 = 2; iVar1 != 0; iVar1 = iVar1 + -1) {
      aiStack_40[iVar1 + 1] = 0;
    }
    for (iVar1 = 2; iVar1 != 0; iVar1 = iVar1 + -1) {
      aiStack_40[iVar1 + 3] = 0;
    }
    iStack_28 = -1;
    tStack_20.tv_sec = 0xf0000;
    tStack_20.tv_usec = 0;
    _Stack_18 = 0;
    esp_zigbee_lock_acquire();
    esp_zigbee_platform_update(aiStack_40);
    esp_zigbee_sleep_process();
    esp_zigbee_lock_release();
    iVar1 = select(iStack_28 + 1,(fd_set *)aiStack_40,(fd_set *)(aiStack_40 + 2),
                   (fd_set *)(aiStack_40 + 4),&tStack_20);
    if (iVar1 < 0) break;
    esp_zigbee_lock_acquire(0xffffffff);
    iVar1 = esp_zigbee_platform_process(aiStack_40);
    esp_zigbee_lock_release();
    if (iVar1 != 0) {
      esp_log(0x11,"ESP-ZIGBEE","esp_zigbee_platform_process failed");
      return iVar1;
    }
  }
  esp_log(0x11,"ESP-ZIGBEE","Zigbee system polling failed");
  return -1;
}

