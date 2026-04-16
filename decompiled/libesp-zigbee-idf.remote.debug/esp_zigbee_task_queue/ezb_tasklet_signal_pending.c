/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_task_queue.o -> ezb_tasklet_signal_pending
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ezb_tasklet_signal_pending(void)

{
  ssize_t sVar1;
  undefined4 uStack_18;
  uint64_t val;
  
  uStack_18 = 1;
  val._0_4_ = 0;
  sVar1 = write(s_task_queue_event_fd,&uStack_18,8);
  if (sVar1 == 8) {
    return;
  }
  __assert_func("//build/esp-zigbee/src/platform_esp/esp-zigbee/platform/esp_zigbee_task_queue.c",
                0x25,"ezb_tasklet_signal_pending","ret == sizeof(val)");
  ezb_tasklet_signal_pending();
  return;
}

