/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_task_queue.o -> esp_zigbee_task_queue_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zigbee_task_queue_init(void)

{
  int iVar1;
  
  s_task_queue_event_fd = eventfd(0,0x10);
  if (s_task_queue_event_fd < 0) {
    esp_log(0x11,"ESP-ZIGBEE","%s(%d): Failed to create Zigbee task queue event fd",
            "esp_zigbee_task_queue_init",0x77);
    iVar1 = -1;
  }
  else {
    s_task_queue = xQueueGenericCreate(8,0);
    if (s_task_queue == 0) {
      esp_log(0x11,"ESP-ZIGBEE","%s(%d): Failed to create Zigbee task queue",
              "esp_zigbee_task_queue_init",0x7b);
      iVar1 = 0x101;
    }
    else {
      iVar1 = esp_zigbee_platform_workflow_register
                        ("task_queue",0x10000,esp_zigbee_task_queue_process);
      if (iVar1 == 0) {
        return 0;
      }
      esp_log(0x11,"ESP-ZIGBEE","%s(%d): Failed to register Zigbee task queue workflow",
              "esp_zigbee_task_queue_init",0x80);
      vQueueDelete(s_task_queue);
      s_task_queue = 0;
    }
    close(s_task_queue_event_fd);
    s_task_queue_event_fd = -1;
  }
  return iVar1;
}

