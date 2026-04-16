/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_task_queue.o -> esp_zigbee_task_queue_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_zigbee_task_queue_process(esp_zigbee_mainloop_context_t *ctx)

{
  ssize_t sVar1;
  esp_err_t eVar2;
  int iVar3;
  code *pcStack_18;
  esp_zigbee_task_t task;
  
  if ((((uint)s_task_queue_event_fd < 0x40) &&
      ((1 << (s_task_queue_event_fd & 0x1fU) &
       (ctx->read_fds).__fds_bits[s_task_queue_event_fd >> 5]) != 0)) &&
     (sVar1 = read(s_task_queue_event_fd,&pcStack_18,8), sVar1 != 8)) {
    __assert_func(0,0,0,0);
  }
  ezb_tasklet_process();
  eVar2 = 0x103;
  if (s_task_queue != (QueueHandle_t)0x0) {
    while (iVar3 = xQueueReceive(s_task_queue,&pcStack_18,0), iVar3 == 1) {
      (*pcStack_18)(task.cb,pcStack_18);
    }
    eVar2 = 0;
  }
  return eVar2;
}

