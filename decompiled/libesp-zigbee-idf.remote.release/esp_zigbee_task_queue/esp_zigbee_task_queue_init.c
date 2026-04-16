/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_task_queue.o -> esp_zigbee_task_queue_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_zigbee_task_queue_init(void)

{
  int iVar1;
  
  s_task_queue_event_fd = eventfd(0,0x10);
  iVar1 = -1;
  if (-1 < s_task_queue_event_fd) {
    s_task_queue = (QueueHandle_t)xQueueGenericCreate(8,0);
    if (s_task_queue == (QueueHandle_t)0x0) {
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
    s_task_queue = (QueueHandle_t)0x0;
    close(s_task_queue_event_fd);
    s_task_queue_event_fd = -1;
  }
  return iVar1;
}

