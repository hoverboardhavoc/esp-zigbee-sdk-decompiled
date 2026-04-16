/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_task_queue.o -> esp_zigbee_task_queue_post
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

esp_err_t esp_zigbee_task_queue_post(esp_zigbee_callback_t cb,void *ctx)

{
  int iVar1;
  int iStack_1c;
  BaseType_t task_woken;
  esp_zigbee_task_t task_storage;
  
  if (s_task_queue == (QueueHandle_t)0x0) {
    esp_log(0x11,"ESP-ZIGBEE","%s(%d): Zigbee task queue not initialized",
            "esp_zigbee_task_queue_post",0x33);
    iStack_1c = 0x103;
  }
  else {
    iStack_1c = 0;
    task_woken = (BaseType_t)cb;
    task_storage.cb = (esp_zigbee_callback_t)ctx;
    if (_DAT_600c2194 < 2) {
      iVar1 = xQueueGenericSend(&task_woken,10,0);
      if (iVar1 == 0) {
        esp_log(0x11,"ESP-ZIGBEE","%s(%d): Failed to post task to Zigbee task queue",
                "esp_zigbee_task_queue_post",0x41);
        return -1;
      }
    }
    else {
      iVar1 = xQueueGenericSendFromISR(&task_woken,&iStack_1c,0);
      if (iVar1 == 0) {
        esp_log(0x19,"ESP-ZIGBEE","%s(%d): Failed to post task to Zigbee task queue",
                "esp_zigbee_task_queue_post",0x3e);
        return -1;
      }
    }
    esp_zigbee_task_queue_signal_pending();
    if (iStack_1c != 0) {
      vPortYieldFromISR();
      iStack_1c = 0;
    }
  }
  return iStack_1c;
}

