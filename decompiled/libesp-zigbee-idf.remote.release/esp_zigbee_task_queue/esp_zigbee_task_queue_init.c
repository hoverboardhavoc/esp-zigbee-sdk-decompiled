/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_task_queue.o -> esp_zigbee_task_queue_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zigbee_task_queue_init(void)

{
  int iVar1;
  
  s_task_queue_event_fd = eventfd(0,0x10);
  iVar1 = -1;
  if (-1 < s_task_queue_event_fd) {
    s_task_queue = xQueueGenericCreate(8,0);
    if (s_task_queue == 0) {
      iVar1 = 0x101;
    }
    else {
      iVar1 = esp_zigbee_platform_workflow_register
                        ("task_queue",esp_zigbee_task_queue_update,0x10000);
      if (iVar1 == 0) {
        return 0;
      }
      vQueueDelete(s_task_queue);
    }
    s_task_queue = 0;
    close(s_task_queue_event_fd);
    s_task_queue_event_fd = -1;
  }
  return iVar1;
}

