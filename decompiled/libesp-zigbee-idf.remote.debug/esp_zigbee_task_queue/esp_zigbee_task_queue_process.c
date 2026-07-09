/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_task_queue.o -> esp_zigbee_task_queue_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zigbee_task_queue_process(int param_1)

{
  undefined4 uVar1;
  ssize_t sVar2;
  int iVar3;
  undefined1 auStack_20 [8];
  code *pcStack_18;
  undefined4 uStack_14;
  
  if ((s_task_queue_event_fd < 0x40) &&
     ((*(uint *)(((int)(((int)s_task_queue_event_fd >> 0x1f & 0x1fU) + s_task_queue_event_fd) >> 5)
                 * 4 + param_1) & 1 << (s_task_queue_event_fd & 0x1f)) != 0)) {
    sVar2 = read(s_task_queue_event_fd,auStack_20,8);
    if (sVar2 != 8) {
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/platform/esp_zigbee_task_queue.c"
                    ,100,"esp_zigbee_task_queue_process","ret == sizeof(val)");
      goto _L0;
    }
  }
  ezb_tasklet_process();
  if (s_task_queue == 0) {
    esp_log(0x11,"ESP-ZIGBEE","%s(%d): Zigbee task queue not initialized",
            "esp_zigbee_task_queue_process",0x69);
    uVar1 = 0x103;
  }
  else {
    while (iVar3 = xQueueReceive(s_task_queue,&pcStack_18,0), iVar3 == 1) {
_L0:
      (*pcStack_18)(uStack_14,pcStack_18);
    }
    uVar1 = 0;
  }
  return uVar1;
}

