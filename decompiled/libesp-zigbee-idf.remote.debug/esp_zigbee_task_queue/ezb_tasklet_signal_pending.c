/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_task_queue.o -> ezb_tasklet_signal_pending
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_tasklet_signal_pending(void)

{
  ssize_t sVar1;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_18 = 1;
  uStack_14 = 0;
  sVar1 = write(s_task_queue_event_fd,&uStack_18,8);
  if (sVar1 == 8) {
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/platform/esp_zigbee_task_queue.c"
                ,0x25,"ezb_tasklet_signal_pending","ret == sizeof(val)");
  ezb_tasklet_signal_pending();
  return;
}

