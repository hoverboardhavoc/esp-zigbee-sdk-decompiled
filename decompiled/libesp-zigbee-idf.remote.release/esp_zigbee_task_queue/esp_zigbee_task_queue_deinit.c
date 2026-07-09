/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_task_queue.o -> esp_zigbee_task_queue_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zigbee_task_queue_deinit(void)

{
  if (s_task_queue != 0) {
    vQueueDelete();
    s_task_queue = 0;
  }
  if (-1 < s_task_queue_event_fd) {
    close(s_task_queue_event_fd);
    s_task_queue_event_fd = -1;
  }
  esp_zigbee_platform_workflow_unregister("task_queue");
  return;
}

