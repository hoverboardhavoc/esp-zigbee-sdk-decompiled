/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee.release -> esp_zigbee.o -> esp_zigbee_launch_mainloop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zigbee_launch_mainloop(void)

{
  int iVar1;
  __fd_mask local_50 [6];
  int iStack_38;
  timeval tStack_30;
  __fd_mask _Stack_28;
  
  fence();
  s_mainloop_running = '\x01';
  fence();
  while( true ) {
    fence();
    fence();
    if (s_mainloop_running == '\0') {
      return 0;
    }
    local_50[1] = 0;
    local_50[0] = 0;
    local_50[3] = 0;
    local_50[2] = 0;
    local_50[5] = 0;
    local_50[4] = 0;
    iStack_38 = -1;
    tStack_30.tv_sec = 0xf0000;
    tStack_30.tv_usec = 0;
    _Stack_28 = 0;
    esp_zigbee_lock_acquire(0xffffffff);
    esp_zigbee_platform_update(local_50);
    esp_zigbee_sleep_process();
    esp_zigbee_lock_release();
    iVar1 = select(iStack_38 + 1,(fd_set *)local_50,(fd_set *)(local_50 + 2),
                   (fd_set *)(local_50 + 4),&tStack_30);
    if (iVar1 < 0) break;
    esp_zigbee_lock_acquire(0xffffffff);
    iVar1 = esp_zigbee_platform_process(local_50);
    esp_zigbee_lock_release();
    if (iVar1 != 0) {
      esp_log(0x11,"ESP-ZIGBEE","esp_zigbee_platform_process failed");
      return iVar1;
    }
  }
  esp_log(0x11,"ESP-ZIGBEE","Zigbee system polling failed");
  return -1;
}

