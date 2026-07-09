/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
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
  
  do {
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
    if (iVar1 < 0) {
      esp_log(0x11,"ESP-ZIGBEE","Zigbee system polling failed");
      return -1;
    }
    esp_zigbee_lock_acquire(0xffffffff);
    iVar1 = esp_zigbee_platform_process(local_50);
    esp_zigbee_lock_release();
  } while (iVar1 == 0);
  esp_log(0x11,"ESP-ZIGBEE","esp_zigbee_platform_process failed");
  return iVar1;
}

