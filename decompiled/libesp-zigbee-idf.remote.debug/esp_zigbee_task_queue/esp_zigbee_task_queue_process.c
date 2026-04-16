/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_task_queue.o -> esp_zigbee_task_queue_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_zigbee_task_queue_process(esp_zigbee_mainloop_context_t *ctx)

{
  esp_err_t eVar1;
  ssize_t sVar2;
  int iVar3;
  undefined1 auStack_20 [4];
  uint64_t val;
  esp_zigbee_task_t task;
  
  if (((uint)s_task_queue_event_fd < 0x40) &&
     (((ctx->read_fds).__fds_bits
       [(int)((s_task_queue_event_fd >> 0x1f & 0x1fU) + s_task_queue_event_fd) >> 5] &
      1 << (s_task_queue_event_fd & 0x1fU)) != 0)) {
    sVar2 = read(s_task_queue_event_fd,auStack_20,8);
    if (sVar2 != 8) {
      __assert_func("//build/esp-zigbee/src/platform_esp/esp-zigbee/platform/esp_zigbee_task_queue.c"
                    ,100,"esp_zigbee_task_queue_process","ret == sizeof(val)");
      goto _L0;
    }
  }
  ezb_tasklet_process();
  if (s_task_queue == (QueueHandle_t)0x0) {
    esp_log(0x11,"ESP-ZIGBEE","%s(%d): Zigbee task queue not initialized",
            "esp_zigbee_task_queue_process",0x69);
    eVar1 = 0x103;
  }
  else {
    while (iVar3 = xQueueReceive(s_task_queue,(int)&val + 4,0), iVar3 == 1) {
_L0:
      (*val._4_4_)(task.cb,val._4_4_);
    }
    eVar1 = 0;
  }
  return eVar1;
}

